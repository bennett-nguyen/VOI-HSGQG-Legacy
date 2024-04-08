#ifndef DIJKSTRA_HEADER
#define DIJKSTRA_HEADER

#include <queue>
#include <utility>
#include <vector>
#include <cstring>

using pii = std::pair<int, int>;

// pair<int, int> -> first: dinh; second: do dai
struct predicate {
    bool operator()(const pii &a, const pii &b) {
        return a.second > b.second;
    }
};

bool relaxation(int current_node, int child_node, int weight, int distance[]) {
    if (distance[child_node] <= distance[current_node] + weight) return false;
    distance[child_node] = distance[current_node] + weight;
    return true;
}

void Dijkstra(int start_node, int distance[], std::vector<pii> adjacency_list[]) {
    std::priority_queue<pii, std::vector<pii>, predicate> pq;
    std::memset(distance, 0x3f, sizeof(distance));

    distance[start_node] = 0;
    pq.push(std::make_pair(start_node, 0));

    while (!pq.empty()) {
        pii i = pq.top(); pq.pop();
        int current_node = i.first;
        int dist_to_curr_node = i.second;

        if (dist_to_curr_node > distance[current_node]) continue;

        for (auto const &j : adjacency_list[current_node]) {
            int child_node = j.first;
            int weight = j.second;

            if (relaxation(current_node, child_node, weight, distance)) {
                pq.push(std::make_pair(child_node, distance[child_node]));
            }
        }   
    }
}

#endif