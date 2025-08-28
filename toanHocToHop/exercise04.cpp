#include <stdio.h>
#include <vector>
#include "danhSachKe.h"
#include "dfs.h"

using namespace std;

int main() {
    int n, m;
    
    // Nhập số lượng đỉnh
    while (true) {
        printf("Nhập số lượng đỉnh (1 <= V <= 10^5): ");
        scanf("%d", &n);
        if (n >= 1 && n <= 100000) break;
        printf("Số đỉnh không hợp lệ. Vui lòng nhập lại!\n");
    }

    vector<pair<int,int> > ds[n];
    taoDanhSach(ds, n);

    // Nhập số lượng cạnh
    int emax = n * (n - 1);
    while (true) {
        printf("Nhập số lượng cạnh (0 <= E <= %d): ", emax);
        scanf("%d", &m);
        if (m >= 0 && m <= emax) break;
        printf("Số cạnh không hợp lệ. Vui lòng nhập lại!\n");
    }

    // Nhập các cạnh
    for (int i = 0; i < m; i++) {
        int src, dest;
        while (true) {
            printf("Nhập cạnh %d (src và dest cách nhau bởi khoảng trắng): ", i+1);
            scanf("%d %d", &src, &dest);

            if (src < 0 || src >= n || dest < 0 || dest >= n) {
                printf("Chỉ số đỉnh phải trong khoảng 0 đến %d. Nhập lại!\n", n - 1);
                continue;
            }
            if (src == dest) {
                printf("Không được phép nhập self-loop (khuyên). Nhập lại!\n");
                continue;
            }
            if (kiemTraCanh(ds, n, src, dest)) {
                printf("Cạnh %d -> %d đã tồn tại. Nhập lại!\n", src, dest);
                continue;
            }

            themCanh(ds, n, src, dest, 1);
            break;
        }
    }

    // Nhập đỉnh nguồn
    int start;
    while (1) {
        printf("Nhập đỉnh nguồn (0 <= S < %d): ", n);
        scanf("%d", &start);

        if (start >= 0 && start < n) {
            break;
        } else {
            printf("Đỉnh nguồn không hợp lệ. Vui lòng nhập lại!\n");
        }
    }

    printf("\n===== KẾT QUẢ =====\n");
    DFS(ds, n, start);

    // Kiểm tra chu trình của đồ thị
    if (hasCycle(ds, n)) {
        printf("Đồ thị có chu trình.\n");
    } else {
        printf("Đồ thị không có chu trình.\n");
    }

    return 0;
}
