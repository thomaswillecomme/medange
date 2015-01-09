#include  "item.h"
#include "metadata.h"
const boost::filesystem::path& item::get_path(){
    return path;
}

item::item(const boost::filesystem::path& p_path) : path(p_path){
    
}

void item::add_metadata(const metafield& field) {
    fields.add(field);
}

const metafield* item::get_metadata(const metafield_description& field) const {
    return fields.get(field);
}
