#include <iostream>
#include <vector>

using namespace std;

class FileSystem {
public:
	virtual int getSize() = 0;
	virtual void remove() = 0;
};

class File : public FileSystem {
private:
	string name;
	int size;
public:
	File(string _name, int _size)
		: name(_name), size(_size) { }

	int getSize() override {
		cout << name << " ���� ũ�� : " << size << "\n";
		return size;
	}

	void remove() override {
		cout << name << " ���� ����\n";
	}
};

class Folder : public FileSystem {
private:
	string name;
	vector<FileSystem*> includeds;
public:
	Folder(string _name) : name(_name) { }
	void add(FileSystem* fileSystem) { includeds.push_back(fileSystem); }

	int getSize() override {
		int total = 0;
		for (auto& included : includeds) {
			total += included->getSize();
		}
		cout << name << " ���� ũ�� : " << total << "\n";
		cout << "- - - - - - -\n";
		return total;
	}

	void remove() override{
		while(!includeds.empty()) {
			includeds.pop_back();
		}
		cout << name << " ���� ����\n";
		cout << "- - - - - - -\n";
	}
};

int main() {
	Folder* schoolFolder = new Folder("�б�");

	Folder* grade1Folder = new Folder("1�г�");
	Folder* grade2Folder = new Folder("2�г�");

	schoolFolder->add(grade1Folder);
	schoolFolder->add(grade2Folder);

	File* enterPhoto = new File("���л���", 256);
	grade1Folder->add(enterPhoto);

	Folder* sem1Folder = new Folder("1�б�");
	Folder* sem2Folder = new Folder("2�б�");

	grade2Folder->add(sem1Folder);
	grade2Folder->add(sem2Folder);

	File* lecturePlan = new File("���ǰ�ȹ��", 120);
	sem1Folder->add(lecturePlan);

	Folder* projFolder = new Folder("������Ʈ");
	sem2Folder->add(projFolder);

	File* draft = new File("�巡��Ʈ", 488);
	File* finalResult = new File("�����", 560);

	projFolder->add(draft);
	projFolder->add(finalResult);
	
	schoolFolder->getSize();
	return 0;
}