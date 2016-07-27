//
//  misc.hpp
//  poker
//
//  Created by Ben Ellis on 7/19/16.
//  Copyright © 2016 Ben Ellis. All rights reserved.
//

#ifndef misc_h
#define misc_h

#include <iostream>
#include <vector>

/* make all combinations in a list of size k and place them into result 2d vector */
//template <typename T>
//void combinations(const std::vector<T>& full_list, std::vector<T>& tmp, std::vector<std::vector<T>>& result, int offset, int k);

template <typename T>
void internal_combinations(const std::vector<T>& full_list, std::vector<T>& tmp, std::vector<std::vector<T>>& result, int offset, int n_elem_left) {
    if(n_elem_left == 0) {
        result.push_back(tmp);
        return;
    }
    for(int i = offset; i <= full_list.size() - n_elem_left; ++i) {
        tmp.push_back(full_list[i]);
        internal_combinations(full_list, tmp, result, i + 1, n_elem_left - 1);
        tmp.pop_back();
    }
}

template <typename T>
std::vector<std::vector<T>> combinations(const std::vector<T>& full_list, int subset_size){
    std::vector<T> tmp;
    std::vector<std::vector<T>> result;
    internal_combinations(full_list, tmp, result, 0, subset_size);
    return result;
}


#endif /* misc_h */
