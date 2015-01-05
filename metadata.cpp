/* 
 * File:   metadata.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 10:50
 */

#include "metadata.h"

metadata::metadata() {
}

metadata::metadata(const metadata& orig) {
}

metadata::~metadata() {
}

void metadata::add(const metafield& field){
    fields.push_back(field);
}

const metafield* metadata::get(const metafield_description& description) const {
    for(std::list<metafield>::const_iterator iter = fields.begin(); iter != fields.end(); iter++){
        if(&iter->get_description() == &description)
            return &(*iter);
    }
        
    return 0;
}


const metafield_description metadata::ORIGINAL_TITLE("otitle","the movie or tvshow original title",0,typeid(std::string));
const metafield_description metadata::TITLE("title","the movie or tvshow title",0,typeid(std::string));
const metafield_description metadata::SEASON("season","the episode season",2,typeid(int));
const metafield_description metadata::EPISODE("episode","the episode number within the season",2,typeid(int));
const metafield_description metadata::EPISODE_TITLE("etitle","the episode title",2,typeid(int));
const metafield_description metadata::YEAR("year","release year",4,typeid(int));
const metafield_description metadata::MONTH("month","release month",2,typeid(int));
const metafield_description metadata::DAY("day","release day",2,typeid(int));
const metafield_description metadata::MEDIA("media","media type",0,typeid(std::string));
const metafield_description metadata::TMDBID("tmdbid","TMDB identification number",10,typeid(int));


