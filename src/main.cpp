/*
• Start: row = 1, col = (size + 1) / 2, data = 1.
• Move: if (data % size == 0) row++; else { row--; col--; }
• Wrap: if (row == 0) row = size; if (col == 0) col = size;
• Loop: do { ... data++; } while (data <= size * size);
• Screen position: gotoxy(col * factor, row * factor).
*/

#include <iostream>
using namespace std;
#include "magicSquare.h"

int main() {
  int size = 0;
  cout << "please enter odd number (3, 5, 7, etc):";
  cin >> size;

  if (size % 2 == 0 || size < 3) {
    cout << "Error: Size must be an odd number >= 3." << endl;
    return 1;
  }

  gotoxy(5, 10);
  magicSquare(size);

  return 0;
}
