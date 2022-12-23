#pragma once

// https://refactoring.guru/ru/design-patterns/abstract-factory
//++ singleTon for factory

#include<iostream>
#include<string>

class Button abstract {
public:
	virtual ~Button() {}
	virtual void paint() abstract;
};

class WinButton : public Button {
public:
	void paint() override final { std::cout << "\nWinButton create!"; }
};

class MacButton : public Button {
public:
	void paint() override final { std::cout << "\nMacButton create!"; }
};

class CheckBox abstract {
public:
	virtual ~CheckBox() {}
	virtual void paint()abstract;
};

class WinCheckBox : public CheckBox {
public:
	void paint()override final { std::cout << "\nWinCheckBox create!"; }
};

class MacCheckBox : public CheckBox {
public:
	void paint()override final { std::cout << "\nMacCheckBox create!"; }
};

class GUIFactory abstract {
public:
	virtual ~GUIFactory() {}
	virtual Button* CreateButton() abstract;
	virtual CheckBox* CreateCheckBox() abstract;
};


class WinFactory : public GUIFactory {
protected:
	WinFactory() {}
	static WinFactory* winfactory;
public:
	static WinFactory* getWinFactory();
public:
	virtual Button* CreateButton() override final { return new WinButton; };
	virtual CheckBox* CreateCheckBox() override final { return new WinCheckBox; };
};

class MacFactory : public GUIFactory {
protected:
	MacFactory() {}
	static MacFactory* macfactory;
public:
	static MacFactory* getMacFactory();
public:
	virtual Button* CreateButton() override final { return new MacButton; };
	virtual CheckBox* CreateCheckBox() override final { return new MacCheckBox; }
};

class Application {
private:
	Button * button;
	CheckBox* checkbox;
	GUIFactory* factory;
public:
	Application(GUIFactory* Factory) : factory(Factory) {}
	void CreateUI();
	void paint();
};
