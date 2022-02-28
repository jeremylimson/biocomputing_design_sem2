/*
* 2-1-2022
* jeremy limson
* description : functions for finding min/max, mean, standard deviation, and creating a histogram
*/

#ifndef super_trooper_cooper

#define super_trooper_cooper

#define _CRT_SECURE_NO_WARNINGS 
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

namespace myStats {
    class statTools {
        // acccessibility and perimssion
        public:
        statTools();	// namespace::class (why do we need this?)

        // setters
        void set_max(std::vector<float> * input_data);
        void set_min(std::vector<float> * input_data);
        void set_mean(std::vector<float> * input_data);
        void set_std_dev(std::vector<float> * input_data);
        void set_size(std::vector<float> * input_data);
        float bin_width(std::vector<float> * input_data);
        void follow_me_on_histogram(std::vector<float> * input_data);

        // getters
        float get_max();
        float get_min();
        float get_mean();
        int get_size();
        float get_std_dev();

        private:
        int size;
        float min;
        float max;
        float mean;
        float std_dev;
    };
}

#endif