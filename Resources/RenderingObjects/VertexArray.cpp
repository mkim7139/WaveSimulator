//
//  VertexArray.cpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "VertexArray.h"

using namespace std;

VertexArray::VertexArray()
{
    glGenVertexArrays(1, &ID);
    glBindVertexArray(ID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &ID);
}

// specify how to read vertex array data
void VertexArray::AttribPointer(unsigned int index, unsigned int count_attrib, GLenum type, GLboolean normalized, unsigned int stride, int offset)
{
    unsigned int itemSize = 0;
    
    // find size of datatype
    switch (type) {
        case GL_FLOAT:
            itemSize = sizeof(float);
            break;
        case GL_INT:
            itemSize = sizeof(int);
            break;
        default:
            cout << "invalid datatype in VertexArray / AttribPointer" << endl;
            break;
    }
    
    // doesn't do anything if size of datatype can't be found
    if (itemSize != 0)
    {
        unsigned int strideSize = stride * itemSize;
        unsigned int offsetSize = offset * itemSize;
        
        glVertexAttribPointer(index, count_attrib, type, normalized, strideSize, (void*)(offsetSize));
        glEnableVertexAttribArray(index);
    }
}

// bind vertex array
void VertexArray::Bind() const
{
    glBindVertexArray(ID);
}
