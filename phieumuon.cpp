#include <bits/stdc++.h>
using namespace std;

class PhieuMuon {
    string maPhieuMuon;
    string maThuThu;
    string maSinhVien;
    string ngayMuon;
    string ngayTra;
    vector<string> danhSachSachMuon;
public:
    PhieuMuon(string maPhieuMuon = "", string maThuThu = "", string maSinhVien = "", string ngayMuon = "", string ngayTra = "") {
        this->maPhieuMuon = maPhieuMuon;
        this->maThuThu = maThuThu;
        this->maSinhVien = maSinhVien;
        this->ngayMuon = ngayMuon; 
        this->ngayTra = ngayTra;
    }

    string getMaPhieuMuon() { return maPhieuMuon; }
    string getMaThuThu() { return maThuThu; }
    string getMaSinhVien() { return maSinhVien; }
    string getNgayMuon() { return ngayMuon; }
    string getNgayTra() { return ngayTra; }
    vector<string> getDanhSachSachMuon() { return danhSachSachMuon; }

    void addSachMuon(string maSach) {
        danhSachSachMuon.push_back(maSach);
    }

    void nhap() {
        cout << "Nhap ma phieu muon: "; getline(cin, maPhieuMuon);
        cout << "Nhap ma thu thu: "; getline(cin, maThuThu);
        cout << "Nhap ma sinh vien: "; getline(cin, maSinhVien);
        cout << "Nhap ngay muon: "; getline(cin, ngayMuon);
        bool check = true;
        while (check) {
            cout << "Nhap ngay tra: "; getline(cin, ngayTra);
            if(ngayTra > ngayMuon) {
                check = false;
            } else {
                cout << "Vui long nhap ngay tra sau ngay muon!";
            }
        }
    }

    void xuat() {
        cout << maPhieuMuon << " " << maThuThu << " " << maSinhVien << " " << ngayMuon << " " << ngayTra << endl;
        if(danhSachSachMuon.size() > 0) {
            cout << "Danh sach ma sach dc muon trong phieu co ma " << maPhieuMuon << ":\n";
            for(auto x : danhSachSachMuon) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
};
