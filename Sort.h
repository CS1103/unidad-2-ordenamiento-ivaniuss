//
// Created by rudri on 9/17/2019.
//


#define SORT_METHODS_SORT_H

#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>

template <typename T>

class Sort{
 
public:
//interfaces
   std::vector<T> values;
    explicit Sort(std::vector<T> values);
    void MergeSort(){
        merge_sort(0,values.size()-1);
    }
    void QuickSort(){
        quickSort(0,values.size()-1);
    }
    void mergeSort( int , int );
    void quickSort( int , int );
    int partition( int , int );
    void HeapSort();
    void ShellSort();
    void print();

};
