#include <iostream>
#include <string>
using namespace std;

int main() {
    string ten;
    int tuoi;

    cout << "Nhập tên của bạn: ";
    getline(cin, ten);  // Nhập họ tên đầy đủ có thể chứa khoảng trắng

    cout << "Nhập tuổi của bạn: ";
    cin >> tuoi;

    cout << "Chào bạn " << ten << ", " << tuoi << " tuổi\n";

    return 0;
}
