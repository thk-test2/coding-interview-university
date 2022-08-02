#include <iostream>

using namespace std;

class Component {
public:
	Component() { cout << "����: "; }
	virtual void press() = 0;
};

class Button : public Component {
public:
	Button() { cout << "��ư\n"; }
	void press() override { cout << "��ư ����\n"; }
};

class Switch : public Component {
public:
	Switch() { cout << "����ġ\n"; }
	void press() override { cout << "����ġ ����\n"; }
};

class Dropdown : public Component {
public:
	Dropdown() { cout << "����ٿ�\n"; }
	void press() override { cout << "����ٿ� ����\n"; }
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