#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Sort.h"
#include "merge_sort"
#include <string>
#include <vector>
#include <sstream> 
#include <fstream>

using namespace std;

vector<vector<double>> parse2DCsvFile(string inputFileName) {

    vector<vector<double> > data;
    ifstream inputFile(inputFileName);
    int l = 0;

    while (inputFile) {
        l++;
        string s;
        if (!getline(inputFile, s)) break;
        if (s[0] != '#') {
            istringstream ss(s);
            vector<double> record;

            while (ss) {
                string line;
                if (!getline(ss, line, ','))
                    break;
                try {
                    record.push_back(stof(line));
                }
                catch (const std::invalid_argument e) {
                    cout << "NaN found in file " << inputFileName << " line " << l
                         << endl;
                    e.what();
                }
            }

            data.push_back(record);
        }
    }

    if (!inputFile.eof()) {
        cerr << "Could not read file " << inputFileName << "\n";
        __throw_invalid_argument("File not found.");
    }

    return data;
}


int main(void)
{
    //probando  merge
    std::vector<int> arr {5, 12, 11, 5, 4, 3, 2, 1, 6};

    merge_sort(arr.begin(), arr.end());

    for(auto const &i : arr) {
        std::cout << ' ' << i;
    }
    std::cout << '\n';

    
    
    //ingresando csv
     vector<vector<double>> data = parse2DCsvFile("pro2.csv"); // poner directorio completo
    for (auto l : data) {
        for (auto x : l)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}
