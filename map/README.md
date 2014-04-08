TODO: broken. Was working before small refactoring, so should be simple to fix.

<http://en.wikipedia.org/wiki/Associative_array>

Map is an interface which can be implemented with many data structures.

A map takes one element of one type and returns a second one of another type.

Average operation time:

|                     | insert | lookup | delete |
|---------------------|--------|--------|--------|
| Binary Search Tree  | log n  | log n  | log n  |
| Hash Map            | 1      | 1      | 1      |

Worst case operation time: `n` for all.

TODO: implement a self balancing tree like RB-tree or AVL to reduce worst case.
