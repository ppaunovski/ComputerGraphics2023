//
// Created by pauno on 11/19/2023.
//

#include "Cube.hpp"
#include "Translating.hpp"
#include "Still.hpp"
#include "Rotating.hpp"

Cube::Cube(glm::mat4 model, glm::vec3 position) {

    this->model = model;
    this->position = position;
    init();

}

Cube::Cube() {

    this->model = glm::mat4(1.0f);
    this->position = glm::vec3(1.0f, 1.0f, 1.0f);
    init();

}

void Cube::init(){
    this->is_Translating = new Translating(this);
    this->is_Rotating = new Rotating(this);
    this->is_Still = new Still(this);

    this->actualSate = new Still(this);

    this->isRotating = false;
    this->isStill = true;

}

bool Cube::rotate(float d) {


    isRotating = actualSate->rotate(d);
    return isRotating;

//    float velocity = 2.5f * d;
//    float goal = 360.0;
//    float increment = goal / velocity;
//    float start = 0.0f;
//    while (start != goal){
//        cube->model = glm::rotate(cube->model, glm::radians(increment), glm::vec3(1.0f, 0.3f, 0.5f));
//        start += increment;
//    }

}

void Cube::contRotate(float d) {

    if(isRotating){
        model = glm::rotate(model, glm::radians(10.0f * 2.5f * d), glm::vec3(1.0f, 0.3f, 0.5f));
    }

}
