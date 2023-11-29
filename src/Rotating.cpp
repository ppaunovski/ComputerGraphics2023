//
// Created by pauno on 11/19/2023.
//

#include <iostream>
#include <map>
#include "Rotating.hpp"

bool Rotating::rotate(float d) {
    //std::cout<<"Already rotating"<<std::endl;

    float velocity = 2.5f * d;
    if(increment * velocity + start > goal)
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 1.0f, 0.0f)));
    else
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f)));
    start += increment*velocity;
    std::cout<<start<<std::endl;
    if(start > goal)
        stop();
    return true;

}
void Rotating::startRotation(){
//    do{
//        cube->model = glm::rotate(cube->model, glm::radians(180*increment), glm::vec3(1.0f, 0.3f, 0.5f));
//        start += 360*increment;
//        std::cout<<start<<std::endl;
//    }
//    while(start < goal);
//    stop();
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

//    rot_left.insert(std::make_pair(0,6));
//    rot_left.insert(std::make_pair(3,14));
//    rot_left.insert(std::make_pair(6,23));
//    rot_left.insert(std::make_pair(14,20));
//    rot_left.insert(std::make_pair(23,17));
//    rot_left.insert(std::make_pair(20,9));
//    rot_left.insert(std::make_pair(17,0));
//    rot_left.insert(std::make_pair(9,3));
//    rot_left.insert(std::make_pair(12,12));
    rot_left[0] = 6;
    rot_left[3] = 14;
    rot_left[6] = 23;
    rot_left[14] = 20;
    rot_left[23] = 17;
    rot_left[20] = 9;
    rot_left[17] = 0;
    rot_left[9] = 3;
    rot_left[12] = 12;

    rot_right[2] = 8;
    rot_right[5] = 16;
    rot_right[8] = 25;
    rot_right[16] = 22;
    rot_right[25] = 19;
    rot_right[22] = 11;
    rot_right[19] = 2;
    rot_right[11] = 5;
    rot_right[13] = 13;

    rot_top[6] = 8;
    rot_top[7] = 5;
    rot_top[8] = 2;
    rot_top[5] = 1;
    rot_top[2] = 0;
    rot_top[1] = 3;
    rot_top[0] = 6;
    rot_top[3] = 7;
    rot_top[4] = 4;


    rot_down[23] = 25;
    rot_down[24] = 22;
    rot_down[25] = 19;
    rot_down[22] = 18;
    rot_down[19] = 17;
    rot_down[18] = 20;
    rot_down[17] = 23;
    rot_down[20] = 24;
    rot_down[21] = 21;

    rot_front[8] = 6;
    rot_front[7] = 14;
    rot_front[6] = 23;
    rot_front[14] = 24;
    rot_front[23] = 25;
    rot_front[24] = 16;
    rot_front[25] = 8;
    rot_front[16] = 7;
    rot_front[15] = 15;


    rot_back[2] = 0;
    rot_back[1] = 9;
    rot_back[0] = 17;
    rot_back[9] = 18;
    rot_back[17] = 19;
    rot_back[18] = 11;
    rot_back[19] = 2;
    rot_back[11] = 1;
    rot_back[10] = 10;

}

