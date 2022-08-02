#include <iostream>

using namespace std;

class Fighter {
public:
	virtual void attack() = 0;
};

class XWingFiter : public Fighter {
public:
	void attack() override {
		cout << "źȯ �߻�" << "\n";
	}
};

class FighterDecorator : public Fighter {
private:
	Fighter* decoratedFighter;
public:
	FighterDecorator(Fighter* _decoratedFighter) 
		: decoratedFighter(_decoratedFighter) { }
	void attack() override{
		decoratedFighter->attack();
	}

	virtual ~FighterDecorator() {
		cout << "�θ� �Ҹ���" << "\n";
	}
};

class LaserDecorator : public FighterDecorator {
public:
	LaserDecorator(Fighter* _decoratedFighter)
		: FighterDecorator(_decoratedFighter) { }
	void attack() override {
		FighterDecorator::attack();
		cout << "������ �߻�" << "\n";
	}
	~LaserDecorator() {
		cout << "������ �Ҹ���" << "\n";
	}
};

class MissileDecorator : public FighterDecorator {
public:
	MissileDecorator(Fighter* _decoratedFighter)
		: FighterDecorator(_decoratedFighter) { }
	void attack() override {
		FighterDecorator::attack();
		cout << "�̻��� �߻�" << "\n";
	}
};

class PlasmaDecorator : public FighterDecorator {
public:
	PlasmaDecorator(Fighter* _decoratedFighter)
		: FighterDecorator(_decoratedFighter) { }
	void attack() override {
		FighterDecorator::attack();
		cout << "�ö�� �߻�" << "\n";
	}
};

class FighterFactory {
public:
	Fighter* getFighter(bool laser, bool missile, bool plasma) {
		Fighter* fighter = new XWingFiter();
		
		if (laser) fighter = new LaserDecorator(fighter);
		if (missile) fighter = new MissileDecorator(fighter);
		if (plasma) fighter = new PlasmaDecorator(fighter);
		return fighter;
	}
};

int main() {
	// without Factory
	XWingFiter* xwf = new XWingFiter();
	xwf->attack(); cout << "\n";

	LaserDecorator* ld = new LaserDecorator(xwf);
	ld->attack(); 
	delete ld;
	cout << "\n";
	
	FighterDecorator* fd = new PlasmaDecorator(
		new MissileDecorator(
			new LaserDecorator(
				new XWingFiter())));
	fd->attack(); cout << "\n";

	// with Factory
	FighterFactory* factory = new FighterFactory();
	factory->getFighter(false, false, false)->attack(); cout << "\n";
	factory->getFighter(true, false, false)->attack(); cout << "\n";
	factory->getFighter(false, true, false)->attack(); cout << "\n";
	factory->getFighter(true, false, true)->attack(); cout << "\n";
	factory->getFighter(true, true, true)->attack(); cout << "\n";
	
	return 0;
}