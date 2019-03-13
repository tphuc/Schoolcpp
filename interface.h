#pragma once
#include <windows.h>
#include <conio.h>
#include <iostream>



using namespace std;

// functions to work with cursor on screen

void gotoxy(int x, int y); // set the cursor at the location (x, y)
int getx();                // get the cursor x(columns)
int gety();                // get the cursor y(row)
COORD getxy();             // get the COORD{ int X, int Y }
string getLineHidden();





