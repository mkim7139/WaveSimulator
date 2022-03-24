//
//  VertexBuffer.hpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//

#pragma once

class VertexBuffer
{
private:
    unsigned int ID;
public:
    VertexBuffer(float* data, unsigned int size);
    ~VertexBuffer();
    
    
    void UnBind();
};
