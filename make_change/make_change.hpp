#ifndef MAKE_CHANGE_H
#define MAKE_CHANGE_H

#include <vector>

#ifdef DEBUG
#include <iostream>     // cout, endl
#endif

void VectorSum(const std::vector<int>& v0, const std::vector<int>& v1,
        std::vector<int>& output) {
    output.resize(v0.size());
    for (std::vector<int>::size_type i = 0; i < v0.size(); ++i)
        output[i] = v0[i] + v1[i];
}

/**
Solve the change making problem via dynamic programming.

Worst case time complexity: $O(output.size() ^ 3)$. TODO check. It is \sum i^2. Does that make i^3?

Given a value `total`, choose the minimum ammount of coins
with one of the values inside `coin_values` that sums up to exactly `total`.

@param[in] coin_values  The value of each type of coin. Must be already ordered.
                        All values must be positive.
@param[in] total        The total value that must be reached with the coins.
                        Must be positive.
@param[out] output      The solution, that is, how many of each type of coin is needed to attain the total.

    If the total is not attainable, this container shall be empty.
*/
void MakeChange(const std::vector<int>& coin_values, int total, std::vector<int>& output) {
    std::vector<bool> possible(total + 1, false);
    std::vector<int> coin_counts(total + 1, std::numeric_limits<int>::max());
    std::vector<std::vector<int> > solutions(total + 1, std::vector<int>(coin_values.size(), 0));
    possible[0] = true;
    coin_counts[0] = 0;
    for (std::vector<int>::size_type i = 0; i < coin_values.size(); ++i) {
        int coin_value = coin_values[i];
        possible[coin_value] = true;
        solutions[coin_value][i] = 1;
        coin_counts[coin_value] = 1;
    }
    for (int subtotal = 1; subtotal <= total; ++subtotal) {
#ifdef DEBUG_OUTPUT
        std::cout << "subtotal = " << subtotal << std::endl;
        std::cout << "possible    = ";
        for (auto i : possible) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << "coin_counts = ";
        for (auto& i : coin_counts) std::cout << i << " ";
        std::cout << std::endl;
        std::cout << std::endl;
#endif
        int min_coin_count = coin_counts[subtotal];
        int best_first, best_second;
        bool cur_possible = false;
        for (int first = 0; first <= subtotal / 2; ++first) {
            int second = subtotal - first;
            if (possible[first] && possible[second]) {
#ifdef DEBUG_OUTPUT
                std::cout << "first = " << first << std::endl;
                std::cout << "second = " << second << std::endl;
                std::cout << "coin_counts[first] = " << coin_counts[first] << std::endl;
                std::cout << "coin_counts[second] = " << coin_counts[second] << std::endl;
                std::cout << "min_coin_count = " << min_coin_count << std::endl;
                std::cout << std::endl;
#endif
                int new_coin_count = coin_counts[first] + coin_counts[second];
                if (new_coin_count < min_coin_count) {
                    best_first = first;
                    best_second = second;
                    min_coin_count = new_coin_count;
                    cur_possible = true;
                }
            }
        }
        if (cur_possible) {
            possible[subtotal] = true;
            coin_counts[subtotal] = coin_counts[best_first]
                + coin_counts[best_second];
            VectorSum(solutions[best_first], solutions[best_second], solutions[subtotal]);
        }
    }
#ifdef DEBUG_OUTPUT
    std::cout << "possible    = ";
    for (auto i : possible) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "coin_counts = ";
    for (auto& i : coin_counts) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    for (auto& solution : solutions) {
        for (auto& i : solution) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
#endif
    output = solutions[total];
}

#endif
