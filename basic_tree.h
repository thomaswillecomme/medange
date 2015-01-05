/* 
 * File:   basic_tree.h
 * Author: thomas
 *
 * Created on 4 janvier 2015, 19:51
 */

#ifndef BASIC_TREE_H
#define	BASIC_TREE_H

#include <type_traits>

template <typename T>
class basic_tree {
    const T item;
    basic_tree<T>* left;
    basic_tree<T>* right;
public:
    basic_tree(const T& item);
    virtual ~basic_tree();
    
    basic_tree<T>* set_left(const T& p_item);
    basic_tree<T>* set_right(const T& p_item);
    
    basic_tree<T>* get_left();
    basic_tree<T>* get_right();
    
    const T& get_item();
    
private:

};

template <typename T>
basic_tree<T>::basic_tree(const T& p_item) : item(p_item), left(0), right(0){
    
}

template <typename T>
basic_tree<T>::~basic_tree(){
    if(left)
        delete(left);
    if(right)
        delete(right);
    if(std::is_pointer<T>::value)
        delete(item);
}

template <typename T>
basic_tree<T>* basic_tree<T>::set_left(const T& p_item){
    this->left = new basic_tree(p_item);
    return this->left;
}

template <typename T>
basic_tree<T>* basic_tree<T>::set_right(const T& p_item){
    this->right = new basic_tree(p_item);
    return this->right;
}

template <typename T>
basic_tree<T>* basic_tree<T>::get_left(){
    return this->left;
}

template <typename T>
basic_tree<T>* basic_tree<T>::get_right(){
    return this->right;
}

template <typename T>
const T& basic_tree<T>::get_item(){
    return this->item;
}

#endif	/* BASIC_TREE_H */

