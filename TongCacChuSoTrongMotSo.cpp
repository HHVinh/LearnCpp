#include <iostream>

int tongCacChuSo(int n)
{
    int sum = 0;

    int  temp = (n < 0 ) ? -n : n;

    while (temp > 0)
    {
        sum += temp % 10;
        temp = temp / 10;
    }
    
    return sum;
}

int main()
{
    int n;
    std::cout << "Nhập số nguyên bất kì: ";
    std::cin >> n;

    int ketQua = tongCacChuSo(n);
    std::cout << "Tổng các chữ số của số " << n << " là : " << ketQua;

    return 0;
}