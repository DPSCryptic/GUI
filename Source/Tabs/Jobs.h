#pragma once
#include <JuceHeader.h>

class JobsComponent : public juce::Component
{
	void paint(juce::Graphics&) override;
	void resized() override;
};