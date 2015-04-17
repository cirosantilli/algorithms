# Algorithms

Algorithms, data structures and algorithmic exercises.

More theoretical information can be found at: <https://github.com/cirosantilli/computer-science>

1. Infrastructure
    1. [src/](src/): source code of educational implementations
    1. [data/](data/): data input and output for some of the problems
    1. [test](test): script to test the implementations
1.  Algorithms
    1.  [Graph](graph.md)
    1.  [Hanoi tower](hanoi-tower.md)
    1.  [Knapsack](knapsack.md)
        1. [Change making](change-making.md)
    1.  [Longest common subsequence](longest-common-subsequence.md)
    1.  [Longest increasing subsequence](longest-increasing-subsequence.md)
    1.  [Maximum subarray](maximum-subarray.md)
    1.  [Map](map.md)
    1.  [String search](string-search.md)
    1.  [tac](tac.md)

## Usage

Dependencies:

- `make` (POSIX)
- `gcc` >= 4.8
- `g++` >= 4.8
- Java >= 1.7

Then:

    test tac.c

or equivalently:

    test src/c/tac.c

This will build the program, choose and feed input data to it, and check if the output is as expected.

More info at (TODO implement help command):

    test --help

## Sources

- <http://www.geeksforgeeks.org/fundamentals-of-algorithms>

- <http://algs4.cs.princeton.edu/home/>, which has lots GPL Java source. This kind soul has put the source up on GitHub: <https://github.com/aistrate/AlgorithmsSedgewick>

- <http://www3.cs.stonybrook.edu/~algorith/>. Links to tons of open source algorithm implementations that solve many problems. Each algorithm has a rating, and algorithms are all classified.

- <http://en.wikibooks.org/wiki/Algorithm_Implementation>

- <https://github.com/vhf/free-programming-books/blob/master/free-programming-books.md#algorithms--data-structures>

## About

Educational use only, for serious applications use real libraries like Boost.

Multiple significantly different implementations are accepted, including in different languages and using different libraries.

Solutions to *algorithmic* programming exercises are accepted. If after modeling the problem it boils down to a single well known algorithm algorithm, only state the model and which algorithm to use, but don't code anything.

## Algorithmic problem sources

Huge list of problem sets at: <https://github.com/vhf/free-programming-books/blob/893072fbbb5702ab7853dc0cc784595e4cf5b1b4/problem-sets-competitive-programming.md>

My favorites are:

- [TopCoder](http://www.topcoder.com/active-challenges/develop). No solutions. 6M registered users. Money prizes. Some company proposed problems have Non Disclosure Agreements. Timed submission contests.
- [HackerRank](https://www.hackerrank.com/categories/fp/intro). No solutions, 3M Round A. Timed submission contests.
- [Kaggle](https://www.kaggle.com/competitions). Data science focused. No solutions. Some problems have money prizes.
- [Sphere Online Judge (SPOJ)](http://www.spoj.com/problems/classical/all/). No solutions. 200K users, 10000 problems.
- [Project Euler](http://projecteuler.net/problems). 350K users, only ~450 problems. No solutions. Since 2001. Probably one of the oldest around, but did not evolve much.
- [UVa](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=1). 100K registered users. No solutions. Slow website.
- [CareerCup](http://www.careercup.com): Interview questions.

Yearly contests:

- [ACM International Collegiate Programming Contest](http://icpc.baylor.edu/). [Wiki](en.wikipedia.org/wiki/ACM_International_Collegiate_Programming_Contest). No solutions. Eligibility: less than five years of university education before the contest. Started in 1977. [World final problems](http://icpc.baylor.edu/worldfinals/problems).
- [Google Code Jam](http://code.google.com/codejam/contests.html). Only a few solutions.
- [ICFP](http://en.wikipedia.org/wiki/ICFP_Programming_Contest). One problem per year. Since 1998.

Problem sources without automatic online checks:

- <http://rubyquiz.com/index.html>. Solutions in Ruby. 150 problems, not active.

## TODO

Algorithms that could be included:

-   <http://stackoverflow.com/questions/2113795/quickest-way-to-find-missing-number-in-an-array-of-numbers>

    Find the missing number of an increasing sequence that has been mixed up.

    E.g., start with:

        1 2 3 4 5 6

    Mix up:

        6 3 5 4 2 1

    Remove an unknown number:

        6 5 4 2 1

    Which number was removed?

    Solution: sum up, use the sum formula, take difference.

-   <http://stackoverflow.com/questions/3492302/easy-interview-question-got-harder-given-numbers-1-100-find-the-missing-numbe>

    Same as above, but remove 2 numbers instead.

-   <http://stackoverflow.com/questions/1586858/find-the-smallest-integer-not-in-a-list>

    Find the smallest non-negative integer *not* in an unsorted array of length `N`.

    The array is stored in RAM.

    Application: generate unique IDs in a system where any ID can be removed.

    Solution intuition:

    - `N` is the largest possible value in case of an increasing sequence. This means that you can throw away any number larger than `N`.
    - if the array were sorted, it would be easy.
    - there are non-comparison sorting algorithms for integers in a fixed range that perform $O(N)$ time $O(1)$ memory.

    Solution: 2 passes, first try to put every number smaller than `N` in the array position with same value as the number. If already occupied by another number, do the same for the other number. Throw away anything larger than `N`.

-   <https://en.wikipedia.org/wiki/Out-of-core_algorithm>. We currently have `tac`. Find more.

-   <http://en.wikipedia.org/wiki/Partition_problem>. Partition a multiset into two sub-multisets such that the sum of each sub-multiset is equal. NP-complete.

    Many not have a solution, which leads to the optimization version: minimize the difference. NP-hard.

-   <http://en.wikipedia.org/wiki/Stable_marriage_problem>

-   <http://en.wikipedia.org/wiki/National_Resident_Matching_Program#Matching_algorithm>

-   <http://en.wikipedia.org/wiki/Stable_roommates_problem>

Some NP-complete ones:

-   <http://en.wikipedia.org/wiki/Karp%27s_21_NP-complete_problems>

-   <http://en.wikipedia.org/wiki/Vertex_cover>


