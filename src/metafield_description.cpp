/* 
 * File:   metafield_description.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 11:31
 */

#include <list>
#include <string>

#include "metafield_description.h"

std::list<const metafield_description*>* metafield_description::index;

metafield_description::~metafield_description() {
}

metafield_description::metafield_description(const char* shortname, const char* longname, unsigned digits, const std::type_info& value_type) :
 shortname(shortname), longname(longname),digits(digits),value_type(value_type) {
    index->push_back(this);
}

const char* metafield_description::get_longname() const {
    return longname;
}

const char* metafield_description::get_shortname() const {
    return shortname;
}

const std::type_info& metafield_description::get_value_type() const {
    return value_type;
}

unsigned metafield_description::get_digits() const {
    return digits;
}

const metafield_description* metafield_description::find(const std::string& shortname) {
    for(std::list<const metafield_description*>::const_iterator iter=index->begin(); iter!=index->end(); iter++)
        if(shortname.compare((*iter)->get_shortname()) == 0)
            return (*iter);
    return 0;
}


static int nifty_counter;
metafield_description_initializer::metafield_description_initializer() {
    if (0 == nifty_counter++){
        metafield_description::index = new std::list<const metafield_description*>();
    }
}

metafield_description_initializer::~metafield_description_initializer() {
    if (0 == --nifty_counter){
        delete(metafield_description::index);
    }
}


