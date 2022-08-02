#include <iostream>
#include <vector>

using namespace std;

enum class Mode {
	LIST,
	GALLERY
};

class ModeListener {
public:
	virtual void onModeChange(Mode mode) = 0;
};

class ListView : public ModeListener {
public:
	void onModeChange(Mode mode) override { cout << "����Ʈ�� " << (mode == Mode::LIST ? "������" : "����") << "\n"; }
};

class GalleryView : public ModeListener {
public:
	void onModeChange(Mode mode) override { cout << "�������� " << (mode == Mode::GALLERY ? "������" : "����") << "\n"; }
};

class DataDownloader : public ModeListener {
public:
	void onModeChange(Mode mode) override { 
		cout << (mode == Mode::LIST ? "����Ʈ" : "������") << "��� ������ �ٿ�ε�\n";
	}
};

class ModeMediator {
private:
	vector<ModeListener*> listeners;
public:
	void addListener(ModeListener* listener) {
		listeners.push_back(listener);
	}
	void onModeChange(Mode mode) {
		for (auto& listener : listeners) {
			listener->onModeChange(mode);
		}
	}
};

class ModeSwitch {
private:
	Mode mode = Mode::LIST;
	ModeMediator* modeMediator;
public:
	void setModeMediator(ModeMediator* _modeMediator) {
		modeMediator = _modeMediator;
	}
	void toggleMode() {
		mode = (mode == Mode::LIST ? Mode::GALLERY : Mode::LIST);
		modeMediator->onModeChange(mode);
	}
};

int main() {
	ModeSwitch* modeSwitch = new ModeSwitch();
	ModeMediator* modeMediator = new ModeMediator();
	modeSwitch->setModeMediator(modeMediator);

	modeMediator->addListener(new ListView());
	modeMediator->addListener(new GalleryView());
	modeMediator->addListener(new DataDownloader());

	modeSwitch->toggleMode();
	cout << "\n";

	modeSwitch->toggleMode();
	return 0;
}