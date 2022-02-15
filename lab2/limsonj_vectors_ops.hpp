/*
* 2-15-2022
* jeremy limson
* description : functions for vecetor operation
*/

#ifndef chu_et_al

#define chu_et_al

#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
* function that sums all elements of an array
*/
float sum_array(std::vector<float> * input_data);

/*
* functions that subtracts one array from another, element by element
*/
std::vector<float> * element_wise_sub(std::vector<float> * input_data1, std::vector<float> * input_data2);

/**
* function that divides all values of an array by a constant
*/
std::vector<float> * div_array(std::vector<float> * input_data);

#endif