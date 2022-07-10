#include <iostream>

using namespace std;

class Component {
public:
	Component() { cout << "생성: "; }
	virtual void press() = 0;
};

class Button : public Component {
public:
	Button() { cout << "버튼\n"; }
	void press() override { cout << "버튼 눌림\n"; }
};

class Switch : public Component {
public:
	Switch() { cout << "스위치\n"; }
	void press() override { cout << "스위치 눌림\n"; }
};

class Dropdown : public Component {
public:
	Dropdown() { cout << "드랍다운\n"; }
	void press() override { cout << "드랍다운 눌림\n"; }
};

enum class Usage {
	PRESS,
	TOGGLE,
	EXPAND
};

class CompFactory {
public:
	static Component* getComp(Usage usage) {
		if (usage == Usage::PRESS) {
			return new Button();
		} 
		else if (usage == Usage::TOGGLE) {
			return new Switch();
		}
		else {
			return new Dropdown();
		}
	};
};

int main() {
	// without Factory
	Component* comp1 = new Button();
	Component* comp2 = new Switch();
	Dropdown* comp3 = new Dropdown();
	cout << "\n";

	// with Factory
	Component* comp4 = CompFactory::getComp(Usage::PRESS);
	comp4->press();
	Component* comp5 = CompFactory::getComp(Usage::TOGGLE);
	comp5->press();
	Component* comp6 = CompFactory::getComp(Usage::EXPAND);
	comp6->press();

	return 0;
}