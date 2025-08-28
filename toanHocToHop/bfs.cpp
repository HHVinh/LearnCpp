#include "bfs.h"
#include <stdio.h>
#include <queue>

using namespace std;

// Duyệt BFS
void BFS(vector<pair<int,int> > ds[], int n, int src)
{
    vector<bool> visited(n, false);
    vector<int> dist(n, -1);
    vector<int> parent(n, -1);

    queue<int> q;
    visited[src] = true;
    dist[src] = 0;
    q.push(src);

    printf("BFS bắt đầu duyệt từ %d: ", src);

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        printf("%d ", u);

        for (vector<pair<int,int> >::iterator it = ds[u].begin(); it != ds[u].end(); ++it) {
            int v = it->first;
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    printf("\n");

    // In đường đi ngắn nhất
    printf("Đường đi ngắn nhất từ %d:\n", src);
    for (int v = 0; v < n; v++) {
        if (dist[v] != -1) {
            printf("- Đỉnh %d: khoảng cách = %d, đường đi = ", v, dist[v]);

            vector<int> path;
            for (int x = v; x != -1; x = parent[x]) {
                path.push_back(x);
            }

            for (int i = path.size() - 1; i >= 0; i--) {
                printf("%d", path[i]);
                if (i > 0) printf(" -> ");
            }
            printf("\n");
        }
    }
}
