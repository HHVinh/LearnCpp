#include <iostream>

int tichTu1DenN(int n)
{
    int tich = 1;
    for(int i = 1; i <= n; i++)
    {
        tich *= i;
    }
    return tich;
}

int main()
{
    int n;
    do
    {
        std::cout << "Nhập giá trị n: ";
        std::cin >> n;
        if (n < 1)
        {
            std::cout << "Giá trị n phải là số nguyên lớn hơn 0\n";
            std::cout << "Hãy nhập lại giá trị n: ";
            std::cin >> n;
        }
        
    } while (n< 1);

    int result = tichTu1DenN(n);

    std::cout << "Tích các số từ 1 đến " << n << " là: " << result;

    return 0;
}