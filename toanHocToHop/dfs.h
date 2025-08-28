#ifndef DFS_H
#define DFS_H

#include <vector>
#include <utility>
using namespace std;

void DFS(vector<pair<int,int> > ds[], int n, int src);
bool hasCycle(vector<pair<int,int> > ds[], int n);

#endif
