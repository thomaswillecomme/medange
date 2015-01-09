/* 
 * File:   action_is_episode.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 20:33
 */

#ifndef ACTION_IS_EPISODE_H
#define	ACTION_IS_EPISODE_H

#include "action.h"

class action_is_episode : public action{
public:
    action_is_episode();
    virtual ~action_is_episode();
    

    virtual bool perform(item& item) const;

private:

};

#endif	/* ACTION_IS_EPISODE_H */

