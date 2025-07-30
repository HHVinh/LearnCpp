#include <iostream>

int tinhXMuN(int x, int n)
{
    int result = 1;
    if(x == 0) return 0;
    else if (n == 0 || x == 1) return 1;
    else if (n == 1) return x;
    else
    {
        while (n > 0)
        {
            result *= x;
            n--;
        }
    }
    return result;
}

int main()
{
    int x, n;
    do
    {
        std::cout << "Nhập x: ";
        std::cin >> x;
        std::cout << "Nhập n: ";
        std::cin >> n;

        if (x < 0 || n < 0)
        {
            std::cout << "Nhập lại x và n phải lớn hơn 0. Hãy nhập lại!\n";
        }
        
    } while (x < 0 || n < 0);
    
    int result = tinhXMuN(x,n);

    std::cout << "Tính " << x << "^" << n << " là: " << result;

    return 0;
}