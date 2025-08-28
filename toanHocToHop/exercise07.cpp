#include <stdio.h>
#include <vector>
#include "prim.h"

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

    // Khởi tạo ma trận kề
    vector<vector<int> > graph(n, vector<int>(n, 0));

    // Nhập số lượng cạnh
    int emax = (n * (n - 1)) / 2;
    while (true) {
        printf("Nhập số lượng cạnh (0 <= E <= %d): ", emax);
        scanf("%d", &m);
        if (m >= 0 && m <= emax) break;
        printf("Số cạnh không hợp lệ. Vui lòng nhập lại!\n");
    }

    // Nhập các cạnh
    for (int i = 0; i < m; i++) {
        int src, dest, weight;
        while (true) {
            printf("Nhập cạnh %d (src, dest và weight cách nhau bởi khoảng trắng): ", i+1);
            scanf("%d %d %d", &src, &dest, &weight);

            if (src < 0 || src >= n || dest < 0 || dest >= n) {
                printf("Chỉ số đỉnh phải trong khoảng 0 đến %d. Nhập lại!\n", n - 1);
                continue;
            }
            if (src == dest) {
                printf("Không được phép self-loop (khuyên). Nhập lại!\n");
                continue;
            }
            if (graph[src][dest] != 0) {
                printf("Cạnh %d - %d đã tồn tại. Nhập lại!\n", src, dest);
                continue;
            }
            if (weight < 1) {
                printf("Trọng số phải >= 1. Nhập lại!\n");
                continue;
            }

            graph[src][dest] = weight;
            graph[dest][src] = weight;
            break;
        }
    }

    printf("\n===== KẾT QUẢ =====\n");
    primMST(graph, n);

    return 0;
}
