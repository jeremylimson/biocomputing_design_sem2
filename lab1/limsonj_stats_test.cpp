/*
* 2-1-2022
* jeremy limson
* description : test file for testing statistical functions
*/

// this is wrong but it won't work without it
#include "limsonj_stats.cpp"

using namespace std;

int main(int argc, char * argv[]) {
    // why does constructor require arguments
    int state = 0, x, y, z;
    float num, average = 0;

    std::vector<float> test_vector;

	// read chosen file
	FILE* data_file;
	data_file = fopen(argv[1], "r");
    state = fscanf(data_file, "%f", &num);

	// exit program if no file is found
	if (data_file == NULL) {
		printf("File does not exist. Please try again.\n");
		exit(1);
	}
    
    while (state == 1) {
        //printf("number: %f\n", num);    // read through the entire file
        test_vector.push_back(num);
        state = fscanf(data_file, "%f", &num);
    }

    // ifstream in_file;
    // in_file.open(argv[1]);

    // if (in_file.fail()) {
    //     cout << "File failed to load. Please try again.";
    // } else {
    //     float input = 0.0;
    //     while (cin >> input) {
    //         cout << input << endl;
    //     }
    // }
    
    myStats::statTools statTest(x, y, z);

    //std::vector<float> test_vector = {1.1, 2.2, 4.4, 5.5, 6.6, 7.7, 8.8, 10.1};

    statTest.set_size(&test_vector);    // should be 8
    statTest.set_max(&test_vector); // should be 10.1
    statTest.set_min(&test_vector); // should be -8
    statTest.set_mean(&test_vector);    // should be ~5
    statTest.set_std_dev(&test_vector);    // should be ~2

    average = statTest.get_mean();
    printf("Mean: %f\n", average);
    
    statTest.follow_me_on_histogram(&test_vector);
    
    fclose(data_file);

    return 0;
}