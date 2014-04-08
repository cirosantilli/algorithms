#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl
#include <tuple>
#include <vector>
#include <utility>      // pair

#include "hanoi.hpp"

int main() {
    // Classic problem.
    {
        typedef std::vector<std::pair<int,int>> OutputType;
        typedef std::tuple<int, int, int, OutputType> IO;
        IO in_outs[]{
            // One moves.
            IO{1, 0, 1, {{0, 1}}},
            IO{1, 0, 2, {{0, 2}}},
            IO{1, 1, 2, {{1, 2}}},
            IO{2, 0, 1, {{0, 2}, {0, 1}, {2, 1}}},
            IO{2, 0, 2, {{0, 1}, {0, 2}, {1, 2}}},
            IO{3, 0, 1, {
                {0, 1}, {0, 2}, {1, 2},
                {0, 1}, {2, 0}, {2, 1},
                {0, 1}
            }},
            // Edge case: move to self.
            IO{1, 0, 0, {}},
            IO{2, 0, 0, {}},
        };
        for (auto& in_out : in_outs) {
            OutputType output;
            auto& n_disks         = std::get<0>(in_out);
            auto& from            = std::get<1>(in_out);
            auto& to              = std::get<2>(in_out);
            auto& expected_output = std::get<3>(in_out);
            Hanoi(n_disks, from, to, output);
#ifdef DEBUG_OUTPUT
            std::cout << "output =" << std::endl;
            for (auto& i : output) std::cout << i.first << " " << i.second << std::endl;
            std::cout << "expected_output =" << std::endl;
            for (auto& i : expected_output) std::cout << i.first << " " << i.second << std::endl;
            std::cout << std::endl;
#endif
            assert(output == expected_output);
        }
    }

#ifdef UNDEFINED
    // Generalized Hanoi. TODO not yet implemented.
    {
        typedef unsigned int InputType;
        typedef std::vector<std::pair<InputType,InputType>> OutputType;
        typedef std::tuple<std::vector<InputType>,
                           std::vector<InputType>,
                           OutputType,
                           > IO;
        IO in_outs[]{
            {
                {0},
                {1},
                3,
                {
                    {0, 1}
                },
            },
            {
                {0, 0},
                {1, 1},
                3,
                {
                    {0, 2},
                    {0, 1},
                    {2, 1}
                },
            },
        };
        OutputType output;
        for (auto& in_out : in_outs) {
            auto& initial_position = std::get<0>(in_out);
            auto& final_position   = std::get<1>(in_out);
            auto& n_pegs           = std::get<2>(in_out);
            auto& expected_output  = std::get<3>(in_out);
            HanoiAnyState(initial_position, final_position, n_pegs, output);
            assert(output == expected_output);
        }
    }
#endif
}
