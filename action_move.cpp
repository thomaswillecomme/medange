/* 
 * File:   action_move.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 17:09
 */

#include <string>
#include <iostream>
#include "action_move.h"
#include "metafield_description.h"
#include "metafield.h"

action_move::action_move(const std::string& pattern) : action(), pattern(pattern), regex("<.*?>",boost::regex::normal){
    
}

action_move::~action_move() {
}

bool action_move::perform(item& item) const {
    std::stringstream filename;
    
    //iter will contain matches (0) and unmatches (-1)
    boost::sregex_token_iterator iter(pattern.begin(), pattern.end(), regex, { -1, 0 });
    boost::sregex_token_iterator end;
    while(iter != end)
    {
        //note: this is safe while the first part of the pattern does not contains a unmatch
        //put the string between two matches
        filename << (*iter);
        iter++;
        if(iter==end)
            break;
        
        //on token found, retrieve token metadata and value
        std::string token(*iter,1,(*iter).length()-2);
        const metafield_description* field_desc = metafield_description::find(token);
        if(field_desc == 0){
            //todo log trace
            return false;
        }        
        const metafield* field = item.get_metadata(*field_desc);
        if(field == 0){
            //todo log trace
            return false;
        }
        
        filename << *field;
        
        iter++;
    }
    std::cout << "==> " << filename.str() << std::endl;
    
    //todo move file
    //todo remove empty dirs

    return true;
}


