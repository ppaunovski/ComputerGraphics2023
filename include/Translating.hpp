//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_TRANSLATING_HPP
#define OPENGLPRJ_TRANSLATING_HPP


#include "Cube.hpp"

class Translating : public CubeState {

public:
    Cube *cube;
    Translating(Cube *cube);
    bool rotate(float d) override;

    void translate() override;
    void stop() override;

};


#endif //OPENGLPRJ_TRANSLATING_HPP
