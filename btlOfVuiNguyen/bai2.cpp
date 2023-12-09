// Bai 2: viết chương trình in ra trung bình cộng, trung bình nhân của 3 số bất kì được nhập từ bàn phím

#include <iostream>

using namespace std;

int main() {
    // Nhập 3 số từ bàn phím
    double a, b, c;
    cout << "Nhap so thu nhat: ";
    cin >> a;
    cout << "Nhap so thu hai: ";
    cin >> b;
    cout << "Nhap so thu ba: ";
    cin >> c;

    // Tính trung bình cộng
    double trungBinhCong = (a + b + c) / 3;

    // Tính trung bình nhân
    double trungBinhNhan = a * b * c;

    // Hiển thị kết quả
    cout << "Trung binh cong: " << trungBinhCong << endl;
    cout << "Trung binh nhan: " << trungBinhNhan << endl;

    return 0;
}
