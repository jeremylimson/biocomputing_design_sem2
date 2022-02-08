/*
* 2-1-2022
* jeremy limson
* description : functions for finding correlation coefficient
*/

#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "limsonj_stats.hpp"
#include "limsonj_corr.hpp"

using namespace myStats;

myStats::corrTools::corrTools(int a, int b, int c) {
    // initialize private variables
    this->coeff_corr = 0;
}

void myStats::corrTools::set_corr_coeff(std::vector<float> * input_data1, std::vector<float> * input_data2) {
    // initialize variables
    int x, y, z;
    float correlation = 0.0;

    // FIXME
    myStats::statTools statTest(x, y, z); // create instance of stat class

    statTest.set_mean(input_data1);
    float mean1 = statTest.get_mean();

    statTest.set_mean(input_data2);
    float mean2 = statTest.get_mean();

    int total_count = input_data1->size() + input_data2->size();
    printf("N: %d\n", total_count);

    float numerator1 = 0.0;

    for(int x : *input_data1) {
        for (int y : *input_data2) {
            numerator1 += x * y;    // calculate the summation of x * y minus N * the mean of x * the mean of y
        }
    }

    float numerator2 = total_count * mean1 * mean2;

    //printf("%f\n", numerator1);
    
    float numerator = numerator1 - numerator2;

    float denominator1 = 0.0;

    for (int x : *input_data1) {
        denominator1 += pow(x, 2);  // summation of x^2
    }

    float denominator2 = (total_count) * (pow(mean1, 2));   // N * (the mean of x) ^2 

    float denominator3 = 0.0;

    for (int x : *input_data2) {
        denominator3 += pow(x, 2);  // summation of y^2
    }

    float denominator4 = (total_count) * (pow(mean2, 2));   // N * (the mean of y) ^2

    float denominator = (denominator1 - denominator2) * (denominator3 - denominator4);
    denominator = pow(denominator, 0.5);    // sqrt of the denominator

    correlation = numerator / denominator;

    this->coeff_corr = correlation;
}

float myStats::corrTools::get_corr_coeff() {
    return coeff_corr;
}