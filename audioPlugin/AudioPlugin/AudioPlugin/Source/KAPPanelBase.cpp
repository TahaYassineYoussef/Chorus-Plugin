/*
  ==============================================================================

    KAPPanelBase.cpp
    Created: 14 Jun 2024 7:58:10am
    Author:  Yassine

  ==============================================================================
*/

#include "KAPPanelBase.h"
KAPPanelBase::KAPPanelBase(AudioPluginAudioProcessor* inProcessor)
    : mProcessor(inProcessor)
{

}

KAPPanelBase::~KAPPanelBase()
{

}

void KAPPanelBase::paint(Graphics& g)
{
    g.setColor(Colours::whitesmoke);
    g.fillAll;
    g.setColor(Colours::black);
    g.drawRect(1, 1, getWidth() - 1, getHeight()-1,2);


}
