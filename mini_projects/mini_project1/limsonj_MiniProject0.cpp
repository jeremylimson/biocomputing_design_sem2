/*
* 2-18-2022
* jeremy limson a.k.a. "tarantula"
* description : you're gonna need to take an anti virus for that lower hack pain
*/

#include "limsonj_MiniProject0.hpp"

empire_strikes_hack::TimeHacking::TimeHacking(std::string objectToHack) {
    // initialize private variables
    this->objectToHack = objectToHack;
    this->time_to_hack = 0;
}

void empire_strikes_hack::TimeHacking::setTimeToHack(int seconds) {
    // set user specified number to private variable
    this->time_to_hack = seconds;
}

void empire_strikes_hack::TimeHacking::hackTime() {
    // sleep for user specified number of seconds
    sleep(this->time_to_hack);
}

int empire_strikes_hack::TimeHacking::getTimeToHack() {
    // return private variable
    return this->time_to_hack;
}

std::string empire_strikes_hack::TimeHacking::getObjectToHack() {
    // return private variable
    return this->objectToHack;
}