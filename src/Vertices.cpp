//
// Created by pauno on 12/10/2023.
//
#include <iostream>
#include "Vertices.hpp"

Vertices::Vertices(){
    float vertices[] = {
            // Vertices for the front face
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // Bottom left (Green)
            0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,    // Bottom right (Green)
            0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,     // Top right (Green)
            0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,     // Top right (Green)
            -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,    // Top left (Green)
            -0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f,   // Bottom left (Green)

            // Vertices for the back face
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,    // Bottom left (Blue)
            0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,     // Bottom right (Blue)
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,      // Top right (Blue)
            0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,      // Top right (Blue)
            -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 1.0f,     // Top left (Blue)
            -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 1.0f,    // Bottom left (Blue)

            // Vertices for the right face
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,    // Bottom front (Red)
            0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.0f,     // Bottom back (Red)
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,      // Top back (Red)
            0.5f, 0.5f, 0.5f, 1.0f, 0.0f, 0.0f,      // Top back (Red)
            0.5f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,     // Top front (Red)
            0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.0f,    // Bottom front (Red)

            // Vertices for the left face
            -0.5f, -0.5f, -0.5f, 1.0f, 0.5f, 0.0f,   // Bottom front (Orange)
            -0.5f, -0.5f, 0.5f, 1.0f, 0.5f, 0.0f,    // Bottom back (Orange)
            -0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.0f,     // Top back (Orange)
            -0.5f, 0.5f, 0.5f, 1.0f, 0.5f, 0.0f,     // Top back (Orange)
            -0.5f, 0.5f, -0.5f, 1.0f, 0.5f, 0.0f,    // Top front (Orange)
            -0.5f, -0.5f, -0.5f, 1.0f, 0.5f, 0.0f,   // Bottom front (Orange)

            // Vertices for the top face
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,    // Front left (White)
            0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,     // Front right (White)
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,      // Back right (White)
            0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,      // Back right (White)
            -0.5f, 0.5f, 0.5f, 1.0f, 1.0f, 1.0f,     // Back left (White)
            -0.5f, 0.5f, -0.5f, 1.0f, 1.0f, 1.0f,    // Front left (White)

            // Vertices for the bottom face
            -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,   // Front left (Yellow)
            0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f,    // Front right (Yellow)
            0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,     // Back right (Yellow)
            0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,     // Back right (Yellow)
            -0.5f, -0.5f, 0.5f, 1.0f, 1.0f, 0.0f,    // Back left (Yellow)
            -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f    // Front left (Yellow)
    };
    for(int i=0; i<216; i++){
        this->vertices[i] = vertices[i];
    }

}

void Vertices::rotateX() {
    std::cout<<"***********************************************************************************************************************"<<std::endl;
    float backColor[3] = { vertices[3], vertices[4], vertices[5] };
    float frontColor[3] = { vertices[39], vertices[40], vertices[41] };
    float topColor[3] = { vertices[147], vertices[148], vertices[149] };
    float downColor[3] = { vertices[183], vertices[184], vertices[185] };
    float leftColor[3] = { vertices[111], vertices[112], vertices[113] };
    float rightColor[3] = { vertices[75], vertices[76], vertices[77] };
    std::cout<<"BACK: " << backColor[0] << " " << backColor[1] << " " << backColor[2] << std::endl;
    std::cout<<"FRONT: " << frontColor[0] << " " << frontColor[1] << " " << frontColor[2] << std::endl;
    std::cout<<"Right: " << rightColor[0] << " " << rightColor[1] << " " << rightColor[2] << std::endl;
    std::cout<<"Left: " << leftColor[0] << " " << leftColor[1] << " " << leftColor[2] << std::endl;
    std::cout<<"TOP: " << topColor[0] << " " << topColor[1] << " " << topColor[2] << std::endl;
    std::cout<<"DOWN: " << downColor[0] << " " << downColor[1] << " " << downColor[2] << std::endl;
    for(int j=0; j<6; j++){

        for (int i = j*6; i < 6 + j*6; i++) {
    //        front colors = top colors
    //        back colors = down colors
    //        left is the same
    //        right is the same
    //        top colors = back colors
    //        down colors = front colors
            switch (j) {
                case 0:
                    //back face
                    vertices[i*6 + 3] = downColor[0];
                    vertices[i*6 + 4] = downColor[1];
                    vertices[i*6 + 5] = downColor[2];
                    break;
                case 1:
                    //front face
                    vertices[i*6 + 3] = topColor[0];
                    vertices[i*6 + 4] = topColor[1];
                    vertices[i*6 + 5] = topColor[2];
                    break;
                case 2:
                    //right face
                    vertices[i*6 + 3] = rightColor[0];
                    vertices[i*6 + 4] = rightColor[1];
                    vertices[i*6 + 5] = rightColor[2];
                    break;
                case 3:
                    //left face
                    vertices[i*6 + 3] = leftColor[0];
                    vertices[i*6 + 4] = leftColor[1];
                    vertices[i*6 + 5] = leftColor[2];
                    break;
                case 4:
                    //top face
                    vertices[i*6 + 3] = backColor[0];
                    vertices[i*6 + 4] = backColor[1];
                    vertices[i*6 + 5] = backColor[2];
                    break;
                case 5:
                    //down face
                    vertices[i*6 + 3] = frontColor[0];
                    vertices[i*6 + 4] = frontColor[1];
                    vertices[i*6 + 5] = frontColor[2];
                    break;
            }
        }
    }

//    for(int i=0; i<36; i++){
//        for(int j=0; j<6; j++){
//            std::cout << vertices[i*6 + j] << " ";
//        }
//        std::cout<<std::endl;
//    }

}

