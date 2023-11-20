//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_RUBIK_HPP
#define OPENGLPRJ_RUBIK_HPP


#include <vector>
#include "Cube.hpp"

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
    std::vector<Cube*> cubes;
    bool isRotating;
    bool isConcreteRotating[6];

    explicit Rubik(const std::vector<Cube*> &cubes);

    Rubik();


    void startRotation(float deltaTime, SIDE side);
};


#endif //OPENGLPRJ_RUBIK_HPP
