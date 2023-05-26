//
// Created by pauno on 5/26/2023.
//

class Pacman {
public:
    float *vertices;
    Pacman(){
        vertices = new float[20];
    }

    const float *getVertices() const {
        return vertices;
    }

    void setVertices(float *vertices) {
        Pacman::vertices = vertices;
    }

    void transform (){

    }

};
