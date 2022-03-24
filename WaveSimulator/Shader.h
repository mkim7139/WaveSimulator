//
//  Shader.hpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//

#pragma once

using namespace std;

class Shader
{
private:
    unsigned int ID;
public:
    Shader();
    ~Shader();
    
    string GetShaderSource(string filepath);
    unsigned int CompileShader(unsigned int type, const string& source);
    void AddShader(unsigned int type, string filepath);
    void Bind() const;
    
    int GetUniformLocation(string& name);
};

