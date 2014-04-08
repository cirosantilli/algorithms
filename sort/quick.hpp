#ifndef QUICK_H
#define QUICK_H

#include <algorithm>    // swap
#include <cmath>        // pow, ceil
#include <vector>
#include <utility>      // pair

#ifdef DEBUG
#include <iostream>     // cout, endl
#endif

/**
Sort the input vector via quick sort.

Same interface as MergeSort.

Worst case time complexity:     $O(input.size() ^ 2)$.

Average case time complexity:   $O(input.size() * log input.size())$.

Extra memory excluding input:   $O(1)$

# Implementation notes

Quicksort is much easier to implement than mergesort.
*/
template<typename COMPARABLE = int>
void QuickSort(std::vector<COMPARABLE>& input) {
    typedef typename std::vector<COMPARABLE>::size_type SizeType;
    SizeType left_begin, left, right, pivot;
    std::vector<std::pair<SizeType,SizeType>> recursion_stack{{0, input.size() - 1}};
    while (!recursion_stack.empty()) {
        std::tie(left_begin, pivot) = recursion_stack.back();
        recursion_stack.pop_back();
        left = left_begin;
        right = left;
#ifdef DEBUG_OUTPUT
                std::cout << "left_begin = " << left_begin  << std::endl;
                std::cout << "left       = " << left        << std::endl;
                std::cout << "right      = " << right       << std::endl;
                std::cout << "pivot      = " << pivot       << std::endl;
#endif
        while (right < pivot) {
            if (input[right] < input[pivot]) {
                std::swap(input[left], input[right]);
                left++;
            }
            right++;
        }
        std::swap(input[left], input[pivot]);
#ifdef DEBUG_OUTPUT
                std::cout << "left  = " << left << std::endl;
                std::cout << "input = ";
                for (auto& i : input) std::cout << i << " ";
                std::cout << std::endl;
                std::cout << std::endl;
#endif
        if (left_begin + 1 < left)
            recursion_stack.push_back({left_begin, left - 1});
        if (left + 1 < pivot)
            recursion_stack.push_back({left + 1, pivot});
    }
}

#endif
