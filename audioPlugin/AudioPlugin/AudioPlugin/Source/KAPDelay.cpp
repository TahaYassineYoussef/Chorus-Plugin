/*
  ==============================================================================

    KAPDelay.cpp
    Created: 13 Jun 2024 9:14:36am
    Author:  Yassine

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"
#include "AudioPluginHelpers.h"

KAPDelay::KAPDelay() {

}

KAPDelay::~KAPDelay()
    : mSampleRate(-1),
    mFeedbackSample(0.0),
    mTimeSmoothed(0),
    mDelayIndex(0)
{

}

void KAPDelay::setSampleRate(double inSampleRate)
{
    mSampleRate = inSampleRate;
}

void KAPDelay::reset()
{
    mTimeSmoothed = 0.0f;
    zeromem(mBuffer, (sizeof(double) * maxBufferDelaySize));
}

void KAPDelay::process(float* inAudio,
    float inTime,
    float inFeedback,
    float inWetDry,
    float* inModulationBuffer,
    float* outAudio,
    int inNumSamplesToRender);
{
    const float wet = inWetDry;
    const float dry = 1.0f - Wet;
    const float feedbackMapped = jmap(inFeedback, 0.0f, 1.0f, 0.0f, 0.95f);

    mTimeSmoothed = mTimeSmoothed - kParameterSmoothingCoeff_Generic * (mTimeSmoothed - inTime ));

    for (int i = 0; i < inNumSamplesToRender; i++) {
        const double delayTimeModulation = (0.003 + (0.002 * inModulationBuffer[i]));
        const double delayTimeInSamples = (mTimeSmoothed * mSampleRate);
        const double sample = getInterpolatedSample(delayTimeInSamples);

        mBuffer[mDelayIndex] = inAudio[i] + (mFeedbackSample * feedbackMapped);
        mFeedbackSample = sample; 

        outAudio[i] = (inAudio[i] * dry + sample * wet);

        mDelayIndex = mDelayIndex + 1;

        if (mDelayIndex > maxBufferDelaySize) {
            mDelayIndex = mDelayIndex - maxBufferDelaySize; 
        }
        
    }
    double KAPDelay::getInterpolatedSample(float inDelayTimeInSamples)
    {
        double readPosition = (double)mDelayIndex - inDelayTimeInSamples;
        if (readPosition < 0.0f) {
            readPosition = readPosition + maxBufferDelaySize;
        }

        int index_y0 = (int)readPosition - 1;
        if (index_y0 <= 0) {
            index_y0 = index_y0 + maxBufferDelaySize;
        }

        int index_y1 = readPosition;
        if (index_y1 >= maxBufferDelaySize) {
            index_y1 = index_y1 + maxBufferDelaySize;
        }

        const float sample_y0 = mBuffer[index_y0];
        const float sample_y1 = mBuffer[index_y1];
        const float t = readPosition - (int)readPosition;

        double outSample = kap_linear_interp(sample_y0, sample_y1, t);
        return outSample;
    }
}