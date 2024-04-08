#ifndef KRUSKAL_HEADER
#define KRUSKAL_HEADER
#include <vector>
#include "../dsu.hpp"

struct Edge {
    int u, v, weight;
};

std::vector<Edge> Kruskal(int parent[], int num_child[], std::vector<Edge> E, int nodes) {
    std::vector<Edge> mst;
    DSU::make_set(nodes, parent, num_child);

    std::sort(E.begin(), E.end(), 
        [](const Edge &a, const Edge &b) -> bool {
            return a.weight < b.weight;
        }
    );

    for (auto const &e : E) {
        if (mst.size() == nodes-1) break;
        if (DSU::dsu_union(e.u, e.v, parent, num_child)) {
            mst.push_back(e);
        }
    }

    return mst;
}

#endif