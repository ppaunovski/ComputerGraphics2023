//
// Created by pauno on 12/10/2023.
//

#ifndef OPENGLPRJ_VERTICES_HPP
#define OPENGLPRJ_VERTICES_HPP

#include <array>

enum COLOR_ORDER{
    BACK_COLOR,
    FRONT_COLOR,
    TOP_COLOR,
    DOWN_COLOR,
    LEFT_COLOR,
    RIGHT_COLOR
};

class Vertices{
public:
    float vertices[216];
    std::array<float, 3> backColorOld;
    std::array<float, 3> frontColorOld;
    std::array<float, 3> topColorOld;
    std::array<float, 3> downColorOld;
    std::array<float, 3> leftColorOld;
    std::array<float, 3> rightColorOld;
    bool hasChanged;
    bool isUsed;
    Vertices();
    void rotateX(std::array<float, 3> backColor,
                 std::array<float, 3> frontColor,
                 std::array<float, 3> topColor,
                 std::array<float, 3> downColor,
                 std::array<float, 3> leftColor,
                 std::array<float, 3> rightColor);
    void rotateXPrime(std::array<float, 3> backColor,
                 std::array<float, 3> frontColor,
                 std::array<float, 3> topColor,
                 std::array<float, 3> downColor,
                 std::array<float, 3> leftColor,
                 std::array<float, 3> rightColor);
    void rotateY(std::array<float, 3> backColor,
                 std::array<float, 3> frontColor,
                 std::array<float, 3> topColor,
                 std::array<float, 3> downColor,
                 std::array<float, 3> leftColor,
                 std::array<float, 3> rightColor);
    void rotateYPrime(std::array<float, 3> backColor,
                 std::array<float, 3> frontColor,
                 std::array<float, 3> topColor,
                 std::array<float, 3> downColor,
                 std::array<float, 3> leftColor,
                 std::array<float, 3> rightColor);
    void rotateZ(std::array<float, 3> backColor,
                 std::array<float, 3> frontColor,
                 std::array<float, 3> topColor,
                 std::array<float, 3> downColor,
                 std::array<float, 3> leftColor,
                 std::array<float, 3> rightColor);
    void rotateZPrime(std::array<float, 3> backColor,
                 std::array<float, 3> frontColor,
                 std::array<float, 3> topColor,
                 std::array<float, 3> downColor,
                 std::array<float, 3> leftColor,
                 std::array<float, 3> rightColor);

    std::array<float, 3> backColor();
    std::array<float, 3> frontColor();
    std::array<float, 3> topColor();
    std::array<float, 3> downColor();
    std::array<float, 3> leftColor();
    std::array<float, 3> rightColor();
    std::array<std::array<float, 3>, 6> allColors();

    void setOldColors();

    void rotate(bool prime, char axis);

    void rotate(bool prime, char axis, std::array<float, 3> backColor, std::array<float, 3> frontColor,
                std::array<float, 3> topColor, std::array<float, 3> downColor, std::array<float, 3> leftColor,
                std::array<float, 3> rightColor);
};

#endif //OPENGLPRJ_VERTICES_HPP
