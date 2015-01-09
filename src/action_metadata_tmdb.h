/* 
 * File:   action_metadata_tmdb.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 13:14
 */

#ifndef ACTION_METADATA_TMDB_H
#define	ACTION_METADATA_TMDB_H

#include "action_metadata_base.h"
#include "synchronizer.h"

class action_metadata_tmdb : public action_metadata_base{
    static const char* URL;
    static const char* KEY;
    static synchronizer SYNC;
public:
    action_metadata_tmdb();
    virtual ~action_metadata_tmdb();
    

    bool perform(item& item) const;

private:
    std::string format_keywords(const std::list<std::string>& keywords) const;
    std::string format_url_request(const std::list<std::string>& keywords) const;
    bool result_to_metadata(item& item, const std::string& result) const;

};

#endif	/* ACTION_METADATA_TMDB_H */

