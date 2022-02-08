/*
* 2-1-2022
* jeremy limson
* description : test file for testing correlation class functions
*/

#include "limsonj_corr.cpp" // i know youre not supposed to have this but this isnt the problem i checked
#include "limsonj_stats.cpp"

int main(int argc, char * argv[]) {
    
    int x, y, z;

    std::vector<float> test_vector = {1.1, 2.2, 4.4, 5.5, 6.6, 7.7, 8.8, 10.1};
    std::vector<float> test_vector2 = {1.1, 2.2, -4.4, 5.5, 6.6, 7.7, -8.8, 10.1};

    myStats::corrTools corrTest(x, y, z);

    corrTest.set_corr_coeff(&test_vector, &test_vector2);
}