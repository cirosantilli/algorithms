#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl
#include <tuple>
#include <vector>
#include <utility>      // pair

#include "hanoi.hpp"

int main() {
    typedef unsigned int InputType;
    typedef std::tuple<std::vector<InputType>,
                        std::vector<InputType>,
                        InputType,
                        std::vector<std::pair<std::vector<InputType>::size_type,InputType>>> InOut;
    InOut in_outs[]{
        InOut{
            {0},
            {1},
            3,
            {
                {0,1}
            },
        },
        InOut{
            {0, 0},
            {1, 1},
            3,
            {
                {0,2},
                {0,1},
                {2,1}
            },
        },
    };
    std::vector<std::pair<std::vector<InputType>::size_type,InputType>> output;
    for (auto& in_out : in_outs) {
        auto& initial_position = std::get<0>(in_out);
        auto& final_position   = std::get<1>(in_out);
        auto& n_pegs           = std::get<2>(in_out);
        auto& expected_output  = std::get<3>(in_out);
#ifdef DEBUG_OUTPUT
        std::cout << "initial_position =";
        for (auto& i : initial_position) std::cout << " " << i;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "final_position =";
        for (auto& i : initial_position) std::cout << " " << i;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "n_pegs = " << n_pegs << std::endl;
#endif
        HanoiTowers(initial_position, final_position, n_pegs, output);
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
