/* 
 * File:   engine.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 19:24
 */

#ifndef ENGINE_H
#define	ENGINE_H

#include <queue>
#include <boost/filesystem.hpp>

class engine {
    static engine* instance;
    
    std::queue<boost::filesystem::path> queue;
    
    engine();
    virtual ~engine();

public:
    static engine& get_instance();
    static void dispose();
    
    void queue_path(const boost::filesystem::path& path);
    void run(const boost::filesystem::path& start_path);

};

#endif	/* ENGINE_H */

