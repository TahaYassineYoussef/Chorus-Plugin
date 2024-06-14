/*
  ==============================================================================

    AudioPluginHelpers.h
    Created: 13 Jun 2024 11:35:57am
    Author:  Yassine

  ==============================================================================
*/

#pragma once
#define kParameterSmoothingCoeff_Generic 0.04 
#define kParameterSmoothingCoeff_Fine 0.002 
const int maxBufferDelaySize = 192000;

const static double KPI = 3.14159265359;
const static double K2PI = 6.283185307179586;
inline float kap_linear_interp(float v0, float v1, float t)
{
    return (1 - t) * v0 + t * v1;
}