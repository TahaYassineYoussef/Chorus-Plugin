/*
  ==============================================================================

    KAPlfo.cpp
    Created: 13 Jun 2024 9:13:45am
    Author:  Yassine

  ==============================================================================
*/

#include "KAPlfo.h"

KAPlfo::KAPlfo() 
{
    reset();
}

KAPlfo::~KAPlfo()
{

}

void KAPlfo::reset()
{
    mPhase = 0.0f;
    zeromem(mBuffer, sizeof(float) * maxBufferDelaySize);

}

void KAPlfo::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPlfo::process(float inRate, float inDepth, int inNumSamples)
{
    const float rate = jmap(inRate, 0.0f, 1.0f, 0.01f, 10.0f);
    for (int i = 0; i < inNumSamples; i++)
    {
        mPhase = mPhase + (rate / mSampleRate);
    }
    if (mPhase > 1.0f) {
        mPhase = mPhase - 1.0f;
    }
    const float lfoPosition = sinf(mPhase * K2PI) * inDepth;
    mBuffer[i] = lfoPosition;
    }
}
float* KAPlfo::getBuffer() {
    return mBuffer; 
}