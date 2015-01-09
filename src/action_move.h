/* 
 * File:   action_move.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 17:09
 */

#ifndef ACTION_MOVE_H
#define	ACTION_MOVE_H

#include "action.h"
#include <boost/regex.hpp>
#include <string>

class action_move : public action{
    std::string pattern;
    boost::regex regex;
public:
    explicit action_move(const std::string& pattern);
    virtual ~action_move();
    
    virtual bool perform(item& item) const;

private:

};

#endif	/* ACTION_MOVE_H */

