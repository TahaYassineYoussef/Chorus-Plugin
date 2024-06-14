/*
  ==============================================================================

    KAPGain.h
    Created: 13 Jun 2024 9:14:00am
    Author:  Yassine

  ==============================================================================
*/

#pragma once

class KAPGain
{
public : 

    KAPGain();
    ~KAPGain();

    void process(float* inAudio,
                 float inGain,
                 float* outAudio
                 int inNumSamplestoRender);
    
private:
};