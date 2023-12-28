//
// Created by pauno on 12/10/2023.
//
#include <iostream>
#include "Vertices.hpp"

Vertices::Vertices(){
    float vertices[] = {
            // Vertices for the back face
            -0.45f, -0.45f, -0.45f, 0.0f, 0.0f, 1.0f,   // Bottom left (Green)
            0.45f, -0.45f, -0.45f, 0.0f, 0.0f, 1.0f,    // Bottom right (Green)
            0.45f, 0.45f, -0.45f, 0.0f, 0.0f, 1.0f,     // Top right (Green)
            0.45f, 0.45f, -0.45f, 0.0f, 0.0f, 1.0f,     // Top right (Green)
            -0.45f, 0.45f, -0.45f, 0.0f, 0.0f, 1.0f,    // Top left (Green)
            -0.45f, -0.45f, -0.45f, 0.0f, 0.0f, 1.0f,   // Bottom left (Green)

            // Vertices for the front face
            -0.45f, -0.45f, 0.45f, 0.0f, 1.0f, 0.0f,    // Bottom left (Blue)
            0.45f, -0.45f, 0.45f, 0.0f, 1.0f, 0.0f,     // Bottom right (Blue)
            0.45f, 0.45f, 0.45f, 0.0f, 1.0f, 0.0f,      // Top right (Blue)
            0.45f, 0.45f, 0.45f, 0.0f, 1.0f, 0.0f,      // Top right (Blue)
            -0.45f, 0.45f, 0.45f, 0.0f, 1.0f, 0.0f,     // Top left (Blue)
            -0.45f, -0.45f, 0.45f, 0.0f, 1.0f, 0.0f,    // Bottom left (Blue)

            // Vertices for the right face
            0.45f, -0.45f, -0.45f, 1.0f, 0.0f, 0.0f,    // Bottom front (Red)
            0.45f, -0.45f, 0.45f, 1.0f, 0.0f, 0.0f,     // Bottom back (Red)
            0.45f, 0.45f, 0.45f, 1.0f, 0.0f, 0.0f,      // Top back (Red)
            0.45f, 0.45f, 0.45f, 1.0f, 0.0f, 0.0f,      // Top back (Red)
            0.45f, 0.45f, -0.45f, 1.0f, 0.0f, 0.0f,     // Top front (Red)
            0.45f, -0.45f, -0.45f, 1.0f, 0.0f, 0.0f,    // Bottom front (Red)

            // Vertices for the left face
            -0.45f, -0.45f, -0.45f, 1.0f, 0.45f, 0.0f,   // Bottom front (Orange)
            -0.45f, -0.45f, 0.45f, 1.0f, 0.45f, 0.0f,    // Bottom back (Orange)
            -0.45f, 0.45f, 0.45f, 1.0f, 0.45f, 0.0f,     // Top back (Orange)
            -0.45f, 0.45f, 0.45f, 1.0f, 0.45f, 0.0f,     // Top back (Orange)
            -0.45f, 0.45f, -0.45f, 1.0f, 0.45f, 0.0f,    // Top front (Orange)
            -0.45f, -0.45f, -0.45f, 1.0f, 0.45f, 0.0f,   // Bottom front (Orange)

            // Vertices for the top face
            -0.45f, 0.45f, -0.45f, 1.0f, 1.0f, 1.0f,    // Front left (White)
            0.45f, 0.45f, -0.45f, 1.0f, 1.0f, 1.0f,     // Front right (White)
            0.45f, 0.45f, 0.45f, 1.0f, 1.0f, 1.0f,      // Back right (White)
            0.45f, 0.45f, 0.45f, 1.0f, 1.0f, 1.0f,      // Back right (White)
            -0.45f, 0.45f, 0.45f, 1.0f, 1.0f, 1.0f,     // Back left (White)
            -0.45f, 0.45f, -0.45f, 1.0f, 1.0f, 1.0f,    // Front left (White)

            // Vertices for the bottom face
            -0.45f, -0.45f, -0.45f, 1.0f, 1.0f, 0.0f,   // Front left (Yellow)
            0.45f, -0.45f, -0.45f, 1.0f, 1.0f, 0.0f,    // Front right (Yellow)
            0.45f, -0.45f, 0.45f, 1.0f, 1.0f, 0.0f,     // Back right (Yellow)
            0.45f, -0.45f, 0.45f, 1.0f, 1.0f, 0.0f,     // Back right (Yellow)
            -0.45f, -0.45f, 0.45f, 1.0f, 1.0f, 0.0f,    // Back left (Yellow)
            -0.45f, -0.45f, -0.45f, 1.0f, 1.0f, 0.0f    // Front left (Yellow)
    };
    for(int i=0; i<216; i++){
        this->vertices[i] = vertices[i];
    }

    setOldColors();

    hasChanged = false;
    isUsed = false;

}

