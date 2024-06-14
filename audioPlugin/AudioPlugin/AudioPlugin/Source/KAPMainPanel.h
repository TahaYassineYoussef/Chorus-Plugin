/*
  ==============================================================================

    KAPMainPanel.h
    Created: 14 Jun 2024 7:59:38am
    Author:  Yassine

  ==============================================================================
*/

#pragma once
#include "KAPPanelBase.h"
#include "KAPTopPanel.h"

class KAPMainPanel
    : public KAPPanelBase
{
public:
    KAPMainPanel(AudioPluginAudioProcessor* inProcessor);
    ~KAPMainPanel();

private:

    ScopedPointer<KAPTopPanel> mTopPanel;
};