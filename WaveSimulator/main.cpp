//  main.cpp
//  HelloOpenGl
//
//  Created by Max on 3/4/22.

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <string>

#include <math.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexArray.h"
#include "Shader.h"
#include "Renderer.h"
#include "Texture.h"
#include "Grid.h"
#include "PointSource.h"

using namespace std;

// takes edge lengths of rectangle and x,y coordinates of lower left corner
// fills a provided array of length 8 with the calculated coordinates
void CreateRect(float width, float height, float x, float y, float* vertices)
{
    float coords[8] = {x,        y,            // Lower left
                         x + width, y,            // Lower right
                         x + width, y + height,     // Upper right
                         x,        y + height};    // Upper left
    
    for (unsigned int i=0; i < 8; i++)
        vertices[i] = coords[i];
}

int main(void)
{
    // initialize glfw
    glfwInit();
    
    // provide opengl version information for gl context
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // generate window
    GLFWwindow* window = glfwCreateWindow(700, 700, "my swamp", NULL, NULL);
    if (window==NULL)
    {
        cout << "error creating window" << endl;
    };
    glfwMakeContextCurrent(window);

    // enable use of gl
    gladLoadGL();


    /// CANVAS
    ///
    ///
    ///

    float width = 2.0f;
    float height = 2.0f;
    float corner_x = -1.0f;
    float corner_y = -1.0f;
    
    float vertices[8];

    CreateRect(width, height, corner_x, corner_y, vertices);

    unsigned int indices[] = {
        0, 1, 2, 2, 3, 0
    };

    /// SHADERS
    ///
    ///
    ///
    // specify shader paths in directory
    string vertPath = "/Users/max/XCodeProjects/WaveSimulator/Resources/Shaders/VertShader.vert";
    string fragPath = "/Users/max/XCodeProjects/WaveSimulator/Resources/shaders/FragShader.frag";

    // generate shader program and attach vertex and fragment shaders
    Shader shaderProgram;
    shaderProgram.AddShader(GL_VERTEX_SHADER, vertPath);
    shaderProgram.AddShader(GL_FRAGMENT_SHADER, fragPath);
    shaderProgram.Bind();
    
    /// OBJECTS
    ///
    ///
    ///
    // vertex array object - points to buffer objects so computer can find and switch between them
    VertexArray VAO;
    
    // vertex buffer object - stores vertex array data allocated by the GL context on the GPU
    // element array buffer object - stores index array data
    VertexBuffer VBO(vertices, sizeof(vertices));
    IndexBuffer EBO(indices, sizeof(indices));
    
    // specify how to read vertex array data
    VAO.AttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2, 0);
    
    // vertex buffer is unecessary once bound to vertex array
    VBO.UnBind();
    
    /// RENDERING
    ///
    ///
    ///
    // create renderer used for drawing shapes
    Renderer renderer(VAO, EBO, shaderProgram);
    // create time variable
    float t = 0.0f;
    // update screen once per frame
    glfwSwapInterval(1);
    
    // get locations of uniforms
    //
    // timer uniform
    string timer_uniform = "u_time";
    int timer_location = shaderProgram.GetUniformLocation(timer_uniform);
    
    // point source data uniforms
    string source_uniform = "u_source";
    int source_location = shaderProgram.GetUniformLocation(source_uniform);
    
    // number of point sources
    string source_count_uniform = "u_source_count";
    int source_count_location = shaderProgram.GetUniformLocation(source_count_uniform);
    
    // point source data
//    PointSource sources;
//
//    sources.NewSource(1.0f, 2.5f, 90.0f, 0.1f, 1.0f);
//    sources.NewSource(-0.5f, 2.5f, 2.0f, 0.6f, 1.0f);
//    sources.NewSource(0.4f, 1.35f, 70.0f, 0.2f, 1.0f);
//    sources.NewSource(1.7f, 1.25f, 60.0f, 0.1f, 1.0f);
//
    int source_count = 1;


    
    float source_data[200];
    
    
    for ( int i=0; i<size(source_data); i++) {
        source_data[i] = 0;
    }
    
    source_data[0] = 1.0f;
    source_data[1] = 1.0f;
    source_data[2] = 90.0f;
    source_data[3] = 0.1f;
    source_data[4] = 1.0f;
    
    glUniform1fv(source_location, size(source_data), source_data);
    glUniform1i(source_count_location, source_count);

    
    // set background color - must be float array of length 4
    float bgColor[] = {0.03f, 0.12f, 0.01f, 1.0f};
    
    
    // loop to keep window open
    while (!glfwWindowShouldClose(window))
    {
        /// rendering
        ///
        ///
        ///
        // update time variable
        t += 0.03f;
        glUniform1f(timer_location, t);
        
        // draw shapes and background
        renderer.Background(bgColor);
        renderer.Draw(VAO, EBO, shaderProgram);

        
        /// updating window
        ///
        ///
        ///
        // swap buffers to update view
        glfwSwapBuffers(window);
        
        // register window events
        glfwPollEvents();
    }
    
    


    
    EBO.UnBind();

    
    glfwTerminate();
    return 0;
}
