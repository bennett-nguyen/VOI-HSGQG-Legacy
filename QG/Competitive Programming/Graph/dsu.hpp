#ifndef DSU_HEADER
#define DSU_HEADER
#include <algorithm>

namespace DSU {
    void make_set(int size, int parent[], int num_child[]) {
        for (int i = 1; i <= size; i++) {
            parent[i] = i;
            num_child[i] = 1;
        }
    }

    int find(int node, int parent[]) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node], parent);
    }

    bool dsu_union(int u, int v, int parent[], int num_child[]) {
        u = find(u, parent);
        v = find(v, parent);

        if (u == v) return false;
        if (num_child[u] < num_child[v]) {
            std::swap(u, v);
        }

        parent[v] = u;
        num_child[u] += num_child[v];
        return true;
    }

    bool same_set(int u, int v, int parent[]) {
        return find(u, parent) == find(v, parent);
    }
}


#endif