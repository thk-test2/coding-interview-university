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
		cout << "네이버 지도 서버에 연결" << "\n";
	};
	virtual void showMapOnScreen() override {
		cout << "네이버 지도를 보여줌" << "\n";
	};
	virtual void moveToCurrentLocation() override {
		cout << "네이버 지도에서 현 좌표로 이동" << "\n";
	};
};

class KakaoMapView : public MapView {
public:
	virtual void connectMapServer() override {
		cout << "카카오 지도 서버에 연결" << "\n";
	};
	virtual void showMapOnScreen() override {
		cout << "카카오 지도를 보여줌" << "\n";
	};
	virtual void moveToCurrentLocation() override {
		cout << "카카오 지도에서 현 좌표로 이동" << "\n";
	};
};

int main() {
	NaverMapView* nmv = new NaverMapView();
	KakaoMapView* kmv = new KakaoMapView();
	nmv->initMap();
	kmv->initMap();

	return 0;
}