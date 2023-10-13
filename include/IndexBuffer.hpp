//
// Created by pauno on 10/11/2023.
//

#ifndef OPENGLPRJ_INDEXBUFFER_HPP
#define OPENGLPRJ_INDEXBUFFER_HPP


#pragma once


class IndexBuffer
{
private:
    unsigned int m_RedererID;
    unsigned int m_Count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const;
    void Unbind() const;

    inline unsigned int GetCount() const { return m_Count; }
};



#endif //OPENGLPRJ_INDEXBUFFER_HPP
