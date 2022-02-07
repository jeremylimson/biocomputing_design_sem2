/*
* 2-1-2022
* jeremy limson
* description : functions for correlation
*/

#ifndef super_trooper_cooper

#define super_trooper_cooper

#include <vector>

namespace corrSpace {
    class corrTools {
        public:
        corrTools(int, int, int);   // constructor

        // setter
        void set_corr_coeff(std::vector<float> * input_data1, std::vector<float> * input_data2);    // calculate correlation

        // getter
        float get_corr_coeff();
        
        private:
        float coeff_corr;
    };
}

#endif