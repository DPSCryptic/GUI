#pragma once
#include <JuceHeader.h>

using namespace juce;

class WerkzoekendeComponent : public Component
{
public:
	void paint(juce::Graphics&) override;
	void resized() override;

};