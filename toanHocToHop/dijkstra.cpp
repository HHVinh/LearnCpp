#include "dijkstra.h"
#include <stdio.h>
#include <limits.h>

using namespace std;

// Tìm đỉnh có khoảng cách nhỏ nhất trong tập chưa được xử lý
int minDistance(vector<int> &dist, vector<bool> &visited, int V) {
    int minVal = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= minVal) {
            minVal = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void dijkstra(vector<vector<int> > &graph, int V, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);
    dist[src] = 0;

    // Tìm đường đi ngắn nhất cho tất cả các đỉnh
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break;

        visited[u] = true;

        // Cập nhật khoảng cách cho các đỉnh kề
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // In kết quả
    printf("Đường đi ngắn nhất từ đỉnh %d dùng thuật toán Dijkstra:\n", src);
    printf("Đỉnh / Khoảng cách từ nguồn\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            printf("%d / INF\n", i);
        else
            printf("%d / %d\n", i, dist[i]);
    }
}
