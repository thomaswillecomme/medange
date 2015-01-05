/* 
 * File:   metafield_description.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 11:31
 */

#ifndef METAFIELD_DESCRIPTION_H
#define	METAFIELD_DESCRIPTION_H

#include <list>
class metafield_description_initializer;

class metafield_description {
    static std::list<const metafield_description*>* index;
    friend class metafield_description_initializer;
    
    const char* shortname;
    const char* longname;
    unsigned digits;
    const std::type_info& value_type;
public:
    
    static const metafield_description* find(const std::string& shortname);

    explicit metafield_description(const char* shortname, const char* longname, unsigned digits, const std::type_info& value_type);
    
    const char* get_longname() const;

    const char* get_shortname() const;
    
    unsigned get_digits() const;

    const std::type_info& get_value_type() const;

    ~metafield_description();
};

static class metafield_description_initializer {
public:
    metafield_description_initializer();
    ~metafield_description_initializer();
} initializer;


#endif	/* METAFIELD_DESCRIPTION_H */

