//
//  PointSource.cpp
//  HelloOpenGl
//
//  Created by Max on 3/19/22.
//

#include <iostream>

#include "PointSource.h"

using namespace std;

PointSource::PointSource()
{
    
}

void PointSource::NewSource(float x, float y, float freq_spatial, float freq_temporal, float amplitude)
{
    source_data[empty_slot]     = x;
    source_data[empty_slot + 1] = y;
    source_data[empty_slot + 2] = freq_spatial;
    source_data[empty_slot + 3] = freq_temporal;
    source_data[empty_slot + 4] = amplitude;
    
    empty_slot += 5;
}

int PointSource::GetDataCount()
{
    return size(source_data);
}

float* PointSource::GetData()
{
    return source_data;
}
