//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_CUBESTATE_HPP
#define OPENGLPRJ_CUBESTATE_HPP

#include "glm/vec3.hpp"

class CubeState {
public:
     virtual bool rotate(float d, glm::vec3 vec);

     virtual void translate();
     virtual void stop();

     virtual bool rotateX(float d);
     virtual bool rotateY(float d);
     virtual bool rotateZ(float d);

     virtual bool rotateYTOP(float d);

     virtual bool rotateYDOWN(float d);

     virtual bool rotateXLEFT(float d);

     virtual bool rotateXRIGHT(float d);

     virtual bool rotateZFRONT(float d);

     virtual bool rotateZBACK(float d);
 };


#endif //OPENGLPRJ_CUBESTATE_HPP
