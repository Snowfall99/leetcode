#include <iostream>
using namespace std;

int a[10000], b[10000];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}

	a[0] = b[0];
	for (int i = 1; i < N; i++) {
		a[i] = b[i] - b[i - 1];
	}

	for (int i = 0; i < N; i++) {
		cout << a[i] << " ";
	}
  return 0;
}
