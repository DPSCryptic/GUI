#pragma once
#include <JuceHeader.h>

using namespace juce;

class WerkzoekendeComponent : public Component
{

	void paint(Graphics&) override;
	void resized() override;

private:
	TreeView treeView;
};