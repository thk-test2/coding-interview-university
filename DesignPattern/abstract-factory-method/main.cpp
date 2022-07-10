#include <iostream>

using namespace std;

class Component {
public:
	Component() { cout << "생성: "; }
};

class LightButton : public Component {
public:
	LightButton() { cout << "라이트 버튼\n"; }
};

class LightSwitch : public Component {
public:
	LightSwitch() { cout << "라이트 스위치\n"; }
};

class LightDropdown : public Component {
public:
	LightDropdown() { cout << "라이트 드랍다운\n"; }
};

class DarkButton : public Component {
public:
	DarkButton() { cout << "다크 버튼\n"; }
};

class DarkSwitch : public Component {
public:
	DarkSwitch() { cout << "다크 스위치\n"; }
};

class DarkDropdown : public Component {
public:
	DarkDropdown() { cout << "다크 드랍다운\n"; }
};

enum class Usage {
	PRESS,
	TOGGLE,
	EXPAND
};

class CompFactory {
public:
	virtual Component* getComp(Usage usage) = 0;
};

class LightCompFactory : public CompFactory {
public:
	Component* getComp(Usage usage) override {
		if (usage == Usage::PRESS) return new LightButton();
		else if (usage == Usage::TOGGLE) return new LightSwitch();
		else return new LightDropdown();
	};
};

class DarkCompFactory : public CompFactory {
public:
	Component* getComp(Usage usage) override {
		if (usage == Usage::PRESS) return new DarkButton();
		else if (usage == Usage::TOGGLE) return new DarkSwitch();
		else return new DarkDropdown();
	};
};

int main() {
	// without Factory
	Component* comp1 = new LightButton();
	Component* comp2 = new LightSwitch();
	Component* comp3 = new LightDropdown();
	cout << "\n";

	// with Factory
	LightCompFactory lcf;
	Component* comp4 = lcf.getComp(Usage::PRESS);
	Component* comp5 = lcf.getComp(Usage::TOGGLE);
	Component* comp6 = lcf.getComp(Usage::EXPAND);
	cout << "\n";

	// with Factory
	DarkCompFactory dcf;
	Component* comp7 = dcf.getComp(Usage::PRESS);
	Component* comp8 = dcf.getComp(Usage::TOGGLE);
	Component* comp9 = dcf.getComp(Usage::EXPAND);
	cout << "\n";

	return 0;
}