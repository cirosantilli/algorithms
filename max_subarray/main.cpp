#include <algorithm>    // TODO why required?
#include <cassert>      // assert
#include <iostream>     // cout, endl
#include <iterator>     // iterator_traits
#include <utility>      // pair
#include <vector>

#include "kadane.hpp"

int main() {
    typedef int InputType ;
    // Input array, output range, output sum.
    typedef std::tuple<std::vector<InputType>,
                       std::pair<std::iterator_traits<std::vector<InputType>::iterator>::difference_type,
                                 std::iterator_traits<std::vector<InputType>::iterator>::difference_type>,
                       InputType> InOut;
    InOut in_outs[]{
        // All positive: easy, take all.
        InOut{
            {1, 3, 2},
            {0, 3},
            6
        },
        InOut{
            {0, -1, 4, -2, 1, 2, -5, 3},
            {2, 6},
            5
        },
        // All negative. Edge case. Take no elements and return an empty range [0, 0[.
        InOut{
            {-1, -3, -2},
            {0, 0},
            0
        },
        // Multiple solutions. Take the one that starts first and is shortest.
        // In this case, the shortest solution is the empty solution.
        InOut{
            {0, 0, 0},
            {0, 0},
            0
        },
        // Coming first has priority over being the shortest.
        InOut{
            {1, 2, -100, 3},
            {0, 2},
            3
        },
        // The shortest possible solution is taken in case of multiple solutions.
        InOut{
            {1, 2, 0, -2, 2},
            {0, 2},
            3
        },
        // Edge case: single element in input.
        InOut{
            {1},
            {0, 1},
            1
        },
    };
    std::pair<std::vector<InputType>::iterator, std::vector<InputType>::iterator> output_range;
    InputType output_value;
    for (auto& in_out : in_outs) {
        auto& input                 = std::get<0>(in_out);
        auto& expected_output_range = std::get<1>(in_out);
        auto& expected_output_value = std::get<2>(in_out);
#ifdef DEBUG
        std::cout << "input = ";
        for (auto& i : input) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        Kadane(input.begin(), input.end(), output_range, output_value);
#ifdef DEBUG
        std::cout << "output begin = " << output_range.first  - input.begin() << std::endl;
        std::cout << "output end   = " << output_range.second - input.begin() << std::endl;
        std::cout << "output value = " << output_value << std::endl;
        std::cout << std::endl;
        std::cout << "expected output begin = " << expected_output_range.first  << std::endl;
        std::cout << "expected output end   = " << expected_output_range.second << std::endl;
        std::cout << "expected output value = " << expected_output_value << std::endl;
        std::cout << std::endl;
#endif
        assert(output_range.first  - input.begin() == expected_output_range.first);
        assert(output_range.second - input.begin() == expected_output_range.second);
        assert(output_value == expected_output_value);
    }
}
