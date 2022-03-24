//
//  PointSource.hpp
//  HelloOpenGl
//
//  Created by Max on 3/19/22.
//

#pragma once

class PointSource
{
private:
    float* source_data_location;    // array containing the dataset of all the point sources
    int data_index;      // the index of the first data item of this point source within the dataset of all the point sources
public:
    PointSource(float x, float y, float freq_spatial, float freq_temporal, float amplitude, float* data_pointer, int& empty_slot);
    
    void UpdateSource(float x, float y);
    void NewSource(float x, float y, float freq_spatial, float freq_temporal, float amplitude);
};
