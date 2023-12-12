//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include <map>
#include "Rotating.hpp"

bool Rotating::rotate(float d, glm::vec3 vec) {
    //std::cout<<"Already rotating"<<std::endl;

    float velocity = 2.5f * d;

    cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment*velocity), vec));

//    float velocity = 2.5f * d;
//    if(increment * velocity + start > goal)
//        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 1.0f, 0.0f)));
//    else
//        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f)));
//    start += increment*velocity;
//    std::cout<<start<<std::endl;
//    if(start > goal)
//        stop();
    return true;

}

void Rotating::translate() {
    std::cout<<"Wait to end rotation"<<std::endl;

}

void Rotating::stop() {
    this->cube->actualSate = this->cube->is_Still;
    this->start = 0.0f;
    this->isRotating = false;
}

Rotating::Rotating(Cube *cube) : cube(cube) {
    this->start = 0.0f;
    this->goal = 90.0f;
    this->increment = 30.f;
    this->isRotating = false;
    this->rot_left = std::map<int, int>();
    this->rot_right = std::map<int, int>();
    this->rot_top = std::map<int, int>();
    this->rot_down = std::map<int, int>();
    this->rot_front = std::map<int, int>();
    this->rot_back = std::map<int, int>();

//    rot_left[0] = 6;
//    rot_left[3] = 14;
//    rot_left[6] = 23;
//    rot_left[14] = 20;
//    rot_left[23] = 17;
//    rot_left[20] = 9;
//    rot_left[17] = 0;
//    rot_left[9] = 3;
//    rot_left[12] = 12;
    rot_left[6] = 0;
    rot_left[14] = 3;
    rot_left[23] = 6;
    rot_left[20] = 14;
    rot_left[17] = 23;
    rot_left[9] = 20;
    rot_left[0] = 17;
    rot_left[3] = 9;
    rot_left[12] = 12;

//    rot_right[2] = 8;
//    rot_right[5] = 16;
//    rot_right[8] = 25;
//    rot_right[16] = 22;
//    rot_right[25] = 19;
//    rot_right[22] = 11;
//    rot_right[19] = 2;
//    rot_right[11] = 5;
//    rot_right[13] = 13;
    rot_right[8] = 2;
    rot_right[16] = 5;
    rot_right[25] = 8;
    rot_right[22] = 16;
    rot_right[19] = 25;
    rot_right[11] = 22;
    rot_right[2] = 19;
    rot_right[5] = 11;
    rot_right[13] = 13;

//    rot_top[6] = 8;
//    rot_top[7] = 5;
//    rot_top[8] = 2;
//    rot_top[5] = 1;
//    rot_top[2] = 0;
//    rot_top[1] = 3;
//    rot_top[0] = 6;
//    rot_top[3] = 7;
//    rot_top[4] = 4;
    rot_top[8] = 6;
    rot_top[5] = 7;
    rot_top[2] = 8;
    rot_top[1] = 5;
    rot_top[0] = 2;
    rot_top[3] = 1;
    rot_top[6] = 0;
    rot_top[7] = 3;
    rot_top[4] = 4;


//    rot_down[23] = 25;
//    rot_down[24] = 22;
//    rot_down[25] = 19;
//    rot_down[22] = 18;
//    rot_down[19] = 17;
//    rot_down[18] = 20;
//    rot_down[17] = 23;
//    rot_down[20] = 24;
//    rot_down[21] = 21;
    rot_down[25] = 23;
    rot_down[22] = 24;
    rot_down[19] = 25;
    rot_down[18] = 22;
    rot_down[17] = 19;
    rot_down[20] = 18;
    rot_down[23] = 17;
    rot_down[24] = 20;
    rot_down[21] = 21;

//    rot_front[8] = 6;
//    rot_front[7] = 14;
//    rot_front[6] = 23;
//    rot_front[14] = 24;
//    rot_front[23] = 25;
//    rot_front[24] = 16;
//    rot_front[25] = 8;
//    rot_front[16] = 7;
//    rot_front[15] = 15;
    rot_front[6] = 8;
    rot_front[14] = 7;
    rot_front[23] = 6;
    rot_front[24] = 14;
    rot_front[25] = 23;
    rot_front[16] = 24;
    rot_front[8] = 25;
    rot_front[7] = 16;
    rot_front[15] = 15;

//    rot_back[2] = 0;
//    rot_back[1] = 9;
//    rot_back[0] = 17;
//    rot_back[9] = 18;
//    rot_back[17] = 19;
//    rot_back[18] = 11;
//    rot_back[19] = 2;
//    rot_back[11] = 1;
//    rot_back[10] = 10;
    rot_back[0] = 2;
    rot_back[9] = 1;
    rot_back[17] = 0;
    rot_back[18] = 9;
    rot_back[19] = 17;
    rot_back[11] = 18;
    rot_back[2] = 19;
    rot_back[1] = 11;
    rot_back[10] = 10;

}

