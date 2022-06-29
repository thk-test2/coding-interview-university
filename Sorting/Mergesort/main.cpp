#include <iostream>

using namespace std;

int arr[20];
int temp[20];
int N;

void combine(int start, int mid, int end) {
	int l = start, k = start, r = mid + 1;
	while (l <= mid && r <= end) {
		if (arr[l] < arr[r]) temp[k++] = arr[l++];
		else temp[k++] = arr[r++];
	}
	while (l <= mid) temp[k++] = arr[l++];
	while (r <= end) temp[k++] = arr[r++];

	for (int i = start; i <= end; ++i)
		arr[i] = temp[i];
}

void mergesort(int start, int end) {
	if (start < end) {
		int mid = (start + end) / 2;
		mergesort(start, mid);
		mergesort(mid + 1, end);
		combine(start, mid, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> arr[i];
	}
	mergesort(0, N - 1);
	for (int i = 0; i < N; ++i)
		cout << arr[i] << "\n";
	return 0;
}