#ifndef LONGEST_INCREASING_H
#define LONGEST_INCREASING_H

#include <algorithm>    // lower_bound
#include <vector>

#ifdef DEBUG
#include <iostream>     // cout, endl
#endif

/**
Computes the longest increasing subsequence of the given input.

The found sequence does not need to be contiguous. For exapmle, if the input is:

    1 0 2

Then the longest increasing subsequence is:

    1 2

Time complexity:    $O(n * log(n))$, $n = input.size()$

Memory complexity:  $O(n))$, $n = input.size()$ extra memory excluding the input.

@param[in]  input  The input array in which the longest increasing subsequence must be found.
@param[out] output The indexes of the longest increasing subsequence found.

    In case that there are multiple possible outputs, the algorithm will choose the one that ends in the smallest
    possible value.

    If there are still multiple solutions, the algorithm will choose that which ends in with the smallest index.

@tparam     T      The data type of the values

# Implementation notes

Based on the pseudo code found at <http://en.wikipedia.org/wiki/Longest_increasing_subsequence#Efficient_algorithms>
on 28/09/2013. The actual implementation is original.

This can be classified as a dynamic programming algorithm, since it relies on the solutions of subproblems
to solve the larger problem, and stores the sub solutions for later use.
*/
template<typename T>
void LongestIncreasingSubsequence(const std::vector<T>& input,
        std::vector<typename std::vector<T>::size_type>& output) {
    typedef typename std::vector<T>::size_type IndexType;
    std::vector<IndexType> M(input.size(), 0);  // M[j] = index of the smallest possible last element of the longest subsequence of length j - 1.
    std::vector<IndexType> P(input.size(), 0);  // P[i] = index of the predecessor of element `i`. If the element is the first then this value has no meaning and must never be used.
    IndexType i;
    T L, j;
    L = 1;                                      // Length of the longest sequence so far.
    for (i = 1; i < input.size(); ++i) {
        auto it = std::lower_bound(M.begin(), M.begin() + L, i,
                [&input](const IndexType& a, const IndexType& b){ return input[a] < input[b]; } );
        j = it - M.begin();
        if (j == 0) { // This is the new best sequence of length one.
            M[0] = i;
            // We will never use its predecessor, so no need to touch P.
            // The length did not increase, so no need to touch L.
        } else {
            P[i] = M[j - 1];
            if ( j == L || input[i] < input[M[j]] ) {
                M[j] = i;
                L = std::max(L, j + 1);
            }
        }
#ifdef DEBUG
        std::cout << "i = " << i << std::endl;
        std::cout << "j = " << j << std::endl;
        std::cout << "P = ";
        for (auto& i : P) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "M = ";
        for (auto& i : M) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "L = " << L << std::endl;
        std::cout << std::endl;
#endif
    }
    output = std::vector<IndexType>(L);
    i = M[L - 1];
    for (auto it = output.rbegin(); it != output.rend(); ++it) {
        *it = i;
        i = P[i];
    }
}

#endif
