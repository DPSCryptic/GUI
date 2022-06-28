#pragma once
#include <JuceHeader.h>

using namespace juce;

class ContentComponent : public Component
{
public:
	ContentComponent(const String& title, Component& contentToDisplay)
		: titleLabel({}, title), content(contentToDisplay)
	{
		addAndMakeVisible(titleLabel);
		setTitle(title);
		addAndMakeVisible(content);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Colours::black);
		g.drawRoundedRectangle(getLocalBounds().reduced(2).toFloat(), 5.0f, 3.0f);
	}

	void resized() override
	{
		auto bounds = getLocalBounds().reduced(5);

		auto topArea = bounds.removeFromTop(30);
		titleLabel.setBounds(topArea.reduced(5));

		content.setBounds(bounds);
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
		setTitle("Werkzoekende");
		addAndMakeVisible(treeView);
		addAndMakeVisible(editArea);
	}

	//void paint(Graphics&) override;
	void resized() override
	{
		auto bounds = getLocalBounds().reduced(5);

		auto treeViewArea = bounds.removeFromLeft(bounds.getWidth() / 4).reduced(2);
		auto treeViewButtonArea = treeViewArea.removeFromBottom(10).reduced(2);
		auto editViewArea = bounds.removeFromLeft(bounds.getWidth()).reduced(2);


		treeView.setBounds(treeViewArea);
		editArea.setBounds(editViewArea);
	}

private:

	class TreeViewComponent : public Component
	{
	public:
		TreeViewComponent()
		{
			tree.setRootItem(&root);
			tree.setRootItemVisible(false);

			addAndMakeVisible(tree);
		}

		void resized() override
		{
			tree.setBounds(getLocalBounds());
		}
	private:
		struct RootItem : public TreeViewItem
		{
			RootItem()
			{
				struct Item : public TreeViewItem
				{
					Item(int index, int depth, int numSubItems)
						: textToDisplay("Item " + String(index)
							+ ". Depth: " + String(depth)
							+ ". Num sub-items: " + String(numSubItems))
					{
						for (int i = 0; i < numSubItems; ++i)
							addSubItem(new Item(i,
								depth + 1,
								Random::getSystemRandom().nextInt(jmax(0, 5 - depth))));
					}

					bool mightContainSubItems() override
					{
						return getNumSubItems() > 0;
					}

					void paintItem(Graphics& g, int width, int height) override
					{
						if (isSelected())
						{
							g.setColour(Colours::yellow.withAlpha(0.3f));
							g.fillRect(0, 0, width, height);
						}

						g.setColour(Colours::black);
						g.drawRect(0, height - 1, width, 1);

						g.setColour(Colours::white);
						g.drawText(textToDisplay, 0, 0, width, height, Justification::centredLeft);
					}

					String getAccessibilityName() override { return textToDisplay; }

					const String textToDisplay;
				};

				for (int i = 0; i < 10; ++i)
					addSubItem(new Item(i, 0, Random::getSystemRandom().nextInt(10)));
			}

			bool mightContainSubItems() override
			{
				return true;
			}
		};
		TreeView tree;
		RootItem root;
	};

	class EditViewComponent : public Component
	{
	public:
		EditViewComponent()
		{
			tree.setRootItem(&root);
			tree.setRootItemVisible(false);

			addAndMakeVisible(tree);
		}

		void resized() override
		{
			tree.setBounds(getLocalBounds());
		}
	private:
		struct RootItem : public TreeViewItem
		{
			RootItem()
			{
				struct Item : public TreeViewItem
				{
					Item(int index, int depth, int numSubItems)
						: textToDisplay("Item " + String(index)
							+ ". Depth: " + String(depth)
							+ ". Num sub-items: " + String(numSubItems))
					{
						for (int i = 0; i < numSubItems; ++i)
							addSubItem(new Item(i,
								depth + 1,
								Random::getSystemRandom().nextInt(jmax(0, 5 - depth))));
					}

					bool mightContainSubItems() override
					{
						return getNumSubItems() > 0;
					}

					void paintItem(Graphics& g, int width, int height) override
					{
						if (isSelected())
						{
							g.setColour(Colours::yellow.withAlpha(0.3f));
							g.fillRect(0, 0, width, height);
						}

						g.setColour(Colours::black);
						g.drawRect(0, height - 1, width, 1);

						g.setColour(Colours::white);
						g.drawText(textToDisplay, 0, 0, width, height, Justification::centredLeft);
					}

					String getAccessibilityName() override { return textToDisplay; }

					const String textToDisplay;
				};

				for (int i = 0; i < 10; ++i)
					addSubItem(new Item(i, 0, Random::getSystemRandom().nextInt(10)));
			}

			bool mightContainSubItems() override
			{
				return true;
			}
		};
		TreeView tree;
		RootItem root;
	};

	TreeViewComponent treeViewComponent;
	EditViewComponent editViewComponent;

	ContentComponent treeView{ "TreeView", treeViewComponent };
	ContentComponent editArea{ "EditArea", editViewComponent };
};