void Vertices::rotateY() {
    float backColor[3] = { vertices[3], vertices[4], vertices[5] };
    float frontColor[3] = { vertices[39], vertices[40], vertices[41] };
    float topColor[3] = { vertices[147], vertices[148], vertices[149] };
    float downColor[3] = { vertices[183], vertices[184], vertices[185] };
    float leftColor[3] = { vertices[111], vertices[112], vertices[113] };
    float rightColor[3] = { vertices[75], vertices[76], vertices[77] };

    for(int j=0; j<6; j++){

        for (int i = j*6; i < 6 + j*6; i++) {
//            top color is the same
//            down color is the same
//            left color = back color
//            front color = left color
//            right color = front color
//            back color = right color
            switch (j) {
                case 0:
                    //back face
                    vertices[i*6 + 3] = rightColor[0];
                    vertices[i*6 + 4] = rightColor[1];
                    vertices[i*6 + 5] = rightColor[2];
                    break;
                case 1:
                    //front face
                    vertices[i*6 + 3] = leftColor[0];
                    vertices[i*6 + 4] = leftColor[1];
                    vertices[i*6 + 5] = leftColor[2];
                    break;
                case 2:
                    //right face
                    vertices[i*6 + 3] = frontColor[0];
                    vertices[i*6 + 4] = frontColor[1];
                    vertices[i*6 + 5] = frontColor[2];
                    break;
                case 3:
                    //left face
                    vertices[i*6 + 3] = backColor[0];
                    vertices[i*6 + 4] = backColor[1];
                    vertices[i*6 + 5] = backColor[2];
                    break;
                case 4:
                    //top face
                    vertices[i*6 + 3] = topColor[0];
                    vertices[i*6 + 4] = topColor[1];
                    vertices[i*6 + 5] = topColor[2];
                    break;
                case 5:
                    //down face
                    vertices[i*6 + 3] = downColor[0];
                    vertices[i*6 + 4] = downColor[1];
                    vertices[i*6 + 5] = downColor[2];
                    break;
            }
        }
    }
}

void Vertices::rotateZ() {

    float backColor[3] = { vertices[3], vertices[4], vertices[5] };
    float frontColor[3] = { vertices[39], vertices[40], vertices[41] };
    float topColor[3] = { vertices[147], vertices[148], vertices[149] };
    float downColor[3] = { vertices[183], vertices[184], vertices[185] };
    float leftColor[3] = { vertices[111], vertices[112], vertices[113] };
    float rightColor[3] = { vertices[75], vertices[76], vertices[77] };

    for(int j=0; j<6; j++){

        for (int i = j*6; i < 6 + j*6; i++) {
//            top color = right color
//            down color = left color
//            left color = top color
//            front color is the same
//            right color = down color
//            back color is the same
            switch (j) {
                case 0:
                    //back face
                    vertices[i*6 + 3] = backColor[0];
                    vertices[i*6 + 4] = backColor[1];
                    vertices[i*6 + 5] = backColor[2];
                    break;
                case 1:
                    //front face
                    vertices[i*6 + 3] = frontColor[0];
                    vertices[i*6 + 4] = frontColor[1];
                    vertices[i*6 + 5] = frontColor[2];
                    break;
                case 2:
                    //right face
                    vertices[i*6 + 3] = downColor[0];
                    vertices[i*6 + 4] = downColor[1];
                    vertices[i*6 + 5] = downColor[2];
                    break;
                case 3:
                    //left face
                    vertices[i*6 + 3] = topColor[0];
                    vertices[i*6 + 4] = topColor[1];
                    vertices[i*6 + 5] = topColor[2];
                    break;
                case 4:
                    //top face
                    vertices[i*6 + 3] = rightColor[0];
                    vertices[i*6 + 4] = rightColor[1];
                    vertices[i*6 + 5] = rightColor[2];
                    break;
                case 5:
                    //down face
                    vertices[i*6 + 3] = leftColor[0];
                    vertices[i*6 + 4] = leftColor[1];
                    vertices[i*6 + 5] = leftColor[2];
                    break;
            }
        }
    }

}
