//
// Created by Ivan Mamani on 28/09/2019.
//

#ifndef SORTMETHODS_QUICK_SORT_H
#define SORTMETHODS_QUICK_SORT_H

#include <vector>
#include <iostream>

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


#endif //SORTMETHODS_QUICK_SORT_H
