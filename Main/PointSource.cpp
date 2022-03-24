//
//  PointSource.cpp
//  HelloOpenGl
//
//  Created by Max on 3/19/22.
//

#include <iostream>

#include "PointSource.h"

using namespace std;

PointSource::PointSource(float x, float y, float freq_spatial, float freq_temporal, float amplitude, float* data_pointer, int& empty_slot)
{
    data_index = empty_slot;
    source_data_location = data_pointer;
    
    source_data_location[data_index]     = x;
    source_data_location[data_index + 1] = y;
    source_data_location[data_index + 2] = freq_spatial;
    source_data_location[data_index + 3] = freq_temporal;
    source_data_location[data_index + 4] = amplitude;
    
    empty_slot += 5;
}

void PointSource::UpdateSource(float x, float y)
{
    source_data_location[data_index]     = x;
    source_data_location[data_index + 1] = y;
}

void PointSource::NewSource(float x, float y, float freq_spatial, float freq_temporal, float amplitude)
{
//    source_data[*empty_slot]     = x;
//    source_data[*empty_slot + 1] = y;
//    source_data[*empty_slot + 2] = freq_spatial;
//    source_data[*empty_slot + 3] = freq_temporal;
//    source_data[*empty_slot + 4] = amplitude;
//
//    *empty_slot += 5;
}

