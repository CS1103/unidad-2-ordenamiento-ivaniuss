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

/*
template <typename T> size_t MedianOfThree(T &a, T &b, T &c, size_t ai, size_t bi, size_t ci)
{
	if (a >= b && a <= c)
		return ai;
	if (b >= a && b <= c)
		return bi;
	return ci;
}

template <typename T> size_t QuicksortPartition(vector<T> &A, size_t lo, size_t hi)
{
	size_t ci = (int)(0.5*(lo+hi)+0.5);
	size_t pivotIndex = MedianOfThree(A[lo], A[ci], A[hi], lo, ci, hi);
	T pivot = A[pivotIndex];

	size_t i = lo;
	size_t j = hi;
	while(true)
	{
		while(A[i] <= pivot && i < pivotIndex) i++;
		while(A[j] >= pivot && j > pivotIndex) j--;
		if (i == pivotIndex && j == pivotIndex)
			return pivotIndex;

		T tmp = A[i];
		A[i] = A[j];
		A[j] = tmp;

		if(i == pivotIndex)
			pivotIndex = j;
		else if(j == pivotIndex)
			pivotIndex = i;
	}
}

template <typename T> void Quicksort(vector<T> &A, size_t lo, size_t hi)
{
	if (lo < hi)
	{
		size_t p = QuicksortPartition<T>(A, lo, hi);
		if (p > 0) 
			Quicksort<T>(A, lo, p-1);
		Quicksort<T>(A, p+1, hi);
	}
}

template <typename T> void Quicksort(vector<T> &A)
{
	if (A.size() <= 1)
		return; 
	Quicksort(A, 0, A.size()-1);
}

// ******************************************

template <typename T> bool SortResultIsValid(const vector<T> &A)
{
	for(size_t i = 1; i < A.size(); i++)
		if (A[i] < A[i-1])
			return false;
	return true;
}


*/
