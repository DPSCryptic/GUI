#pragma once
#include <JuceHeader.h>

using namespace juce;

class ContentComponent : public Component
{
public:
	ContentComponent(Component& contentToDisplay)
		: content(contentToDisplay)
	{
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

		//auto topArea = bounds.removeFromTop(30);
		//titleLabel.setBounds(topArea.reduced(5));

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
		addAndMakeVisible(buttonArea1);
		addAndMakeVisible(buttonArea2);
	}

	//void paint(Graphics&) override;
	void resized() override
	{
		auto bounds = getLocalBounds().reduced(5);

		auto treeViewArea = bounds.removeFromLeft(bounds.getWidth() / 4).reduced(2);
		auto treeViewButtonArea = treeViewArea.removeFromBottom(100).reduced(2);
		auto addButton = treeViewButtonArea.removeFromLeft(treeViewButtonArea.getWidth() / 2);
		auto deleteButton = treeViewButtonArea.removeFromLeft(treeViewButtonArea.getWidth());
		auto editViewArea = bounds.removeFromLeft(bounds.getWidth()).reduced(2);

		treeView.setBounds(treeViewArea);
		editArea.setBounds(editViewArea);
		buttonArea1.setBounds(addButton);
		buttonArea2.setBounds(deleteButton);
	}

private:

	class TreeViewComponent : public Component
	{
	public:
		TreeViewComponent()
		{
			//tree.setRootItem(&root);
			//tree.setRootItemVisible(false);

			addAndMakeVisible(tree);
		}

		void resized() override
		{
			tree.setBounds(getLocalBounds());
		}
	private:



		ListBox tree;

	};

	class EditViewComponent : public Component
	{
	public:
		EditViewComponent()
		{
			addAndMakeVisible(editor);
		}

		void resized() override
		{
			editor.setBounds(getLocalBounds());
		}
	private:

		TextEditor editor;
	};

	class AddButtonViewComponent : public Component
	{
	public:
		AddButtonViewComponent()
		{
			textButton1.setHasFocusOutline(true);
			addAndMakeVisible(textButton1);
		}

		void resized() override
		{
			auto bounds1 = getLocalBounds().removeFromLeft(getLocalBounds().getWidth());
			auto bounds2 = bounds1.removeFromLeft(bounds1.getWidth());

			textButton1.setBounds(bounds2);
		}
	private:
		TextButton textButton1{ "Add" };
	};

	class DeleteButtonViewComponent : public Component
	{
	public:
		DeleteButtonViewComponent()
		{
			textButton1.setHasFocusOutline(true);
			addAndMakeVisible(textButton1);
		}

		void resized() override
		{
			auto bounds1 = getLocalBounds().removeFromLeft(getLocalBounds().getWidth());
			auto bounds2 = bounds1.removeFromLeft(bounds1.getWidth());

			textButton1.setBounds(bounds2);
		}
	private:
		TextButton textButton1{ "Delete" };
	};

	TreeViewComponent treeViewComponent;
	EditViewComponent editViewComponent;
	AddButtonViewComponent addButtonViewComponent;
	DeleteButtonViewComponent deleteButtonViewComponent;

	ContentComponent treeView{ treeViewComponent };
	ContentComponent editArea{ editViewComponent };
	ContentComponent buttonArea1{ addButtonViewComponent };
	ContentComponent buttonArea2{ deleteButtonViewComponent };
};
