//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_ROTATING_HPP
#define OPENGLPRJ_ROTATING_HPP


#include "CubeState.hpp"
#include "Cube.hpp"

class Rotating : public CubeState{
public:
    Cube *cube;
    float start;
    float goal;
    float increment;
    bool isRotating;

    explicit Rotating(Cube *cube);

    void startRotation();

    bool rotate(float d) override;

    void translate() override;

    void stop() override;

};


#endif //OPENGLPRJ_ROTATING_HPP
