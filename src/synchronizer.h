/* 
 * File:   synchronizer.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 13:32
 */

#ifndef SYNCHRONIZER_H
#define	SYNCHRONIZER_H

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/recursive_mutex.hpp>

class synchronizer {
    const boost::posix_time::milliseconds interval;
    boost::posix_time::ptime next_slot;
    boost::recursive_mutex guard;

public:
    synchronizer(unsigned interval);
    virtual ~synchronizer();

    void wait_slot();

private:

};

#endif	/* SYNCHRONIZER_H */