bool Rotating::rotateXLEFT(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(1.0f, 0.0f, 0.0f)));
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(1.0f, 0.0f, 0.0f)));
    }
    start += increment*velocity;

    if(start > goal){
        for (Cube* c:cube->rubik) {
            if(c->pos == rot_left[cube->pos] && &c != &cube){
                std::array<std::array<float,3>,6> allColors = c->vertices->allColors();
                cube->vertices->rotateX(
                        allColors[BACK_COLOR],
                        allColors[FRONT_COLOR],
                        allColors[TOP_COLOR],
                        allColors[DOWN_COLOR],
                        allColors[LEFT_COLOR],
                        allColors[RIGHT_COLOR]
                        );
            }
        }
//        std::array<std::array<float,3>,6> allColors = cube->vertices->allColors();
//        cube->vertices->rotateX(
//                allColors[BACK_COLOR],
//                allColors[FRONT_COLOR],
//                allColors[TOP_COLOR],
//                allColors[DOWN_COLOR],
//                allColors[LEFT_COLOR],
//                allColors[RIGHT_COLOR]
//        );
//        cube->pos = rot_left[cube->pos];

        cube->model = new glm::mat4(1.0f);

        stop();
    }

    return true;
}

bool Rotating::rotateXRIGHT(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(1.0f, 0.0f, 0.0f)));
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(1.0f, 0.0f, 0.0f)));
    }

    start += increment*velocity;

    if(start > goal){
        for (Cube* c:cube->rubik) {
            if(c->pos == rot_right[cube->pos] && &c != &cube){
                std::array<std::array<float,3>,6> allColors = c->vertices->allColors();
                cube->vertices->rotateX(
                        allColors[BACK_COLOR],
                        allColors[FRONT_COLOR],
                        allColors[TOP_COLOR],
                        allColors[DOWN_COLOR],
                        allColors[LEFT_COLOR],
                        allColors[RIGHT_COLOR]
                );
            }
        }
//        std::array<std::array<float,3>,6> allColors = cube->vertices->allColors();
//        cube->vertices->rotateX(
//                allColors[BACK_COLOR],
//                allColors[FRONT_COLOR],
//                allColors[TOP_COLOR],
//                allColors[DOWN_COLOR],
//                allColors[LEFT_COLOR],
//                allColors[RIGHT_COLOR]
//        );
//        cube->pos = rot_right[cube->pos];

        cube->model = new glm::mat4(1.0f);

        stop();
    }

    return true;
}

bool Rotating::rotateYTOP(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 1.0f, 0.0f)));
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f)));
    }
    start += increment*velocity;

    if(start > goal){
        for (Cube* c:cube->rubik) {
            if(c->pos == rot_top[cube->pos] && &c != &cube){
                std::array<std::array<float,3>,6> allColors = c->vertices->allColors();
                cube->vertices->rotateY(
                        allColors[BACK_COLOR],
                        allColors[FRONT_COLOR],
                        allColors[TOP_COLOR],
                        allColors[DOWN_COLOR],
                        allColors[LEFT_COLOR],
                        allColors[RIGHT_COLOR]
                );
            }
        }
//        std::array<std::array<float,3>,6> allColors = cube->vertices->allColors();
//        cube->vertices->rotateY(
//                allColors[BACK_COLOR],
//                allColors[FRONT_COLOR],
//                allColors[TOP_COLOR],
//                allColors[DOWN_COLOR],
//                allColors[LEFT_COLOR],
//                allColors[RIGHT_COLOR]
//        );

//        cube->pos = rot_top[cube->pos];

        cube->model = new glm::mat4(1.0f);

        stop();
    }

    return true;
}

