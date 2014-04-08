#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl
#include <tuple>
#include <vector>

#include "knapsack01.hpp"

int main() {
    typedef std::tuple<std::vector<int>,
                        std::vector<int>,
                        int,
                        std::vector<std::vector<int>::size_type>
                      > InOut;
    InOut in_outs[]{
        InOut{
            {1, 2,  3 },
            {6, 10, 12},
            5,
            {1, 2}
        },
        InOut{
            {1, 2, 3, 4 , 5 },
            {3, 8, 7, 10, 14},
            10,
            {1, 2, 4}
        },
    };
    for (auto& in_out : in_outs) {
        auto& weights = std::get<0>(in_out);
        auto& values  = std::get<1>(in_out);
        auto& max_weight  = std::get<2>(in_out);
        auto& expected_output = std::get<3>(in_out);
        std::vector<unsigned int> output;
        int output_value;
#ifdef DEBUG_OUTPUT
        std::cout << "max_weight = " << max_weight << std::endl;

        std::cout << "weights = ";
        for (auto& i : weights) std::cout << i << " ";
        std::cout << std::endl;

        std::cout << "values = ";
        for (auto& i : values) std::cout << i << " ";
        std::cout << std::endl;
#endif
        Knapsack01Dynamic(weights, values, max_weight, output, output_value);
        std::sort(output.begin(), output.end());
        std::sort(expected_output.begin(), expected_output.end());
#ifdef DEBUG_OUTPUT
        std::cout << "output_value = " << output_value << std::endl;
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
