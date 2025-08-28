#ifndef FLEURY_H
#define FLEURY_H

#include <vector>
using namespace std;

void dfsCount(const vector<vector<int> > &graph, int u, vector<bool> &visited, int &count);
void removeEdge(vector<vector<int> > &graph, int u, int v);
bool isValidNextEdge(vector<vector<int> > &graph, int u, int v);
void fleuryDeQuy(vector<vector<int> > &graph, int u, vector<int> &path);
bool hasEulerCycle(const vector<vector<int> > &graph);
vector<int> findEulerCycle(const vector<vector<int> > &graphIn);

#endif



// #ifndef FLEURY_H
// #define FLEURY_H

// #include <vector>
// using namespace std;

// bool hasEulerCycle(vector<vector<int> > &graph, int V);
// vector<int> findEulerCycle(vector<vector<int> > &graph, int V);

// #endif
