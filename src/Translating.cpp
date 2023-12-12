//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include "Translating.hpp"

Translating::Translating(Cube *cube) {
    this->cube = cube;
}

bool Translating::rotate(float d, glm::vec3 vec) {
    std::cout<<"Wait to end translation"<<std::endl;
    return false;
}

void Translating::translate() {
    std::cout<<"Already translating"<<std::endl;
}

void Translating::stop() {

    this->cube->actualSate = this->cube->is_Still;

}
