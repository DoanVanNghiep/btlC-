// Bài 5: Viết hàm nhập 1 số nguyên x(0< x =< 109) và tính tổng các chữ số có trong x. 
// Viết chương trình nhập 1 số nguyên từ bàn phím, 
// hiện ra màn hình tổng các chữ số của x(ví dụ 42 thì kết quả = 4 + 2 = 6)

#include <iostream>

using namespace std;

// Hàm tính tổng các chữ số của một số nguyên
int TinhTongChuSo(int so) {
    int tong = 0;
    while (so > 0) {
        tong += so % 10;
        so /= 10;
    }
    return tong;
}

int main() {
    // Nhập số nguyên từ bàn phím
    int x;
    cout << "Nhap mot so nguyen (0 < x <= 10^9): ";
    cin >> x;

    // Kiểm tra tính hợp lệ của x
    if (x > 0 && x <= 1000000000) {
        // Tính tổng các chữ số của x
        int tongChuSo = TinhTongChuSo(x);

        // Hiển thị kết quả
        cout << "Tong cac chu so cua " << x << " la: " << tongChuSo << endl;
    } else {
        cout << "Vui long nhap mot so nguyen hop le." << endl;
    }

    return 0;
}


