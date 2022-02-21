/*
* 2-22-2022
* jeremy limson
* description : pre processing *.dat files by normalizing data points
*/

#include "limsonj_vector_ops_pre_processing.hpp"

int main(int argc, char * argv[]) {
    // initialzie variables and file pointers
    int num_genes = argv[6];

    std::vector<float> * red_vec_data;
    std::vector<float> * red_vec_back;
    std::vector<float> * green_vec_data;
    std::vector<float> * green_vec_back;

	FILE* red_data; 
    FILE* red_back;
    FILE* green_data;
    FILE* green_back;
    FILE* out_file;

    std::string file_name = argv[5];

    // read red sporulating cells file and background data
	red_data = fopen(argv[1], "r");
	red_back = fopen(argv[2], "r");
    
    // read green sporulating cells file and background data
    green_data = fopen(argv[3], "r");
	green_back = fopen(argv[4], "r");

    // fifth argument is the output file name
    out_file = fopen(file_name, "w");

    // read and store data into vector
    open_file(red_data, red_vec_data);
    open_file(red_back, red_vec_back);
    open_file(green_data, green_vec_data);
    open_file(green_back, green_vec_back);

    // close files
    fclose(red_data);
    fclose(red_back);
    fclose(green_data);
    fclose(green_back);
    
    return 0;
}

void open_file(FILE* handle, std::vector<int> * input_data) {
    // initialize variables
    int state = 0, num;
    state = fscanf(red_data, "%d", &num);

    // read through the entire red data file
    while (state == 1) {
        std::cout << num << "\n";
        input_data->push_back(num);
        state = fscanf(red_data, "%d\n", &num);
    }
}