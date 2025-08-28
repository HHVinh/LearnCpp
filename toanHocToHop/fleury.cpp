#include "fleury.h"
#include <stdio.h>
using namespace std;

// DFS đếm số đỉnh có thể tới được
void dfsCount(const vector<vector<int> > &graph, int u, vector<bool> &visited, int &count) {
    visited[u] = true;
    ++count;
    for (size_t i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if (!visited[v]) dfsCount(graph, v, visited, count);
    }
}

// Xoá cạnh u-v
void removeEdge(vector<vector<int> > &graph, int u, int v) {
    for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
        if (*it == v) {
            graph[u].erase(it);
            break;
        }
    }
    for (vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); ++it) {
        if (*it == u) {
            graph[v].erase(it);
            break;
        }
    }
}

// Kiểm tra cạnh u-v có hợp lệ để đi tiếp không
bool isValidNextEdge(vector<vector<int> > &graph, int u, int v) {
    if (graph[u].size() == 1) return true;

    int V = graph.size();
    vector<bool> visited1(V, false);
    int count1 = 0;
    dfsCount(graph, u, visited1, count1);

    removeEdge(graph, u, v);

    vector<bool> visited2(V, false);
    int count2 = 0;
    dfsCount(graph, u, visited2, count2);

    graph[u].push_back(v);
    graph[v].push_back(u);

    return (count1 == count2);
}

// Hàm đệ quy Fleury
void fleuryDeQuy(vector<vector<int> > &graph, int u, vector<int> &path) {
    while (!graph[u].empty()) {
        int v = graph[u][0];
        if (isValidNextEdge(graph, u, v)) {
            removeEdge(graph, u, v);
            fleuryDeQuy(graph, v, path);
        } else {
            
            graph[u].erase(graph[u].begin());
            graph[u].push_back(v);
        }
    }
    path.push_back(u);
}

// Kiểm tra có Euler cycle không
bool hasEulerCycle(const vector<vector<int> > &graph) {
    int V = graph.size();
    for (int i = 0; i < V; ++i) {
        if (graph[i].size() % 2 != 0) return false;
    }

    vector<bool> visited(V, false);
    int start = -1;
    for (int i = 0; i < V; ++i) if (!graph[i].empty()) { start = i; break; }
    if (start == -1) return true;

    int count = 0;
    vector<vector<int> > tmp = graph;
    dfsCount(tmp, start, visited, count);

    for (int i = 0; i < V; ++i) {
        if (!visited[i] && !graph[i].empty()) return false;
    }
    return true;
}

// Tìm Euler cycle
vector<int> findEulerCycle(const vector<vector<int> > &graphIn) {
    vector<int> cycle;
    int V = graphIn.size();
    if (!hasEulerCycle(graphIn)) return cycle;

    vector<vector<int> > g = graphIn;

    int start = -1;
    for (int i = 0; i < V; ++i) if (!g[i].empty()) { start = i; break; }
    if (start == -1) return cycle;

    fleuryDeQuy(g, start, cycle);

    reverse(cycle.begin(), cycle.end());
    if (!cycle.empty() && cycle.front() == cycle.back()) cycle.pop_back();
    return cycle;
}