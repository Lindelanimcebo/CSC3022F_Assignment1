/*
* Header file for the C++ application to process XML tags
* Author: Lindelani Mbathsa
* Date: March 2021
**/

#ifndef TAGS_H
#define TAGS_H

#include <string>
#include <stack>
#include <vector>
#include <sstream>

namespace MBTLIN007{
    
    struct TagStruct{
        std::string name;
        std::int count;
        std::string text
    };

    std::vector<TagStruct> vect;

    // Methods Declarations
    void parse (std::string file_str);
    void printTags (void);
    void dump (void);
    void list (std::string tag);

}

#endif