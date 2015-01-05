#include "action_is_file.h"

action_is_file::action_is_file() : action(){
}

action_is_file::~action_is_file() {

}

bool action_is_file::perform(item& p_item) const{
    return boost::filesystem::is_regular_file(p_item.get_path());
}
