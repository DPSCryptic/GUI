#include "Jobs.h"

using namespace juce;

void JobsComponent::paint(juce::Graphics& g)
{
	auto bounds = getLocalBounds().reduced(5);

	auto treeViewBedrijven = bounds.removeFromLeft(bounds.getWidth() / 4).reduced(2);
	auto treeViewBeschikbareVacatures = bounds.removeFromLeft(treeViewBedrijven.getWidth()).reduced(2);
	auto treeViewKandidaten = bounds.removeFromLeft(treeViewBedrijven.getWidth()).reduced(2);
	auto treeViewOpties = bounds.removeFromLeft(treeViewBedrijven.getWidth()).reduced(2);

	g.setColour(Colours::red);
	g.drawRect(treeViewBedrijven, 2.f);
	g.drawRect(treeViewBeschikbareVacatures, 2.f);
	g.drawRect(treeViewKandidaten, 2.f);
	g.drawRect(treeViewOpties, 2.f);

	g.setFont(juce::Font(16.0f));
	g.setColour(juce::Colours::white);
	g.drawText("Bedrijven", treeViewBedrijven, juce::Justification::centred, true);
	g.drawText("Beschikbare Vacatures", treeViewBeschikbareVacatures, juce::Justification::centred, true);
	g.drawText("Kandidaten", treeViewKandidaten, juce::Justification::centred, true);
	g.drawText("Opties", treeViewOpties, juce::Justification::centred, true);
}

void JobsComponent::resized()
{
}