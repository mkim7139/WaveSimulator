//
//  IndexBuffer.cpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IndexBuffer.h"

IndexBuffer::IndexBuffer(unsigned int* data, unsigned int size)
{
    // specify number of elements within index array
    indexCount = size / sizeof(data[0]);
    
    // generate and bind buffer and data
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}

// delete object before terminating program
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &ID);
}

// bind index buffer
void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

// unbind index buffer
void IndexBuffer::UnBind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

// get the number of elements within the relevent index array
unsigned int IndexBuffer::GetCount() const
{
    return indexCount;
}
