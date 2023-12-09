/*
Bài 7: Viết các hàm thực hiện:
Nhập một mảng số nguyên dương cho điến khi gặp số -1 thì dừng
hiện một mảng n số nguyên ra màn hình
sắp xếp lại dãy sao cho các số lẻ chia hết cho 3 đứng đầu dãy
kiểm tra một số có phải là số chính phương không
tính trung bình cộng các số chính phương có trong mảng
Viết chương trình chính Áp dụng lần lượt các hàm trên
*/

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm nhập mảng số nguyên dương cho đến khi gặp số -1
vector<int> NhapMang() {
    vector<int> mang;
    int so;
    cout << "Nhap cac so nguyen duong cho den khi gap -1 (nhap -1 de dung):\n";
    while (true) {
        cin >> so;
        if (so == -1) {
            break;
        }
        mang.push_back(so);
    }
    return mang;
}

// Hàm hiển thị mảng ra màn hình
void HienThiMang(const vector<int>& mang) {
    cout << "Mang da nhap: ";
    for (int i : mang) {
        cout << i << " ";
    }
    cout << endl;
}

// Hàm sắp xếp lại mảng sao cho các số lẻ chia hết cho 3 đứng đầu
void SapXepMang(vector<int>& mang) {
    sort(mang.begin(), mang.end(), [](int a, int b) {
        if (a % 2 != 0 && b % 2 != 0) {
            return a % 3 < b % 3;
        }
        return a % 2 > b % 2;
    });
}

// Hàm kiểm tra một số có phải là số chính phương không
bool LaSoChinhPhuong(int so) {
    int canBacHai = sqrt(so);
    return canBacHai * canBacHai == so;
}

// Hàm tính trung bình cộng các số chính phương trong mảng
double TrungBinhCongSoChinhPhuong(const vector<int>& mang) {
    int tong = 0;
    int dem = 0;

    for (int so : mang) {
        if (LaSoChinhPhuong(so)) {
            tong += so;
            dem++;
        }
    }

    return (dem > 0) ? static_cast<double>(tong) / dem : 0;
}

int main() {
    // 1. Nhập mảng số nguyên dương cho đến khi gặp số -1
    vector<int> mang = NhapMang();

    // 2. Hiển thị mảng ra màn hình
    HienThiMang(mang);

    // 3. Sắp xếp lại mảng sao cho các số lẻ chia hết cho 3 đứng đầu
    SapXepMang(mang);
    cout << "Mang sau khi sap xep:\n";
    HienThiMang(mang);

    // 4. Kiểm tra một số có phải là số chính phương không
    int soKiemTra;
    cout << "Nhap mot so de kiem tra co phai la so chinh phuong khong: ";
    cin >> soKiemTra;
    if (LaSoChinhPhuong(soKiemTra)) {
        cout << soKiemTra << " la so chinh phuong.\n";
    } else {
        cout << soKiemTra << " khong phai la so chinh phuong.\n";
    }

    // 5. Tính trung bình cộng các số chính phương trong mảng
    double trungBinhCong = TrungBinhCongSoChinhPhuong(mang);
    cout << "Trung binh cong cua cac so chinh phuong trong mang la: " << trungBinhCong << endl;

    return 0;
}
