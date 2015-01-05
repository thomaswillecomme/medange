/* 
 * File:   is_file_action.h
 * Author: thomas
 *
 * Created on 3 janvier 2015, 23:51
 */

#ifndef IS_FILE_ACTION_H
#define	IS_FILE_ACTION_H

#include "action.h"

class action_is_file : public action{
public:
    bool perform(item& item) const;
    explicit action_is_file();
    virtual ~action_is_file();
};

#endif	/* IS_FILE_ACTION_H */

