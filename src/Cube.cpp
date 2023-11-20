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
    std::cout<<"rotate in Cube called"<<std::endl;
    return isRotating;

}

bool Cube::rotateYTOP(float d) {


    isRotating = actualSate->rotateYTOP(d);
    std::cout<<"rotateY in Cube called"<<std::endl;
    return isRotating;

}

bool Cube::rotateYDOWN(float d) {


    isRotating = actualSate->rotateYDOWN(d);
    std::cout<<"rotateY in Cube called"<<std::endl;
    return isRotating;

}

bool Cube::rotateXLEFT(float d) {


    isRotating = actualSate->rotateXLEFT(d);
    std::cout<<"rotateX in Cube called"<<std::endl;
    return isRotating;

}

bool Cube::rotateXRIGHT(float d) {


    isRotating = actualSate->rotateXRIGHT(d);
    std::cout<<"rotateX in Cube called"<<std::endl;
    return isRotating;

}

bool Cube::rotateZFRONT(float d) {


    isRotating = actualSate->rotateZFRONT(d);
    std::cout<<"rotateZ in Cube called"<<std::endl;
    return isRotating;

}

bool Cube::rotateZBACK(float d) {


    isRotating = actualSate->rotateZBACK(d);
    std::cout<<"rotateZ in Cube called"<<std::endl;
    return isRotating;

}

void Cube::contRotate(float d) {

    if(isRotating){
        model = glm::rotate(model, glm::radians(10.0f * 2.5f * d), glm::vec3(1.0f, 0.3f, 0.5f));
    }

}

bool Cube::is_top(){

//    if(position.y == 1.0f)
//        return true;
//    return false;

    for(int i : top){
        if(i == pos)
            return true;
    }
    return false;

}

bool Cube::is_down(){

//    if(position.y == -1.0f)
//        return true;
//    return false;

    for(int i : down){
        if(i == pos)
            return true;
    }
    return false;

}

bool Cube::is_left(){

//    if(position.x == -1.0f)
//        return true;
//    return false;

    for(int i : left){
        if(i == pos)
            return true;
    }
    return false;

}

bool Cube::is_right(){

//    if(position.x == 1.0f)
//        return true;
//    return false;
    for(int i : right){
        if(i == pos)
            return true;
    }
    return false;

}

bool Cube::is_front(){

//    if(position.z == 1.0f)
//        return true;
//    return false;
    for(int i : front){
        if(i == pos)
            return true;
    }
    return false;

}

bool Cube::is_back(){

//    if(position.z == -1.0f)
//        return true;
//    return false;
    for(int i : back){
        if(i == pos)
            return true;
    }
    return false;

}



