# Graph

<http://en.wikipedia.org/wiki/Graph_%28abstract_data_type%29>

Graphs structures must be able to contain arbitrary properties associated to each edge (node pair), and this is their major design concern.

For example:

-   on a shortest path problem, the only edge property is the width of an edge.

-   on a city, each street takes a time to cross, and has a different length.

    The two are not necessarily proportional since some streets have more traffic than others.

    Cover the maximum length withing a fixed amount of time.

    In this problem, each edge must have 2 integers associated to it: length and time to cross.

Node properties are simpler to deal with as they can just be stored into a single array or properties.

Dynamic operations such as addition and removal of edges and nodes are also required, but often less important, as many practical graph problems are based on static graphs.

## Implementations

There are two major graph implementations:

### Adjacency list

Represent nodes by integers. For each node, store what it points to.

-   directed implementation: array of destination to properties maps:

        g[origin0] = {dest00: properties00, dest01: properties01}.
        g[origin1] = {dest10: properties10, dest11: properties11}.
        ...

    Probably the best option in general, as it is `O(1)` average to get edge properties from an origin / destination pair.

-   undirected: same as above, but store every node pair as `(smaller, larger)`, and convert all inputs `(larger, smaller)` to `(smaller, larger)`.

### Adjacency matrix

Keep a matrix of edge properties.

Advantage: `O(1)` worst time to access each edge properties from node pair.

Disadvantage: `O(n^2)` memory, regardless of graph density.

This method is generally less useful because:

- most graphs encountered in practice are very sparse, so the matrix will contain too many 0 entries.
- adjacency list implementation can already reach `O(1)` average time (but not worst).
