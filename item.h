/* 
 * File:   item.h
 * Author: thomas
 *
 * Created on 3 janvier 2015, 23:50
 */

#ifndef ITEM_H
#define	ITEM_H

#include <boost/filesystem.hpp>
#include "metadata.h"
#include "metafield.h"

class item{
    boost::filesystem::path path;
    metadata fields;
    
public:
    item(const boost::filesystem::path& p_path);
    const boost::filesystem::path& get_path();
 
    void add_metadata(const metafield& field);
    const metafield* get_metadata(const metafield_description& field) const;
};

#endif	/* ITEM_H */

