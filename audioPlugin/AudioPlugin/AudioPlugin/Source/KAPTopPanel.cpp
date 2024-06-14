/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 14 Jun 2024 8:02:24am
    Author:  Yassine

  ==============================================================================
*/

#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(AudioPluginAudioProcessor* inProcessor)
    :KAPPanelBase(inProcessor)
{
    setSize(TOP_PANEL_WIDTH, TOP_PANEL_HEIGHT);
}

KAPTopPanel::~KAPTopPanel()
{

}
void KAPTopPanel::paint(Graphics& g)
{
    KAPPanelBase::paint(g);
    g.drawFittedText("TAHA YASSINE Youssef Audio Plugin", 0, 0, getWidth() -10, getHeight(), Justification::centeredRight, 1);
}