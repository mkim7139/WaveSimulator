//
//  VertexBuffer.cpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(float* data, unsigned int size)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &ID);
}

void VertexBuffer::UnBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
