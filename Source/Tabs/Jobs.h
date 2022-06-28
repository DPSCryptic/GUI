#pragma once
#include <JuceHeader.h>

using namespace juce;

class JobsComponent : public juce::Component
{
	void paint(juce::Graphics&) override;
	void resized() override;
};