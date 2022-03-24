//
//  Texture.c
//  HelloOpenGl
//
//  Created by Max on 3/10/22.
//

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include "Texture.h"

Texture::Texture(const string& path)
    : width(0), height(0), BPP(0), filepath(path), localBuffer(nullptr)
{
        // png reads top down, openGL marks bottom left of window as start
        stbi_set_flip_vertically_on_load(1);
        localBuffer = stbi_load(path.c_str(), &width, &height, &BPP, 4); // r, g, b, a - 4 channels
        
        
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);
        
        glBindTexture(GL_TEXTURE_2D, 0);
        
        if (localBuffer)
        {
            stbi_image_free(localBuffer);
        }
}

Texture::~Texture()
{
    glDeleteTextures(1, &ID);
}

void Texture::Bind(unsigned int slot)
{
    glActiveTexture(GL_TEXTURE0 + slot);
    
}

void Texture::UnBind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
