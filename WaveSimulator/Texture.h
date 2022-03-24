//
//  Texture.h
//  HelloOpenGl
//
//  Created by Max on 3/10/22.
//

#pragma once

using namespace std;

class Texture
{
private:
    unsigned int ID;
    
    int width, height, BPP;
    string filepath;
    unsigned char* localBuffer;
public:
    Texture(const string& path);
    ~Texture();
    
    void Bind(unsigned int slot);
    void UnBind();
    
    inline int GetWidth() const { return width; }
    inline int GetHeight() const { return height; }
};
