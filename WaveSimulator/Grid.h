//
//  Grid.h
//  HelloOpenGl
//
//  Created by Max on 3/10/22.
//

#pragma once

class Grid
{
private:
    unsigned int row_count, col_count;
    // TODO: make size of indices and vertices line up
    float vertices[60000];
    unsigned int indices[60000];
public:
    Grid(float width, float height, float x_corner, float y_corner, unsigned int row_count, unsigned int col_count);
    
    void PointSource(float x_cent, float y_cent, float freq_spatial, float freq_temp);
    
    float* GetVertices();
    unsigned int* GetIndices();
    
    unsigned int SizeOfVertices();
    unsigned int SizeOfIndices();
};
