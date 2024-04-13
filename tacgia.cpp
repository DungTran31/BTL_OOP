#include <bits/stdc++.h>
using namespace std;

class TacGia {
    string maTacGia;
    string tenTacGia;
    string soDienThoaiTacGia;
public:
    TacGia(string maTacGia = "", string tenTacGia = "", string soDienThoaiTacGia = "") {
        this->maTacGia = maTacGia;
        this->tenTacGia = tenTacGia;
        this->soDienThoaiTacGia = soDienThoaiTacGia;
    }

    string getMaTacGia() { return maTacGia; }
    string getTenTacGia() { return tenTacGia; }
    string getSoDienThoaiTacGia() { return soDienThoaiTacGia; }

    void nhap() {
        cout << "Nhap ma tac gia: "; getline(cin, maTacGia);
        cout << "Nhap ten tac gia: "; getline(cin, tenTacGia);
        cout << "Nhap so dien thoai tac gia: "; getline(cin, soDienThoaiTacGia);
    }

    void xuat() {
        cout << maTacGia << " " << tenTacGia << " " << soDienThoaiTacGia << endl;
    }
};




