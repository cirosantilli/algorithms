#ifndef GRAPH_H
#define GRAPH_H

#include <initializer_list>
#include <list>
#include <string>
#include <sstream>
#include <utility>              // pair
#include <vector>

/**
Represents a directed graph via adjency lists.

@todo use array of destionation -> edge properties hash maps implementation. Currently uses array of tuples.
*/
class GraphList {
    public:
        typedef std::vector<int>::size_type EdgeNumberType ;
        class Edge {
            public:
                Edge(){}
                Edge(EdgeNumberType to, int weight) : to(to), weight(weight) {}

                // To which vertex this edge goes to.
                EdgeNumberType to;
                int weight;
        };
        typedef std::pair<EdgeNumberType,std::vector<Edge> > NodeEdgesPair;

        GraphList() {}
        GraphList(std::initializer_list<NodeEdgesPair> pairs) {
            for (auto& pair : pairs)
                this->add(pair);
        }

        /**
        Adds a node / edges pair to the graph.

        If the node number is larger than the current number of nodes, the current number of
        nodes is increased to fit that new list of edges.

        No error check is done to see if one of the edges points to a destination node that is not in the graph,
        If you add such an edge, you must also explicitly add the node afterwards, even if it has no edges coming
        out of it for example via:

            graph.add({1234, {}});
        */
        void add(NodeEdgesPair pair) {
            EdgeNumberType node_number = pair.first;
            if (nodes.size() < node_number + 1) {
                nodes.resize(node_number + 1);
            }
            nodes[node_number] = pair.second;
        }

        std::string str() const {
            std::stringstream ss;
            for (EdgeNumberType i = 0; i < nodes.size(); ++i) {
                ss << i << ": ";
                for (auto& edge : nodes[i]) {
                    ss << edge.to << "," << edge.weight << " ";
                }
                ss << std::endl;
            }
            return ss.str();
        }

        /**
        Calculates the single source shortest path from one node to another.

        Recommended for dense graphs (unordered list implementation).

        The weights of the graph must all be positive. No check is done to determine that.

        @param[in] from, to Node numbers of source and destination respectively.

            If `from == to`, a 0 length path is assumed to exist even if there is no edge from `from` to itself.

            If either `from` or `to` not in the graph, the behaviour is undefined (possibly an infinite loop).

        @param[out] path

            - if a path exists, this it shall be modified to contain one of the shortest paths from from to to.

                In case that there are mutiple solutions, only one of them shall be found and it is not predictable which.

                The output shall be of type: `{from, X, Y, Z, ..., to}`.

                This is still valid if `to == from`, in which case the output will be of type: `{from, from}`

            - else: this parameter shall be modified to be equal to an empty container.
        */
        void dijikstra(const EdgeNumberType& from,
                    const EdgeNumberType& to,
                    std::vector<EdgeNumberType>& path) const {
            std::list<EdgeNumberType> not_visited;  // This is better as a list than an array, so that it is possible to loop over the non-visited nodes only to find the next min one.
            std::vector<int> distances(nodes.size(), std::numeric_limits<int>::max());
            std::vector<EdgeNumberType> previous(nodes.size());
            EdgeNumberType cur(from);
            distances[from] = 0;
            for (EdgeNumberType i = 0; i < nodes.size(); i++) {
                if (i != from)
                    not_visited.push_back(i);
            }
            path = std::vector<EdgeNumberType>();
            while (cur != to) {
                //DEBUG prints!
                /*
                std::cout << "cur = " << cur << std::endl;
                std::cout << "distances = ";
                for (auto& d : distances) std::cout << d << " " ;
                std::cout << std::endl;
                std::cout << "not_visited = ";
                for (auto& d : not_visited) std::cout << d << " " ;
                std::cout << std::endl;
                std::cout.flush();
                */
                // Update weights of nodes neighbour to cur.
                for (auto& edge : nodes[cur]) {
                        int new_distance = distances[cur] + edge.weight;
                        if (new_distance < distances[edge.to]) {
                            distances[edge.to] = new_distance;
                            previous[edge.to] = cur;
                        }
                }
                // Find non visited min and make it current.
                int min_distance = std::numeric_limits<int>::max();
                auto min_not_visited_it = not_visited.begin();
                for (auto it = not_visited.begin(); it != not_visited.end(); ++it) {
                    if (distances[*it] < min_distance) {
                        min_distance = distances[*it];
                        min_not_visited_it = it;
                    }
                }
                // Next has infinite distance: graph not connected.
                if (distances[*min_not_visited_it] == std::numeric_limits<int>::max())
                    return;
                cur = *min_not_visited_it;
                not_visited.erase(min_not_visited_it);
            }
            // Rebuild the path.
            cur = to;
            path.push_back(to);
            cur = previous[cur];
            while (cur != from) {
                path.push_back(cur);
                cur = previous[cur];
            }
            path.push_back(from);
            std::reverse(path.begin(), path.end()); //TODO with a push_front container this would not be necessary.
                                                    //so what to do? force the users to give push_front containers?
        }

        /**
        Calculates the single source shortest path from one node to another.

        Recommended for sparse graphs (Fibonacci heap implementation).

        Has not been implemented because there is no Fibonacci heap in the STL, only in Boost.
        */
        void dijikstraSparse(const EdgeNumberType& from,
                    const EdgeNumberType& to,
                    std::vector<EdgeNumberType>& path) {}

    private:
        std::vector<std::vector<Edge> > nodes;

        friend std::ostream& operator<<(std::ostream& os, const GraphList& rhs) {
            return os << rhs.str();
        }
};

#endif
