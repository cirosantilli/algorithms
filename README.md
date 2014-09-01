# Algorithms

Algorithms, data structures and algorithmic exercises in C++.

Educational use only, for serious applications use real libraries like Boost.

Non stdlib implementations are accepted, but you must provide an installation procedure.

Multiple significantly different implementations are accepted, including in different languages and using different libraries.

Every algorithm is tested on a standard virtual machine with fixed memory and CPU, and has CPU time measured.

Intuitive algorithm explanation and complexity analysis will not be included here. Consider <https://github.com/cirosantilli/comp-sci> instead.

Solutions to *algorithmic* programming exercises are accepted. If after modeling the problem it boils down to a single well known algorithm algorithm, only state the model and which algorithm to use, but don't code anything.

## Places where you can find algorithmic problems

Most of the websites don't have solutions. One good way to search for unofficial solutions to GitHub search for the contest name.

Problem sources automatic online checks:

- [TopCoder](http://www.topcoder.com/active-challenges/develop). No solutions. 6M registered users. Money prizes. Some company proposed problems have Non Disclosure Agreements. Timed submission contests.
- [HackerRank](https://www.hackerrank.com/categories/fp/intro). No solutions, 3M Round A. Timed submission contests.
- [Kaggle](https://www.kaggle.com/competitions). Data science focused. No solutions. Some problems have money prizes.
- [Sphere Online Judge (SPOJ)](http://www.spoj.com/problems/classical/all/).  No solutions. 200K users, 10000 problems.
- [Project Euler](http://projecteuler.net/problems). 350K users, only ~450 problems. No solutions. Since 2001. Probably one of the oldest around, but did not evolve much.
- [UVa](http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=1). 100K registered users. No solutions. Slow website.

Yearly contests:

- [ACM International Collegiate Programming Contest](http://icpc.baylor.edu/). [Wiki](en.wikipedia.org/wiki/ACM_International_Collegiate_Programming_Contest).  No solutions. Eligibility: less than five years of university education before the contest. Started in 1977. [World final problems](http://icpc.baylor.edu/worldfinals/problems).
- [Google Code Jam](http://code.google.com/codejam/contests.html). Only a few solutions.
- [ICFP](http://en.wikipedia.org/wiki/ICFP_Programming_Contest). One problem per year. Since 1998.

Problem sources without automatic online checks:

- <http://rubyquiz.com/index.html>. Solutions in Ruby. 150 problems, not active.

## Algorithms that could be included

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

-   String metrics: <http://en.wikipedia.org/wiki/String_metric>

    The length of the already implemented longest common subsequence result is a metric, although it is too local to be practically used as a metric.

    Subjective as application dependant, and the only thing to optimize is to match "what humans think is sensible".

    Formal definitions set the basic operations, and what must be optimized.

    -   <http://en.wikipedia.org/wiki/Levenshtein_distance>

        The most famous one. Operations: single char addition, deletion and substitution. Dynamic programming algorithm.

-   <http://en.wikipedia.org/wiki/String_searching_algorithm>

-   <http://en.wikipedia.org/wiki/Sequence_alignment> seem to be string search algorithms with more complex metrics. Used in practice in bioinformatics.

-   <http://en.wikipedia.org/wiki/Longest_repeated_substring_problem>

-   <http://en.wikipedia.org/wiki/Approximate_string_matching>

## Contributing

[Google C++ style](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml).

Header only implementations because:

- educational only, so writing faster is more important than compiling faster
- easier to copy paste for programming competitions

Keep one algorithm per header.
