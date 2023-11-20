//
// Created by pauno on 11/19/2023.
//

#include <string>
#include "Rubik.hpp"

Rubik::Rubik(const std::vector<Cube*> &cubes) : cubes(cubes) {

}

Rubik::Rubik() {
    this->cubes = std::vector<Cube*>();
    for(int i=0; i<6; i++){
        isConcreteRotating[i] = false;
    }
    isRotating = false;
    glm::mat4 difMat = glm::mat4(1.0f);
    glm::vec3 pos[27] = {
            //TOP
            glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f),

            //MID
            glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f),

            //BOT
            glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, -1.0f, -1.0f), glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, -1.0f, 0.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 1.0f), glm::vec3(1.0f, -1.0f, 1.0f),
    };
    for(int i=0; i<27; i++){
        Cube *cube = new Cube(difMat, pos[i], i);
        cubes.push_back(cube);
    }
}

void Rubik::startRotation(float deltaTime, SIDE side) {

    switch(side){

        case T:
            for(auto c : cubes){
                if(c->is_top()){
                    isRotating = c->rotateYTOP(deltaTime);

                }
            }
            break;
        case D:
            for(auto c : cubes){
                if(c->is_down())
                    isRotating = c->rotateYDOWN(deltaTime);
            }
            break;
        case L:
            for(auto c : cubes){
                if(c->is_left())
                    isRotating = c->rotateXLEFT(deltaTime);
            }
            break;
        case R:
            for(auto c : cubes){
                if(c->is_right())
                    isRotating = c->rotateXRIGHT(deltaTime);
            }
            break;
        case F:
            for(auto c : cubes){
                if(c->is_front())
                    isRotating = c->rotateZFRONT(deltaTime);
            }
            break;
        case B:
            for(auto c : cubes){
                if(c->is_back())
                    isRotating = c->rotateZBACK(deltaTime);
            }
            break;
    }

    isConcreteRotating[side] = isRotating;

}

