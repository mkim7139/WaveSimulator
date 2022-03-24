//
//  Grid.c
//  HelloOpenGl
//
//  Created by Max on 3/10/22.
//

#include <iostream>


#include "Grid.h"

using namespace std;

Grid::Grid(float width, float height, float x_corner, float y_corner, unsigned int rows, unsigned int columns)
{
    // initialize row and column counts
    row_count = rows;
    col_count = columns;
    
    cout << row_count << endl;
    cout << col_count << endl;
    
    // initialize vertices and indices by insuring all values are 0
    for (unsigned int i=0; i < size(vertices); i++) {
        vertices[i]=0;
    }

    for (unsigned int i=0; i < size(indices); i++) {
        indices[i]=0;
    }
    
    // initializes first few values of indices to show the order of the vertices
    unsigned int base[6] = { 0, 1, col_count + 2, col_count + 2, col_count + 1, 0};
    
    for (unsigned int j=0; j < row_count; j++) {
        for (unsigned int i=0; i < col_count; i++) {
            for (unsigned int k=0; k < 6; k++) {
                indices[6 * (i + col_count*j) + k] = base[k] + i + (col_count+1)*j;
            }
        }
    }

    
    // charactaristics of individual square on grid
    float x_vertex;
    float y_vertex;
    
    float square_width = width / col_count;
    float square_height = height / row_count;
    
    unsigned int vertex_index=0; // index of value within vertices
    
    // generate vertex data
    // format:
    // coordinates   /   isPointSrc   /   freq_spatial   /    freq_temporal    /    amplitude
    //   0, 0,               0,                0,                  0,                   0
    //
    for (unsigned int j=0; j <= row_count; j++) {
        for (unsigned int i=0; i < 6*(col_count + 1); i++) {
            
            // set every i==n*6 to x coord, every i==n*7 to y coord
            if( vertex_index%6 == 0) {
                x_vertex = x_corner + (i / 6) * square_width;
                y_vertex = y_corner + j * square_height;

                vertices[vertex_index] = x_vertex;
                vertices[vertex_index + 1] = y_vertex;
            }
            vertex_index++; // index must be updated at end to allow for easy indexing of vertices array
        }
    }
}

void Grid::PointSource(float x_cent, float y_cent, float freq_spatial, float freq_temp)
{
    // find line of data in vertices array corresponding to x, y cent. input data
    
    unsigned int vertex_index=0; // index of value within vertices
    
    // generate vertex data
    // format:
    // coordinates   /   isPointSrc   /   freq_spatial   /    freq_temporal    /    amplitude
    //   0, 0,               0,                0,                  0,                   0
    //
    for ( unsigned int j=0; j <= row_count; j++ ) {
        for ( unsigned int i=0; i < 6*(col_count + 1); i++ ) {

            // every i==n*6 and i==n*7 correspond to x and y coords
            if ( vertex_index%6 == 0 ) {
//                pass;
            }
            vertex_index++; // index must be updated at end to allow for easy indexing of vertices array
        }
    }
}

float* Grid::GetVertices()
{
    return vertices;
}

unsigned int* Grid::GetIndices()
{
    return indices;
}

unsigned int Grid::SizeOfVertices()
{
    return sizeof(vertices);
}

unsigned int Grid::SizeOfIndices()
{
    return sizeof(indices);
}
