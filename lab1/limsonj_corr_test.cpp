/*
* 2-1-2022
* jeremy limson
* description : test file for testing correlation class functions
*/

#include "limsonj_corr.cpp"

int main(int argc, char * argv[]) {
    // std::vector is not a member of std
    // myStats has not been declared
    
    int x, y, z;

    std::vector<float> test_vector = {1.1, 2.2, 4.4, 5.5, 6.6, 7.7, 8.8, 10.1};
    std::vector<float> test_vector2 = {1.1, 2.2, -4.4, 5.5, 6.6, 7.7, -8.8, 10.1};

    corrSpace::corrTools corrTest(x, y, z);

    corrTest.get_corr_coeff(&test_vector, &test_vector2);
}