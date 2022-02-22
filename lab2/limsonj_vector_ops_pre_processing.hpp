/*
* 2-22-2022
* jeremy limson
* description : pre processing *.dat files by normalizing data points
*/

#ifndef pre_process

#define pre_process

#define _CRT_SECURE_NO_WARNINGS 

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "limsonj_vectors_ops.hpp"
#include "limsonj_stats.hpp"

void open_file(FILE* handle, std::vector<int> * input_data);

bool geneCheck(std::vector<int>* input_data, int genes);

//float log_intensity_ratio(std::vector<int>);

#endif