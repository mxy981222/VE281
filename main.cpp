#include"sort.h"
#include<time.h>
using namespace std;
/*
bool joj_sort(int* a, int n) {
	for (int i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			return false;
		}
	}
	return true;
}
bool joj_select(int* a, int n, int res, int i) {
	bubble_sort(a, n);
	if (res == a[i]) return true;
	return false;
}*/
int main() {
	clock_t t;
	int method = 0;
	cin >> method;
	int length = 0;
	cin >> length;
	int* a = new int[length] {0};
	int* temp = new int[length] {0};
	if (method >= 0 && method <= 4) {
		for (int i = 0; i < length; i++) {
			cin >> a[i];
		}
		t=clock();
		if (method == 0) {
			bubble_sort(a, length);
		}
		if (method == 1) {
			insertion_sort(a, length);
		}
		if (method == 2) {
			selection_sort(a, length);
		}
		if (method == 3) {
			merge_sort(a, 0, length - 1, temp);
		}
		if (method == 4) {
			quick_sort(a, 0, length - 1);
		}
		for (int i = 0; i < length; i++) {
			cout << a[i] << endl;
		}
		t = clock() - t;
		cout << (float)t)/CLOCKS_PER_SEC << endl;
		//cout << joj_sort(a, length) << endl;
	}
	else {
		int index = 0;
		cin >> index;
		int res = 0;
		for (int i = 0; i < length; i++) {
			cin >> a[i];
		}
		if (method == 5) {
			res = RSelect(a, 0, length - 1, index);
		}
		if (method == 6) {
			res = DSelect(a, 0, length - 1, index);
		}
		cout << "The order-" << index << " item is " << res << endl;
		t = clock() - t;
		cout << (float)t)/CLOCKS_PER_SEC << endl;
		//cout << joj_select(a, length, res, index) << endl;
	}
}
