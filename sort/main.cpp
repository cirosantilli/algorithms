#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl

#include "merge.hpp"
#include "quick.hpp"

int main() {
    typedef std::tuple<std::vector<int>,
                        std::vector<int> > InOut;

    InOut in_outs[]{
        InOut{
            {1, 3, 2, 0},
            {0, 1, 2, 3}
        },
        InOut{
            {4, 5, 6, 2, 1, 3, 0, 7},
            {0, 1, 2, 3, 4, 5, 6, 7}
        },
        // Size not power of 2, specially 2^n + 1
        // Edgy for merge sort.
        InOut{
            {1, 2, 0},
            {0, 1, 2}
        },
        InOut{
            {1, 4, 0, 2, 3},
            {0, 1, 2, 3, 4}
        },
    };
    void (*algorithms[])(std::vector<int>&){MergeSort, QuickSort};
    for (auto& algorithm : algorithms) {
        for (auto& in_out : in_outs) {
            auto input = std::get<0>(in_out);
            auto expected_output = std::get<1>(in_out);
#ifdef DEBUG_OUTPUT
            std::cout << "input = ";
            for (auto& i : input) std::cout << i << " ";
            std::cout << std::endl;
            std::cout << std::endl;
#endif
            (*algorithm)(input);
#ifdef DEBUG_OUTPUT
            std::cout << std::endl;

            std::cout << "output = ";
            for (auto& i : input) std::cout << i << " ";
            std::cout << std::endl;

            std::cout << "expected_output = ";
            for (auto& i : expected_output) std::cout << i << " ";
            std::cout << std::endl;

            std::cout << std::endl;
#endif
            assert(input == expected_output);
        }
    }
}
