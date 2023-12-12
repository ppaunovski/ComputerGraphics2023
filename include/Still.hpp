//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_STILL_HPP
#define OPENGLPRJ_STILL_HPP


#include "CubeState.hpp"
#include "Cube.hpp"

class Still : public CubeState{

public:
    Cube *cube;

    explicit Still(Cube *cube);

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


#endif //OPENGLPRJ_STILL_HPP
