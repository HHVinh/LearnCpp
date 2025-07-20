#include <iostream>

void nhapMang(int arr[], int n){
    for(int i = 0; i < n; i++){
        std::cout << "Nhập phần tử thứ " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

void xuatMang(int arr[], int n){
    std::cout << "Mảng vừa nhập là: \n";
    for(int i = 0; i < n; i++){
        std::cout << arr[i];
    }
}

int main() {
    int arr[100];
    int n;

    std::cout << "Nhập số phần tử của mảng: ";
    std::cin >> n;

    nhapMang(arr, n);
    xuatMang(arr, n);

    return 0;
}