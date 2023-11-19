//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_RUBIK_HPP
#define OPENGLPRJ_RUBIK_HPP


#include <vector>
#include "Cube.hpp"

class Rubik {

public:
    std::vector<Cube> cubes;
    bool isRotating;

    explicit Rubik(const std::vector<Cube> &cubes);

    Rubik();

    void startRotation(float deltaTime);
};


#endif //OPENGLPRJ_RUBIK_HPP
