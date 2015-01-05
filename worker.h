/* 
 * File:   worker.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 19:42
 */

#ifndef WORKER_H
#define	WORKER_H

#include "basic_tree.h"
#include "action.h"
#include <boost/filesystem.hpp>

class worker {
    basic_tree<const action*>* procedure;
public:
    explicit worker();
    virtual ~worker();
    
    void work(const boost::filesystem::path& path);

};

#endif	/* WORKER_H */

