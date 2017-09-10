#include <iostream>
#define INFINITY 1000000

using namespace std;

// ≤Â»Î≈≈–Ú
void INSERT_SORT(int *a, int n) {
	for (int i = 1; i < n; ++i) {
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && key < a[j]) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

// √∞≈›≈≈–Ú
void PUPPY_SORT(int *a, int n) {
	for (int i = 0; i < n; ++i) {
		int flag = 1;
		for (int j = 0; j < n - i - 1; ++j) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag) return;
	}
}

// πÈ≤¢≈≈–Ú
void MERGE(int *a, int p, int q, int r) {
	int nl = q - p + 1;
	int nr = r - q;

	int i, j;

	int *cl = new int[nl + 1];
	int *cr = new int[nr + 1];

	for (i = 0; i < nl; ++i) cl[i] = a[i + p];
	for (i = 0; i < nr; ++i) cr[i] = a[i + q + 1];

	cl[nl] = INFINITY;
	cr[nr] = INFINITY;

	i = 0, j = 0;

	for (int k = p; k <= r; ++k) {
		if (cl[i] < cr[j]) {
			a[k] = cl[i];
			i++;
		}
		else {
			a[k] = cr[j];
			j++;
		}
	}
}

void MERGE_SORT(int *a, int l, int r) {
	if (r > l) {
		int m = (l + r) / 2;
		MERGE_SORT(a, l, m);
		MERGE_SORT(a, m + 1, r);
		MERGE(a, l, m, r);
	}
}


int main() {
	//int *a = new int[10];
	int a[10] = { 1, 234, 11, 23, 77, 99, -1, 34, 987, -433987 };
	//for (int i = 0; i < 10; ++i) cin >> a[i];

	//INSERT_SORT(a, 10);
	//PUPPY_SORT(a, 10);
	MERGE_SORT(a, 0, 9);
	for (int i = 0; i < 10; ++i) cout << a[i] << ' ';
	cout << endl;
}