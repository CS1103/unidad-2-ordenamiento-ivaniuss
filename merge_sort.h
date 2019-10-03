//
// Created by Ivan Mamani on 28/09/2019.
//

#ifndef SORTMETHODS_MERGE_SORT_H
#define SORTMETHODS_MERGE_SORT_H


#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <iterator>

template <typename It>
void merge(It left, It middle, It right)
{
    using value_type = typename std::iterator_traits<It>::value_type;
    std::vector<value_type> left_side_copy(left, middle);
    It L = left_side_copy.begin();
    It R = middle;
    while (L != left_side_copy.end()  &&  R != right)
    {
        if ( *L <= *R )
        {
            *left = *L;
            ++L;
        }
        else {
            *left = *R;
            ++R;
        }
        ++left;
    }
    std::copy(L, left_side_copy.end(), left);
}

template <typename It>
void merge_sort(It left, It right)
{
    if (auto dist = std::distance(left, right); dist > 1)
    {
        It middle = left + dist / 2;
        merge_sort(left, middle);
        merge_sort(middle, right);
        merge(left, middle, right);
    }
}


#endif //SORTMETHODS_MERGE_SORT_H


