/*
* 2-22-2022
* jeremy limson
* description : part 3 k means and clustering
*/

#ifndef annie_are_you_oh_k_mean

#define annie_are_you_oh_k_mean

#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

namespace k_mean {
    class cluster {
        public:
        cluster();  // constructor

        float distance(int data_point);

        // setters
        void set_object_name(std::string name);
        void set_object_mean(float mean);
        
        // getters
        std::string get_object_name();
        float get_object_mean();

        private:
        // class variables
        std::string object_name;
        float object_mean;
        std::vector<float> cluster_set;
    };
}

#endif