#include "GUIFactory.h"

MacFactory* MacFactory::macfactory = nullptr;

WinFactory* WinFactory::winfactory = nullptr;

WinFactory*
WinFactory::getWinFactory() {
	if (winfactory == nullptr)
		winfactory = new WinFactory;
	return winfactory;
}

MacFactory*
MacFactory::getMacFactory() {
	if (macfactory == nullptr)
		macfactory = new MacFactory;
	return macfactory;
}

void
Application::CreateUI() {
	button = factory->CreateButton();
	checkbox = factory->CreateCheckBox();
}

void
Application::paint() {
	button->paint();
	checkbox->paint();
}
