#include <stdio.h>
#include <vector>
#include "danhSachKe.h"

using namespace std;

int main()
{
    int n, m;
    printf("Nhập số lượng đỉnh: ");
    scanf("%d", &n);

    // Yêu cầu nhập lại nếu nhập sai
    do {
        printf("Nhập số lượng cạnh (1 đến %d): ", n*n);
        scanf("%d", &m);
        if (m <= 0 || m > n*n) {
            printf("Số cạnh không hợp lệ. Vui lòng nhập lại!\n");
        }
    } while (m <= 0 || m > n*n);

    vector<pair<int,int> > ds[n];
    taoDanhSach(ds, n);
    
    // Nhập cạnh
    for (int i = 1; i <= m; i++) {
        int src, dest, w;
        while (true) {
            printf("Nhập cạnh %d (src, dest và weight cách nhau bởi khoảng trắng): ", i);
            scanf("%d %d %d", &src, &dest, &w);

            if (src >= 0 && src < n && dest >= 0 && dest < n) {
                if (src == dest) {
                    printf("Bạn đang thêm self-loop (khuyên) tại đỉnh %d.\n", src);
                }
                themCanh(ds, n, src, dest, w);
                break;
            } else {
                printf("Chỉ số đỉnh phải trong khoảng 0 đến %d. Nhập lại!\n", n - 1);
            }
        }
    }

    printf("\nDanh sách kề:\n");
    inDanhSach(ds, n);

    // Menu
    int choice;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Kiểm tra cạnh\n");
        printf("2. Lấy trọng số cạnh\n");
        printf("0. Thoát\n");
        printf("\nLựa chọn: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int s, d;
            printf("Nhập cạnh cần kiểm tra (src và dest cách nhau bởi khoảng trắng): ");
            scanf("%d %d", &s, &d);
            if (kiemTraCanh(ds, n, s, d)) {
                printf("Có cạnh %d -> %d\n", s, d);
            } else {
                printf("Không có cạnh %d -> %d\n", s, d);
            }
        }
        else if (choice == 2) {
            int s, d;
            printf("Nhập cạnh cần lấy trọng số (src và dest cách nhau bởi khoảng trắng): ");
            scanf("%d %d", &s, &d);
            int w = layTrongSo(ds, n, s, d);
            if (w != 0) {
                printf("Trọng số cạnh %d -> %d là: %d\n", s, d, w);
            } else {
                printf("Không có cạnh %d -> %d\n", s, d);
            }
        }
        else if (choice != 0) {
            printf("Lựa chọn không hợp lệ. Vui lòng nhập lại!\n");
        }
    } while (choice != 0);

    return 0;
}
