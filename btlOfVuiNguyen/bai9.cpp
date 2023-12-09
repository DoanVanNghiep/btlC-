/**
 * Bài 9:
 * Viết các chương trình con thực hiện các công việc sau:
Nhập danh sách các loại xe của hãng xe máy honda gồm các thông tin: mã xe, tên xe, màu sắc, đơn giá; 
việc nhập sẽ dừng lại khi mã xe được nhập là 0
hiện danh sách xe vừa nhập in ra màn hình với đầy đủ các thông tin như mã xe, tên xe, màu sắc, đơn giá;
Sắp xếp danh sách các loại xe máy theo thú tự giảm dần của đơn giá và lưu vào tệp honda.dat(theo dạng nhị phân);
Tìm loại xe co đơn giá thấp nhất có màu x(X được nhập từ bàn phím) và 
hiện ra màn hình nếu tìm thấy, ngược lại hiển thị thông báo:"Không tìm thấy".
Viết chương trình chính để gọi các phương trình con theo thứ tự trên. 
Nếu có thể tổ chức chương trình thông qua menu thì sẽ là một điểm cộng
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

// Hàm nhập thông tin về xe máy Honda
void NhapDanhSachXe(vector<XeMay>& danhSachXe) {
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

        danhSachXe.push_back(xe);
    }
}

// Hàm hiển thị danh sách xe máy Honda
void HienThiDanhSachXe(const vector<XeMay>& danhSachXe) {
    cout << "Danh sach xe may Honda:\n";
    for (const auto& xe : danhSachXe) {
        cout << "Ma xe: " << xe.maXe << ", Ten xe: " << xe.tenXe
             << ", Mau sac: " << xe.mauSac << ", Don gia: " << xe.donGia << endl;
    }
}

// Hàm sắp xếp danh sách xe máy theo thứ tự giảm dần của đơn giá và lưu vào tệp
void SapXepVaLuuXeTheoDonGia(const vector<XeMay>& danhSachXe) {
    vector<XeMay> danhSachXeSapXep = danhSachXe;
    sort(danhSachXeSapXep.begin(), danhSachXeSapXep.end(),
         [](const XeMay& a, const XeMay& b) {
             return a.donGia > b.donGia;
         });

    ofstream outFile("honda.dat", ios::binary);
    if (!outFile.is_open()) {
        cerr << "Khong the mo file de ghi.\n";
        return;
    }

    for (const auto& xe : danhSachXeSapXep) {
        outFile.write(reinterpret_cast<const char*>(&xe), sizeof(XeMay));
    }

    outFile.close();
    cout << "Da sap xep va luu danh sach xe vao honda.dat.\n";
}

// Hàm tìm loại xe có đơn giá thấp nhất và có màu x
void TimXeCoDonGiaThapNhatTheoMau(const vector<XeMay>& danhSachXe, const string& mauX) {
    auto iter = min_element(danhSachXe.begin(), danhSachXe.end(),
                            [mauX](const XeMay& a, const XeMay& b) {
                                return a.donGia < b.donGia && a.mauSac == mauX;
                            });

    if (iter != danhSachXe.end()) {
        cout << "Loai xe co don gia thap nhat voi mau " << mauX << ":\n";
        cout << "Ma xe: " << iter->maXe << ", Ten xe: " << iter->tenXe
             << ", Mau sac: " << iter->mauSac << ", Don gia: " << iter->donGia << endl;
    } else {
        cout << "Khong tim thay loai xe nao voi mau " << mauX << ".\n";
    }
}

int main() {
    vector<XeMay> danhSachXe;

    while (true) {
        cout << "\n======= MENU =======\n";
        cout << "1. Nhap danh sach xe\n";
        cout << "2. Hien thi danh sach xe\n";
        cout << "3. Sap xep va luu xe theo don gia\n";
        cout << "4. Tim loai xe co don gia thap nhat voi mau x\n";
        cout << "0. Thoat\n";
        cout << "====================\n";

        int luaChon;
        cout << "Nhap lua chon: ";
        cin >> luaChon;

        switch (luaChon) {
            case 1:
                NhapDanhSachXe(danhSachXe);
                break;
            case 2:
                HienThiDanhSachXe(danhSachXe);
                break;
            case 3:
                SapXepVaLuuXeTheoDonGia(danhSachXe);
                break;
            case 4:
                {
                    string mauX;
                    cout << "Nhap mau x: ";
                    cin >> mauX;
                    TimXeCoDonGiaThapNhatTheoMau(danhSachXe, mauX);
                }
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
