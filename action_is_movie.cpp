/* 
 * File:   action_is_movie.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 20:29
 */

#include "action_is_movie.h"
#include "metadata.h"

action_is_movie::action_is_movie() {
}

action_is_movie::~action_is_movie() {
}

bool action_is_movie::perform(item& item) const {
    return (item.get_metadata(metadata::MEDIA) !=0 && item.get_metadata(metadata::MEDIA)->get_value() == metafield::value_type("movie"));
}

