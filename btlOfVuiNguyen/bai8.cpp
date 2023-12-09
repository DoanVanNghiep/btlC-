/**
 * Bài 8:
 * Viết các hàm thực hiện các công việc sau:
nhập ma trận số nguyên có kích thước n*n
hiện ma trận vừa nhập ra màn hình
thay thế các phần tử giống nhau trong cùng hàng bằng các gí trị Trung bình cộng(TBC) của phần tử đó với phần tử đối xứng của nó qua đường chéo(TBC = (a[i,j]+a[j,i])/2).
tính TBC các phần tử nằm trên đường chéo chính
tìm vị trí của cột có tổng phần tử lớn nhất của ma trận
Viết chương trình chính áp dụng lần lượt các hàm trên
*/

#include <iostream>
#include <vector>

using namespace std;

// Hàm nhập ma trận kích thước n*n
vector<vector<int>> NhapMaTran(int n) {
    vector<vector<int>> maTran(n, vector<int>(n, 0));

    cout << "Nhap ma tran " << n << "x" << n << ":\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << "a[" << i << "][" << j << "]: ";
            cin >> maTran[i][j];
        }
    }

    return maTran;
}

// Hàm hiển thị ma trận ra màn hình
void HienThiMaTran(const vector<vector<int>>& maTran) {
    cout << "Ma tran:\n";
    for (const auto& hang : maTran) {
        for (int phanTu : hang) {
            cout << phanTu << " ";
        }
        cout << endl;
    }
}

// Hàm thay thế các phần tử giống nhau trong cùng hàng
void ThayTheGiongNhau(vector<vector<int>>& maTran) {
    int n = maTran.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j && maTran[i][j] == maTran[j][i]) {
                int tbc = (maTran[i][j] + maTran[j][i]) / 2;
                maTran[i][j] = maTran[j][i] = tbc;
            }
        }
    }
}

// Hàm tính TBC các phần tử nằm trên đường chéo chính
double TinhTBCDuongCheoChinh(const vector<vector<int>>& maTran) {
    int n = maTran.size();
    int tong = 0;
    int dem = 0;

    for (int i = 0; i < n; ++i) {
        tong += maTran[i][i];
        dem++;
    }

    return (dem > 0) ? static_cast<double>(tong) / dem : 0;
}

// Hàm tìm vị trí cột có tổng phần tử lớn nhất của ma trận
int TimCotTongLonNhat(const vector<vector<int>>& maTran) {
    int n = maTran.size();
    int cotMax = 0;
    int tongMax = 0;

    for (int j = 0; j < n; ++j) {
        int tongCot = 0;
        for (int i = 0; i < n; ++i) {
            tongCot += maTran[i][j];
        }
        if (tongCot > tongMax) {
            tongMax = tongCot;
            cotMax = j;
        }
    }

    return cotMax;
}

int main() {
    // Nhập kích thước ma trận
    int n;
    cout << "Nhap kich thuoc ma tran n (n > 0): ";
    cin >> n;

    // Nhập ma trận
    vector<vector<int>> maTran = NhapMaTran(n);

    // Hiển thị ma trận
    HienThiMaTran(maTran);

    // Thay thế các phần tử giống nhau trong cùng hàng
    ThayTheGiongNhau(maTran);

    // Hiển thị ma trận sau khi thay thế
    cout << "Ma tran sau khi thay the:\n";
    HienThiMaTran(maTran);

    // Tính TBC các phần tử nằm trên đường chéo chính
    double tbcDuongCheoChinh = TinhTBCDuongCheoChinh(maTran);
    cout << "Trung binh cong cac phan tu tren duong cheo chinh: " << tbcDuongCheoChinh << endl;

    // Tìm vị trí cột có tổng phần tử lớn nhất
    int cotMax = TimCotTongLonNhat(maTran);
    cout << "Cot co tong phan tu lon nhat: " << cotMax << endl;

    return 0;
}
