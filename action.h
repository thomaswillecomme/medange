/* 
 * File:   action.h
 * Author: thomas
 *
 * Created on 3 janvier 2015, 23:49
 */

#ifndef ACTION_H
#define	ACTION_H

#include "item.h"

class action{
   
public:
    virtual bool perform(item& item) const =0;
    action();
    virtual ~action();
    
};

#endif	/* ACTION_H */

