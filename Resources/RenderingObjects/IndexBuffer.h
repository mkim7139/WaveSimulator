//
//  IndexBuffer.hpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//

#pragma once

class IndexBuffer
{
private:
    unsigned int ID;
    unsigned int indexCount;
public:
    IndexBuffer(unsigned int* data, unsigned int size);
    ~IndexBuffer();
    
    unsigned int GetCount() const;
    
    void Bind() const;
    void UnBind();
};
