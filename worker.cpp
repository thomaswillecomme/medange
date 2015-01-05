/* 
 * File:   worker.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 19:42
 */

#include "worker.h"
#include "action_is_dir.h"
#include "action_scan_directory.h"
#include "action_is_video.h"
#include "action_is_file.h"
#include "action_is_movie.h"
#include "action_is_episode.h"
#include "action_metadata_tmdb.h"
#include "action_move.h"
#include "basic_tree.h"


worker::worker() {
    procedure = new basic_tree<const action*>(new action_is_file());
    basic_tree<const action*>* root = procedure;
    root->set_right(new action_is_dir())->set_left(new action_scan_directory());
    basic_tree<const action*>* video = root->set_left(new action_is_video());
    basic_tree<const action*>* tmdb = video->set_left(new action_metadata_tmdb());
    basic_tree<const action*>* movie = tmdb->set_left(new action_is_movie());
    movie->set_left(new action_move("/mnt/data/medange/movies/<otitle> (<year>)"));
    basic_tree<const action*>* episode = movie->set_right(new action_is_episode());
    episode->set_left(new action_move("/mnt/data/medange/tvshows/<otitle>/season <season>/episode <episode>"));
}

worker::~worker() {
    delete(procedure);
}

void worker::work(const boost::filesystem::path& path) {
    std::cout << path <<std::endl;
    
    //initialize item
    item l_item(path);
    //initialize iterator
    basic_tree<const action*>* iter = procedure;
    while(iter != 0){
        //if perform is successfull, continue to the left of the tree
        if(iter->get_item()->perform(l_item))
            iter = iter->get_left();
        //otherwise, continue to the right
        else
            iter = iter->get_right();
    }
    
    
    
}