void Vertices::rotate(bool prime, char axis,
                      std::array<float, 3> backColor,
                      std::array<float, 3> frontColor,
                      std::array<float, 3> topColor,
                      std::array<float, 3> downColor,
                      std::array<float, 3> leftColor,
                      std::array<float, 3> rightColor){
    switch (axis) {
        case 'x':
            if(prime) rotateXPrime(backColor, frontColor, topColor, downColor, leftColor, rightColor);
            else rotateX(backColor, frontColor, topColor, downColor, leftColor, rightColor);
            break;
        case 'y':
            if(prime) rotateYPrime(backColor, frontColor, topColor, downColor, leftColor, rightColor);
            else rotateY(backColor, frontColor, topColor, downColor, leftColor, rightColor);
            break;
        case 'z':
            if(prime) rotateZPrime(backColor, frontColor, topColor, downColor, leftColor, rightColor);
            else rotateZ(backColor, frontColor, topColor, downColor, leftColor, rightColor);
            break;
    }
}

void Vertices::rotateX(std::array<float, 3> backColor,
                       std::array<float, 3> frontColor,
                       std::array<float, 3> topColor,
                       std::array<float, 3> downColor,
                       std::array<float, 3> leftColor,
                       std::array<float, 3> rightColor) {

//   if(!isUsed){
//       hasChanged = true;
//   }
//    hasChanged = true;
//    setOldColors();

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

void Vertices::rotateXPrime(std::array<float, 3> backColor,
                       std::array<float, 3> frontColor,
                       std::array<float, 3> topColor,
                       std::array<float, 3> downColor,
                       std::array<float, 3> leftColor,
                       std::array<float, 3> rightColor) {

//   if(!isUsed){
//       hasChanged = true;
//   }
//    hasChanged = true;
//    setOldColors();

    for(int j=0; j<6; j++){

        for (int i = j*6; i < 6 + j*6; i++) {
            //        front colors = down colors
            //        back colors = top colors
            //        left is the same
            //        right is the same
            //        top colors = front colors
            //        down colors = back colors
            switch (j) {
                case 0:
                    //back face
                    vertices[i*6 + 3] = topColor[0];
                    vertices[i*6 + 4] = topColor[1];
                    vertices[i*6 + 5] = topColor[2];
                    break;
                case 1:
                    //front face
                    vertices[i*6 + 3] = downColor[0];
                    vertices[i*6 + 4] = downColor[1];
                    vertices[i*6 + 5] = downColor[2];
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
                    vertices[i*6 + 3] = frontColor[0];
                    vertices[i*6 + 4] = frontColor[1];
                    vertices[i*6 + 5] = frontColor[2];
                    break;
                case 5:
                    //down face
                    vertices[i*6 + 3] = backColor[0];
                    vertices[i*6 + 4] = backColor[1];
                    vertices[i*6 + 5] = backColor[2];
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

void Vertices::rotateY(std::array<float, 3> backColor,
                       std::array<float, 3> frontColor,
                       std::array<float, 3> topColor,
                       std::array<float, 3> downColor,
                       std::array<float, 3> leftColor,
                       std::array<float, 3> rightColor) {

//    hasChanged = true;
//    setOldColors();

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


void Vertices::rotateYPrime(std::array<float, 3> backColor,
                       std::array<float, 3> frontColor,
                       std::array<float, 3> topColor,
                       std::array<float, 3> downColor,
                       std::array<float, 3> leftColor,
                       std::array<float, 3> rightColor) {

//    hasChanged = true;
//    setOldColors();

    for(int j=0; j<6; j++){

        for (int i = j*6; i < 6 + j*6; i++) {
//            top color is the same
//            down color is the same
//            left color = front color
//            front color = right color
//            right color = back color
//            back color = left color
            switch (j) {
                case 0:
                    //back face
                    vertices[i*6 + 3] = leftColor[0];
                    vertices[i*6 + 4] = leftColor[1];
                    vertices[i*6 + 5] = leftColor[2];
                    break;
                case 1:
                    //front face
                    vertices[i*6 + 3] = rightColor[0];
                    vertices[i*6 + 4] = rightColor[1];
                    vertices[i*6 + 5] = rightColor[2];
                    break;
                case 2:
                    //right face
                    vertices[i*6 + 3] = backColor[0];
                    vertices[i*6 + 4] = backColor[1];
                    vertices[i*6 + 5] = backColor[2];
                    break;
                case 3:
                    //left face
                    vertices[i*6 + 3] = frontColor[0];
                    vertices[i*6 + 4] = frontColor[1];
                    vertices[i*6 + 5] = frontColor[2];
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

void Vertices::rotateZ(std::array<float, 3> backColor,
                       std::array<float, 3> frontColor,
                       std::array<float, 3> topColor,
                       std::array<float, 3> downColor,
                       std::array<float, 3> leftColor,
                       std::array<float, 3> rightColor) {

//    hasChanged = true;
//    setOldColors();

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

void Vertices::rotateZPrime(std::array<float, 3> backColor,
                       std::array<float, 3> frontColor,
                       std::array<float, 3> topColor,
                       std::array<float, 3> downColor,
                       std::array<float, 3> leftColor,
                       std::array<float, 3> rightColor) {

//    hasChanged = true;
//    setOldColors();

    for(int j=0; j<6; j++){

        for (int i = j*6; i < 6 + j*6; i++) {
//            top color = left color
//            down color = right color
//            left color = down color
//            front color is the same
//            right color = top color
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
                    vertices[i*6 + 3] = topColor[0];
                    vertices[i*6 + 4] = topColor[1];
                    vertices[i*6 + 5] = topColor[2];
                    break;
                case 3:
                    //left face
                    vertices[i*6 + 3] = downColor[0];
                    vertices[i*6 + 4] = downColor[1];
                    vertices[i*6 + 5] = downColor[2];
                    break;
                case 4:
                    //top face
                    vertices[i*6 + 3] = leftColor[0];
                    vertices[i*6 + 4] = leftColor[1];
                    vertices[i*6 + 5] = leftColor[2];
                    break;
                case 5:
                    //down face
                    vertices[i*6 + 3] = rightColor[0];
                    vertices[i*6 + 4] = rightColor[1];
                    vertices[i*6 + 5] = rightColor[2];
                    break;
            }
        }
    }

}

std::array<float, 3> Vertices::backColor() {
    std::array<float, 3> backColor = { vertices[3], vertices[4], vertices[5] };
    return backColor;
}

std::array<float, 3> Vertices::frontColor() {
    std::array<float, 3> frontColor = { vertices[39], vertices[40], vertices[41] };
    return frontColor;
}

std::array<float, 3> Vertices::topColor() {
    std::array<float, 3> topColor = { vertices[147], vertices[148], vertices[149] };
    return topColor;
}

std::array<float, 3> Vertices::downColor() {
    std::array<float, 3> downColor = { vertices[183], vertices[184], vertices[185] };
    return downColor;
}

std::array<float, 3> Vertices::leftColor() {
    std::array<float, 3> leftColor = { vertices[111], vertices[112], vertices[113] };
    return leftColor;
}

std::array<float, 3> Vertices::rightColor() {
    std::array<float, 3> rightColor = { vertices[75], vertices[76], vertices[77] };
    return rightColor;
}

std::array<std::array<float, 3>, 6> Vertices::allColors() {
    std::array<std::array<float, 3>, 6> allColors{};
//    if(hasChanged){
        allColors[BACK_COLOR] = backColorOld;
        allColors[FRONT_COLOR] = frontColorOld;
        allColors[TOP_COLOR] = topColorOld;
        allColors[DOWN_COLOR] = downColorOld;
        allColors[LEFT_COLOR] = leftColorOld;
        allColors[RIGHT_COLOR] = rightColorOld;

//    }
//    else{
//        allColors[BACK_COLOR] = backColor();
//        allColors[FRONT_COLOR] = frontColor();
//        allColors[TOP_COLOR] = topColor();
//        allColors[DOWN_COLOR] = downColor();
//        allColors[LEFT_COLOR] = leftColor();
//        allColors[RIGHT_COLOR] = rightColor();
//    }

    isUsed = !isUsed;
//    hasChanged = false;

    return allColors;
}

void Vertices::setOldColors() {
    backColorOld = backColor();
    frontColorOld = frontColor();
    topColorOld = topColor();
    downColorOld = downColor();
    leftColorOld = leftColor();
    rightColorOld = rightColor();
}
