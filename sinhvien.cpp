#include <bits/stdc++.h>
using namespace std;

class SinhVien {
    string maSinhVien;
    string tenSinhVien;
    string tenLop;
public:
    SinhVien(string maSinhVien = "", string tenSinhVien = "", string tenLop = "") {
        this->maSinhVien = maSinhVien;
        this->tenSinhVien = tenSinhVien;
        this->tenLop = tenLop;
    }

    string getMaSinhVien() { return maSinhVien; }
    string getTenSinhVien() { return tenSinhVien; }
    string getTenLop() { return tenLop; }

    void nhap() {
        cout << "Nhap ma sinh vien: "; getline(cin, maSinhVien);
        cout << "Nhap ten sinh vien: "; getline(cin, tenSinhVien);
        cout << "Nhap ten lop: "; getline(cin, tenLop);
    }

    void xuat() {
        cout << maSinhVien << " " << tenSinhVien << " " << tenLop << endl;
    }
};
