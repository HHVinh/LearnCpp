#include "hierholzer.h"
#include <stdio.h>
#include <stack>

using namespace std;

// Kiểm tra điều kiện chu trình Euler
bool hasEulerCycle(vector<vector<int> > &graph, int V) {
    vector<int> inDegree(V, 0);
    vector<int> outDegree(V, 0);

    for (int u = 0; u < V; u++) {
        for (vector<int>::iterator it = graph[u].begin(); it != graph[u].end(); ++it) {
            int v = *it;
            outDegree[u]++;
            inDegree[v]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (inDegree[i] != outDegree[i]) {
            return false;
        }
    }
    return true;
}

// Thuật toán Hierholzer để tìm chu trình Euler
vector<int> findEulerCycle(vector<vector<int> > &graph, int V) {
    vector<int> cycle;
    if (!hasEulerCycle(graph, V)) {
        return cycle;
    }

    stack<int> st;
    vector<int> path;
    vector<vector<int> > adjCopy = graph;

    st.push(0);
    while (!st.empty()) {
        int u = st.top();
        if (!adjCopy[u].empty()) {
            int v = adjCopy[u].back();
            adjCopy[u].pop_back();
            st.push(v);
        } else {
            path.push_back(u);
            st.pop();
        }
    }

    for (int i = path.size() - 1; i >= 0; i--) {
        cycle.push_back(path[i]);
    }

    return cycle;
}
