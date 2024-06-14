/*
  ==============================================================================

    KAPPanelBase.h
    Created: 14 Jun 2024 7:58:10am
    Author:  Yassine

  ==============================================================================
*/

#pragma once
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"
class KAPPanelBase
    :
    public Component
{
public:
    KAPPanelBase(AudioPluginAudioProcessor* inProcessor);
    ~KAPPanelBase();

    void paint(Graphics& g) override;

protected:
    AudioPluginAudioProcessor* mProcessor;
};