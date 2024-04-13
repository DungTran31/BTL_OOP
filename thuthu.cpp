#include <bits/stdc++.h>
using namespace std;

class ThuThu {
    string maThuThu;
    string tenThuThu;
    string soDienThoaiThuThu;
public:
    ThuThu(string maThuThu = "", string tenThuThu = "", string soDienThoaiThuThu = "") {
        this->maThuThu = maThuThu;
        this->tenThuThu = tenThuThu;
        this->soDienThoaiThuThu = soDienThoaiThuThu;
    }

    string getMaThuThu() { return maThuThu; }
    string getTenThuThu() { return tenThuThu; }
    string getSoDienThoaiThuThu() { return soDienThoaiThuThu; }

    void nhap() {
        cout << "Nhap ma thu thu: "; getline(cin, maThuThu);
        cout << "Nhap ten thu thu: "; getline(cin, tenThuThu);
        cout << "Nhap so dien thoai thu thu: "; getline(cin, soDienThoaiThuThu);
    }

    void xuat() {
        cout << maThuThu << " " << tenThuThu << " " << soDienThoaiThuThu << endl;
    }
};
