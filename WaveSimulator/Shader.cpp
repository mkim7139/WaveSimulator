//
//  Shader.cpp
//  HelloOpenGl
//
//  Created by Max on 3/9/22.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

#include "Shader.h"

using namespace std;

Shader::Shader()
{
    ID = glCreateProgram();
}

Shader::~Shader()
{
    glDeleteProgram(ID);
    glLinkProgram(ID);
    glUseProgram(ID);
}

// bind shader to openGL context
void Shader::Bind() const
{
    glUseProgram(ID);
}

unsigned int Shader::CompileShader (unsigned int type, const string& source)
{
    // generate shader
    unsigned int id = glCreateShader(type);
    // get source code in form of c-string
    const char* src = source.c_str();
    
    // assign source code to shader
    glShaderSource(id, 1, &src, NULL);
    // compile shader source code into machine code for GPU
    glCompileShader(id);
    
    // return handle for shader
    return id;
};

// takes in directory of shader source code to return source code in form of string
string Shader::GetShaderSource(string filepath)
{
    // open file from given path
    ifstream shaderFile;
    shaderFile.open(filepath);
    
    // string for storing text read from source code
    string shaderTxt;
    string line;
    
    // check file open successfully
    if (shaderFile.is_open())
    {
        // while not at end of file
        while (shaderFile)
        {
            getline(shaderFile, line);
            shaderTxt += line + "\n";
        }
    } else
    {
        cout << "failed to read shader file from:" << endl;
        cout << filepath << endl;
    }
    
    return shaderTxt;
}

// add new shader to the context by attaching to program
void Shader::AddShader(unsigned int type, string filepath)
{
    string shaderTxt = GetShaderSource(filepath);
    unsigned int shader = CompileShader(type, shaderTxt);
    
    glAttachShader(ID, shader);
    glLinkProgram(ID);
}

// return the location for a given uniform
int Shader::GetUniformLocation(string& name)
{
    int location = glGetUniformLocation(ID, name.c_str());
    return location;
}
