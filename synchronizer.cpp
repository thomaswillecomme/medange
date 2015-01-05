/* 
 * File:   synchronizer.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 13:32
 */

#include "synchronizer.h"

#include <boost/thread/thread.hpp>

synchronizer::synchronizer(unsigned p_interval) : interval(p_interval), next_slot(boost::posix_time::second_clock::local_time()+interval) {

}

synchronizer::~synchronizer() {
}

void synchronizer::wait_slot() {
    boost::posix_time::ptime now = boost::posix_time::second_clock::local_time();
    //if the slot have not been used yet, we can use it right away
    {
        boost::lock_guard<boost::recursive_mutex> lock(guard);
        if(next_slot < now){
            next_slot = now+interval;
            return;
        }
    }
        

    //otherwise, we have to wait until we reach the time slot
    boost::posix_time::time_duration delay;
    {
        boost::lock_guard<boost::recursive_mutex> lock(guard);
        delay = next_slot-now;
        next_slot+=interval;
    }
    
    boost::this_thread::sleep(delay);
}

