/*
  ==============================================================================

    KAPTopPanel.h
    Created: 14 Jun 2024 8:02:24am
    Author:  Yassine

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"

class KAPTopPanel
    : public KAPPanelBase
{
    KAPTopPanel(AudioPluginAudioProcessor* inProcessor);
    ~KAPTopPanel();
    void paint(Graphics& g) override;
private:
};