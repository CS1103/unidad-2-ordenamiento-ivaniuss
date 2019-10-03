//
// Created by rudri on 9/17/2019.
//

#include "Sort.h"
#include <iostream>
#include <vector>
#include <algorithm>    
#include <iterator> 
#include <stdlib.h> 
#include <time.h>   
#include <stdexcept>
using namespace std;

template<typename T>
Sort<T>::Sort(std::vector<T> values) {
    this->values = values;
}

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


using namespace std;
template<typename T>
int partition(T *a,int start,int end)
{
    int pivot=a[end];
    int P_index=start;
    int i,t;

    for(i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            t=a[i];
            a[i]=a[P_index];
            a[P_index]=t;
            P_index++;
        }
    }
    t=a[end];
    a[end]=a[P_index];
    a[P_index]=t;

    return P_index;
}

template<typename T>
void Quicksort(T *a,int start,int end)
{
    if(start<end)
    {
        int P_index=partition(a,start,end);
        Quicksort(a,start,P_index-1);
        Quicksort(a,P_index+1,end);
    }
}

