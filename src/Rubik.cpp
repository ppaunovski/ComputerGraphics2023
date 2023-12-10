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
    for(int i=0; i<6; i++){
        isConcreteRotating[i] = false;
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
        Cube *cube = new Cube(new glm::mat4 (1.0f), new glm::vec3(pos[i]), i);
        cubes.push_back(cube);
    }
    for(auto c : cubes){
        std::cout << "Cube pos: " << c->pos << " position coord: " << c->position->x << " " << c->position->y << " " << c->position->z << std::endl;
    }
    std::cout<<"-------------------------------------------------"<<std::endl;
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

    if(!isConcreteRotating[side]){
        int count = 0;
        for(auto c : cubes){
            std::cout << count << ". Cube pos: " << c->pos << " position coord: " << c->position->x << " " << c->position->y << " " << c->position->z << std::endl;
            count++;
        }
        std::cout<<"-------------------------------------------------"<<std::endl;
    }

}

void Rubik::addCube(int index, Vertices *v, glm::vec3 pos) {
    glm::mat4 difMat = glm::mat4(1.0f);
    Cube *cube = new Cube(new glm::mat4 (1.0f), new glm::vec3 (pos), index, v);
    cubes.push_back(cube);

    if(cubes.size() == 26){
        for(auto c : cubes){
            c->rubik = cubes;
        }
    }
}

