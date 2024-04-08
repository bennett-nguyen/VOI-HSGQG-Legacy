#include <bits/stdc++.h>
using namespace std;

#define el '\n'
#define ll long long
#define FOR(i, l, r) for (int i = l; i <= r; i++)
#define FOD(i, l, r) for (int i = l; i >= r; i--)

using pii = pair<int, int>;
const int MAX = 1e4+1;

struct predicate_dijktra {
    bool operator()(const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

bool relaxation(int current, int child, int weight, int dist[]) {
    if (dist[child] <= dist[current] + weight) return false;
    dist[child] = dist[current] + weight;
    return true;
}

void Dijkstra(int start_node, int dist[], vector<pii> adj[]) {
    priority_queue<pii, vector<pii>, predicate_dijktra> pq;
    memset(dist, 0x3f, sizeof(dist));

    dist[start_node] = 0;
    pq.push(make_pair(start_node, 0));

    while (!pq.empty()) {
        pii i = pq.top(); pq.pop();
        int current = i.first;
        int dist_to_curr_node = i.second;

        if (dist_to_curr_node > dist[current]) continue;

        for (auto const &j : adj[current]) {
            int child = j.first;
            int weight = j.second;

            if (relaxation(current, child, weight, dist)) {
                pq.push(make_pair(child, dist[child]));
            }
        }   
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("a.inp", "r", stdin);
    #endif
    
    return 0;
}