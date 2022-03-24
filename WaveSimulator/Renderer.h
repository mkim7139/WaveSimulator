//
//  Renderer.hpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//

#pragma once



class Renderer
{
public:
    Renderer(const VertexArray& VAO, const IndexBuffer& EBO, const Shader& shaderProgram);
    
    // draw shapes
    void Draw(const VertexArray& VAO, const IndexBuffer& EBO, const Shader& shaderProgram) const;
    
    // color background
    void Background(const float* color) const;
};
