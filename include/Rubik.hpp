//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_RUBIK_HPP
#define OPENGLPRJ_RUBIK_HPP


#include <vector>
#include "Cube.hpp"
#include "Vertices.hpp"

enum SIDE{
    T,
    D,
    L,
    R,
    F,
    B
};

class Rubik {

public:
    Rubik(int i);

    std::vector<Cube*> cubes;
    bool isRotating;
    bool isConcreteRotating[6];
    bool plusOne[6];

    explicit Rubik(const std::vector<Cube*> &cubes);

    Rubik();


    void startRotation(float deltaTime, SIDE side);
    void addCube(int index, Vertices *v, glm::vec3 pos);

    void rotateOwnAxis(float d, glm::vec3 vec);
};


#endif //OPENGLPRJ_RUBIK_HPP
