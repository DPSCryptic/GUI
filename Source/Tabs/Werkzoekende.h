#pragma once
#include <JuceHeader.h>

using namespace juce;

class ContentComponent : public Component
{
public:
	ContentComponent(const String& title, Component& contentToDisplay)
		: titleLabel ({}, title), content(contentToDisplay)
	{
		addAndMakeVisible(titleLabel);
		addAndMakeVisible(content);
	}

private:
	Label titleLabel;
	Component& content;
};

class WerkzoekendeComponent : public Component
{
public:
	WerkzoekendeComponent()
	{

		addAndMakeVisible(treeView);

	}


	void paint(Graphics&) override;
	void resized() override;


private:
	
	class TreeViewComponent : public Component
	{
	public:
		TreeViewComponent()
		{
			addAndMakeVisible(tree);
		}

		void resized() override
		{
			tree.setBounds(getLocalBounds());
		}
	private:

		TreeView tree;
	};

	TreeViewComponent treeViewComponent;
	ContentComponent treeView{"TreeView", treeViewComponent};
};