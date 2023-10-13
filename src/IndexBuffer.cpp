//
// Created by pauno on 10/11/2023.
//

#include "IndexBuffer.hpp"
#include "glad/glad.h"

IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count)
        : m_Count(count)
{
    glGenBuffers(1, &m_RedererID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RedererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
}

IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_RedererID);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RedererID);
}

void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}