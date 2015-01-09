/* 
 * File:   engine.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 19:24
 */

#include <queue>

#include "engine.h"
#include "worker.h"

engine* engine::instance = 0;

engine::engine() {
}

engine::~engine() {
}

void engine::dispose() {
    if(instance){
        delete(instance);
        instance = 0;
    }                
}

engine& engine::get_instance() {
    if(instance == 0)
        instance = new engine();
    return *instance;
}

void engine::queue_path(const boost::filesystem::path& path) {
    queue.push(path);
}

void engine::run(const boost::filesystem::path& start_path) {
    
    queue_path(start_path);
    
    worker my_worker;
    do{
        my_worker.work(queue.front());
        queue.pop();
    }while(!queue.empty());    
}






