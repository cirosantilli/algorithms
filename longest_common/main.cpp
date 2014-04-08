#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl
#include <tuple>
#include <vector>

#include "longest_common.hpp"

int main() {
    typedef int InputType;
    typedef std::vector<std::vector<InputType>::size_type> OutputType;
    typedef std::tuple<std::vector<InputType>,
                       std::vector<InputType>,
                       OutputType> IO;
    IO in_outs[]{
        IO{
            {0},
            {0},
            {0},
        },
        IO{
            {0},
            {1},
            {},
        },
        IO{
            {2, 0, 1},
            {0, 2, 1, 0, 3},
            {0, 1},
        },
    };
    OutputType output;
    for (auto& in_out : in_outs) {
        auto& input0           = std::get<0>(in_out);
        auto& input1           = std::get<1>(in_out);
        auto& expected_output  = std::get<2>(in_out);
#ifdef DEBUG_OUTPUT
        std::cout << "input0 = ";
        for (auto& i : input0) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "input1 = ";
        for (auto& i : input1) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        LongestCommonSubsequence(input0, input1, output);
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
