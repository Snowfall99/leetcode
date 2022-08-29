#include <iostream>
using namespace std;

int a[100000];

int main() {
	int n, k;
	cin >> n >> k;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int curr = 0;
	int max = 0;
	for (int i = 0; i < k; i++) {
		curr += a[i];
	}

	max = curr;
	for (int i = k; i < n; i++) {
		curr -= a[i - k];
		curr += a[i];
		if (curr > max) {
			max = curr;
		}
	}

	cout << max << endl;
	return 0;
}
