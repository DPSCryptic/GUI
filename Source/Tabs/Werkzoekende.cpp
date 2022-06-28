#include "Werkzoekende.h"

using namespace juce;

void WerkzoekendeComponent::paint(juce::Graphics& g)
{
    auto bounds = getLocalBounds().reduced(5);

    auto treeViewArea = bounds.removeFromLeft(bounds.getWidth() / 4).reduced(2);
    auto treeViewButtonArea = treeViewArea.removeFromBottom(50).reduced(2);
    auto editArea = bounds.removeFromLeft(bounds.getWidth()).reduced(2);

    g.setColour(Colours::red);
    g.drawRect(editArea, 2.f);
    g.drawRect(treeViewArea, 2.f);
    g.drawRect(treeViewButtonArea, 2.f);

    g.setFont(juce::Font(16.0f));
    g.setColour(juce::Colours::white);
    g.drawText("TreeView Area", treeViewArea, juce::Justification::centred, true);
    g.drawText("Edit Area", editArea, juce::Justification::centred, true);
    g.drawText("Button Area", treeViewButtonArea, juce::Justification::centred, true);
    

}

void WerkzoekendeComponent::resized()
{
}
