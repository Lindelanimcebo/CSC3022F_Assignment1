/*
* Implementation file for the C++ application to process XML tags
* Author: Lindelani Mbatha
* Date: March 2021
**/

#include "tags.h"

namespace MBTLIN007{

    std::vector<TagStruct> vect;

    void parse (std::string fileName){

        std::ifstream file_in(fileName);
        std::string line;
        std::string file_str = "";

        //std::cout << fileName << std::endl;

        while ( std::getline(file_in, line) ){
            file_str.append(line);
        }
        file_in.close();

        //std::cout << file_str << std::endl;

        std::stack<std::string> opening_stack;
        int opn = -1, cls = -1, opnl = 0, clsf = 0;
        int it = 0, sz = file_str.size();
        
        while ( it < sz ) {
            if ( file_str.substr(it, 1) == "<"){
                opn = it;
            } 
            else if ( file_str.substr(it, 1) == ">" ){
                
                if ( cls < opn ){ 
                    cls = it;
                    if ( file_str.substr(opn + 1, 1) != "/"){
                        opnl = cls;
                        opening_stack.push( file_str.substr ( opn + 1, cls - opn - 1 ) );
                    } 
                    else {
                        std::string tag = opening_stack.top();
                        opening_stack.pop();
                        std::string txt = file_str.substr( opnl + 1, opn - opnl - 1);

                        addTag(tag, txt);
                        
                    }
                }
            }
            it++;
        }
        
    }

    void printTags (void){
        for (int i = 0; i < vect.size(); i++){
            std::cout << vect[i].name << std::endl;
        }
    }
    void dump (void){
        std::ofstream file_out;
        file_out.open("tag.txt");
        for (int i = 0; i < vect.size(); i++){
            file_out << vect[i].name << std::endl;
        }
        file_out.close();
    }

    void list (std::string tag){
        for (int i = 0; i < vect.size(); i++){
            if (vect[i].name == tag){
                std::cout << "Tag : " << tag << std::endl;
                std::cout << vect[i].text << std::endl;
            }

        };
    }

    void addTag( std::string tag, std::string txt){
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
