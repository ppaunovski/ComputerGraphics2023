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
    bool rotateXLEFT(float d, bool prime) override;
    bool rotateXRIGHT(float d, bool prime) override;
    bool rotateYTOP(float d, bool prime) override;
    bool rotateYDOWN(float d, bool prime) override;
    bool rotateZFRONT(float d, bool prime) override;
    bool rotateZBACK(float d, bool prime) override;

    void translate() override;

    void stop() override;

};


#endif //OPENGLPRJ_STILL_HPP
