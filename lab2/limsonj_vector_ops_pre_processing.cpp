/*
* 2-22-2022
* jeremy limson
* description : pre processing *.dat files by normalizing data points
*/

#include "limsonj_vector_ops_pre_processing.hpp"
#include "limsonj_k_means.hpp"
#include <fstream>

int main(int argc, char * argv[]) {
    // sixth argument is the number of genes to be analyzed
    int num_genes = atoi(argv[6]);

    // initialzie variables and file pointers
    int x, y, z;
    char output_buffer[100];

    // file i/o for part 3
    std::ofstream suppressed_file;
    std::ofstream stationary_file;
    std::ofstream expressed_file;

    suppressed_file.open("suppressed_genes.txt");
    stationary_file.open("stationary_genes.txt");
    expressed_file.open("expressed_genes.txt");

    std::vector<int> red_vec_data;
    std::vector<int> red_vec_back;
    std::vector<int> green_vec_data;
    std::vector<int> green_vec_back;

	FILE* red_data; 
    FILE* red_back;
    FILE* green_data;
    FILE* green_back;
    FILE* out_file;
    FILE* normal_file;

    // fifth argument is the output file name
    char* file_name = argv[5];

    // read red sporulating cells file and background data
	if (red_data = fopen(argv[1], "r")) {
        std::cout << argv[1] <<" file exists\n";
    } else {
        std::cout << "Swing and a miss... " << argv[1] << " does not exist. Try again\n\r";
        return -1;
    }

	if (red_back = fopen(argv[2], "r")) {
        std::cout << argv[2] <<" file exists\n";
    } else {
        std::cout << "Swing and a miss... " << argv[2] << " does not exist. Try again\n\r";
        return -1;
    }
    
    // read green sporulating cells file and background data
    if (green_data = fopen(argv[3], "r")) {
        std::cout << argv[3] <<" file exists\n";
    } else {
        std::cout << "Swing and a miss... " << argv[3] << " does not exist. Try again\n\r";
        return -1;
    }
	if (green_back = fopen(argv[4], "r")) {
        std::cout << argv[4] <<" file exists\n";
    } else {
        std::cout << "Swing and a miss... " << argv[4] << " does not exist. Try again\n\r";
        return -1;
    }

    // fifth argument is the output file name
    out_file = fopen(file_name, "w");

    // read and store data into vector
    open_file(red_data, &red_vec_data);
    open_file(red_back, &red_vec_back);
    open_file(green_data, &green_vec_data);
    open_file(green_back, &green_vec_back);
    
    // check that the number of genes requested does not exceed number of data points in the file
    bool red_check1 = geneCheck(&red_vec_data, num_genes);
    bool red_check2 = geneCheck(&red_vec_back, num_genes);
    bool green_check1 = geneCheck(&green_vec_data, num_genes);
    bool green_check2 = geneCheck(&green_vec_back, num_genes);

    if (red_check1 == false || red_check2 == false || green_check1 == false || green_check2 == false) {
        std::cout << "Number of genes exceeds data points provided \n";
        return 0;
    }

    // subtract the corresponding background intensities from the red and green datasets. 
    vector_ops::vector_tools get_vectored(x, y, z);

    std::vector<int> red_sub_array;
    std::vector<int> green_sub_array;

    get_vectored.element_wise_sub(&red_vec_data, &red_vec_back, &red_sub_array);
    get_vectored.element_wise_sub(&green_vec_data, &green_vec_back, &green_sub_array);

    // calculate the means of the corrected red and green datasets. 
    int red_sum = get_vectored.sum_array(&red_sub_array);
    float red_mean = red_sum / red_sub_array.size();

    int green_sum = get_vectored.sum_array(&green_sub_array);
    float green_mean = green_sum / green_sub_array.size();

    std::vector<float> normalized_red;
    std::vector<float> normalized_green;
    
    // normalize data by dividing each data point by the mean
    get_vectored.div_array(&red_sub_array, red_mean, &normalized_red);
    get_vectored.div_array(&green_sub_array, green_mean, &normalized_green);

    // calculate log intensity ratio
    for (int i = 0; i < red_sub_array.size(); i++) {
        float lr = log10(normalized_red.at(i) / normalized_green.at(i));
        fprintf(out_file, "%f\n", lr);
    }

    std::vector<float> normalized_data;
    fclose(out_file);
    FILE* normal_data;
    float line, distance1 = 0.0, distance2 = 0.0, distance3 = 0.0, criteria = 1.0,
    old_mean1 = 0.0, old_mean2 = 0.0, old_mean3 = 0.0, new_mean1 = 0.0, new_mean2 = 0.0, new_mean3 = 0.0;

    // PART 3: read in data file and check if it exists
    if (normal_data = fopen("log_ratio_input.dat", "r")) {
        std::cout << " log_ratio_input.dat exists\n";
    } else {
        std::cout << "Swing and a miss... " << "log_ratio_input.dat" << " does not exist. Try again\n\r";
        return -1;
    }

    fscanf(normal_data, "%f", &line);

    while (!feof(normal_data)) {
        normalized_data.push_back(line);
        fscanf(normal_data, "%f", &line);
    }

    myStats::statTools clusterStat;

    // initialize three cluster classes, names, and means
    k_mean::cluster cluster1;
    k_mean::cluster cluster2;
    k_mean::cluster cluster3;

    // suppressed < 0, stationary = 0, expressed > 0
    cluster1.set_object_name("Suppressed");
    cluster2.set_object_name("Stationary");
    cluster3.set_object_name("Expressed");

    // suppressed -> log ratio = -0.5, stationary -> log ratio = 0, expressed -> log ratio = .5
    cluster1.set_object_mean(-0.5);
    cluster2.set_object_mean(0.0);
    cluster3.set_object_mean(0.5);

    // (4) while this criteria is greater than 0.0001, repeat 1-4
    while (criteria > 0.0001) {
        // remove all members
        cluster1.cluster_set.clear();
        cluster2.cluster_set.clear();
        cluster3.cluster_set.clear();

        // (1) for each log ratio data point calculate the distance of the point to each of the three cluster means
        for (float i : normalized_data) {
            distance1 = cluster1.distance(i);
            distance2 = cluster2.distance(i);
            distance3 = cluster3.distance(i);
            
            // /(2) compare returned distance to means and add point to closest cluster
            if (distance1 < distance2 && distance1 < distance3) {
                cluster1.cluster_set.push_back(i);
            } else if (distance2 < distance1 && distance2 < distance3) {
                cluster2.cluster_set.push_back(i);
            } else if (distance3 < distance1 && distance3 < distance2) {
                cluster3.cluster_set.push_back(i);
            }
        }

        // (3) when all points have been reassigned, recalculate the cluster means
        old_mean1 = cluster1.get_object_mean();
        old_mean2 = cluster2.get_object_mean();
        old_mean3 = cluster3.get_object_mean();

        clusterStat.set_mean(&cluster1.cluster_set);
        new_mean1 = clusterStat.get_mean();

        clusterStat.set_mean(&cluster2.cluster_set);
        new_mean2 = clusterStat.get_mean();

        clusterStat.set_mean(&cluster3.cluster_set);
        new_mean3 = clusterStat.get_mean();

        cluster1.set_object_mean(new_mean1);
        cluster2.set_object_mean(new_mean2);
        cluster3.set_object_mean(new_mean3);

        // (4) criteria = |c1_mean_old – c1_mean| + |c2_mean_old – c2_mean|+|c3_mean_old –c3_mean|
        criteria = abs(old_mean1 - new_mean1) + abs(old_mean2 - new_mean2) + abs(old_mean3 - new_mean3);
    }

    std::cout << "\n\rmean 1: " << cluster1.get_object_mean() << "\n";
    std::cout << "mean 2: " << cluster2.get_object_mean() << "\n";
    std::cout << "mean 3: " << cluster3.get_object_mean() << "\n\n";

    int count = 0;

    // FIXME

    // output final cluster means to standard output
    // write three output files, one for each of the final clusters
    if (normal_file = fopen("./microarray/gene_list.txt", "r")) {
        while (fgets(output_buffer, sizeof(output_buffer), normal_file) != NULL) {
            float distance1 = cluster1.distance(normalized_data.at(count));
            float distance2 = cluster2.distance(normalized_data.at(count));
            float distance3 = cluster3.distance(normalized_data.at(count));

            if (distance1 <= distance2 && distance1 < distance3) {
                // print to suppressed_genes.txt file
                suppressed_file << output_buffer;
            } else if (distance2 < distance1 && distance2 < distance3) {
                // print to stationary_genes.txt file
                stationary_file << output_buffer;
            } else if (distance3 < distance1 && distance3 < distance2) {
                // print to expressed_genes.txt file
                expressed_file << output_buffer;
            }
            count++;
        }
    }
    
    // close files
    fclose(red_data);
    fclose(red_back);
    fclose(green_data);
    fclose(green_back);
    fclose(normal_data);

    suppressed_file.close();
    stationary_file.close();
    expressed_file.close();
    
    return 0;
}

void open_file(FILE* handle, std::vector<int>* input_data) {
    // initialize variables
    int state = 0, num;
    state = fscanf(handle, "%d", &num);

    // read through the entire red data file
    while (state == 1) {
        //std::cout << num << "\n";
        input_data->push_back(num);
        state = fscanf(handle, "%d\n", &num);
    }
}

bool geneCheck(std::vector<int>* input_data, int genes) {
    // check that the number of genes requested does not exceed number of data points in the file
    if (genes > input_data->size()) {
        return false;
    } else {
        return true;
    }
}

