#include <iostream>

using namespace std;

#include <cstdio>

#include "MagicSquare.h"
#include "setcolor.h"

int readSize() {
  int n;
  bool valid = false;  // 3ashan ana lesa mkhdtesh input

  while (!valid) {
    cout << "Please enter the size of the square: ";

    if (!(cin >> n)) {
      cout << "Invalid input! Enter numbers only.\n";

      cin.clear();  // return to default state
      cin.ignore(1000, '\n');
    } else {
      cin.ignore(1000, '\n');

      if (n < 3 || n > MAX_SIZE) {
        cout << "Size must be between 3 and " << MAX_SIZE << ".\n";
      } else if (n % 2 == 0) {
        cout << "Size must be an odd number (3, 5, 7, ...).\n";
      } else {
        valid = true;
      }
    }
  }

  return n;
}

int main() {
  int n = readSize();

  int square[MAX_SIZE][MAX_SIZE];

  buildMagicSquare(square, n);

  if (verifyMagicSquare(square, n)) {
    int sum = n * (n * n + 1) / 2;

    cout << "\nDone! Every row, column and diagonal sums to " << sum << ".\n";
  } else {
    cout << "\nError: The Magic Square is invalid!\n";
  }

  return 0;
}