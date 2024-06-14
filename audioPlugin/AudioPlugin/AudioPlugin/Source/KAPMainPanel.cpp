/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 14 Jun 2024 7:59:38am
    Author:  Yassine

  ==============================================================================
*/

#include "KAPMainPanel.h"

KAPMainPanel::KAPMainPanel(AudioPluginAudioProcessor* inProcessor)
    : KAPPanelBase(inProcessor)
{
    setSize(MAIN_PANEL_WIDTH, MAIN_PANEL_HEIGHT);

    mTopPanel = KAPTopPanel(inProcessor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel);
}
KAPMainPanel::~KAPMainPanel()
{

}