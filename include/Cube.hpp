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

    bool rotate(float d);

    void contRotate(float d);

    void init();
};


#endif //OPENGLPRJ_CUBE_HPP
