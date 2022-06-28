#pragma once

#include <JuceHeader.h>
#include "Tabs/Werkzoekende.h"
#include "Tabs/Jobs.h"
#include "Tabs/Bedrijven.h"

using namespace juce;

//==============================================================================
/*
	This component lives inside our window, and this is where you should put all
	your controls and content.
*/

class MainComponent : public juce::Component
{
public:
	//==============================================================================
	MainComponent();
	~MainComponent() override;

	//==============================================================================
	void paint(juce::Graphics&) override;
	void resized() override;

	WerkzoekendeComponent werkzoekendeComponent;
	BedrijvenComponent bedrijvenComponent;
	JobsComponent jobsComponent;
private:
	//==============================================================================
	// Your private member variables go here...
	juce::TabbedComponent tabs{ juce::TabbedButtonBar::Orientation::TabsAtTop };

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};
