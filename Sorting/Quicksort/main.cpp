#include <iostream>

using namespace std;

int arr[10];
int N;

int partition(int start, int end) {
	int pivot = start, l = start + 1, r = end;

	while (l < r) {
		while (arr[pivot] > arr[l] && l < end) l++;
		while (arr[pivot] < arr[r] && r > 0) r--;
		swap(arr[l], arr[r]);
		swap(r, l);
	}
	swap(arr[pivot], arr[r]);
	return r;
}

void quicksort(int start, int end) {
	if (start < end) {
		int pivot = partition(start, end);
		quicksort(start, pivot - 1);
		quicksort(pivot + 1, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	quicksort(0, N-1);
	for (int i = 0; i < N; ++i) {
		cout << arr[i] << "\n";
	}
	return 0;
}