#include "action_is_dir.h"

action_is_dir::action_is_dir() : action(){}

bool action_is_dir::perform(item& p_item) const{
    return boost::filesystem::is_directory(p_item.get_path());
}

