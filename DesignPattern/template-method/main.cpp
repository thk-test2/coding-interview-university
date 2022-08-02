#include <iostream>

using namespace std;

class MapView {
public:
	virtual void connectMapServer() = 0;
	virtual void showMapOnScreen() = 0;
	virtual void moveToCurrentLocation() = 0;

	void initMap() {
		connectMapServer();
		showMapOnScreen();
		moveToCurrentLocation();
	}
};

class NaverMapView : public MapView {
public:
	virtual void connectMapServer() override {
		cout << "���̹� ���� ������ ����" << "\n";
	};
	virtual void showMapOnScreen() override {
		cout << "���̹� ������ ������" << "\n";
	};
	virtual void moveToCurrentLocation() override {
		cout << "���̹� �������� �� ��ǥ�� �̵�" << "\n";
	};
};

class KakaoMapView : public MapView {
public:
	virtual void connectMapServer() override {
		cout << "īī�� ���� ������ ����" << "\n";
	};
	virtual void showMapOnScreen() override {
		cout << "īī�� ������ ������" << "\n";
	};
	virtual void moveToCurrentLocation() override {
		cout << "īī�� �������� �� ��ǥ�� �̵�" << "\n";
	};
};

int main() {
	NaverMapView* nmv = new NaverMapView();
	KakaoMapView* kmv = new KakaoMapView();
	nmv->initMap();
	kmv->initMap();

	return 0;
}