/*
* 2-1-2022
* jeremy limson
* description : functions for finding min/max, mean, standard deviation, and creating a histogram
*/

#define _CRT_SECURE_NO_WARNINGS 
#include "limsonj_stats.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

myStats::statTools::statTools(int, int, int) {
    this->min;
    this->max;
    this->mean;
    this->std_dev;
}

void myStats::statTools::set_max(std::vector<float> * input_data) {
    // initialize variables
    float max_val = input_data->at(0);

    for(float x : *input_data) {
        // if current value is greater than current max, update max
        if (max_val < x) {
            max_val = x;
        }
    }
    // printf("Max Val: %f\n", max_val);

    // set private variable
    this->max = max_val;
}

void myStats::statTools::set_min(std::vector<float> * input_data) {
    // initialize variables
    float min_val = input_data->at(0);;

    for(int x : *input_data) {
        // if current value is less than current min, update min
        if (min_val > x) {
            min_val = x;
        }
    }
    //printf("Min Val: %f\n", min_val);

    // set private variable
    this->min = min_val;
}

void myStats::statTools::set_mean(std::vector<float> * input_data) {
    // initialize variables
    float mean_val = 0.0;
    float sum = 0.0;

    for (int x : *input_data) {
        // sum all of elements in vector
        sum += x;
    }

    // divide sum by total number of elements
    mean_val = sum / input_data->size();

    //printf("Mean: %f\n", mean_val);

    // set private variable
    this->mean = mean_val;
}

void myStats::statTools::set_std_dev(std::vector<float> * input_data) {
    // initialize variables
    float std_dev_val = 0.0;
    this->set_mean(input_data);
    float mean = this->get_mean();

    for (int x : *input_data) {
        // square the difference of the element minus the mean
        std_dev_val += pow((x - mean), 2);
    }

    // take the square root of the squared difference by number of elements
    std_dev_val = sqrt(std_dev_val / input_data->size());

    // printf("Std dev: %f\n", std_dev_val);

    // set private variable
    this->std_dev = std_dev_val;
}

float myStats::statTools::get_max() {
    return max;
}

float myStats::statTools::get_min() {
    return min;
}

float myStats::statTools::get_mean() {
    return mean;
}

float myStats::statTools::get_std_dev() {
    return std_dev;
}

/*
* calculate bins externally(bins vector) --> separate function
*/

void myStats::statTools::follow_me_on_histogram(std::vector<float> * input_data) {
    // declare and initialize vector to hold upper and lower limits of bins
    std::vector<float> bin_edges;
    std::vector<float> bin_count;

    // calculate mean as center of distribution
    this->set_mean(input_data);

    // calculate mean to use for bin width and edges
    this->set_std_dev(input_data);
    float std_dev_val = this->get_std_dev();

    // bins begin and end at +/- 3*(sample standard deviation)
    float bin_width = 0.4 * (std_dev_val);
    float lower_edge = -3.0 * (std_dev_val);
    float upper_edge = 3.0 * (std_dev_val);

    int i = 0;

    float edge_tracker = lower_edge;

    // populate bin edges
    while (edge_tracker < upper_edge) {
        // populate vector holding bins
        bin_edges.push_back(edge_tracker);

        // similar to calloc --> allocate memory in vector and make 0
        bin_count.push_back(0);
        edge_tracker += bin_width;  // this vector will store the actual frequency
    }

    bin_edges.push_back(upper_edge);

    for (int i = 0; i < input_data->size(); i++) {
        for (int k = 0; k < bin_count.size(); k++) {
            if (input_data->at(i) >= bin_edges.at(k) && input_data->at(i) < bin_edges.at(k + 1)) {
                // increase frequency count
                bin_count.at(k)++;
            }
        }
    }

    // log histogram to console
    for (int i = 0; i < bin_edges.size(); i++) {
        printf("\n%f\n", bin_edges.at(i));    // print bin labels
        for (int k = 0; k < bin_count.at(i); k++) {
            printf("*");    // * represents count
        }
    }
}