bool Rotating::rotateXLEFT(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(1.0f, 0.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(goal - (increment * velocity + start)), glm::vec3(1.0f, 0.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(1.0f, 0.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(increment * velocity), glm::vec3(1.0f, 0.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);

    }
    start += increment*velocity;
    //std::cout<<start<<std::endl;
    if(start > goal){
        std::cout<<cube->pos<<std::endl;
        cube->pos = rot_left[cube->pos];
        std::cout<<cube->pos<<std::endl;


        float x = cube->position->x;
        float y = cube->position->y;
        float z = cube->position->z;

        if(y == -1.0f){
            if(z == -1.0f){
                y = 1.0f;
            }
            else if(z == 0.0f){
                y = 0.0f;
                z = -1.0f;
            }
            else{
                z = -1.0f;
            }
        }
        else if(y == 0.0f){

            if(z == -1.0f){
                y = 1.0f;
                z = 0.0f;
            }
            else if(z == 0.0f){

            }
            else{
                z = 0.0f;
                y = -1.0f;
            }

        }
        else{

            if(z == -1.0f){
                z = 1.0f;
            }
            else if(z == 0.0f){
                y=0.0f;
                z=1.0f;
            }
            else{
                y = -1.0f;
            }

        }

        cube->position = new glm::vec3(x, y, z);

        stop();
    }
    return true;
}

bool Rotating::rotateXRIGHT(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(1.0f, 0.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(goal - (increment * velocity + start)), glm::vec3(1.0f, 0.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(1.0f, 0.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(increment * velocity), glm::vec3(1.0f, 0.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    start += increment*velocity;
    //std::cout<<start<<std::endl;
    if(start > goal){
        cube->pos = rot_right[cube->pos];

        float x = cube->position->x;
        float y = cube->position->y;
        float z = cube->position->z;

        if(y == -1.0f){
            if(z == -1.0f){
                y = 1.0f;
            }
            else if(z == 0.0f){
                y = 0.0f;
                z = -1.0f;
            }
            else{
                z = -1.0f;
            }
        }
        else if(y == 0.0f){

            if(z == -1.0f){
                y = 1.0f;
                z = 0.0f;
            }
            else if(z == 0.0f){

            }
            else{
                z = 0.0f;
                y = -1.0f;
            }

        }
        else{

            if(z == -1.0f){
                z = 1.0f;
            }
            else if(z == 0.0f){
                y=0.0f;
                z=1.0f;
            }
            else{
                y = -1.0f;
            }

        }


        cube->position = new glm::vec3(x, y, z);

        stop();
    }
    return true;
}

bool Rotating::rotateYTOP(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 1.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 1.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    start += increment*velocity;
    //std::cout<<start<<std::endl;
    if(start > goal){

        std::cout<<cube->pos<<std::endl;
        cube->pos = rot_top[cube->pos];
        std::cout<<cube->pos<<std::endl;

        float x = cube->position->x;
        float y = cube->position->y;
        float z = cube->position->z;

        if(x == -1.0f){
            if(z == -1.0f){
                z = 1.0f;
            }
            else if(z == 0.0f){
                x = 0.0f;
                z = 1.0f;
            }
            else{
                x = 1.0f;
            }
        }
        else if(x == 0.0f){

            if(z == -1.0f){
                x = -1.0f;
                z = 0.0f;
            }
            else if(z == 0.0f){

            }
            else{
                z = 0.0f;
                x = 1.0f;
            }

        }
        else{

            if(z == -1.0f){
                x = -1.0f;
                z = -1.0f;
            }
            else if(z == 0.0f){
                x=0.0f;
                z=-1.0f;
            }
            else{
                z = -1.0f;
            }

        }

        cube->position = new glm::vec3(x, y, z);

        stop();
    }
    return true;
}

bool Rotating::rotateYDOWN(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 1.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 1.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(increment * velocity), glm::vec3(0.0f, 1.0f, 0.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    start += increment*velocity;
    //std::cout<<start<<std::endl;
    if(start > goal){

        cube->pos = rot_down[cube->pos];

        float x = cube->position->x;
        float y = cube->position->y;
        float z = cube->position->z;

        if(x == -1.0f){
            if(z == -1.0f){
                z = 1.0f;
            }
            else if(z == 0.0f){
                x = 0.0f;
                z = 1.0f;
            }
            else{
                x = 1.0f;
            }
        }
        else if(x == 0.0f){

            if(z == -1.0f){
                x = -1.0f;
                z = 0.0f;
            }
            else if(z == 0.0f){

            }
            else{
                z = 0.0f;
                x = 1.0f;
            }

        }
        else{

            if(z == -1.0f){
                x = -1.0f;
                z = -1.0f;
            }
            else if(z == 0.0f){
                x=0.0f;
                z=-1.0f;
            }
            else{
                z = -1.0f;
            }

        }

        cube->position = new glm::vec3(x, y, z);

        stop();
    }
    return true;
}

bool Rotating::rotateZFRONT(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 0.0f, 1.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 0.0f, 1.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 0.0f, 1.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(increment * velocity), glm::vec3(0.0f, 0.0f, 1.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    start += increment*velocity;
    //std::cout<<start<<std::endl;
    if(start > goal){
        cube->pos = rot_front[cube->pos];

        float x = cube->position->x;
        float y = cube->position->y;
        float z = cube->position->z;

        if(y == -1.0f){
            if(x == -1.0f){
                x = 1.0f;
            }
            else if(x == 0.0f){
                y = 0.0f;
                x = 1.0f;
            }
            else{
                y = 1.0f;
            }
        }
        else if(y == 0.0f){

            if(x == -1.0f){
                y = -1.0f;
                x = 0.0f;
            }
            else if(x == 0.0f){

            }
            else{
                x = 0.0f;
                y = 1.0f;
            }

        }
        else{

            if(x == -1.0f){
                y = -1.0f;
            }
            else if(x == 0.0f){
                y=0.0f;
                x=-1.0f;
            }
            else{
                x = -1.0f;
            }

        }

        cube->position = new glm::vec3(x, y, z);

        stop();
    }
    return true;
}

bool Rotating::rotateZBACK(float d) {
    float velocity = 2.5f * d;
    if(increment * velocity + start > goal){
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(goal - (start)), glm::vec3(0.0f, 0.0f, 1.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(goal - (increment * velocity + start)), glm::vec3(0.0f, 0.0f, 1.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    else{
        cube->model = new glm::mat4(glm::rotate(*cube->model, glm::radians(increment * velocity), glm::vec3(0.0f, 0.0f, 1.0f)));
//        glm::mat4 rot_mat = glm::rotate(glm::mat4(1.0f), glm::radians(increment * velocity), glm::vec3(0.0f, 0.0f, 1.0f));
//        glm::vec4 new_pos = rot_mat * glm::vec4(cube->position, 1.0f);
//        cube->position = glm::vec3(new_pos.x, new_pos.y, new_pos.z);
    }
    start += increment*velocity;
    //std::cout<<start<<std::endl;
    if(start > goal){

        cube->pos = rot_back[cube->pos];

        float x = cube->position->x;
        float y = cube->position->y;
        float z = cube->position->z;

        if(y == -1.0f){
            if(x == -1.0f){
                x = 1.0f;
            }
            else if(x == 0.0f){
                y = 0.0f;
                x = 1.0f;
            }
            else{
                y = 1.0f;
            }
        }
        else if(y == 0.0f){

            if(x == -1.0f){
                y = -1.0f;
                x = 0.0f;
            }
            else if(x == 0.0f){

            }
            else{
                x = 0.0f;
                y = 1.0f;
            }

        }
        else{

            if(x == -1.0f){
                y = -1.0f;
            }
            else if(x == 0.0f){
                y=0.0f;
                x=-1.0f;
            }
            else{
                x = -1.0f;
            }

        }

        cube->position = new glm::vec3(x, y, z);

        stop();
    }
    return true;
}
