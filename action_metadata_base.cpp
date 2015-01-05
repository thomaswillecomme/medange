/* 
 * File:   action_metadata_base.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 12:57
 */

#include "action_metadata_base.h"

#include <iostream>
const char* action_metadata_base::CLEAN_REGEX="\\[.*?\\]|[.\\- _\\s]|[0-9]{4}|audio|dvdrip|bluray|x264|720p|www\\.[a-zA-Z0-9]*\\.[a-zA-Z0-9]*";

action_metadata_base::action_metadata_base() : action(), regex(CLEAN_REGEX,boost::regex::normal | boost::regbase::icase){
    
}

action_metadata_base::~action_metadata_base() {
}

std::list<std::string> action_metadata_base::filename_to_keywords(const boost::filesystem::path& p_path) const{
    std::string filename = p_path.filename().string();
    filename = filename.substr(0,filename.length()-p_path.extension().string().length());

    std::list<std::string> keywords; 

    boost::sregex_token_iterator iter(filename.begin(), filename.end(), regex, -1);
    boost::sregex_token_iterator end;
    while(iter != end)
    {
        if(iter->length() != 0){
            keywords.push_back(*iter);
        
            std::cout << *iter << std::endl;
        }
        
        iter++;
        
    }
    
    
    return keywords;
}





