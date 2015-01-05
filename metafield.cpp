/* 
 * File:   metafield.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 10:59
 */

#include "metafield.h"

#include <iomanip>
//
//metafield::metafield() {
//}
//
//metafield::metafield(const metafield& orig) {
//}

metafield::~metafield() {
}

const boost::variant<int, std::string>& metafield::get_value() const {
    return m_value;
}

const metafield_description& metafield::get_description() const {
    return m_description;
}

std::ostream& operator<<(std::ostream& os, const metafield& field) {
    os << std::setfill('0') << std::setw(field.get_description().get_digits()) << field.get_value();
    return os;
}


