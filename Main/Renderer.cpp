//
//  Renderer.cpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//



#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "Shader.h"

#include "Renderer.h"

Renderer::Renderer(const VertexArray& VAO, const IndexBuffer& EBO, const Shader &shaderProgram)
{
    // bind relevant index buffer and vertex array
    shaderProgram.Bind();
    EBO.Bind();
    VAO.Bind();
}

void Renderer::Draw(const VertexArray& VAO, const IndexBuffer& EBO, const Shader &shaderProgram) const
{
    // bind relevant index buffer and vertex array
    shaderProgram.Bind();
    EBO.Bind();
    VAO.Bind();
    
    // draw shape
    unsigned int indexCount = EBO.GetCount();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, 0);
}

void Renderer::Background(const float* color) const
{
    // color background
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);
}
