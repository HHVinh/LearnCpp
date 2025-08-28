#include "prim.h"
#include <stdio.h>
#include <limits.h>

using namespace std;

// Tìm đỉnh có key nhỏ nhất trong tập chưa thuộc MST
int minKey(vector<int> &key, vector<bool> &inMST, int V) {
    int minVal = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < minVal) {
            minVal = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int> > &graph, int V) {
    vector<int> parent(V, -1);
    vector<int> key(V, INT_MAX);
    vector<bool> inMST(V, false);

    key[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // In kết quả
    int totalWeight = 0;
    printf("Cây khung nhỏ nhất (MST) dùng thuật toán Prim:\n");
    printf("Cạnh / Trọng số\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d / %d\n", parent[i], i, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    printf("Tổng trọng số của MST: %d\n", totalWeight);
}
