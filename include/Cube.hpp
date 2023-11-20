//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_CUBE_HPP
#define OPENGLPRJ_CUBE_HPP


#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "CubeState.hpp"

class Cube {
public:
    bool isRotating;
    bool isStill;
    int pos;
    int top[9] = {0,1,2,3,4,5,6,7,8};
    int down[9] = {18,19,20,21,22,23,24,25,26};
    int left[9] = {0,3,6,9,12,15,18,21,24};
    int right[9] = {2,5,8,11,14,17,20,23,26};
    int front[9] = {6,7,8,15,16,17,24,25,26};
    int back[9] = {0,1,2,9,10,11,18,19,20};
public:
    glm::mat4 model;
    glm::vec3 position;
    CubeState *is_Rotating;
    CubeState *is_Translating;
    CubeState *is_Still;

    CubeState *actualSate;
public:
    Cube();
    Cube(glm::mat4 model, glm::vec3 position);
    Cube(glm::mat4 model, glm::vec3 position, int pos);

    bool rotate(float d);

    void contRotate(float d);

    void init();

    bool is_top();

    bool is_down();

    bool is_left();

    bool is_right();

    bool is_front();

    bool is_back();

    bool rotateY(float d);

    bool rotateX(float d);

    bool rotateZ(float d);

    bool rotateZBACK(float d);

    bool rotateZFRONT(float d);

    bool rotateXRIGHT(float d);

    bool rotateXLEFT(float d);

    bool rotateYDOWN(float d);

    bool rotateYTOP(float d);
};


#endif //OPENGLPRJ_CUBE_HPP
