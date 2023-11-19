//
// Created by pauno on 11/19/2023.
//

#include "Rubik.hpp"

Rubik::Rubik(const std::vector<Cube> &cubes) : cubes(cubes) {

}

Rubik::Rubik() {
    this->cubes = std::vector<Cube>();
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
        Cube cube = Cube(difMat, pos[i]);
        cubes.push_back(cube);
    }
}

void Rubik::startRotation(float deltaTime) {
    for(Cube c : cubes){
        isRotating = true;
        c.rotate(deltaTime);
    }

}
