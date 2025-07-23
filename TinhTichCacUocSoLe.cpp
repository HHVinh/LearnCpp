#include <iostream>

int tichUocSoLe(int n)
{
    int temp = (n < 0) ? -n : n;
    int tich = 1;
    int dem = 0;

    for (int i = 1; i <= temp / 2; i++)
    {
        if (temp % i == 0 && i % 2 == 1)
        {
            tich *= i;
            dem++;
        }
    }

    if (temp % 2 == 1)
    {
        tich *= temp;
        dem++;
    }

    if (dem == 0)
        return 0;

    return tich;
}


int main()
{
    int n;
    std::cout << "Nhập số nguyên bất kì: ";
    std::cin >> n;

    int ketQua = tichUocSoLe(n);

    std::cout << "Tích các ước số lẻ của số " << n << " là: " << ketQua;

    return 0;
}