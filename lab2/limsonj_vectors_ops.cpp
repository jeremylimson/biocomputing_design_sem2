/*
* 2-15-2022
* jeremy limson
* description : functions for vecetor operation
*/

#include "limsonj_vectors.hpp"

float sum_array(std::vector<float> * input_data) {
    // initialize variables
    float sum = 0.0;

    for (float i : *input_data) {
        sum += i;   // add all elements
        std::cout << i;
    }

    std::cout << sum;
    return sum;
}

std::vector<float> * element_wise_sub(std::vector<float> * input_data1, std::vector<float> * input_data2) {
    std::vector<float> * input_data;

    
    return sub_arr;
}

std::vector<float> * div_array(std::vector<float> * input_data) {
    std::vector<float> * divided_arr;

    return divided_arr;
}