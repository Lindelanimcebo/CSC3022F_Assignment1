/*
* Drive file for the C++ application to process XML tags
* Author: Lindelani Mbatha
* Date: March 2021
**/

#include <iostream>
#include <cstdlib>
#include "tags.h"

int main(void){
    for (;;){
        std::cout << "Enter an option (r,p,d,l) or q to quit, and press return.." << std::endl;
        std::cout << "r: Read and process tag file" << std::endl;
        std::cout << "p: Print all tags" << std::endl;
        std::cout << "d: Dump/write tags to a data file (tag.txt)" << std::endl;
        std::cout << "l: list/print tag data for a given tag" << std::endl;
        std::cout << "q: quit" << std::endl;
        
        std::string in;
        std::cin >> in;

        // Quiting the application
        if ( (in == "q") || (in == "quit") ){
            system("clear");
            break;
        }

        if ( in == "r" ){
            MBTLIN007::parse("Any");
        } 

        else if (in == "p") {
            MBTLIN007::printTags();
        }

        else if (in == "d") {
            MBTLIN007::dump();
        }

        else if ( in == "l") {
            MBTLIN007::list("Any");
        }

        else { std::cout << "Invalid command!" << std::endl; }

    }
    
    return 0;
}