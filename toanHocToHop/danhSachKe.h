#ifndef DANHSACHKE_H
#define DANHSACHKE_H

#include <vector>
#include <utility>

using namespace std;

void taoDanhSach(vector<pair<int,int> > ds[], int n);
void inDanhSach(vector<pair<int,int> > ds[], int n);
void themCanh(vector<pair<int,int> > ds[], int n, int src, int dest, int w);
bool kiemTraCanh(vector<pair<int,int> > ds[], int n, int src, int dest);
int layTrongSo(vector<pair<int,int> > ds[], int n, int src, int dest);

#endif
