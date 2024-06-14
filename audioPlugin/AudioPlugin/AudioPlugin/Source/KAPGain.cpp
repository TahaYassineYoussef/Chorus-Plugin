/*
  ==============================================================================

    KAPGain.cpp
    Created: 13 Jun 2024 9:14:00am
    Author:  Yassine

  ==============================================================================
*/

#include "KAPGain.h"
#include "JuceHeader.h"
KAPGain::KAPGain() {

}
KAPGain :: ~KAPGain() {

}

void KAPGain::process(float* inAudio,
    float inGain,
    float* outAudio
    int inNumSamplestoRender)
{

    float gainMapped = jmap(inGain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = Decibels::decibelsToGain(gainMapped, -24.0f);
    for (int i = 0; i < inNumSamplestoRender; ++i) {
        outAudio[i] = inAudio[i] * gainMapped ;
    };
}
