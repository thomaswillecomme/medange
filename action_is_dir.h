/* 
 * File:   is_dir_action.h
 * Author: thomas
 *
 * Created on 3 janvier 2015, 23:52
 */

#ifndef IS_DIR_ACTION_H
#define	IS_DIR_ACTION_H

#include "action.h"

class action_is_dir : public action{
public:
    bool perform(item& item) const;
    action_is_dir();
};


#endif	/* IS_DIR_ACTION_H */

