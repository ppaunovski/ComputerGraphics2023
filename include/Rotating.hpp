//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_ROTATING_HPP
#define OPENGLPRJ_ROTATING_HPP


#include <map>
#include "CubeState.hpp"
#include "Cube.hpp"

class Rotating : public CubeState{
public:
    Cube *cube;
    float start;
    float goal;
    float increment;
    bool isRotating;
    std::map<int, int> rot_left;
    std::map<int, int> rot_right;
    std::map<int, int> rot_top;
    std::map<int, int> rot_down;
    std::map<int, int> rot_front;
    std::map<int, int> rot_back;

    explicit Rotating(Cube *cube);

    void startRotation();

    bool rotate(float d, glm::vec3 vec) override;
    bool rotateXLEFT(float d) override;
    bool rotateXRIGHT(float d) override;
    bool rotateYTOP(float d) override;
    bool rotateYDOWN(float d) override;
    bool rotateZFRONT(float d) override;
    bool rotateZBACK(float d) override;

    void translate() override;

    void stop() override;

};


#endif //OPENGLPRJ_ROTATING_HPP