bool Rotating::rotateYDOWN(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 1.0f, 0.0f)));
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f)));
    }
    start += increment*velocity;

    if(start > goal){
        for (Cube* c:cube->rubik) {
            if(c->pos == rot_down[cube->pos] && &c != &cube){
                std::array<std::array<float,3>,6> allColors = c->vertices->allColors();
                cube->vertices->rotateY(
                        allColors[BACK_COLOR],
                        allColors[FRONT_COLOR],
                        allColors[TOP_COLOR],
                        allColors[DOWN_COLOR],
                        allColors[LEFT_COLOR],
                        allColors[RIGHT_COLOR]
                );
            }
        }
//        std::array<std::array<float,3>,6> allColors = cube->vertices->allColors();
//        cube->vertices->rotateY(
//                allColors[BACK_COLOR],
//                allColors[FRONT_COLOR],
//                allColors[TOP_COLOR],
//                allColors[DOWN_COLOR],
//                allColors[LEFT_COLOR],
//                allColors[RIGHT_COLOR]
//        );

//        cube->pos = rot_down[cube->pos];

        cube->model = new glm::mat4(1.0f);

        stop();
    }

    return true;
}

bool Rotating::rotateZFRONT(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 0.0f, 1.0f)));
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 0.0f, 1.0f)));
    }
    start += increment*velocity;

    if(start > goal){
        for (Cube* c:cube->rubik) {
            if(c->pos == rot_front[cube->pos] && &c != &cube){
                std::array<std::array<float,3>,6> allColors = c->vertices->allColors();
                cube->vertices->rotateZ(
                        allColors[BACK_COLOR],
                        allColors[FRONT_COLOR],
                        allColors[TOP_COLOR],
                        allColors[DOWN_COLOR],
                        allColors[LEFT_COLOR],
                        allColors[RIGHT_COLOR]
                );
            }
        }
//        std::array<std::array<float,3>,6> allColors = cube->vertices->allColors();
//        cube->vertices->rotateZ(
//                allColors[BACK_COLOR],
//                allColors[FRONT_COLOR],
//                allColors[TOP_COLOR],
//                allColors[DOWN_COLOR],
//                allColors[LEFT_COLOR],
//                allColors[RIGHT_COLOR]
//        );
//        cube->pos = rot_front[cube->pos];

        cube->model = new glm::mat4(1.0f);

        stop();
    }

    return true;
}

bool Rotating::rotateZBACK(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 0.0f, 1.0f)));
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 0.0f, 1.0f)));
    }
    start += increment*velocity;

    if(start > goal){
        for (Cube* c:cube->rubik) {
            if(c->pos == rot_back[cube->pos] && &c != &cube){
                std::array<std::array<float,3>,6> allColors = c->vertices->allColors();
                cube->vertices->rotateZ(
                        allColors[BACK_COLOR],
                        allColors[FRONT_COLOR],
                        allColors[TOP_COLOR],
                        allColors[DOWN_COLOR],
                        allColors[LEFT_COLOR],
                        allColors[RIGHT_COLOR]
                );
            }
        }
//        std::array<std::array<float,3>,6> allColors = cube->vertices->allColors();
//        cube->vertices->rotateZ(
//                allColors[BACK_COLOR],
//                allColors[FRONT_COLOR],
//                allColors[TOP_COLOR],
//                allColors[DOWN_COLOR],
//                allColors[LEFT_COLOR],
//                allColors[RIGHT_COLOR]
//        );

//        cube->pos = rot_back[cube->pos];

        cube->model = new glm::mat4(1.0f);

        stop();
    }

    return true;
}
