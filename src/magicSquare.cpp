#include <iostream>
using namespace std;

#include "magicSquare.h"
#include "setcolor.h"

void delay(int ms) {
  for (volatile int i = 0; i < ms * 1000000; i++)
    ;
}

void clearScreen() { cout << "\033[2J\033[H" << flush; }

void gotoxy(int x, int y) {
  if (x < 1) x = 1;
  if (y < 1) y = 1;
  cout << "\033[" << y << ";" << x << "H" << flush;
  ;
}

void magicSquare(int size) {
  clearScreen();

  int data = 1;
  int row = 1;
  int col = (size + 1) / 2;  // middle column

  do {
    gotoxy(col * 5, row * 2);

    int color = COLOR_RED + (data % 7);

    setColor(color);
    cout << data << flush;
    setColor(COLOR_RESET);
    delay(150);

    if (data % size == 0) {
      row++;  // down
    } else {
      row--;  // up
      col--;  // left
    }

    // wrapping
    if (row == 0) {
      row = size;
    }
    if (col == 0) {
      col = size;
    }

    data++;
  } while (data <= size * size);

  gotoxy(1, size * 2 + 2);
}