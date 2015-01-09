/* 
 * File:   directory_scanner.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 19:04
 */

#ifndef DIRECTORY_SCANNER_H
#define	DIRECTORY_SCANNER_H

#include <boost/filesystem.hpp>
#include "action.h"
namespace bfs = boost::filesystem; 

class action_scan_directory : public action{
public:
    action_scan_directory();
    virtual ~action_scan_directory();
    
    virtual bool perform(item& item) const;

};

#endif	/* DIRECTORY_SCANNER_H */

