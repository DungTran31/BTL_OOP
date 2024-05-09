#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "sinhvien.cpp"
#include "phieutra.cpp"

using namespace std;

class QuanLySinhVienTraSach{
public:
    vector<SinhVien> listSinhVien;
    vector<PhieuTra> listPhieuTra;	
    
    QuanLySinhVienTraSach(){
        //read data
        getSinhVienDataFromFile("inputSinhVien.txt");
        getPhieuTraDataFromFile("inputPhieuTra.txt");
    }
    
    ~QuanLySinhVienTraSach(){
        //write data
        writeSinhVienDataToFile("inputSinhVien.txt");
        writePhieuTraDataToFile("inputPhieuTra.txt");
    }
    
    //Check is in lists
	bool isInListSinhVien2(string msv){
		for(SinhVien s: listSinhVien){
			if(s.getMaSinhVien() == msv){
				return true;
			}
		}
		return false;
	}
	
	bool isInListPhieuTra2(string mpt){
		for(PhieuTra s: listPhieuTra){
			if(s.getMaPhieuTra() == mpt){
				return true;
			}
		}
		return false;
	}
	
	//print lists
	void printListSinhVien2(){
		for(SinhVien s: listSinhVien){
			s.xuat();
		}
	}
	
	void printListPhieuTra2(){
		for(PhieuTra pt: listPhieuTra){
			pt.xuat();
		}
	}
	
	void printListMaSinhVien2(){
		for(SinhVien s: listSinhVien){
			cout << s.getMaSinhVien() << " ";
		}
		cout << endl;
	}
	
    vector<PhieuTra> getListPhieuTra() {
        return listPhieuTra;
    }
	
	void getSinhVienDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string sNumberOfStudent;
		getline(file, sNumberOfStudent);
		int numberOfStudent = stoi(sNumberOfStudent);
		
		for(int i=0; i<numberOfStudent; i++){
			string maSV;
			string lopSV;
			string tenSV;
			getline(file, maSV);
			getline(file, tenSV);
			getline(file, lopSV);
			SinhVien sv(maSV, tenSV, lopSV);
			listSinhVien.push_back(sv);
		}
		
		file.close();
	}
	
	void getPhieuTraDataFromFile(string filePath){
		fstream file;
		file.open(filePath, ios::in);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		string sNumberOfPhieuTra;
		getline(file, sNumberOfPhieuTra);
		int numberOfPhieuTra = stoi(sNumberOfPhieuTra);
		
		for(int i = 0; i < numberOfPhieuTra; i++){
			string maPhieuTra;
			string maThuThu;
			string maSinhVien;
			string ngayTra;
			string elemSach;
			getline(file, maPhieuTra);
			getline(file, maThuThu);
			getline(file, maSinhVien);
			getline(file, ngayTra);
			vector<string> listSachTra;
			while(true){
				file >> elemSach;
				if(elemSach == "end"){
					break;
				}
				listSachTra.push_back(elemSach);
			}
			PhieuTra pt(maPhieuTra, maThuThu, maSinhVien, ngayTra);
			pt.setDanhSachTra(listSachTra);
			listPhieuTra.push_back(pt);
			file.ignore();
		}
		file.close();
	}
	
	//write
	void writeSinhVienDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		file << listSinhVien.size() << endl;
		
		for(SinhVien sv: listSinhVien){
			file << sv.getMaSinhVien() << endl;
			file << sv.getTenSinhVien() << endl;
			file << sv.getTenLop() << endl;
		}
		
		file.close();
	}

	void writePhieuTraDataToFile(string filePath){
		fstream file;
		file.open(filePath, ios::out);
		if (!file.is_open()) {
			cout << "Failed to open file!" << endl;
			return;
		}
		
		file << listPhieuTra.size() << endl;
		for(PhieuTra pt : listPhieuTra){
			file << pt.getMaPhieuTra() << endl;
			file << pt.getMaThuThu() << endl;
			file << pt.getMaSinhVien() << endl;
			file << pt.getNgayTra() << endl;
			for(string ma : pt.getDanhSachSachTra()){
				file << ma << " ";
			}
			file << "end" << endl;
		}
		
		file.close();
	}

	
	//them

	void themSinhVien(){
		SinhVien sv;
		sv.nhap();
		if(!isInListSinhVien2(sv.getMaSinhVien())){
			listSinhVien.push_back(sv);
			cout << "Them sinh vien thanh cong" << endl;
		} else{
			cout << "Ma sinh vien da ton tai" << endl;
		}
	}
	
	//xoa
	
	void xoaSinhVien(){
		cout << "Nhap ma sinh vien muon xoa: " << endl;
		string maSinhVien;
		getline(cin, maSinhVien);
		if(!isInListSinhVien2(maSinhVien)){
			cout << "Khong tim thay sinh vien can xoa" << endl;
		} else{
			for(int i = 0; i < listSinhVien.size(); i++){
				if(listSinhVien.at(i).getMaSinhVien() == maSinhVien){
					listSinhVien.erase(listSinhVien.begin()+i);
					cout << "Xoa sinh vien thanh cong" << endl;
					return;
				}
			}
		}
	}
	void xoaPhieuTra(){
		cout << "Nhap ma phieu tra muon xoa: " << endl;
		string maPhieuTra;
		getline(cin, maPhieuTra);
		if(!isInListPhieuTra2(maPhieuTra)){
			cout << "Khong tim thay phieu tra can xoa" << endl;
		} else{
			for(int i = 0; i < listSinhVien.size(); i++){
				if(listPhieuTra.at(i).getMaPhieuTra() == maPhieuTra){
                    string maPhieuMuon = "pm" + maPhieuTra.substr(2);
					listPhieuTra.erase(listPhieuTra.begin()+i);
					cout << "Xoa phieu muon thanh cong" << endl;
					return;
				}
			}
		}
	}


	// thong tin
	
	void thongTinPhieuTra(){
		string maPhieuTra;
		cout << "Nhap ma phieu tra: ";
		getline(cin, maPhieuTra);
		
		if(!isInListPhieuTra2(maPhieuTra)){
			cout << "Khong tim thay ma phieu tra" << endl;
			return;
		}
		
		for(auto pt: listPhieuTra){
			if(pt.getMaPhieuTra() == maPhieuTra){
				pt.xuat();
				return;
			}
		}
		
	}
	
	void thongTinSinhVien(){
		string maSinhVien;
		cout << "Nhap ma sinh vien can tim kiem: ";
		getline(cin, maSinhVien);
		
		if(!isInListSinhVien2(maSinhVien)){
			return;
		}
		cout << "Thong tin sinh vien: " << endl;
		for(auto sv: listSinhVien){
			if(sv.getMaSinhVien() == maSinhVien){
				sv.xuat();
				break;
			}
		}
		
		cout << "Cac phieu tra cua sinh vien: " << endl;
		int soPhieu = 0;
		for(auto pt: listPhieuTra){
			if(pt.getMaSinhVien() == maSinhVien){
				pt.xuat();
				soPhieu++;
			}
		}
		if(soPhieu == 0){
			cout << "Sinh vien khong co phieu tra nao" << endl;		
		}
	}
};