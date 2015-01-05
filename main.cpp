/* 
 * File:   main.cpp
 * Author: thomas
 *
 * Created on 3 janvier 2015, 21:53
 */

#include <cstdlib>
#include <map>
#include <boost/filesystem.hpp>
#include <iostream>


#include "action_is_video.h"
#include "action_is_file.h"
#include "action_metadata_tmdb.h"
#include "action_move.h"
#include "engine.h"

int main(int argc, char** argv) {
    
    
    boost::filesystem::path l_path("/mnt/freebox/Torents/Finished");
    
    
    
    engine::get_instance().run(l_path);
    engine::dispose();
    
    return 0;
}

