#ifndef HANOI_H
#define HANOI_H

#include <utility>
#include <vector>

/**
Solves the classic Hanoi problem starting from any of the 3 pegs `from`
and ending at any of the 3 pegs `to` in the minimum ammont of moves.
*/
template<typename INPUT_TYPE>
void Hanoi(int n_disks, int from, int to,
        std::vector<std::pair<INPUT_TYPE,INPUT_TYPE>>& output) {
    if (from != to) {
        if (n_disks == 1) {
            output.push_back(std::pair<int,int>{from,to});
            return;
        } else {
            int other = 3 - to - from;
            Hanoi(n_disks - 1, from, other, output);
            output.push_back(std::pair<int,int>{from,to});
            Hanoi(n_disks - 1, other, to, output);
        }
    } else {
        return;
    }
}

/**
Find a minimal path solution to generalizations of the towers of Hanoi problem.

The generalizations to the classic puzzle include:

- from any starting position to any ending position.

    The classical puzzel always starts from the position where all pegs are the first pike,
    and they must finish at either the second or third pike.

    This also solves the problem for any initial or final configuration in a minimal number of moves.

    For exapmle, this could solve the problem if the initial position is:

    - smallest        disk is on first pike
    - second smallest disk is on first pike

    and the desired final position is:

    - both disks on the third pike

@param[in] inital_position, final_position Container that describes the initial and final positions.

    Positions are described as follows: the ith element of the vector contains the number of peg
    on which the ith largest pike is located.

    For example, the following situation:

    -        largest disk is on first  pike
    - second largest disk is on second pike
    - third  largest disk is on first  pike

    can be represented as:

    {0, 1, 0}

@parm[in] n_pegs The total number of pegs. Currently only works for 3.

@parm[out] output The minimal sequence of moves that solves the puzzle.

    Each move is represented as a pair `{i, j}` meaning the top disk of the ith peg
    is to be moved to the top of the jth peg.
*/
template<typename INPUT_TYPE>
void HanoiAnyState(const std::vector<INPUT_TYPE>& initial_position,
                   const std::vector<INPUT_TYPE>& final_position,
                   const INPUT_TYPE n_pegs,
                   std::vector<std::pair<typename std::vector<INPUT_TYPE>::size_type,INPUT_TYPE>>& output) {
    if (n_pegs > 3) {
        throw "Not yet implemented.";
    } else {
        throw "Not yet implemented.";
        for (auto initial_position_it = initial_position.begin(), final_position_it = final_position.begin();
                  initial_position_it != initial_position.end();
                  ++initial_position_it, ++final_position_it) {
            auto largest_wrong_position = *initial_position_it;
            auto largest_correct_position = *final_position_it;
            if (largest_wrong_position != largest_correct_position) {
                auto other_peg = 3 - (largest_wrong_position + largest_correct_position);
                // TODO Critical steps missing here.
                //HanoiManyToOne(std::next(initial_position_it), other_peg, n_pegs, output);
                output.push_back({largest_wrong_position, largest_correct_position});
                //HanoiOneToMany(other_peg, std::next(final_position_it), n_pegs, output);
            }
        }
    }
}

#endif
