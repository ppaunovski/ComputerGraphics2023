//
// Created by pauno on 10/11/2023.
//

#include "VertexBuffer.hpp"
#include "glad/glad.h"
#include <vector>

VertexBuffer::VertexBuffer(const void* data, unsigned int size)
{
    glGenBuffers(1, &m_RedererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RedererID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::VertexBuffer(std::vector<float>* data, unsigned int size)
{
    glGenBuffers(1, &m_RedererID);
    glBindBuffer(GL_ARRAY_BUFFER, m_RedererID);
    glBufferData(GL_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_RedererID);
}

void VertexBuffer::Bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_RedererID);
}

void VertexBuffer::Unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}