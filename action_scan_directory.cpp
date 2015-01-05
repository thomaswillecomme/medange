/* 
 * File:   directory_scanner.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 19:04
 */

#include "action_scan_directory.h"
#include "item.h"
#include "engine.h"


action_scan_directory::action_scan_directory() {
}

action_scan_directory::~action_scan_directory() {
}

bool action_scan_directory::perform(item& item) const {
    try{
        bfs::directory_iterator dir(item.get_path());
        while(dir != bfs::directory_iterator()){
           engine::get_instance().queue_path(*dir);
           dir++;
        }
        return true;
    }catch(const boost::filesystem::filesystem_error& error){
        //todo log error
        return false;
    }
}


