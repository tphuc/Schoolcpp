#include "csvhelper.h"

vector< vector<string> > readCSV(string path){
    ifstream in(path);

    string line, field;

    vector< vector<string> > array;  // the 2D array
    vector<string> v;                // array of values for one line only

    while ( getline(in,line) )    // get next line in file
    {
        v.clear();
        stringstream ss(line);

        while (getline(ss,field,','))  // break line into comma delimitted fields
        {
            v.push_back(field);  // add each field to the 1D array
        }

        array.push_back(v);  // add the 1D array to the 2D array
    }
    return array;
}



void outputCSV(vector< vector<string> > data){
    for (size_t i=0; i<data.size(); ++i)
    {
        for (size_t j=0; j<data[i].size(); ++j)
        {
            cout << data[i][j] << "|"; // (separate fields by |)
        }
        cout << "\n";
    }
}