#pragma once
#include <JuceHeader.h>

using namespace juce;

class WerkzoekendeComponent : public Component
{
public:

	Werkzoekende();

	void paint(juce::Graphics&) override;
	void resized() override;

private:
	juce::TreeView treeView;

};