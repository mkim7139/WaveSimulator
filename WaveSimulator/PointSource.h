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
    unsigned int empty_slot;
    float source_data[200];
public:
    PointSource();
    
    void NewSource(float x, float y, float freq_spatial, float freq_temporal, float amplitude);
    int GetDataCount();
    float* GetData();
};
