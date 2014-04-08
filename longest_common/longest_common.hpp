#ifndef LONGEST_COMMON_H
#define LONGEST_COMMON_H

#include <vector>

#ifdef DEBUG
#include <iostream>     // cout
#endif

/**
Calculates the [longest common subsequence](https://en.wikipedia.org/wiki/Longest_common_subsequence_problem)
between two strings.

The substrings do not need to be contiguous.

@param[in]  input0, input1  The input strings.
@param[out] output          The longest substring.

    In case that there are multiple possible outputs

@tparam T The data type of the values of each string. Must implement `==`.
*/
template<typename T>
void LongestCommonSubsequence(
        const std::vector<T>& input0,
        const std::vector<T>& input1,
        std::vector<typename std::vector<T>::size_type>& output) {
    typedef typename std::vector<T>::size_type SizeType;
    typedef char PreviousDirectionType;
    const PreviousDirectionType kUp   = 0;
    const PreviousDirectionType kLeft = 1;
    const PreviousDirectionType kDiag = 2;
    SizeType input0_size = input0.size();
    SizeType input1_size = input1.size();
    std::vector<std::vector<PreviousDirectionType>> previous(
            input0_size + 1, std::vector<PreviousDirectionType>(input1_size + 1));
    std::vector<SizeType> length_cur(input1_size + 1, 0);
    std::vector<SizeType> length_prev(input1_size + 1, 0);
    SizeType i, j;
    for (i = 1; i <= input0_size; ++i) {
        for (j = 1; j <= input1_size; ++j) {
            if (input0[i - 1] == input1[j - 1]) {
                previous[i][j] = kDiag;
                length_cur[j]  = length_prev[j - 1] + 1;
            } else {
                if (length_cur[j - 1] < length_prev[j]) {
                    previous[i][j] = kUp;
                    length_cur[j]  = length_prev[j];
                } else {
                    previous[i][j] = kLeft;
                    length_cur[j]  = length_cur[j - 1];
                }
            }
        }
#ifdef DEBUG_OUTPUT
        std::cout << "i = " << i << std::endl;
        std::cout << "length_cur  = ";
        for (auto& i : length_cur) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "length_prev = ";
        for (auto& i : length_prev) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "previous[i] = ";
        for (auto it = previous[i].begin(); it != previous[i].end(); ++it) std::cout << (int)*it << " ";
        // TODO why does auto fail to compile on g++ 4.8??
        //for (auto& i : previous[i]) std::cout << i << " ";
        // TODO why segfault?
        //for (PreviousDirectionType& i : previous[i]) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        length_prev = length_cur;
    }
    output = std::vector<SizeType>(length_cur[input1_size]);
    i = input0_size;
    j = input1_size;
    auto it = output.rbegin();
    while (it != output.rend()) {
        switch (previous[i][j]) {
            case kLeft: {
                --j;
                break;
            }
            case kUp: {
                --i;
                break;
            }
            case kDiag: {
                *it = input0[i - 1];
                ++it;
                --i;
                --j;
                break;
            }
        }
    }
}

#endif
