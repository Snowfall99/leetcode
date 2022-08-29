#include <iostream>
using namespace std;

int a[10000], b[10000];

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  b[0] = a[0];
  for (int i = 1; i < N; i++) {
    b[i] = b[i - 1] + a[i];
  }
  
  for (int i = 0; i < N; i++) {
    cout << b[i] << " ";
  }
  return 0;
}
