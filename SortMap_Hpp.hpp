/*
File: SortMap_Hpp
Author: hassan ihsan
Purpose: for sorting a map 
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

#include <filesystem>
using namespace std::filesystem;
 
//map sorter
bool cmp(pair<string, int>& a, pair<string, int>& b);
void sortmap(map<string, int>& M, int freq);
