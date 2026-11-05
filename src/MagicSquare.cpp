#include "MagicSquare.h"

#include <chrono>   //time
#include <cstdlib>  //system
#include <iomanip>  //setw
#include <iostream>
#include <thread>  //sleep_for

#include "setcolor.h"

using namespace std;

const int DELAY_MS = 100;

void clearScreen() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// void clearScreen() {
//     cout << "\033[2J\033[H";
// }

void printSquare(int square[MAX_SIZE][MAX_SIZE], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (square[i][j] == 0) {
        cout << setw(5) << " ";
      } else {
        int color = 50 + (square[i][j] * 15) % 182;
        // 50 is the starting color code in the ANSI 256-color palette.
        // * 15: Multiplies the number by 15 to change the color value.
        // % 182: Keeps the result within a range from 0 to 181.

        setColor(color);

        cout << setw(5) << square[i][j];

        setColor(COLOR_RESET);
      }
    }
    cout << endl;
  }
}

void buildMagicSquare(int square[MAX_SIZE][MAX_SIZE], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      square[i][j] = 0;
    }
  }

  int row = 0;
  int col = n / 2;

  for (int number = 1; number <= n * n; number++) {
    square[row][col] = number;

    clearScreen();
    cout << "Building the magic square... (" << number << "/" << n * n
         << ")\n\n";
    printSquare(square, n);
    this_thread::sleep_for(chrono::milliseconds(DELAY_MS));

    int newRow = (row - 1 + n) % n;
    int newCol = (col + 1) % n;

    if (square[newRow][newCol] != 0) {
      newRow = (row + 1) % n;
      newCol = col;
    }

    //     int row = 0;
    // int col = 2;
    // int n = 3;
    // (0-1+3)%3
    // (2+1+3)%3

    row = newRow;
    col = newCol;
  }
}

// 3ashan a check en kolo ad b3do
bool verifyMagicSquare(int square[MAX_SIZE][MAX_SIZE], int n) {
  int expectedSum = n * (n * n + 1) / 2;

  for (int i = 0; i < n; i++) {
    int rowSum = 0;
    int colSum = 0;

    for (int j = 0; j < n; j++) {
      rowSum += square[i][j];
      colSum += square[j][i];
    }

    if (rowSum != expectedSum || colSum != expectedSum) {
      return false;
    }
  }

  int diagonal1 = 0;
  int diagonal2 = 0;

  for (int i = 0; i < n; i++) {
    diagonal1 += square[i][i];
    diagonal2 += square[i][n - 1 - i];
  }

  return diagonal1 == expectedSum && diagonal2 == expectedSum;
}