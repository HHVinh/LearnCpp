#include <iostream>
#include <stdlib.h>

int kiemTraPhanTuLe(int n)
{   
    if(n < 0) n = -n;
    if (n == 0) return 0;
    while (n > 0)
    {
        if((n % 10) % 2 == 0){
            return 0;
        }
        n = n / 10;
    }

    return 1;
}

void lietKeGiaTriToanSoLe(int* arr, int n)
{   
    int count = 0;
    for(int i = 0; i < n; i++)
    {   
        int temp = arr[i];
        if(kiemTraPhanTuLe(temp))
        {   
            count += 1;
        }
    }

    if(count == 0)
    {
        std::cout << "Không có số nào toàn giá trị lẻ trong mảng";
    } else
    {
        std::cout << "Các phần tử có giá trị toàn số lẻ trong mảng là: ";
        for(int i = 0; i < n; i++)
        {
            int temp = arr[i];
            if(kiemTraPhanTuLe(temp))
            {
                std::cout << arr[i];
                count--;
                if(count > 0)
                {
                    std::cout << ", ";
                }
            }
        }
        std::cout << "\n";
    }    
}

void nhapMang(int* arr, int n) 
{
    for(int i = 0; i < n; i++)
    {
        std::cout << "Nhập phần tử A[" << i << "]: ";
        std::cin >> arr[i];
    }
}

void xuatMang(int* arr, int n)
{   
    std::cout << "Mảng vừa nhập là: \n";
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    int n;
    std::cout << "Nhập số lượng n: ";
    std::cin >> n;

    int* arr = new int[n];

    nhapMang(arr, n);
    xuatMang(arr,n);
    lietKeGiaTriToanSoLe(arr, n);

    delete[] arr;

    return 0;
}