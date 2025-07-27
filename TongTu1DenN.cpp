#include <iostream>

int tongTu1DenN(int n)
{
    int tong = 0;
    for(int i = 1; i <= n; i++)
    {
        tong += i;
    }

    return tong;
}

int main()
{
    int n;
    std::cout << "Nhập giá trị n: ";
    std::cin >> n;

    int ketQua = tongTu1DenN(n);

    std::cout << "Tổng từ 1 đến " << n << " là: " << ketQua;
    
    return 0;
}