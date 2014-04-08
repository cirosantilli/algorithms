#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout
#include <utility>      // get, pair
#include <vector>

#include "longest_increasing.hpp"

int main() {
    typedef int InputType;
    typedef std::vector<std::vector<InputType>::size_type> OutputType;
    typedef std::tuple<std::vector<InputType>, OutputType> IO;
    IO in_outs[]{
        IO{
            {0},
            {0},
        },
        IO{
            {0, 1},
            {0, 1},
        },
        IO{
            {1, 0},
            {   1},
        },
        IO{
            {2, 0, 1},
            {   1, 2},
        },
        IO{
            {0, 2, 1},
            {0,    2},
        },
        IO{
            {1, -1, 2, 0, 1, 5, 5, 2, 3},
            {    1,    3, 4,       7, 8},
        },
        IO{
            {3, 2, 6, 4, 5, 1},
            {   1,    3, 4   },
        },
    };
    OutputType output;
    for (auto& in_out : in_outs) {
        auto& input           = std::get<0>(in_out);
        auto& expected_output = std::get<1>(in_out);
#ifdef DEBUG_OUTPUT
        std::cout << "input = ";
        for (auto& i : input) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        LongestIncreasingSubsequence(input, output);
#ifdef DEBUG_OUTPUT
        std::cout << "output.size() = " << output.size() << std::endl;
        std::cout << "output = ";
        for (auto& i : output) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "expected_output.size() = " << expected_output.size() << std::endl;
        std::cout << "expected_output        = ";
        for (auto& i : expected_output) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        assert(output == expected_output);
    }
}
