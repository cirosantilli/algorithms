#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl

#include "make_change.hpp"

int main() {
    typedef std::tuple<std::vector<int>,
                       int,
                       std::vector<int>> InOut;

    InOut in_outs[]{
        InOut{
            {1, 3, 4},
            6,
            {0, 2, 0}
        },
        InOut{
            {1, 3, 4, 7, 11, 24},
            1731,
            {0, 1, 0, 0, 0, 72}
        },
    };
    for (auto& in_out : in_outs) {
        auto& coin_values = std::get<0>(in_out);
        auto& total  = std::get<1>(in_out);
        auto& expected_output = std::get<2>(in_out);
        std::vector<int> output;
#ifdef DEBUG_OUTPUT
        std::cout << "total = " << total << std::endl;

        std::cout << "coin_values = ";
        for (auto& i : coin_values) std::cout << i << " ";
        std::cout << std::endl;
#endif
        MakeChange(coin_values, total, output);
#ifdef DEBUG_OUTPUT
        std::cout << "output = ";
        for (auto& i : output) std::cout << i << " ";
        std::cout << std::endl;

        std::cout << "expected_output = ";
        for (auto& i : expected_output) std::cout << i << " ";
        std::cout << std::endl;

        std::cout << std::endl;
#endif
        assert(output == expected_output);
    }
}
