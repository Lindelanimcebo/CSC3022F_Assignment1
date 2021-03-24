/*
* Header file for the C++ application to process XML tags
* Author: Lindelani Mbathsa
* Date: March 2021
**/

#ifndef TAGS_H
#define TAGS_H

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>

namespace MBTLIN007{
    
    struct TagStruct{
        std::string name;
        int count;
        std::string text;
    };

    extern std::vector<TagStruct> vect;

    // Methods Declarations
    void parse (std::string fileName);
    void printTags (void);
    void dump (void);
    void list (std::string tag);
    void addTag( std::string tag, std::string txt );

}
#endif