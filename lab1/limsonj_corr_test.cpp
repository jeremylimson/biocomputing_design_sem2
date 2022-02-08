/*
* 2-1-2022
* jeremy limson
* description : test file for testing correlation class functions
*/

#include "limsonj_corr.cpp" // i know youre not supposed to have this but this isnt the problem i checked
#include "limsonj_stats.cpp"

int main(int argc, char * argv[]) {

    // why does constructor require arguments
    int state1 = 0, state2 = 0, x, y, z;
    float num, num2;

    std::vector<float> test_vector;
    std::vector<float> test_vector2;

	// read chosen file
	FILE* data_file1; 
    FILE* data_file2;
	data_file1 = fopen(argv[1], "r");
	data_file2 = fopen(argv[2], "r");

    state1 = fscanf(data_file1, "%f", &num);
    state2 = fscanf(data_file2, "%f", &num2);

	// // exit program if no file(s) found
	// if (data_file == NULL) {
	// 	printf("File does not exist. Please try again.\n");
	// 	exit(1);
	// }

    // if (data_file2 == NULL) {
	// 	printf("File 2 does not exist. Please try again.\n");
	// 	exit(1);
	// }
    
    while (state1 == 1) {
        //printf("number: %f\n", num);    // read through the entire file
        test_vector.push_back(num);
        state1 = fscanf(data_file1, "%f", &num);
    }

    while (state2 == 1) {
        //printf("number: %f\n", num);    // read through the entire file
        test_vector2.push_back(num2);
        state2 = fscanf(data_file2, "%f", &num2);
    }

    // std::vector<float> test_vector = {1.1, 2.2, 4.4, 5.5, 6.6, 7.7, 8.8, 10.1};

    myStats::corrTools corrTest(x, y, z);

    corrTest.set_corr_coeff(&test_vector, &test_vector2);

    fclose(data_file1);
    fclose(data_file2);

    return 0;
}