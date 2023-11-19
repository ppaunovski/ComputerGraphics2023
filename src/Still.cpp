//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include "Still.hpp"

bool Still::rotate(float d) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;

}

void Still::translate() {
    this->cube->actualSate = this->cube->is_Translating;
}

void Still::stop() {
    std::cout<<"Already still"<<std::endl;
}

Still::Still(Cube *cube) : cube(cube) {}
