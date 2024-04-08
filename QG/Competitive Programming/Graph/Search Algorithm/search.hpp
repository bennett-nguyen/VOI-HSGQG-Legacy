#ifndef SEARCH_ALGO_HEADER
#define SEARCH_ALGO_HEADER
#include <vector>
#include <queue>

void DFS(int current_node, std::vector<int> adjacency_list[], bool visited[]) {
    visited[current_node] = true;

    for (auto const &child : adjacency_list[current_node]) {
        if (visited[child]) continue;
        DFS(child, adjacency_list, visited);
    }
}

void BFS(int start_node, std::vector<int> adjacency_list[], bool visited[]) {
    std::queue<int> q;
    q.push(start_node);
    visited[start_node] = true;

    while (!q.empty()) {
        int current_node = q.front();
        q.pop();

        for (auto const &child_node : adjacency_list[current_node]) {
            if (visited[child_node]) continue;
            q.push(child_node);
            visited[child_node] = true;
        }
    }
}

#endif