#include "danhSachKe.h"
#include <stdio.h>

// Tạo danh sách kề
void taoDanhSach(vector<pair<int,int> > ds[], int n)
{
    for (int i = 0; i < n; i++) {
        ds[i].clear();
    }
}

// In danh sách kề
void inDanhSach(vector<pair<int,int> > ds[], int n)
{
    for (int i = 0; i < n; i++) {
        if (ds[i].empty()) {
            printf("%d -> ", i);
            printf("(không có cạnh)");
        }
        else {
            printf("%d -> ", i);
            for (vector<pair<int,int> >::iterator it = ds[i].begin(); it != ds[i].end(); ++it) {
                printf("(%d, %d) ", it->first, it->second);
            }
        }
        printf("\n");
    }
}

// Thêm cạnh có hướng src -> dest và trọng số w
void themCanh(vector<pair<int,int> > ds[], int n, int src, int dest, int w)
{
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        for (vector<pair<int,int> >::iterator it = ds[src].begin(); it != ds[src].end(); ++it) {
            if (it->first == dest) {
                it->second = w;
                return;
            }
        }
        ds[src].push_back(make_pair(dest, w));
    }
}

// Kiểm tra cạnh
bool kiemTraCanh(vector<pair<int,int> > ds[], int n, int src, int dest)
{
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        for (vector<pair<int,int> >::iterator it = ds[src].begin(); it != ds[src].end(); ++it) {
            if (it->first == dest) return true;
        }
    }
    return false;
}

// Lấy trọng số
int layTrongSo(vector<pair<int,int> > ds[], int n, int src, int dest)
{
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        for (vector<pair<int,int> >::iterator it = ds[src].begin(); it != ds[src].end(); ++it) {
            if (it->first == dest) return it->second;
        }
    }
    return 0;
}
