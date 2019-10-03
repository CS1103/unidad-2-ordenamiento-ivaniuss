#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "Sort.h"
#include "definiciones.h"

int main(void)
{
    std::vector<int> arr {5, 12, 11, 5, 4, 3, 2, 1, 6};

    merge_sort(arr.begin(), arr.end());

    for(auto const &i : arr) {
        std::cout << ' ' << i;
    }
    std::cout << '\n';

    return 0;
}
