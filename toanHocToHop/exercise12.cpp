#include <stdio.h>
#include <vector>
#include "fleury.h"

using namespace std;

int main() {
    int V, E;

    // Nhập số đỉnh
    while (true) {
        printf("Nhập số lượng đỉnh (>=1): ");
        if (scanf("%d", &V) != 1) return 0;
        if (V >= 1) break;
        printf("Số đỉnh không hợp lệ. Nhập lại!\n");
    }

    // Nhập số lượng cạnh
    int emax = (V * (V - 1)) / 2;
    while (true) {
        printf("Nhập số lượng cạnh (0 <= E <= %d): ", emax);
        if (scanf("%d", &E) != 1) return 0;
        if (E >= 0 && E <= emax) break;
        printf("Số cạnh không hợp lệ. Vui lòng nhập lại!\n");
    }

    vector<vector<int> > graph(V);

    // Nhập các cạnh
    for (int i = 0; i < E; i++) {
        int src, dest;
        while (true) {
            printf("Nhập cạnh %d (src và dest cách nhau bởi khoảng trắng): ", i+1);
            scanf("%d %d", &src, &dest);

            if (src < 0 || src >= V || dest < 0 || dest >= V) {
                printf("Chỉ số đỉnh phải trong khoảng 0 đến %d. Nhập lại!\n", V - 1);
                continue;
            }
            if (src == dest) {
                printf("Không được phép self-loop (khuyên). Nhập lại!\n");
                continue;
            }

            bool exists = false;
            for (size_t j = 0; j < graph[src].size(); j++) {
                if (graph[src][j] == dest) { exists = true; break; }
            }
            if (exists) {
                printf("Cạnh %d-%d đã tồn tại. Nhập cạnh khác!\n", src, dest);
                continue;
            }

            graph[src].push_back(dest);
            graph[dest].push_back(src);
            break;
        }
    }

    printf("\n===== KẾT QUẢ =====\n");

    printf("Tìm chu trình Euler bằng thuật toán Fleury's:\n");
    vector<int> cycle = findEulerCycle(graph);

    if (cycle.empty()) {
        printf("Đồ thị không có chu trình Euler.\n");
    } else {
        int val = cycle[0];
        printf("Đồ thị có chu trình Euler là: ");
        for (size_t i = 0; i < cycle.size(); i++) {
            printf("%d ", cycle[i]);
            printf(" -> ");
        }
        printf("%d ", cycle[0]);
        printf("\n");
    }

    return 0;
}