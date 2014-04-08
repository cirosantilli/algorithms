#include <algorithm>    // TODO why required?
#include <cassert>
#include <iostream>     // cout, endl

#include "graph.hpp"

int main() {
    // Dijikstra.
    {
        // Input graphs and origin dest pair and expected output shortest paths.

        typedef std::tuple<GraphList,
                            std::pair<GraphList::EdgeNumberType,GraphList::EdgeNumberType>,
                            std::vector<GraphList::EdgeNumberType> > InOut;

        InOut in_outs[]{
            // InOut needed because tuple constructors are explicit
            // Edge case: path to self with edge to self.
            InOut{
                {
                    {0, {{0, 0}}},
                },
                {0, 0},
                {0, 0}
            },
            // Edge case: path to self with no edge to self.
            InOut{
                {
                    {0, {}},
                },
                {0, 0},
                {0, 0}
            },
            InOut{
                {
                    {0, {{1, 1}}},
                    {1, {}},
                },
                {0, 1},
                {0, 1}
            },
            InOut{
                {
                    {0, {{1, 1}}},
                    {1, {{2, 1}}},
                    {2, {}},
                },
                {0, 2},
                {0, 1, 2}
            },
            InOut{
                {
                    {0, {{2, 1}}},
                    {1, {}},
                    {2, {{1, 1}}},
                },
                {0, 1},
                {0, 2, 1}
            },
            // No path.
            InOut{
                {
                    {0, {}},
                    {1, {}},
                },
                {0, 1},
                {}
            },
            // Example similar to that drawn at: <http://optlab-server.sce.carleton.ca/POAnimations2007/DijkstrasAlgo.html>
            // Some edges have been made unidirectional, and the ambiguity resolved.
            InOut{
                {
                    {0, {{1, 2}, {2, 5}, {3, 4},  }},
                    {1, {{2, 2}, {4, 7}, {6, 12}, }},
                    {2, {{4, 5}, {5, 3}, {3, 1},  }},
                    {3, {{2, 1}, {5, 4},          }},
                    {4, {{5, 1}, {7, 5},          }},
                    {5, {{4, 1}, {7, 7},          }},
                    {6, {{7, 3},                  }},
                    {7, {                         }},
                },
                {0, 7},
                {0, 1, 2, 5, 4, 7}
            },
        };
        for (auto& in_out : in_outs) {
            auto& graph = std::get<0>(in_out);
            auto& origin_destination = std::get<1>(in_out);
            auto& expected_path = std::get<2>(in_out);
            std::vector<GraphList::EdgeNumberType> path;
#ifdef DEBUG_OUTPUT
            std::cout << graph << std::endl;
#endif
            graph.dijikstra(origin_destination.first, origin_destination.second, path);
#ifdef DEBUG_OUTPUT
            std::cout << graph << std::endl;
            std::cout << "dijikstra path: ";
            for (auto& node_number : path)
                std::cout << node_number << " ";
            std::cout << std::endl;
            std::cout << std::endl;
#endif
            assert(path == expected_path);
        }
    }
}

