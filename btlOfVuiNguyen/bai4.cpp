// bai4: viết chương trình nhập n từ bàn phím và tính n!!. sau đó in kết quả ra màn hình

#include <iostream>

using namespace std;

// Hàm tính giai thừa của một số nguyên
int TinhGiaiThua(int so) {
    if (so == 0 || so == 1) {
        return 1;
    } else {
        return so * TinhGiaiThua(so - 2);
    }
}

int main() {
    // Nhập số nguyên n từ bàn phím
    int n;
    cout << "Nhap so nguyen n: ";
    cin >> n;

    // Kiểm tra tính hợp lệ của n (n cần là số chẵn để tính n!!)
    if (n % 2 == 0 && n >= 0) {
        // Tính giai thừa kép n!!
        int ketQua = TinhGiaiThua(n);

        // Hiển thị kết quả
        cout << n << "!! = " << ketQua << endl;
    } else {
        cout << "Vui long nhap so nguyen duong chan." << endl;
    }

    return 0;
}
