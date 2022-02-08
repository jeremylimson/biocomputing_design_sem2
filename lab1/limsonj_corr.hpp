/*
* 2-1-2022
* jeremy limson
* description : functions for correlation
*/

#ifndef super_trooper_cooper2

#define super_trooper_cooper2

#include <vector>

namespace myStats {
    class corrTools {
        public:
        corrTools(int a, int b, int c);   // constructor

        // setter
        void set_corr_coeff(std::vector<float> * input_data1, std::vector<float> * input_data2);    // calculate correlation

        // getter
        float get_corr_coeff();
        
        private:
        float coeff_corr;
    };
}

#endif