/*
File: sortMap_Cpp
Author: hassan ihsan
Purpose: for sorting the map code
*/


#include "SortMap_Hpp.hpp"
#include <iostream>
#include <string>
#include <map>


bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}


void sortmap(map<string, int>& M, int freq)
{

    // Declare vector of pairs
    vector<pair<string, int> > A;

    // Copy key-value pair from Map
    // to vector of pairs
    for (auto& it : M) {
        A.push_back(it);
    }

    // Sort using comparator function
    sort(A.begin(), A.end(), cmp);

    // Print the sorted value
    for (auto& it : A) {

        cout << setw(7) << it.first << setw(3) << " : " << setw(3) << freq << " : " << setw(10) << it.second << endl;
    }
}
