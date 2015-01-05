/* 
 * File:   is_video_action.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 00:38
 */

#include "action_is_video.h"
#include <iostream>
action_is_video::action_is_video() : action_mime() {
}


bool action_is_video::does_match(std::string& p_mime) const{
    return p_mime.find("video")!=std::string::npos;
}

