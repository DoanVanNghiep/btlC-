// Bai 3: viết chương trình nhập 2 số nguyên từ bàn phím. In ra tổng, tích, hiệu và thương của 2 số đó

#include <iostream>

using namespace std;

int main() {
    // Nhập hai số nguyên từ bàn phím
    int soThuNhat, soThuHai;
    cout << "Nhap so thu nhat: ";
    cin >> soThuNhat;
    cout << "Nhap so thu hai: ";
    cin >> soThuHai;

    // Tính tổng, tích, hiệu và thương
    int tong = soThuNhat + soThuHai;
    int tich = soThuNhat * soThuHai;
    int hieu = soThuNhat - soThuHai;

    // Kiểm tra trường hợp chia cho 0 trước khi tính thương
    if (soThuHai != 0) {
        double thuong = static_cast<double>(soThuNhat) / soThuHai;

        // Hiển thị kết quả
        cout << "Tong: " << tong << endl;
        cout << "Tich: " << tich << endl;
        cout << "Hieu: " << hieu << endl;
        cout << "Thuong: " << thuong << endl;
    } else {
        cout << "Khong the chia cho 0. Vui long nhap so thu hai khac 0." << endl;
    }

    return 0;
}

