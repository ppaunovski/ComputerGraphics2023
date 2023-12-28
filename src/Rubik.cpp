//
// Created by pauno on 11/19/2023.
//

#include <string>
#include <iostream>
#include "Rubik.hpp"

Rubik::Rubik(const std::vector<Cube*> &cubes) : cubes(cubes) {

}
Rubik::Rubik(int j){
    this->cubes = std::vector<Cube*>();
    for(int i=0; i<12; i++){
        isConcreteRotating[i] = false;
//        plusOne[i] = false;
    }
    isRotating = false;


}
Rubik::Rubik() {
    this->cubes = std::vector<Cube*>();
    for(int i=0; i<6; i++){
        isConcreteRotating[i] = false;
    }
    isRotating = false;
    glm::mat4 difMat = glm::mat4(1.0f);
    glm::vec3 pos[26] = {
            //TOP
            glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f),

            //MID
            glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            //glm::vec3(0.0f, 0.0f, 0.0f), // THIS ONE IS USELESS
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f),

            //BOT
            glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, -1.0f, -1.0f), glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, -1.0f, 0.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 1.0f), glm::vec3(1.0f, -1.0f, 1.0f),
    };
    for(int i=0; i<26; i++){
        Cube *cube = new Cube( glm::mat4 (1.0f),  glm::vec3(pos[i]), i);
        cubes.push_back(cube);
    }

}

void Rubik::startRotation(float deltaTime, SIDE side, bool prime) {

//    if(!plusOne[side]){

    switch(side){

        case T:
        case TP:
            for(auto c : cubes){
                if(c->is_top()){
                    isRotating = c->rotateYTOP(deltaTime, prime);

                }
            }
            break;
        case D:
        case DP:
            for(auto c : cubes){
                if(c->is_down()){
                    isRotating = c->rotateYDOWN(deltaTime, prime);
                }
            }
            break;
        case L:
        case LP:
            for(auto c : cubes){
                if(c->is_left()){
                    isRotating = c->rotateXLEFT(deltaTime, prime);
                }
            }
            break;
        case R:
        case RP:
            for(auto c : cubes){
                if(c->is_right()){
                    isRotating = c->rotateXRIGHT(deltaTime, prime);
                }
            }
            break;
        case F:
        case FP:
            for(auto c : cubes){
                if(c->is_front()){
                    isRotating = c->rotateZFRONT(deltaTime, prime);
                }
            }
            break;
        case B:
        case BP:
            for(auto c : cubes){
                if(c->is_back()){
                    isRotating = c->rotateZBACK(deltaTime, prime);
                }
            }
            break;
    }

    isConcreteRotating[side] = isRotating;
//    plusOne[side] = !isRotating;
//    }
//    if(plusOne[side])
//        plusOne[side] = false;

    glm::vec3 pos[26] = {
            //TOP
            glm::vec3(-1.0f, 1.0f, -1.0f), glm::vec3(0.0f, 1.0f, -1.0f), glm::vec3(1.0f, 1.0f, -1.0f),
            glm::vec3(-1.0f, 1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 0.0f),
            glm::vec3(-1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f),

            //MID
            glm::vec3(-1.0f, 0.0f, -1.0f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(1.0f, 0.0f, -1.0f),
            glm::vec3(-1.0f, 0.0f, 0.0f),
            //glm::vec3(0.0f, 0.0f, 0.0f), // THIS ONE IS USELESS
            glm::vec3(1.0f, 0.0f, 0.0f),
            glm::vec3(-1.0f, 0.0f, 1.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 1.0f),

            //BOT
            glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec3(0.0f, -1.0f, -1.0f), glm::vec3(1.0f, -1.0f, -1.0f),
            glm::vec3(-1.0f, -1.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f), glm::vec3(1.0f, -1.0f, 0.0f),
            glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec3(0.0f, -1.0f, 1.0f), glm::vec3(1.0f, -1.0f, 1.0f),
    };
    if(!isRotating){
        int i=0;
        for(auto c : cubes){
            c->vertices->setOldColors();
            c->position = pos[i++];
        }

    std::cout<<"ITERATION IS DONE -----------------------------------------"<<std::endl;
    }
}

void Rubik::addCube(int index, Vertices *v, glm::vec3 pos) {
    glm::mat4 difMat = glm::mat4(1.0f);
    Cube *cube = new Cube( glm::mat4 (1.0f),  glm::vec3 (pos), index, v);
    cubes.push_back(cube);

    if(cubes.size() == 26){
        for(auto c : cubes){
            c->rubik = cubes;
        }
    }
}

void Rubik::rotateOwnAxis(float d, glm::vec3 vec) {

    for(auto cube : cubes){
        cube->rotate(d, vec);
    }

}

