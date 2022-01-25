/*
* Programmer: Hassan Ihsan
* Program Name: fileusage
* date: ///
*/

#include "directory_scan_hpp.hpp"
#include <locale>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  
#include <iterator>
#include <vector>
#include <map> 
 

#include <filesystem>
using namespace std::filesystem;
 
using namespace std;
 
int main(int argc,char* argv[])
{
    cout << "fileusage {v1} (c) 2021, Hassan Ihsan" << endl;
    //cfiles
     
    string cextention = ".c";
    string cexttention2 = ".h";
   
    //c++files
    
    string cplusextention = ".cc";
    string cplusextention2 = ".cp";
    string cplusextention3 = ".cpp";
    string cplusextention4 = ".cxx";
    string cplusextention5 = ".c++";
    string cplusextention6 = ".hpp";
    string cplusextention7 = ".hxx";

    //java files
    string jextention = ".class";
    string jextention2 = ".j";
    string jextention3 = ".jad";
    string jextention4 = ".jar";
    string jextention5 = ".java";
    string jextention6 = ".jsp";
    string jextention7 = ".ser";

    //c#files
    string hashextention = ".cs";
    string hashextention2 = ".jsl";
    string hashextention3 = ".vb";

    //web files
    string webextention = ".htm";
    string webextention2 = ".html";
    string webextention3 = ".html5";
    string webextention4 = ".js";
    string webextention5 = ".jse";
    string webextention6 = ".jsc";

    string notRecursice = "";
    string reverseOrder = "";
    string sortbyfilesize = "";
    if (argc == 1) {

        path current = ".";
        rscan(current,sortbyfilesize, reverseOrder, notRecursice);
        

    }
    else if (argc == 2) {
        //reading in a folder with directory
        path current = ".";
        
        std::vector<char> cLine(argv[1], argv[1] + std::strlen(argv[1]));
         

        for (size_t i = 1; i < cLine.size(); i++) {
            if (cLine[0] == '-' && cLine[i] == 'h') {
                cout << endl;
                cout << "\t\tUsage: fileusage [-hrRsSvc+#jw(x regularexpression)] [folder]" << endl;
                cout << "\t\tswitches:" << endl;
                cout << "\t\t\t c       C files" << endl;
                cout << "\t\t\t +       C++ files" << endl;
                cout << "\t\t\t j       Java files" << endl;
                cout << "\t\t\t #       C# files" << endl;
                cout << "\t\t\t w       Web files" << endl;
                cout << "\t\t\t s       summary of the different categories" << endl;
                cout << "\t\t\t x       filter with a regular expression" << endl;
                cout << "\t\t\t r       suppress recursive processing of the folder" << endl;
                cout << "\t\t\t R       reverse the order of the listing" << endl;
                cout << "\t\t\t S       sort by file sizes" << endl;
                cout << "\t\t\t v       verbose - list all files being scanned" << endl;
                cout << "\t\t\t h       help" << endl;
                cout << "\t\tfolder" << endl;
                cout << "\t\t\t starting folder or current folder if not provided" << endl;
                return EXIT_SUCCESS;
            }
        }

        for (size_t i = 1; i < cLine.size(); i++) {
            if (cLine[0] == '-' && cLine[i] == 'r' && i == 1) {
                notRecursice = "r";
                rscan(current,sortbyfilesize, reverseOrder,notRecursice);
            }else
            if (cLine[0] == '-' && cLine[i] == 'r') {
                 
                notRecursice = "r";
            }
      
        }

        for (size_t i = 1; i < cLine.size(); i++) {
            
            
            if (cLine[0] == '-' && cLine[i] == 'R' && i == 1) {
                reverseOrder = "R";
                rscan(current,sortbyfilesize, reverseOrder, notRecursice);
            }else
            if (cLine[0] == '-' && cLine[i] == 'R') {
                
                reverseOrder = "R";
                 
                
            }
             
        
        }
        
        for (size_t i = 1; i < cLine.size(); i++) {
            
            if (cLine[0] == '-' && cLine[i] == 'S' && i == 1) {
                sortbyfilesize = "S";
                rscan(current,sortbyfilesize, reverseOrder, notRecursice);
            }
            else
            if (cLine[0] == '-' && cLine[i] == 'S') {
                sortbyfilesize = "S";
                  
            }
             
        }
    
        for (size_t i = 0; i < cLine.size(); i++) {

            if (cLine[0] == '-' && cLine[i] == 's' && cLine.size() > 2 ) {
                for (size_t i = 0; i < cLine.size(); i++) {
                    if (cLine[i] == 'c') {
                       // cout << "has c" << endl;
                    }
                    if (cLine[i] == '+') {
                       // cout << "has c++" << endl;
                    }
                    if (cLine[i] == 'j') {
                       // cout << "has j" << endl;
                    }
                    if (cLine[i] == '#') {
                       // cout << "has #" << endl;
                    }
                    if (cLine[i] == 'w') {
                       // cout << "has w" << endl;
                    }
                }
                cout << cLine.size() << endl;
                //GetGivenExtions(current, cextention);
                //cout << "summarsy";

            }

        }


        for (size_t i = 1; i < cLine.size(); i++) {
           
           
            if (cLine[0] == '-' && cLine[i] == 'c') {
                string searchType = "C";
           
                //adding the same values since we're only looking for .c and .h
                //porb could have used vectors to make it eaiser/simpler
                GetGivenExtions(current, sortbyfilesize,reverseOrder ,notRecursice, searchType, cextention, cexttention2, cexttention2, cexttention2, cexttention2, cexttention2, cexttention2);
                
            }
            else
            if (cLine[0] == '-' && cLine[i] == '+') {

                string searchType = "C++";
              
                GetGivenExtions(current,sortbyfilesize, reverseOrder,notRecursice, searchType, cplusextention, cplusextention2, cplusextention3, cplusextention4, cplusextention5, cplusextention6, cplusextention7);
           
                
            }else
            if (cLine[0] == '-' && cLine[i] == 'j') {
                string searchType = "Java";
               
                 
                 GetGivenExtions(current,sortbyfilesize, reverseOrder ,notRecursice, searchType, jextention, jextention2, jextention3, jextention4, jextention5, jextention6, jextention7);
         

            }else
            if (cLine[0] == '-' && cLine[i] == '#') {
                string searchType = "C#";
                 
                GetGivenExtions(current,sortbyfilesize, reverseOrder ,notRecursice, searchType, hashextention, hashextention2, hashextention3, hashextention, hashextention, hashextention, hashextention);
           

            }else
            if (cLine[0] == '-' && cLine[i] == 'w') {
                string searchType = "Web";
               
          
                GetGivenExtions(current,sortbyfilesize, reverseOrder, notRecursice, searchType, webextention, webextention2, webextention3, webextention4, webextention5, webextention6, webextention);
    

            }else
           
             
            
            
           
            if (cLine[0] == '-' && cLine[i] == 'v') {
                
                //cout << "list all files";

            }
             
        } 
       
         if (cLine[0] != '-') {
            path givendirectory = argv[1];
            rscan(givendirectory,sortbyfilesize, reverseOrder, notRecursice);
         }

    }
    else if (argc == 3) {
         
        std::vector<std::string> args(argv, argv + argc);

        path givenpath = string(args[2]);

        std::vector<char> cLine(argv[1], argv[1] + std::strlen(argv[1]));
         

        for (size_t i = 1; i < cLine.size(); i++) {
            if (cLine[0] == '-' && cLine[i] == 'h') {
                cout << endl;
                cout << "\t\tUsage: fileusage [-hrRsSvc+#jw(x regularexpression)] [folder]" << endl;
                cout << "\t\tswitches:" << endl;
                cout << "\t\t\t c       C files" << endl;
                cout << "\t\t\t +       C++ files" << endl;
                cout << "\t\t\t j       Java files" << endl;
                cout << "\t\t\t #       C# files" << endl;
                cout << "\t\t\t w       Web files" << endl;
                cout << "\t\t\t s       summary of the different categories" << endl;
                cout << "\t\t\t x       filter with a regular expression" << endl;
                cout << "\t\t\t r       suppress recursive processing of the folder" << endl;
                cout << "\t\t\t R       reverse the order of the listing" << endl;
                cout << "\t\t\t S       sort by file sizes" << endl;
                cout << "\t\t\t v       verbose - list all files being scanned" << endl;
                cout << "\t\t\t h       help" << endl;
                cout << "\t\tfolder" << endl;
                cout << "\t\t\t starting folder or current folder if not provided" << endl;
                return EXIT_SUCCESS;
            }
        }

        for (size_t i = 1; i < cLine.size(); i++) {
            if (cLine[0] == '-' && cLine[i] == 'r' && i == 1) {
                notRecursice = "r";
                rscan(givenpath,sortbyfilesize, reverseOrder,notRecursice);
            }else
            if (cLine[0] == '-' && cLine[i] == 'r') {
                
                notRecursice = "r";
            }
      
        }

        for (size_t i = 1; i < cLine.size(); i++) {
            
            
            if (cLine[0] == '-' && cLine[i] == 'R' && i == 1) {
                reverseOrder = "R";
                rscan(givenpath,sortbyfilesize, reverseOrder, notRecursice);
            }else
            if (cLine[0] == '-' && cLine[i] == 'R') {
                
                reverseOrder = "R";
                 
                
            }
             
        
        }
       

        
        for (size_t i = 1; i < cLine.size(); i++) {
            
            if (cLine[0] == '-' && cLine[i] == 'S' && i == 1) {
                sortbyfilesize = "S";
                rscan(givenpath,sortbyfilesize, reverseOrder, notRecursice);
            }
            else
            if (cLine[0] == '-' && cLine[i] == 'S') {
                sortbyfilesize = "S";
                  
            }
             
        }
   

        for (size_t i = 1; i < cLine.size(); i++) {
           
           
            if (cLine[0] == '-' && cLine[i] == 'c') {
                string searchType = "C";
           
                //adding the same values since we're only looking for .c and .h
                //porb could have used vectors to make it eaiser/simpler
                GetGivenExtions(givenpath, sortbyfilesize,reverseOrder ,notRecursice, searchType, cextention, cexttention2, cexttention2, cexttention2, cexttention2, cexttention2, cexttention2);
                
            }
            else
            if (cLine[0] == '-' && cLine[i] == '+') {

                string searchType = "C++";
              
                GetGivenExtions(givenpath,sortbyfilesize, reverseOrder,notRecursice, searchType, cplusextention, cplusextention2, cplusextention3, cplusextention4, cplusextention5, cplusextention6, cplusextention7);
           
                
            }else
            if (cLine[0] == '-' && cLine[i] == 'j') {
                string searchType = "Java";
               
                 
                 GetGivenExtions(givenpath,sortbyfilesize, reverseOrder ,notRecursice, searchType, jextention, jextention2, jextention3, jextention4, jextention5, jextention6, jextention7);
         

            }else
            if (cLine[0] == '-' && cLine[i] == '#') {
                string searchType = "C#";
                 
                GetGivenExtions(givenpath,sortbyfilesize, reverseOrder ,notRecursice, searchType, hashextention, hashextention2, hashextention3, hashextention, hashextention, hashextention, hashextention);
           

            }else
            if (cLine[0] == '-' && cLine[i] == 'w') {
                string searchType = "Web";
               
          
                GetGivenExtions(givenpath,sortbyfilesize, reverseOrder, notRecursice, searchType, webextention, webextention2, webextention3, webextention4, webextention5, webextention6, webextention);
    

            }else
            
            
            
           
            if (cLine[0] == '-' && cLine[i] == 'v') {
                // string cextention = ".c";
                 //GetGivenExtions(current, cextention);
               // cout << "list all files";

            }
             
        } 
       
       
         
        
    }
     
      

         
    return EXIT_SUCCESS;
}
 