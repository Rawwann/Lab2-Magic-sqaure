#ifndef MAGICSQUARE_H
#define MAGICSQUARE_H

const int MAX_SIZE = 15;

void clearScreen();

// display matrix
void printSquare(int square[MAX_SIZE][MAX_SIZE], int n);

// create magic square
void buildMagicSquare(int square[MAX_SIZE][MAX_SIZE], int n);

bool verifyMagicSquare(int square[MAX_SIZE][MAX_SIZE], int n);

#endif