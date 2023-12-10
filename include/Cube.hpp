//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_CUBE_HPP
#define OPENGLPRJ_CUBE_HPP


#include "glm/glm.hpp"
#include "glm/ext/matrix_transform.hpp"
#include "CubeState.hpp"
#include "Vertices.hpp"

class Cube {
public:
    Cube(glm::mat4 *model, glm::vec3 *position, int pos);
    Cube(glm::mat4 *model, glm::vec3 *position, int pos, Vertices *v);

    Cube(glm::mat4 *model, glm::vec3 *position);

    bool isRotating;
    bool isStill;
    int pos;
    int top[9] = {0,1,2,3,4,5,6,7,8};
    int down[9] = {17,18,19,20,21,22,23,24,25};
    int left[9] = {0,3,6,9,12,14,17,20,23};
    int right[9] = {2,5,8,11,13,16,19,22,25};
    int front[9] = {6,7,8,14,15,16,23,24,25};
    int back[9] = {0,1,2,9,10,11,17,18,19};
public:
    Vertices *vertices;
    glm::mat4 *model;
    glm::vec3 *position;
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
