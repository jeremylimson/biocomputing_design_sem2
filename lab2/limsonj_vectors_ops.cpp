/*
* 2-15-2022
* jeremy limson
* description : functions for vecetor operation
*/

#include "limsonj_vectors_ops.hpp"

vector_ops::vector_tools::vector_tools(int x, int y, int z) {
    // initialize constructor
    x = 0;
    y = 0;
    z = 0;
}

int vector_ops::vector_tools::sum_array(std::vector<int> * input_data) {
    // initialize variables
    int sum = 0.0;

    // TODO: check if vectors are NULL
    if (input_data->empty() == true) {
        std::cout << "The vector is empty";
        return 0;
    } else {
        // sum all numbers
        for (int i : *input_data) {
            sum += i;   // add all elements
            //std::cout << i;
        }
        //std::cout << sum;
        return sum;
    }
}

void vector_ops::vector_tools::element_wise_sub(std::vector<int> * input_data1, std::vector<int> * input_data2, std::vector<int> * output_data) {
    // initialize variables
    int difference = 0;

    // TODO: check if input vectors are NULL
    if (input_data1->empty() == true || input_data2->empty() == true) {
        std::cout << "The vector is empty";
    } else {
        // check if vectors are the same size
        if (input_data1->size() == input_data2->size()) {
            for (int i = 0; i < input_data1->size(); i++) {
                difference = input_data1->at(i) - input_data2->at(i);   // subtract elements
                output_data->push_back(difference); // populate output vector
            }
        } else {
            // tell the user they messed up
            std::cout << "Sorry friend, these vectors are not the same size\n";
        }
    }
}

void vector_ops::vector_tools::div_array(std::vector<int> * input_data, float divisor, std::vector<float> * output_data) {
    // initialize variables
    float quotient = 0.0;

    // TODO: check if vector is NULL
    if (input_data->empty() == true) {
        std::cout << "The vector is empty";
    } else {
        for (int i = 0; i < input_data->size(); i++) {
        // perform division
        quotient = input_data->at(i) / (float) divisor;
        output_data->push_back(quotient);
        }
    }
}