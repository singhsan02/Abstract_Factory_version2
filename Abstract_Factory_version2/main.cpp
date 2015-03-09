#include <iostream>
using namespace std;

class Button{
public:
	virtual void paint() = 0;
};

class WindowsButton : public Button{
public:
	void paint(){
		cout << "Windows Paint Button" << endl;
	}
};

class MacButton : public Button{
public:
	void paint(){
		cout << "Mac Paint Button" << endl;
	}
};

class ScrollBar{
public:
	virtual void paint() = 0;
};

class WindowsScrollBar : public ScrollBar{
public:
	void paint(){
		cout << "Windows ScrollBar" << endl;
	}
};

class MacScrollBar : public ScrollBar{
public:
	void paint(){
		cout << "Mac ScrollBar" << endl;
	}
};

class GUIFactory{
public:
	virtual Button* createButton() = 0;
	virtual ScrollBar* createScrollBar() = 0;
};

class WinFactory : public GUIFactory{
public:
	virtual Button* createButton(){
		return new WindowsButton;
	}

	virtual ScrollBar* createScrollBar(){
		return new WindowsScrollBar;
	}
};

class MacFactory : public GUIFactory{
public:
	virtual Button* createButton(){
		return new MacButton;
	}

	virtual ScrollBar* createScrollBar(){
		return new MacScrollBar;
	}
};


int main(){
	//Factory  
	GUIFactory *guifactory;
	Button     *button;
	ScrollBar   *scrollbar;

	guifactory = new WinFactory();
	guifactory->createButton()->paint();
	guifactory->createScrollBar()->paint();

	guifactory = new MacFactory();

	button = guifactory->createButton();
	button->paint();

	scrollbar = guifactory->createScrollBar();
	scrollbar->paint();


	system("pause");
	return 0;
}