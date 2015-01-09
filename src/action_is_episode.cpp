/* 
 * File:   action_is_episode.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 20:33
 */

#include "action_is_episode.h"
#include "metadata.h"

action_is_episode::action_is_episode() {
}

action_is_episode::~action_is_episode() {
}

bool action_is_episode::perform(item& item) const {
    return (item.get_metadata(metadata::MEDIA) !=0 && item.get_metadata(metadata::MEDIA)->get_value() == metafield::value_type("tv"));
}

