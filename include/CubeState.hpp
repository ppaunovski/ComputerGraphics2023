//
// Created by pauno on 11/19/2023.
//

#ifndef OPENGLPRJ_CUBESTATE_HPP
#define OPENGLPRJ_CUBESTATE_HPP

 class CubeState {
public:
     virtual bool rotate(float d);

     virtual void translate();
     virtual void stop();
};


#endif //OPENGLPRJ_CUBESTATE_HPP
