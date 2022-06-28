#pragma once
#include <JuceHeader.h>

using namespace juce;

class BedrijvenComponent : public Component
{
	void paint(Graphics&) override;
	void resized() override;
};