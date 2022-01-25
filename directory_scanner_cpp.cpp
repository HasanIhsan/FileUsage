/*
File: directory_scanner_cpp
Author: hassan ihsan
Purpose: for scanning the directory and sub directtorys
*/

#include "directory_scan_hpp.hpp"
#include "SortMap_Hpp.hpp"
#include <iomanip>      // std::setw
 
using namespace std;

 





int GetGivenExtions(path const& root,string sortbySize, string reverseOrder, string  recursiveornot, string const& searchname, string const& ext1, string const& ext2, string const& ext3, string const& ext4, string const& ext5, string const& ext6, string const& ext7)
{
    (void)cout.imbue(locale(""));

    

    if (exists(root)) {

        vector<string>  GivenfilesExtentions;

        vector<int> fileSizes;

        size_t totalFiles = 0;
        size_t totalExtentions = 0;
        auto nSize = 0;
        size_t totalSize = 0;


        cout << "\n" << searchname << " files: " << absolute(root).string() << endl;
        cout << "\n";
        cout << setw(7) << "    Ext :   # :       Total" << endl;
        cout << setw(7) << "------- : --- : -----------";


        if (recursiveornot == "r") {

            for (recursive_directory_iterator d(root), e; d != e; ++d)
            {
                bool isdirectory = is_directory(d->status());


                error_code ee;
                nSize = file_size(d->path(), ee);

                if (ee) {
                    cout << "Error [" << ee.value() << "]: " << ee.message() << endl;
                    cout << "Category = " << ee.category().name() << endl;
                }

                if (!isdirectory) {
                    if (d->path().extension() == ext1 || d->path().extension() == ext2 || d->path().extension() == ext3 || d->path().extension() == ext4 || d->path().extension() == ext5 || d->path().extension() == ext6 || d->path().extension() == ext7) {

                        GivenfilesExtentions.push_back(d->path().extension().string());
                        fileSizes.push_back(nSize);
                    }
                }


            }
        }
        else {
            for ( directory_iterator d(root), e; d != e; ++d)
            {
                bool isdirectory = is_directory(d->status());


                error_code ee;
                nSize = file_size(d->path(), ee);

                if (ee) {
                    cout << "Error [" << ee.value() << "]: " << ee.message() << endl;
                    cout << "Category = " << ee.category().name() << endl;
                }

                if (!isdirectory) {
                    if (d->path().extension() == ext1 || d->path().extension() == ext2 || d->path().extension() == ext3 || d->path().extension() == ext4 || d->path().extension() == ext5 || d->path().extension() == ext6 || d->path().extension() == ext7) {

                        GivenfilesExtentions.push_back(d->path().extension().string());
                        fileSizes.push_back(nSize);
                    } 
                }


            }
        }

        map<string, int> mp;
        for (size_t i = 0; i < GivenfilesExtentions.size(); i++) {
            mp.insert({ GivenfilesExtentions.at(i), fileSizes.at(i) });
        }
        cout << "\n";
        size_t freq = 0;

       

        if (reverseOrder == "R") {
            map<string, int>::reverse_iterator it;
            for (it = mp.rbegin(); it != mp.rend(); it++) {
                totalExtentions++;
                string val = it->first;
                freq = std::count(GivenfilesExtentions.begin(), GivenfilesExtentions.end(), val);
                totalFiles += freq;
                totalSize += it->second;


                cout << setw(7) << it->first << setw(3) << " : " << setw(3) << freq << " : " << setw(10) << it->second << endl;
            }
            

        }
        else if (sortbySize == "S") {

            for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
                totalExtentions++;
                string val = itr->first;
                freq = std::count(GivenfilesExtentions.begin(), GivenfilesExtentions.end(), val);
                totalFiles += freq;
                totalSize += itr->second;
                
            }

            sortmap(mp, freq);
        }
        else {

            for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
                totalExtentions++;
                string val = itr->first;
                freq = std::count(GivenfilesExtentions.begin(), GivenfilesExtentions.end(), val);
                totalFiles += freq;
                totalSize += itr->second;


                cout << setw(7) << itr->first << setw(3) << " : " << setw(3) << freq << " : " << setw(10) << itr->second << endl;
            }

        }

       

        cout << setw(6) << "  ----- : --- : -----------" << endl;
        cout << setw(4) << " " << setw(3) << totalExtentions << " : " << setw(3) << totalFiles << " : " << setw(10) << totalSize << endl;


    }
    else {
        cout << "Error: folder [" << root.string() << "] doesn't exists." << endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void rscan(path const& file,string sortbyfileSize, string reverseOrder, string recursiveorNot) {
    cout << endl;
    (void)cout.imbue(locale(""));
    vector<string> filesExtentions;
    vector<int> fileSizes;
    if (exists(file)) {

        size_t totalFiles = 0;
        size_t totalExtentions = 0;
        auto nSize = 0;
        size_t totalSize = 0;

        cout << "\nAll files: " << absolute(file).string() << endl;
        cout << "\n";
        cout << setw(7)<<"    Ext :   # :       Total" << endl;
        cout << setw(7)<<"------- : --- : -----------";

        //auto d : directory_iterator(file)
        if (recursiveorNot == "r") {
            for (recursive_directory_iterator d(file), e; d != e; ++d) {
                bool isdirectory = is_directory(d->status());

                error_code ee;
                nSize = file_size(d->path(), ee);

                if (ee) {
                    cout << "Error [" << ee.value() << "]: " << ee.message() << endl;
                    cout << "Category = " << ee.category().name() << endl;
                }
                if (!isdirectory) {
                    filesExtentions.push_back(d->path().extension().string());
                    fileSizes.push_back(nSize);
                }



            }
        }

        else {
            for ( directory_iterator d(file), e; d != e; ++d) {
                bool isdirectory = is_directory(d->status());

                error_code ee;
                nSize = file_size(d->path(), ee);

                if (ee) {
                    cout << "Error [" << ee.value() << "]: " << ee.message() << endl;
                    cout << "Category = " << ee.category().name() << endl;
                }
                if (!isdirectory) {
                    filesExtentions.push_back(d->path().extension().string());
                    fileSizes.push_back(nSize);
                }



            }
        }
        



        map<string, int> mp;
        for (size_t i = 0; i < filesExtentions.size(); i++) {
            mp.insert({ filesExtentions.at(i), fileSizes.at(i) });
        }
        cout << "\n";

        size_t freq = 0;
        if (reverseOrder == "R") {
            map<string, int>::reverse_iterator it;
            for (it = mp.rbegin(); it != mp.rend(); it++) {
                totalExtentions++;
                string val = it->first;
                freq = std::count(filesExtentions.begin(), filesExtentions.end(), val);
                totalFiles += freq;
                totalSize += it->second;


                cout << setw(7) << it->first << setw(3) << " : " << setw(3) << freq << " : " << setw(10) << it->second << endl;
            }
        }
        else if (sortbyfileSize == "S") {

            for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
                totalExtentions++;
                string val = itr->first;
                freq = std::count(filesExtentions.begin(), filesExtentions.end(), val);
                totalFiles += freq;
                totalSize += itr->second;

            }

            sortmap(mp, freq);
        }
        else {
            for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
                totalExtentions++;
                string val = itr->first;
                freq = std::count(filesExtentions.begin(), filesExtentions.end(), val);
                totalFiles += freq;
                totalSize += itr->second;

                cout << setw(7) << itr->first << setw(3) << " : " << setw(3) << freq << " : " << setw(10) << itr->second << endl;
            }
        }
        


        cout << setw(6)<<"  ----- : --- : -----------" << endl;
        cout << setw(4)<<" " << setw(3) << totalExtentions  << " : " << setw(3) << totalFiles << " : " << setw(10) << totalSize << endl;
    }
    else {

        cout << "Error: folder [" << file.string() << "] doesn't exists." << endl;
    }
}