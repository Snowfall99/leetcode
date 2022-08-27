#include <iostream>

int main() {
  int n, na, nb;
  std::cin >> n >> na >> nb;
  
  int ain[na];
  int bin[nb];
  for (int i = 0; i < na; i++) {
    std::cin >> ain[i];
  }
  for (int i = 0; i < nb; i++) {
    std::cin >> bin[i];
  }

  int acount = 0;
  int bcount = 0;
  for (int i = 0; i < n; i++) {
    int a = ain[i % na];
    int b = bin[i % nb];
    if (a == b) {
      continue;
    } else if (a == 0 && b == 1) {
      bcount ++;
    } else if (a == 1 && b == 0) {
      acount ++;
    } else if (a == 0 && b == 2) {
      acount ++;
    } else if (a == 2 && b == 0) {
      bcount ++;
    } else if (a == 0 && b == 3) {
      acount ++;
    } else if (a == 3 && b == 0) {
      bcount ++;
    } else if (a == 0 && b == 4) {
      bcount ++;
    } else if (a == 4 && b == 0) {
      acount ++;
    } else if (a == 1 && b == 2) {
      bcount ++;
    } else if (a == 2 && b == 1) {
      acount ++;
    } else if (a == 1 && b == 3) {
      acount ++;
    } else if (a == 3 && b == 1) {
      bcount ++;
    } else if (a == 1 && b == 4) {
      bcount ++;
    } else if (a == 4 && b == 1) {
      acount ++;
    } else if (a == 2 && b == 3) {
      bcount ++;
    } else if (a == 3 && b == 2) {
      acount ++;
    } else if (a == 2 && b == 4) {
      acount ++;
    } else if (a == 4 && b == 2) {
      bcount ++;
    } else if (a == 3 && b == 4) {
      acount ++;
    } else if (a == 4 && b == 3) {
      bcount ++;
    }
  }

  std::cout << acount << ' ' << bcount << std::endl;
  
  return 0;
}
