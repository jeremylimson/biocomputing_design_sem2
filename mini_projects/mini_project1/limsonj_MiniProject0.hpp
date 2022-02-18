/*
* 2-18-2022
* jeremy limson a.k.a. "tarantula"
* description : you're gonna need to take an anti virus for that lower hack pain
*/

#ifndef baby_got_hack

#define baby_got_hack

#include <iostream>
#include <unistd.h>

namespace empire_strikes_hack {
    class TimeHacking {
        // accessibility
        public:
        // constructor
        TimeHacking(std::string objectToHack);

        // setters and public members
        void setTimeToHack(int seconds);
        void hackTime();

        // getters
        int getTimeToHack();
        std::string getObjectToHack();

        private:
        int time_to_hack;
        std::string objectToHack;
    };
}

#endif