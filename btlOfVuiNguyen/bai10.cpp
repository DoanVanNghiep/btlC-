/**
 * Viết các chương trình con thực hiện công việc sau:
nhập danh sách các loại xe của hãng xe máy honda gồm các thông tin: Mã xe, tên xe, màu sắc, đơn giá, 
và lưu vào tẹp honda.dat(dạng nhị phân); việc nhập sẽ dừng lại khi mã xe được nhập là 0.
hiện danh sách xe từ tệp honda.txt ra màn hình;
nhập tên xe từ bàn phím, tìm và in ra các màu sắc và đơn giá tương ứng của loại xe đó.
sắp xếp danh sách xe theo đơn giá giảm dần và hiển thị ra màn hình với đầy đủ các thông tin .
Viết chương trình chính để gọi các chương trình con theo trật tự trên.(tổ chức chương trình thông qua menu)
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// Định nghĩa struct cho thông tin về xe máy Honda
struct XeMay {
    int maXe;
    string tenXe;
    string mauSac;
    double donGia;
};

// Hàm nhập thông tin về xe máy Honda và lưu vào tệp
void NhapVaLuuXeVaoTep() {
    ofstream outFile("honda.dat", ios::binary);
    if (!outFile.is_open()) {
        cerr << "Khong the mo file de ghi.\n";
        return;
    }

    while (true) {
        XeMay xe;
        cout << "Nhap ma xe (nhap 0 de ket thuc): ";
        cin >> xe.maXe;

        if (xe.maXe == 0) {
            break;
        }

        cout << "Nhap ten xe: ";
        cin.ignore();
        getline(cin, xe.tenXe);

        cout << "Nhap mau sac: ";
        getline(cin, xe.mauSac);

        cout << "Nhap don gia: ";
        cin >> xe.donGia;

        outFile.write(reinterpret_cast<const char*>(&xe), sizeof(XeMay));
    }

    outFile.close();
    cout << "Da nhap va luu danh sach xe vao honda.dat.\n";
}

// Hàm hiển thị danh sách xe từ tệp honda.dat ra màn hình
void HienThiDanhSachXeTuTep() {
    ifstream inFile("honda.dat", ios::binary);
    if (!inFile.is_open()) {
        cerr << "Khong the mo file de doc.\n";
        return;
    }

    vector<XeMay> danhSachXe;
    while (inFile) {
        XeMay xe;
        inFile.read(reinterpret_cast<char*>(&xe), sizeof(XeMay));
        if (inFile) {
            danhSachXe.push_back(xe);
        }
    }

    inFile.close();

    if (!danhSachXe.empty()) {
        cout << "Danh sach xe may Honda tu tep honda.dat:\n";
        for (const auto& xe : danhSachXe) {
            cout << "Ma xe: " << xe.maXe << ", Ten xe: " << xe.tenXe
                 << ", Mau sac: " << xe.mauSac << ", Don gia: " << xe.donGia << endl;
        }
    } else {
        cout << "Danh sach xe trong tep rong.\n";
    }
}

// Hàm tìm và hiển thị màu sắc và đơn giá tương ứng của loại xe theo tên
void TimVaHienThiThongTinXeTheoTen(const vector<XeMay>& danhSachXe) {
    string tenXe;
    cout << "Nhap ten xe can tim: ";
    cin.ignore();
    getline(cin, tenXe);

    auto iter = find_if(danhSachXe.begin(), danhSachXe.end(),
                        [tenXe](const XeMay& xe) {
                            return xe.tenXe == tenXe;
                        });

    if (iter != danhSachXe.end()) {
        cout << "Thong tin ve loai xe " << tenXe << ":\n";
        cout << "Mau sac: " << iter->mauSac << ", Don gia: " << iter->donGia << endl;
    } else {
        cout << "Khong tim thay loai xe " << tenXe << ".\n";
    }
}

// Hàm sắp xếp danh sách xe theo đơn giá giảm dần và hiển thị ra màn hình
void SapXepVaHienThiDanhSachXeTheoDonGia(const vector<XeMay>& danhSachXe) {
    vector<XeMay> danhSachXeSapXep = danhSachXe;
    sort(danhSachXeSapXep.begin(), danhSachXeSapXep.end(),
         [](const XeMay& a, const XeMay& b) {
             return a.donGia > b.donGia;
         });

    cout << "Danh sach xe sau khi sap xep theo don gia giam dan:\n";
    for (const auto& xe : danhSachXeSapXep) {
        cout << "Ma xe: " << xe.maXe << ", Ten xe: " << xe.tenXe
             << ", Mau sac: " << xe.mauSac << ", Don gia: " << xe.donGia << endl;
    }
}

int main() {
    vector<XeMay> danhSachXe;

    while (true) {
        cout << "\n======= MENU =======\n";
        cout << "1. Nhap va luu danh sach xe vao tep\n";
        cout << "2. Hien thi danh sach xe tu tep\n";
        cout << "3. Tim va hien thi thong tin xe theo ten\n";
        cout << "4. Sap xep va hien thi danh sach xe theo don gia\n";
        cout << "0. Thoat\n";
        cout << "====================\n";

        int luaChon;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                NhapVaLuuXeVaoTep();
                break;
            case 2:
                HienThiDanhSachXeTuTep();
                break;
            case 3:
                TimVaHienThiThongTinXeTheoTen(danhSachXe);
                break;
            case 4:
                SapXepVaHienThiDanhSachXeTheoDonGia(danhSachXe);
                break;
            case 0:
                cout << "Ket thuc chuong trinh.\n";
                return 0;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai.\n";
                break;
        }
    }

    return 0;
}
