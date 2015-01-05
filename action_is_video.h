/* 
 * File:   is_video_action.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 00:38
 */

#ifndef IS_VIDEO_ACTION_H
#define	IS_VIDEO_ACTION_H

#include "action_mime.h"


class action_is_video : public action_mime{
public:
    action_is_video();
protected:
    bool does_match(std::string& p_mime) const;

};

#endif	/* IS_VIDEO_ACTION_H */

