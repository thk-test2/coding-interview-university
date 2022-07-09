#include <iostream>

using namespace std;

class ModeSwitch;

class ModeState {
public:
	virtual void toggle(ModeSwitch* modeSwitch) = 0;
};

class ModeStateLight : public ModeState {
	virtual void toggle(ModeSwitch* modeSwitch) override;
};

class ModeStateDark : public ModeState {
	virtual void toggle(ModeSwitch* modeSwitch) override;
};

class ModeSwitch {
private: 
	ModeState* modeState = new ModeStateLight();

public:
	void setState(ModeState* _modeState) { modeState = _modeState; }
	void onSwitch() { modeState->toggle(this); }
};

void ModeStateLight::toggle(ModeSwitch* modeSwitch) {
	cout << "From Light to Dark" << "\n";
	modeSwitch->setState(new ModeStateDark());
}

void ModeStateDark::toggle(ModeSwitch* modeSwitch){
	cout << "From Dark to Light" << "\n";
	modeSwitch->setState(new ModeStateLight());
}

int main() {
	ModeSwitch ms;
	ms.onSwitch();
	ms.onSwitch();
	ms.onSwitch();

	return 0;
}