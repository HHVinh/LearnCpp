#include <iostream>

void nhapMang(int* arr, int n)
{
    for(int i = 0; i < n; i++)
    {
        std::cout << "Nhập phần tử thứ " << i + 1 << ": ";
        std::cin >> arr[i];
    }
}

void xuatMang(int* arr, int n)
{
    std::cout << "Mảng vừa nhập là: ";
    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int timChuSoLonNhatCuaSoNguyenDuong(int n)
{   
    int temp = (n < 0) ? -n : n;
    int soLonNhat = 0;
    while (temp > 0)
    {
        int soCuoi = temp % 10;
        if(soLonNhat < soCuoi)
        {
            soLonNhat = soCuoi;
        }
        temp = temp / 10; 
    }
    
    return soLonNhat;
}

int main()
{
    int n;
    std::cout << "Nhập một số nguyên dương bất kì: ";
    std::cin >> n;

    int ketQua = timChuSoLonNhatCuaSoNguyenDuong(n);
    std::cout << "Chữ số lớn nhất trong số " << n << " là số: " << ketQua;

    return 0;
}