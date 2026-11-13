#include <iostream>
using namespace std;

#include "setcolor.h"

void setColor(int color) { cout << "\033[" << color << "m"; }