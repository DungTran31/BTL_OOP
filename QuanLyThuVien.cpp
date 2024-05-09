#include<iostream>
#include <regex>
#include "QuanLySachVaTacGia.cpp"
#include "QuanLyThuThu.cpp"
#include "QuanLySinhVienMuonSach.cpp"
#include "QuanLySinhVienTraSach.cpp"
#include "QuanLyCauTruyVan.cpp"

using namespace std;
class QuanLyThuVien : public QuanLySachVaTacGia, public QuanLySinhVienMuonSach, public QuanLyThuThu, public QuanLyCauTruyVan, public QuanLySinhVienTraSach {
public:
	
	// check ngay muon
	bool isValidDate(const string& date) {
 		regex re("(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[012])/[0-9]{4}");
    	return regex_match(date, re);
	}

	void themPhieuMuon(){		
		//tao ma phieu muon
		string maPhieuMuon = "pm";
		if(listPhieuMuon.size() < 9){
			maPhieuMuon += "00";
			maPhieuMuon += to_string(listPhieuMuon.size()+1);
		} else if(listPhieuMuon.size() < 99){
			maPhieuMuon += "0";
			maPhieuMuon += to_string(listPhieuMuon.size()+1);
		} else{
			maPhieuMuon += to_string(listPhieuMuon.size()+1);
		}
		
		
		// nhap ma sinh vien
		string maSinhVien;
		cout << "Nhap ma sinh vien muon sach:" << endl;
		getline(cin, maSinhVien);
		
		while(!isInListSinhVien(maSinhVien)){
			cout << "Ma sinh vien khong ton tai trong he thong!" << endl;
			cout << "Hien dang co cac ma sinh vien sau: " << endl;
			printListMaSinhVien();
			cout << "Nhap lai ma sinh vien muon sach: " << endl;
			getline(cin, maSinhVien);
		}
		
		// nhap ma thu thu
		string maThuThu;
		cout << "Nhap ma thu thu phu trach: " << endl;
		getline(cin, maThuThu);
		
		while(!isInListThuThu(maThuThu)){
			cout << "Ma thu thu khong ton tai trong he thong!" << endl;
			cout << "Hien dang co cac ma thu thu sau: " << endl;
			printListMaThuThu();
			cout << "Nhap lai ma thu thu phu trach: " << endl;
			getline(cin, maThuThu);
		}
		
		
		// nhap ngay muon
		string ngayMuon;
		cout << "Nhap ngay muon sach: " << endl;
		getline(cin, ngayMuon);
		
		while(!isValidDate(ngayMuon)){
			cout << "Dinh dang ngay muon khong dung (dd/mm/yyyy)!!" << endl;
			cout << "Nhap lai ngay muon sach: " << endl;	
			getline(cin, ngayMuon);
		}
		
		PhieuMuon pm(maPhieuMuon, maThuThu, maSinhVien, ngayMuon);
		
		
		// nhap danh sach sach muon
		vector<string> danhSachSachMuon;
		int numberOfBooks;
		cout << "Nhap so luong sach muon: " << endl;
		cin >> numberOfBooks; cin.ignore();
		for(int i = 0; i < numberOfBooks; i++){
			string maSach;
			cout << "Nhap ma sach thu " << i+1 << ": ";
			getline(cin, maSach);
			
			while(!isInListSach(maSach) || getSoLuongSach(maSach)==0){
				cout << "Ma sach khong ton tai hoac khong du so luong sach cho muon!" << endl;
				cout << "Cac ma sach co the muon: " << endl;
				printListMaSach();
				cout << "Nhap lai ma sach thu " << i+1 << ": ";
				getline(cin, maSach);
				
				if(isInListSinhVien(maSach) && getSoLuongSach(maSach)==0){
					cout << "So luong sach khong du xin nhap ma sach khac" << endl;
					continue;
				}
			}
			
			giamSoLuongSach(maSach);
			danhSachSachMuon.push_back(maSach);
		}
		pm.setDanhSachMuon(danhSachSachMuon);
		
		if(!isInListPhieuMuon(pm.getMaPhieuMuon())){
			listPhieuMuon.push_back(pm);
			cout << "Them phieu muon thanh cong" << endl;
		} else{
			cout << "Ma phieu muon da ton tai" << endl;
		}
	}
};



