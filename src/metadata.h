/* 
 * File:   metadata.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 10:50
 */

#ifndef METADATA_H
#define	METADATA_H


#include <list>
#include "metafield.h"
#include "metafield_description.h"

class metadata {
    std::list<metafield> fields;
public:
    metadata();
    metadata(const metadata& orig);
    virtual ~metadata();
    
    void add(const metafield& field);
    const metafield* get(const metafield_description& description) const;
    

    static const metafield_description ORIGINAL_TITLE;
    static const metafield_description TITLE;
    static const metafield_description SEASON;
    static const metafield_description EPISODE;
    static const metafield_description EPISODE_TITLE;
    static const metafield_description YEAR;
    static const metafield_description MONTH;
    static const metafield_description DAY;
    static const metafield_description MEDIA;
    static const metafield_description TMDBID;

};



#endif	/* METADATA_H */

