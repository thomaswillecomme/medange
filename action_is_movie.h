/* 
 * File:   action_is_movie.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 20:29
 */

#ifndef ACTION_IS_MOVIE_H
#define	ACTION_IS_MOVIE_H

#include "action.h"


class action_is_movie : public action{
public:
    explicit action_is_movie();
    virtual ~action_is_movie();
    

    virtual bool perform(item& item) const;

private:

};

#endif	/* ACTION_IS_MOVIE_H */

