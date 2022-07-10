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
		cout << name << " 파일 크기 : " << size << "\n";
		return size;
	}

	void remove() override {
		cout << name << " 파일 삭제\n";
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
		cout << name << " 폴더 크기 : " << total << "\n";
		cout << "- - - - - - -\n";
		return total;
	}

	void remove() override{
		while(!includeds.empty()) {
			includeds.pop_back();
		}
		cout << name << " 폴더 삭제\n";
		cout << "- - - - - - -\n";
	}
};

int main() {
	Folder* schoolFolder = new Folder("학교");

	Folder* grade1Folder = new Folder("1학년");
	Folder* grade2Folder = new Folder("2학년");

	schoolFolder->add(grade1Folder);
	schoolFolder->add(grade2Folder);

	File* enterPhoto = new File("입학사진", 256);
	grade1Folder->add(enterPhoto);

	Folder* sem1Folder = new Folder("1학기");
	Folder* sem2Folder = new Folder("2학기");

	grade2Folder->add(sem1Folder);
	grade2Folder->add(sem2Folder);

	File* lecturePlan = new File("강의계획서", 120);
	sem1Folder->add(lecturePlan);

	Folder* projFolder = new Folder("프로젝트");
	sem2Folder->add(projFolder);

	File* draft = new File("드래프트", 488);
	File* finalResult = new File("결과물", 560);

	projFolder->add(draft);
	projFolder->add(finalResult);
	
	schoolFolder->getSize();
	return 0;
}