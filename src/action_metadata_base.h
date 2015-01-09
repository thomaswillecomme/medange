/* 
 * File:   action_metadata_base.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 12:57
 */

#ifndef ACTION_METADATA_BASE_H
#define	ACTION_METADATA_BASE_H

#include <boost/regex.hpp>

#include "action.h"
class action_metadata_base : public action {
    static const char* CLEAN_REGEX;
    boost::regex regex;
public:
    action_metadata_base();
    virtual ~action_metadata_base();
    
    std::list<std::string> filename_to_keywords(const boost::filesystem::path& p_path) const;
private:

};

#endif	/* ACTION_METADATA_BASE_H */

