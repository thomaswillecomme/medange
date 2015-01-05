/* 
 * File:   action_metadata_tmdb.cpp
 * Author: thomas
 * 
 * Created on 4 janvier 2015, 13:14
 */

#include "action_metadata_tmdb.h"
#include "curl_wrapper.h"
#include "metadata.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/regex.hpp>

const char* action_metadata_tmdb::KEY = "2080e506f6b94aab0c7c7fe628665fa2";
const char* action_metadata_tmdb::URL = "http://api.themoviedb.org";
synchronizer action_metadata_tmdb::SYNC(10./30.);

action_metadata_tmdb::action_metadata_tmdb() : action_metadata_base(){
}


action_metadata_tmdb::~action_metadata_tmdb() {
}

bool action_metadata_tmdb::perform(item& item) const {
    curl_wrapper connection;
    std::list<std::string> keywords = filename_to_keywords(item.get_path());

    
    try{
        std::string result;
        while(keywords.size()){
            //perform request
            std::string request = format_url_request(keywords);
            std::cout << "querying TMDB: " << request << std::endl;
            SYNC.wait_slot();
            result = connection.perform(request);
            std::cout << result << std::endl;
            keywords.pop_back();
            if(result_to_metadata(item,result))
                break;
        }
        
        //for an episode, we need to perform another request to fetch episode title and date
        if(item.get_metadata(metadata::MEDIA) != 0 && item.get_metadata(metadata::MEDIA)->get_value() == metafield::value_type("tv")){
            int season=0;
            int episode=0;
            //int id = boost::get<int>(item.get_metadata(metadata::TMDBID)->get_value());

            boost::regex regex_episode("[0-9]{2}",boost::regex::normal);
            BOOST_FOREACH(const std::string& keyword, filename_to_keywords(item.get_path())){
                boost::sregex_token_iterator iter(keyword.begin(), keyword.end(), regex_episode, 0);
                boost::sregex_token_iterator end;
                while(iter != end)
                {
                    if(iter->length() != 0){
                        std::string match = (*iter);
                        if(season == 0){
                            season = atoi(match.c_str());
                            std::cout << "guessing season : " << *iter << std::endl;
                        }else if(episode == 0){
                            episode = atoi(match.c_str());
                            std::cout << "guessing episode : " << *iter << std::endl;
                        }
                    }
                    iter++;
                }
            }
            
            item.add_metadata(metafield(metadata::SEASON,season));
            item.add_metadata(metafield(metadata::EPISODE,episode));
            
            
            //std::string episode_request = format_season_request(id,season);
            
        }
    
        return true;
    }catch(const std::exception& e){
        std::cerr << e.what() << std::endl;
        return false;
    }
    
}

std::string action_metadata_tmdb::format_keywords(const std::list<std::string>& keywords) const {
    //formating query string by separating keywords with a CGI space
    std::string query;
    for (std::list<std::string>::const_iterator iter = keywords.begin(); iter != keywords.end(); iter++) {
        if (query.length() == 0) {
            query = *iter;
        } else {
            query.append("%20");
            query.append(*iter);
        }
    }
    return query;
}

std::string action_metadata_tmdb::format_url_request(const std::list<std::string>& keywords) const{
    std::string query = format_keywords(keywords);
    std::stringstream request;
    request << URL << "/3/search/multi?api_key=" << KEY << "&query=" << query;
    return request.str();
}

bool action_metadata_tmdb::result_to_metadata(item& item, const std::string& result) const {
    boost::property_tree::ptree tree;
    
    //convert the response to a property tree
    std::stringstream ss;
    ss << result;
    boost::property_tree::json_parser::read_json(ss,tree);
    
    //if any matches
    int total_results = tree.get<int>("total_results");
    if(total_results!=0){
        //std::cout << "found " << total_results << " matches" << std::endl;
        
        //iterate through matches
        BOOST_FOREACH(const boost::property_tree::ptree::value_type &match, tree.get_child("results")) {
            //todo: ask user to choose instead of using first match
            
            //movie metadata
            item.add_metadata(metafield(metadata::TMDBID,match.second.get<int>("id")));
            std::string mediatype = match.second.get<std::string>("media_type");
            item.add_metadata(metafield(metadata::MEDIA,mediatype));    
            if(mediatype.compare("movie")==0){
                //release date
                int year,month,day;
                std::string date = match.second.get<std::string>("release_date");
                sscanf(date.c_str(),"%d-%d-%d",&year,&month,&day);
                item.add_metadata(metafield(metadata::YEAR,year));
                item.add_metadata(metafield(metadata::MONTH,month));
                item.add_metadata(metafield(metadata::DAY,day));
            
                //original title
                item.add_metadata(metafield(metadata::ORIGINAL_TITLE,match.second.get<std::string>("original_title")));
                
                //title
                item.add_metadata(metafield(metadata::TITLE,match.second.get<std::string>("title")));
                break;
            }else if(mediatype.compare("tv")==0){
                //original title
                item.add_metadata(metafield(metadata::ORIGINAL_TITLE,match.second.get<std::string>("original_name")));
                
                //title
                item.add_metadata(metafield(metadata::TITLE,match.second.get<std::string>("name")));
                break;
            }
        }
        return true;
    }
    
    return false;       
    
}


