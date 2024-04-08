struct DSU {
    vector<int> lab;

    DSU(int n=0) { lab.assign(n+1, -1); }
    bool same_set(int u, int v) { return find(u) == find(v); }
    int find(int u) { return lab[u] < 0 ? u : lab[u] = find(lab[u]); }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }
};



















struct DSU {
    vector<int> lab;

    DSU(int n=0) { lab.assign(n+1, -1); }
    int find(int u) { return lab[u] < 0 ? u : lab[u] = find(lab[u]); }
    bool same_set(int u, int v) { return find(u) == find(v); }

    bool join(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return false;

        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    } 
}