/* 
 * File:   is_mime_type.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 00:10
 */

#include "action_mime.h"



const char action_mime::s_magic_db_file[] = "/usr/share/file/magic";

action_mime::action_mime() : action() {
    m_magic = magic_open(MAGIC_MIME);
    if(magic_errno(m_magic) > 0)
    {
            //todo logging
    }

    magic_load(m_magic, 0);
    if(magic_errno(m_magic) > 0)
    {
            //todo logging
    }
}

action_mime::~action_mime() {
    magic_close(m_magic);
    if(magic_errno(m_magic) > 0)
    {
            //todo logging
    }
}

bool action_mime::perform(item& p_item) const{
    
    const char* l_data = p_item.get_path().string().c_str();
    const char* l_result = magic_file(m_magic, l_data);

    if(magic_errno(m_magic) > 0)
    {
            return false; //todo logging
    }

    std::string str(l_result);

    return does_match(str);
}

