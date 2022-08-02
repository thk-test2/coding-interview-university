#include <iostream>
#include <vector>

using namespace std;

class Thumbnail {
public:
	virtual void showTitle() = 0;
	virtual void showPreview() = 0;
};

class RealThumbnail : public Thumbnail {
private:
	string title;
	string movieUrl;
public:
	RealThumbnail(string _title, string _movieUrl) 
		: title(_title), movieUrl(_movieUrl) {
		cout << movieUrl << "�κ���" << title << "�� ���� ������ �ٿ�" << "\n";
	}
	void showTitle() override { cout << "����: " << title << "\n"; }
	void showPreview() override { cout << title << "�� ������ ���" << "\n"; }
};

class ProxyThumbnail : public Thumbnail {
private:
	string title;
	string movieUrl;
	RealThumbnail* realThumbnail = nullptr;
public:
	ProxyThumbnail(string _title, string _movieUrl) 
		: title(_title), movieUrl(_movieUrl) { }
	
	void showTitle() override { cout << "����: " << title << "\n"; }
	void showPreview() override { 
		if (realThumbnail == nullptr)
			realThumbnail = new RealThumbnail(title, movieUrl);

		realThumbnail->showPreview();
	}
};

int main() {
	vector<Thumbnail*> thumbnails;
	thumbnails.push_back(new ProxyThumbnail("Git ����", "/git.mp4"));
	thumbnails.push_back(new ProxyThumbnail("Rest API��?", "/rest-api.mp4"));
	thumbnails.push_back(new ProxyThumbnail("��Ŀ ����", "/docker.mp4"));

	for (auto& thumbnail : thumbnails)
		thumbnail->showTitle();

	thumbnails[0]->showPreview();
	thumbnails[1]->showPreview();
	thumbnails[2]->showPreview();

	return 0;
}