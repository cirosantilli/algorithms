#ifndef KNAPSACK01_H
#define KNAPSACK01_H

#include <vector>

/**
Solves the 0-1 knapsack problem via dynamic programming.

Time   complexity: $O(max_weight * weights.size())$
Memory complexity: $O(max_weight * weights.size())$

All inputs must be contain only positive integer types.

The input is expected to be normalized beforehand, that is,
all values, weights and the maximum weight must have already been divided
by the GCD of all of those values, or this algorithm will be very memory inneficient.

@param[in] weights      Weight of each item.
@param[in] values       Value of each item.
@param[in] max_weight   Maximum weight to be carried.
@param[out] output      Modified to contain one of the sets of element indexes that reaches the minimum.

    If this container is ordered, no sorting shall be done on it, and the item order is unspecified.

    If more than one optimal solution exists, it is not specified which one shall be returned.

@param[out] output_value The maximum value attained by the solution.

@tparam WEIGHT data type of the weights
@tparam VALUE  data type of the values

# Implementation notes

TODO is it possible to not keep the 2D accepted_items, thus reducing memory to n instead of n^2?
*/
template<typename WEIGHT = int, typename VALUE = int>
void Knapsack01Dynamic(const std::vector<WEIGHT>& weights,
        const std::vector<VALUE>& values,
        WEIGHT max_weight,
        std::vector<typename std::vector<WEIGHT>::size_type>& output,
        VALUE& output_value) {
    typename std::vector<WEIGHT>::size_type number_items = weights.size();
    std::vector<VALUE> cur_line(std::vector<VALUE>(max_weight + 1));
    std::vector<VALUE> last_line(std::vector<VALUE>(max_weight + 1));
    std::vector<std::vector<bool>> accepted_items(number_items + 1,
            std::vector<bool>(max_weight + 1));
    for (typename std::vector<WEIGHT>::size_type i = 1; i <= number_items; ++i ) {
        for (WEIGHT w = 1; w <= max_weight; ++w ) {
            if (weights[i] <= w) {
                VALUE new_optimum_if_accept = values[i] + last_line[w - weights[i]];
                if (new_optimum_if_accept > last_line[w]) {
                    accepted_items[i][w] = true;
                    cur_line[w] = new_optimum_if_accept;
                    continue;
                }
            }
            cur_line[w] = last_line[w];
        }
        last_line = cur_line;
    }
    output_value = cur_line[max_weight];
    // Generate the solution.
    for (typename std::vector<WEIGHT>::size_type i = number_items; i > 0; --i) {
        if (accepted_items[i][max_weight]) {
            output.push_back(i);
            max_weight -= weights[i];
        }
    }
}

#endif
