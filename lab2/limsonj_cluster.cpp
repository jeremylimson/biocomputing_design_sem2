/*
* 2-22-2022
* jeremy limson
* description : k mean clustering
*/

#include "limsonj_k_means.hpp"
#include <fstream>

int main(int argc, char * argv[]) {
    // initialzie variables and file pointers
    int gene_size = atoi(argv[1]);
    char output_buffer[100];

    FILE* normal_file;
    
    // file i/o for part 3
    std::ofstream suppressed_file;
    std::ofstream stationary_file;
    std::ofstream expressed_file;

    suppressed_file.open(argv[2]);
    stationary_file.open(argv[3]);
    expressed_file.open(argv[4]);

    std::vector<float> normalized_data;
    FILE* normal_data;
    float line, distance1 = 0.0, distance2 = 0.0, distance3 = 0.0, criteria = 1.0,
    old_mean1 = 0.0, old_mean2 = 0.0, old_mean3 = 0.0, new_mean1 = 0.0, new_mean2 = 0.0, new_mean3 = 0.0;

    // PART 3: read in data file and check if it exists
    if (normal_data = fopen("log_ratio_input.dat", "r")) {
        //std::cout << " log_ratio_input.dat exists\n";
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
            if (count < gene_size) {
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
    }

    fclose(normal_data);

    suppressed_file.close();
    stationary_file.close();
    expressed_file.close();

    return 0;
}