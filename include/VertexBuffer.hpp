//
// Created by pauno on 10/11/2023.
//

#ifndef OPENGLPRJ_VERTEXBUFFER_HPP
#define OPENGLPRJ_VERTEXBUFFER_HPP


#pragma once
#include <vector>

class VertexBuffer
{
private:
    unsigned int m_RedererID;
public:
    VertexBuffer(const void* data, unsigned int size);
    VertexBuffer(std::vector<float>* data, unsigned int size);
    ~VertexBuffer();

    void Bind() const;
    void Unbind() const;
};



#endif //OPENGLPRJ_VERTEXBUFFER_HPP
