#include "dfs.h"
#include <stdio.h>

using namespace std;

// Đệ quy
void dfsDeQuy(vector<pair<int,int> > ds[], int u, vector<bool> &visited) {
    visited[u] = true;
    printf("%d ", u);
    for (vector<pair<int,int> >::iterator it = ds[u].begin(); it != ds[u].end(); ++it) {
        int v = it->first;
        if (!visited[v]) {
            dfsDeQuy(ds, v, visited);
        }
    }
}

// Duyệt DFS
void DFS(vector<pair<int,int> > ds[], int n, int src) {
    vector<bool> visited(n, false);
    printf("DFS bắt đầu duyệt từ %d: ", src);
    dfsDeQuy(ds, src, visited);
    printf("\n");
}

// Kiểm tra chu trình của 1 đỉnh
bool dfsCycle(vector<pair<int,int> > ds[], int u,
              vector<bool> &visited,
              vector<bool> &recStack) {
    visited[u] = true;
    recStack[u] = true;

    for (vector<pair<int,int> >::iterator it = ds[u].begin(); it != ds[u].end(); ++it) {
        int v = it->first;
        if (!visited[v] && dfsCycle(ds, v, visited, recStack)) {
            return true;
        } else if (recStack[v]) {
            return true;
        }
    }

    recStack[u] = false;
    return false;
}

// Kiểm tra chu trình của đồ thị
bool hasCycle(vector<pair<int,int> > ds[], int n) {
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfsCycle(ds, i, visited, recStack)) {
                return true;
            }
        }
    }
    return false;
}
