/*
* 2-1-2022
* jeremy limson
* description : functions for finding min/max, mean, standard deviation, and creating a histogram
*/

#ifndef super_trooper_cooper

#define super_trooper_cooper

#include <vector>

namespace myStats {
    class statTools {
        // acccessibility and perimssion
        public:
        statTools();	// namespace::class

        void set_max(std::vector<float> * input_data);
        void set_min(std::vector<float> * input_data);
        void set_mean(std::vector<float> * input_data);
        void set_std_dev(std::vector<float> * input_data);
        float follow_me_on_histogram(std::vector<float> * input_data);

        float get_max();
        float get_min();
        float get_mean();
        float get_std_dev();

        private:
        float min;
        float max;
        float mean;
        float std_dev;
    };
}

#endif