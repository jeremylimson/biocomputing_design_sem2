/*
* 2-1-2022
* jeremy limson
* description : test file for testing
*/

// this is wrong but it won't work without it
#include "limsonj_stats.cpp"

int main(int argc, char * argv[]) {
    int i, dont, know;  // why does constructor require arguments

    // how do we initialize a pointer to a vector
    std::vector<float> test_vector = {1.1, 2.2, 4.4, 5.5, 6.6, 7.7, 8.8, 10.1};
    std::vector<float> test_vector2 = {1.1, 2.2, -4.4, 5.5, 6.6, 7.7, -8.8, 10.1};

    myStats::statTools statTest(i, dont, know); // why

    statTest.set_max(&test_vector); // should be 10.1
    statTest.set_min(&test_vector2); // should be -8
    statTest.set_mean(&test_vector);    // should be ~5
    statTest.set_std_dev(&test_vector);    // should be ~2

    return 0;
}