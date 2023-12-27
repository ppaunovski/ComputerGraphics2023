//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include "Cube.hpp"
#include "Translating.hpp"
#include "Still.hpp"
#include "Rotating.hpp"

Cube::Cube(glm::mat4 model, glm::vec3 position) {

    this->model = model;
    this->position = position;
    init();

}

Cube::Cube(glm::mat4 model, glm::vec3 position, int pos) {
    this->pos = pos;
    this->model = model;
    this->position = position;
    init();
}

Cube::Cube(glm::mat4 model, glm::vec3 position, int pos, Vertices *v) {
    this->pos = pos;
    this->model = model;
    this->position = position;
    this->vertices = v;
    init();
}



Cube::Cube() {

    this->model =  glm::mat4(1.0f);
    this->position =  glm::vec3(1.0f, 1.0f, 1.0f);
    init();

}

void Cube::init(){
    this->is_Translating = new Translating(this);
    this->is_Rotating = new Rotating(this);
    this->is_Still = new Still(this);

    this->actualSate = new Still(this);

    this->isRotating = false;
    this->aggregate = glm::mat4(1.0f);
    this->inverseAggregate = glm::mat4(1.0f);

}

bool Cube::rotate(float d, glm::vec3 vec) {


    return actualSate->rotate(d, vec);

}

bool Cube::rotateYTOP(float d) {


    isRotating = actualSate->rotateYTOP(d);
    return isRotating;

}

bool Cube::rotateYDOWN(float d) {


    isRotating = actualSate->rotateYDOWN(d);
    return isRotating;

}

bool Cube::rotateXLEFT(float d) {


    isRotating = actualSate->rotateXLEFT(d);
    return isRotating;

}

bool Cube::rotateXRIGHT(float d) {


    isRotating = actualSate->rotateXRIGHT(d);
    return isRotating;

}

bool Cube::rotateZFRONT(float d) {


    isRotating = actualSate->rotateZFRONT(d);
    return isRotating;

}

bool Cube::rotateZBACK(float d) {


    isRotating = actualSate->rotateZBACK(d);
    return isRotating;

}



bool Cube::is_top(){

    if(position.y == 1.0f)
        return true;
    return false;

}

bool Cube::is_down(){

    if(position.y == -1.0f)
        return true;
    return false;

}

bool Cube::is_left(){

    if(position.x == -1.0f)
        return true;
    return false;

}

bool Cube::is_right(){

    if(position.x == 1.0f)
        return true;
    return false;

}

bool Cube::is_front(){

    if(position.z == 1.0f)
        return true;
    return false;

}

bool Cube::is_back(){

    if(position.z == -1.0f)
        return true;
    return false;

}




