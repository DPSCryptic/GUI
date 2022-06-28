#pragma once
#include <JuceHeader.h>

class BedrijvenComponent : public juce::Component
{
	void paint(juce::Graphics&) override;
	void resized() override;
};