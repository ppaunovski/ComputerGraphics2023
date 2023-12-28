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
    float goalN;
    float increment;
    float decrement;
    bool isRotating;
    std::map<int, int> rot_left;
    std::map<int, int> rot_left_prime;
    std::map<int, int> rot_right;
    std::map<int, int> rot_right_prime;
    std::map<int, int> rot_top;
    std::map<int, int> rot_top_prime;
    std::map<int, int> rot_down;
    std::map<int, int> rot_down_prime;
    std::map<int, int> rot_front;
    std::map<int, int> rot_front_prime;
    std::map<int, int> rot_back;
    std::map<int, int> rot_back_prime;

    explicit Rotating(Cube *cube);

    void startRotation();

    bool rotate(float d, glm::vec3 vec) override;
    bool rotateXLEFT(float d, bool prime) override;
    bool rotateXRIGHT(float d, bool prime) override;
    bool rotateYTOP(float d, bool prime) override;
    bool rotateYDOWN(float d, bool prime) override;
    bool rotateZFRONT(float d, bool prime) override;
    bool rotateZBACK(float d, bool prime) override;

    void translate() override;
    void make_rotation(float velocity, bool prime, glm::vec3 axis);

    void stop() override;

    void change_colors(std::map<int, int> map);
    void change_colors_prime(std::map<int, int> map);

    void change_colors_prime(std::map<int, int> map, bool prime, char axis);

    void change_colors(std::map<int, int> map, bool prime, char axis);
};


#endif //OPENGLPRJ_ROTATING_HPP
