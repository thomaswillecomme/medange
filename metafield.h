/* 
 * File:   metafield.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 10:59
 */

#ifndef METAFIELD_H
#define	METAFIELD_H

#include <assert.h>
#include <boost/variant.hpp>
#include "metafield_description.h"

class metafield {
public:
    typedef boost::variant<int,std::string> value_type;
private:
    const metafield_description& m_description;
    value_type m_value;

public:
    template <typename T>
    explicit metafield(const metafield_description& p_description, T p_value);

    virtual ~metafield();
    
    const boost::variant<int, std::string>& get_value() const;
    const metafield_description& get_description() const;

    


};

std::ostream& operator<<(std::ostream& os, const metafield& field);

template <typename T>
metafield::metafield(const metafield_description& p_description, T p_value) :
m_description(p_description), m_value(p_value) {
    assert(typeid(p_value) == p_description.get_value_type());
}

#endif	/* METAFIELD_H */

