/*
* 2-22-2022
* jeremy limson
* description : part 3 k means and clustering
*/

#include "limsonj_k_means.hpp"

k_mean::cluster::cluster() {
    // initialize class variables
    this->object_name = "";
    this->object_mean = 0;
    this->cluster_set;
}

float k_mean::cluster::distance(int data_point) {
    float cluster_distance = 0.0;

    return cluster_distance;
}

void k_mean::cluster::set_object_name(std::string name) {
    this->object_name = name;
}

void k_mean::cluster::set_object_mean(float mean) {
    this->object_mean = mean;
}

std::string k_mean::cluster::get_object_name() {
    return object_name;
}

float k_mean::cluster::get_object_mean() {
    return object_mean;
}