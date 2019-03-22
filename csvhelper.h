#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<string>> readCSV(string filepath); // return 2D array
/*[[a0, b0, c0],
   [a1, b1, c1],
   [...],...]
*/
void outputCSV( vector< vector<string> > data); //print the data
