#ifndef HIERHOLZER_H
#define HIERHOLZER_H

#include <vector>
using namespace std;

bool hasEulerCycle(vector<vector<int> > &graph, int V);
vector<int> findEulerCycle(vector<vector<int> > &graph, int V);

#endif