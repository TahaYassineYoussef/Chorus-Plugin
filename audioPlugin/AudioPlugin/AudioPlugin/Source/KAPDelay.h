/*
  ==============================================================================

    KAPDelay.h
    Created: 13 Jun 2024 9:14:36am
    Author:  Yassine

  ==============================================================================
*/

#pragma once
#include "AudioPluginHelpers.h"

class KAPDelay {

public : 
    KAPDelay();
    ~KAPDelay();

    void setSampleRate(double inSampleRate);
    void reset();

    void process(float* inAudio,
        float inTime,
        float inFeedback,
        float inWetDry,
        float* inModulationBuffer,
        float* outAudio,
        int inNumSamplesToRender);

private:
    double getInterpolatedSample(float inDelayTimeInSamples);
    double mSampleRate;
    double mBuffer[maxBufferDelaySize];
    double mFeedbackSample;

    float mTimeSmoothed;
    int mDelayIndex;
};