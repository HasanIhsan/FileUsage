/*
File: directory_scan_hpp.hpp
Author: hassan ihsan
Purpose: a header file for scanning the directorys
*/
#include <locale>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>  
#include <iterator>
using namespace std;

#include <filesystem>
using namespace std::filesystem;


void rscan(path const& file,string sortbyfileSize, string reverseOrder, string recursiiveornot); 
int GetGivenExtions(path const& root,string sortbySize, string reverseOrder ,string  recursiveornot, string const& searchname, string const& ext1, string const& ext2, string const& ext3, string const& ext4, string const& ext5, string const& ext6, string const& ext7);

 