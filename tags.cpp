/*
* Implementation file for the C++ application to process XML tags
* Author: Lindelani Mbatha
* Date: March 2021
**/

#include "tags.h"

namespace MBTLIN007{

    std::vector<TagStruct> vect;

    void parse (std::string fileName){
        /* 
        * Reads and searches the file for XML tags
        **/

        // Reading the file to a string
        std::ifstream file_in(fileName);
        std::string line;
        std::string file_str = "";

        while ( std::getline(file_in, line) ){
            file_str.append(line);
        }
        file_in.close();

        std::stack<std::string> openingTagStack;  // stores opening tags
        std::stack<int> lastCloseStack;          // stores index of latest closing brace

        
        int open = -1, close = -1, last_close = 0;     // keeps track of opening and closing braces
        int it = 0, sz = file_str.size();              // iterator and size of file string
        
        while ( it < sz ) {
            if ( file_str.substr(it, 1) == "<"){
                open = it;
            } 
            else if ( file_str.substr(it, 1) == ">" ){
                
                if ( close < open ){
                    /* 
                    * To ignore in-text braces,
                    * since a closing brace should be followed by an opening brace
                    */
                    close = it;

                    if ( file_str.substr(open + 1, 1) != "/"){ // checks for an opening tag
                        last_close = close;
                        lastCloseStack.push(last_close);
                        openingTagStack.push( file_str.substr ( open + 1, close - open - 1 ) );
                    } 
                    else { // closing tag found
                        std::string tag = openingTagStack.top();
                        openingTagStack.pop();

                        int last_close = lastCloseStack.top();
                        lastCloseStack.pop();

                        std::string txt = file_str.substr( last_close + 1, open - last_close - 1);
                        addTag(tag, txt);
                        
                        if(!openingTagStack.empty()){
                            /**
                            * if the stack is empty then there are no nested tags,
                            * otherwise, the top() opening tag corresponds to the current closing tag,
                            * erase inner-most tag from the file string to force it's parent to be the inner-most,
                            * and reset the iterator to account for this
                            */
                            int start = last_close - tag.size() - 1;
                            file_str.erase(start, close - start + 1);
                            it =  start - 1;
                            close = lastCloseStack.top();
                        }
                    }
                }
            }
            sz = file_str.size(); // ensure the new size is captured
            it++;
        } 
    }

    void printTags (void){
        // Prints all tag names from the vector
        for (int i = 0; i < vect.size(); i++){
            std::cout << vect[i].name << std::endl;
        }
    }

    void dump (void){
        // write all tag names to the output file
        std::ofstream file_out;
        file_out.open("tag.txt");
        for (int i = 0; i < vect.size(); i++){
            file_out << vect[i].name << std::endl;
        }
        file_out.close();
    }

    void list (std::string tag){
        // list all text enclosed by the tag
        for (int i = 0; i < vect.size(); i++){
            if (vect[i].name == tag){
                std::cout << "Tag : " << tag << std::endl;
                std::cout << vect[i].text << std::endl;
            }

        };
    }

    void addTag( std::string tag, std::string txt){
        /** Adds a tag to the vector
        * if tag in vector, only the text is appended to the tags' test,
        * and the count is incremented
        */

        bool found = false;
        int i = 0;

        while (!found && i < vect.size()) {
            if (vect[i++].name == tag){ found = true; }
        }

        if (found){
            vect[i-1].text = vect[i-1].text + ":" + txt;
            vect[i-1].count++;
        }
        else{
            TagStruct temp = {tag, 1, txt};
            vect.push_back(temp);
        }
    }

}