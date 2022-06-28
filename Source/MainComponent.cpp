#include "MainComponent.h"
#include "Tabs/Werkzoekende.h"
//==============================================================================
MainComponent::MainComponent()
	{

		const auto tabColour = getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId).darker(0.1f);
		juce::String title = tabs.getTitle();

		tabs.addTab("Tab 1", tabColour, &werkzoekendeComponent, false);
		tabs.addTab("Tab 2", tabColour, &bedrijvenComponent, false);
		tabs.addTab("Tab 3", tabColour, &jobsComponent, false);

		addAndMakeVisible(tabs);
		setSize(1000, 800);
	}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint(juce::Graphics& g)
{
	// (Our component is opaque, so we must completely fill the background with a solid colour)
	g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
	tabs.setBounds(getLocalBounds());
}