//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include "Rotating.hpp"

bool Rotating::rotate(float d) {
    //std::cout<<"Already rotating"<<std::endl;

    float velocity = 2.5f * d;
    if(increment * velocity + start > goal)
        cube->model = glm::rotate(cube->model, glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 1.0f, 0.0f));
    else
        cube->model = glm::rotate(cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f));
    start += increment*velocity;
    std::cout<<start<<std::endl;
    if(start > goal)
        stop();
    return true;

}
void Rotating::startRotation(){
//    do{
//        cube->model = glm::rotate(cube->model, glm::radians(180*increment), glm::vec3(1.0f, 0.3f, 0.5f));
//        start += 360*increment;
//        std::cout<<start<<std::endl;
//    }
//    while(start < goal);
//    stop();
}
void Rotating::translate() {
    std::cout<<"Wait to end rotation"<<std::endl;

}

void Rotating::stop() {
    this->cube->actualSate = this->cube->is_Still;
    this->start = 0.0f;
    this->isRotating = false;
}

Rotating::Rotating(Cube *cube) : cube(cube) {
    this->start = 0.0f;
    this->goal = 90.0f;
    this->increment = 30.f;
    this->isRotating = false;
}
