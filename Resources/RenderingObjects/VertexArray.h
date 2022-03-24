//
//  VertexArray.hpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//

#pragma once

class VertexArray
{
private:
    unsigned int ID;
public:
    VertexArray();
    ~VertexArray();
    
    void AttribPointer(unsigned int index, unsigned int count_attrib, GLenum type, GLboolean normalized, unsigned int stride, int offset);
    
    void Bind() const;
};
