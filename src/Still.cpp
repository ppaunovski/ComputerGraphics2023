//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include "Still.hpp"

bool Still::rotate(float d, glm::vec3 vec) {
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

bool Still::rotateXLEFT(float d, bool prime) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;
}

bool Still::rotateXRIGHT(float d, bool prime) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;
}

bool Still::rotateYTOP(float d, bool prime) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;
}

bool Still::rotateYDOWN(float d, bool prime) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;
}

bool Still::rotateZFRONT(float d, bool prime) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;
}

bool Still::rotateZBACK(float d, bool prime) {
    this->cube->actualSate = this->cube->is_Rotating;
    return false;
}
