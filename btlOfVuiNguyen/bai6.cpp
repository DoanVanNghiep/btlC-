// bài 6: viết hàm chuyển chữ thường thành chữ hoa. 
// Sau đó, viết chương trình nhập 1 chuỗi bất kì, gọi làm trên và cho biết kết quả.

#include <iostream>
#include <string>

using namespace std;

// Hàm chuyển chữ thường thành chữ hoa
string ChuyenChuThuongSangChuHoa(const string& chuoi) {
    string chuoiChuHoa = chuoi;
    for (char& c : chuoiChuHoa) {
        if (islower(c)) {
            c = toupper(c);
        }
    }
    return chuoiChuHoa;
}

int main() {
    // Nhập chuỗi từ bàn phím
    string chuoi;
    cout << "Nhap mot chuoi: ";
    getline(cin, chuoi);

    // Gọi hàm chuyển chữ thường thành chữ hoa
    string chuoiChuHoa = ChuyenChuThuongSangChuHoa(chuoi);

    // Hiển thị kết quả
    cout << "Chuoi sau khi chuyen thanh chu hoa: " << chuoiChuHoa << endl;

    return 0;
}
