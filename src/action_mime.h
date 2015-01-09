/* 
 * File:   is_mime_type.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 00:10
 */

#ifndef IS_MIME_TYPE_H
#define	IS_MIME_TYPE_H

#include "action.h"
#include "magic.h"

class action_mime : public action{
    static const char s_magic_db_file[];
    magic_t m_magic;
public:
    action_mime();
    ~action_mime();
    bool perform(item& p_item) const;
    virtual bool does_match(std::string& p_mime) const =0;


};

#endif	/* IS_MIME_TYPE_H */

