/*
* 2-1-2022
* jeremy limson
* description : functions for finding correlation coefficient
*/

#define _CRT_SECURE_NO_WARNINGS 
#include "limsonj_corr.hpp"
#include "limsonj_stats.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>

corrSpace::corrTools::corrTools(int, int, int) {
    this->coeff_corr;   // constructor
}

void set_corr_coeff(std::vector<float> * input_data1, std::vector<float> * input_data2) {
    int x, y, z;
    float correlation = 0.0;

    myStats::statTools statTest(x, y, z); // create instance of stat class

    statTest.set_mean(input_data1);
    float mean1 = statTest.get_mean();

    statTest.set_mean(input_data2);
    float mean2 = statTest.get_mean();

    int total_count = input_data1->size() + input_data2->size();
    printf("N: \n", total_count);

    float numerator1 = 0;
    //float numerator2 = 

    for(int x : *input_data1) {
        for (int y : *input_data2) {
            numerator1 += x * y;
        }
    }

    printf("%f\n", numerator1);

}

float corrSpace::corrTools::get_corr_coeff() {
    return coeff_corr;
}