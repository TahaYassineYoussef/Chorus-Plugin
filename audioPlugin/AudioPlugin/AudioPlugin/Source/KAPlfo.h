/*
  ==============================================================================

    KAPlfo.h
    Created: 13 Jun 2024 9:13:45am
    Author:  Yassine

  ==============================================================================
*/

#pragma once
#include"AudioPluginHelpers.h"
class KAPlfo
{
public :
    KAPlfo();
    ~KAPlfo();

    void reset();

    void setSampleRate(double inSampleRate);

    void process(float inRate, float inDepth, int inNumSamples);

    float* getBuffer();
private : 
    double mSampleRate;
    float mPhase;
    float mBuffer(192000);
};