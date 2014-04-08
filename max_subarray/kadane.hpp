#include <iterator>     // iterator_traits
#include <utility>      // pair
#include <vector>

#ifdef DEBUG
#include <iostream>     // cout, endl
#endif

/**
Solve the [maximum subarray problem](http://en.wikipedia.org/wiki/Maximum_subarray_problem)

Time complexity:    $O(n)$

Memory complexity:  $O(1)$ (excluding the input).

@param[in]  input_begin, input_end  Iterators pointing to the two corners of the input interval of the input container.
                                    input_end points to one element after the maximu, that is, the interval is semi open [input_begin; input_end)

@param[out] output_range Container with two elements: the index of the beginning and the end of the optimal interval.
    The end is one past the last element, which allows a pair of equal numbers (0, 0) to mean an empty interval.
    This shall be the case if all the input numbers are negative.

    If multiple solutions are possible, the algorithm will always
    choose the same solution in the following order of decreasing priority:

    1) starts first
    2) is shortest

@param[out] output_value Value attained by the optimal subarray.
    If all the input numbers are negative, the empty interval will be selected,
    and this output shall be `0`.

@tparam ITER  The type of iterator to the input.

#algorithm idea

The naive brute force approach of trying every pair would take $O(n^3)$:
$O(n^2)$ pairs * $O(n)$ length sum calculations.

This is a simple example of how dynamic programming can reduce algorithmic complexity.

Central idea: let K[i] mean: the value of the best sequence that ends at a_i, Including a_i.

Then there are two possibilities:

- if $K[i-1] > 0$, we should continue the sequence that gives that positive sum.

    Therefore, K[i] = K[i-1] + a_i.

- if K[i-1] < 0, we should give up existing sequences and start a new one,
    since continuing the best existing sequence would only bring us down.

    Therefore $K[i] = a_i$

The algorithm uses the ``keep frontier only'' strategy of dynamic programming to reduce memory usage to its minimum,
since only the last value of K is kept in memory inside a single variable instead of the entire array K.
*/
template<typename ITER>
void Kadane(
        const ITER& input_begin,
        const ITER& input_end,
        std::pair<ITER, ITER>& output_range,
        typename std::iterator_traits<ITER>::value_type& output_value) {
    typedef typename std::iterator_traits<std::vector<int>::iterator>::value_type ValueType;
    ITER begin, begin_temp, end;
    ValueType max_so_far, max_ending_here;
    begin = input_begin;
    begin_temp = input_begin;
    end = input_begin;
    max_so_far = -1;
    max_ending_here = -1;  // Holds the frontier value of K[i-1].
    for (auto it = input_begin; it != input_end; ++it) {
#ifdef DEBUG_OUTPUT
        std::cout << "*it = " << *it << std::endl;
        std::cout << "max_ending_here = " << max_ending_here << std::endl;
        std::cout << std::endl;
#endif
        if (max_ending_here <= 0) {
            max_ending_here = *it;
            begin_temp = it;
        } else {
            max_ending_here += *it;
        }
        if (max_ending_here > max_so_far) {
            max_so_far = max_ending_here;
            begin = begin_temp;
            end = it;
        }
    }
    if (max_so_far <= 0)
        max_so_far = 0;
    else
        end++;
    output_range = std::pair<ITER,ITER>{begin, end};
    output_value = max_so_far;
}
