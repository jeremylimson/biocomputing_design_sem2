/*
* 2-15-2022
* jeremy limson
* description : functions for vecetor operation
*/

#ifndef chu_et_al

#define chu_et_al

#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

namespace vector_ops {
    class vector_tools {
        public:
        // constructor
        vector_tools(int x, int y, int z);

        // function that sums all elements of an array        
        int sum_array(std::vector<int> * input_data);

        // functions that subtracts one array from another, element by element
        void element_wise_sub(std::vector<int> * input_data1, std::vector<int> * input_data2, std::vector<int> * output_data);

        // function that divides all values of an array by a constant
        void div_array(std::vector<int> * input_data, float divisor, std::vector<float> * output_data);
    };
}

#endif