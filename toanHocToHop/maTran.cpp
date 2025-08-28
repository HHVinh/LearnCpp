#include "maTran.h"
#include <stdio.h>

// Cấp phát động và tạo ma trận
void taoMaTran(int** &arr, int n)
{
    arr = new int*[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
}

// In ma trận
void inMaTran(int** arr, int n)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// Thêm cạnh có hướng src -> dest và trọng số w
void themCanh(int** arr, int n, int src, int dest, int w)
{
    if (src >= 0 && src < n && dest >= 0 && dest < n) {
        arr[src][dest] = w;
    }
}

// Kiểm tra cạnh
bool kiemTraCanh(int** arr, int n, int src, int dest)
{
    return (src >= 0 && src < n && dest >= 0 && dest < n && arr[src][dest] != 0);
}

// Lấy trọng số
int layTrongSo(int** arr, int n, int src, int dest)
{
    if (src >= 0 && src < n && dest >= 0 && dest < n)
        return arr[src][dest];
    return 0;
}
