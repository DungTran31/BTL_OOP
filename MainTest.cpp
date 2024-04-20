#include<iostream>
#include "QuanLyThuVien.cpp"

using namespace std;

QuanLyThuVien qltv;

bool actionWithLastChoice(){
	cout << "\n\nNhap hanh dong" << endl;
	cout << "1. Quay Ve trang chu" << endl;
	cout << "2. Thoat" << endl;	
	int choice;
	cin >> choice; 
	cin.ignore();
	if(choice == 2){
		return true;
	}
	return false;
}

bool actionWithThuThu(){
	system("CLS");
	cout << "1. Them thu thu" << endl;
	cout << "2. Xoa thu thu" << endl;
	cout << "3. Danh sach thu thu" << endl;
	cout << "4. Quay Lai" << endl;
	cout << "Chon thao tac: "; 
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themThuThu();
	} else if(choice == 2){
		qltv.xoaThuThu();
	} else if(choice == 3){
		qltv.printListThuThu();
	} else if(choice == 4){
		return false;
	}
	return actionWithLastChoice();
}

bool actionWithSinhVien(){
	system("CLS");
	cout << "Chon thao tac: " << endl;
	cout << "1. Them sinh vien" << endl;
	cout << "2. Xoa sinh vien" << endl;
	cout << "3. Danh sach sinh vien" << endl;
	cout << "4. Tra cuu thong tin sinh vien" << endl;
	cout << "5. Quay Lai" << endl;
	cout << "Chon thao tac: "; 
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themSinhVien();
	} else if(choice == 2){
		qltv.xoaSinhVien();
	} else if(choice == 3){
		qltv.printListSinhVien();
	} else if(choice == 4){
		qltv.thongTinSinhVien();
	} else if(choice == 5){
		return false;
	}
	
	return actionWithLastChoice();
	
}


bool actionWithSach(){
	system("CLS");
	cout << "Chon thao tac: " << endl;
	cout << "1. Them sach" << endl;
	cout << "2. Xoa sach" << endl;
	cout << "3. Tim sach" << endl;
	cout << "4. Danh sach the loai sach" << endl;
	cout << "5. Quay Lai" << endl;
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themSach();
	} else if(choice == 2){
		qltv.xoaSach();
	} else if(choice == 3){
		qltv.searchBookInfo();
	} else if(choice == 4){
		qltv.printBooksByGenre();
	} else if(choice == 5){
		return false;
	}
	
	return actionWithLastChoice();
}


bool actionWithTacGia(){
	system("CLS");
	cout << "1. Them tac gia" << endl;
	cout << "2. Xoa tac gia" << endl;
	cout << "3. Danh sach tac gia" << endl;
	cout << "4. Quay Lai" << endl;
	cout << "Chon thao tac: " << endl;
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themTacGia();
	} else if(choice == 2){
		qltv.xoaTacGia();
	} else if(choice == 3){
		qltv.printBooksByAuthorName();
	} else if(choice == 4){
		return false;
	}
	return actionWithLastChoice();
}


bool actionWithTraMuonSach(){
	system("CLS");
	cout << "1. Them phieu muon" << endl;
	cout << "2. Xoa phieu muon" << endl;
	cout << "3. Danh sach phieu muon" << endl;
	cout << "4. Thong tin chi tiet phieu muon" << endl;
	cout << "5. Quay Lai" << endl;
	cout << "Chon thao tac: " << endl;
	int choice; cin >> choice; cin.ignore();
	if(choice == 1){
		qltv.themPhieuMuon();
	} else if(choice == 2){
		qltv.xoaPhieuMuon();
	} else if(choice == 3){
		qltv.printListPhieuMuon();
	} else if(choice == 4){
		qltv.thongTinPhieuMuon();
	} else if(choice == 5){
		return false;
	}
	return actionWithLastChoice();
}



void printChoices(){
	system("CLS");
	cout << "1. Thu Thu" << endl;
	cout << "2. Sinh Vien" << endl;
	cout << "3. Sach" << endl;
	cout << "4. Tac Gia" << endl;
	cout << "5. Tra/Muon Sach" << endl;
	cout << "6. Thoat" << endl;
	cout << "Chon doi tuong muon thao tac: " << endl;
}



bool choiceAction(int choice){
	if(choice == 1){
		return actionWithThuThu();
	} else if(choice == 2){
		return actionWithSinhVien();
	} else if(choice == 3){
		return actionWithSach();
	} else if(choice == 4){
		return actionWithTacGia();
	} else if(choice == 5){
		return actionWithTraMuonSach();
	} else if(choice == 6){
		return true;
	}
	return false;
}


int main(){
	bool isEnd = false;
	while(!isEnd){
		printChoices();
		int choice;
		cin >> choice; cin.ignore();
		isEnd = choiceAction(choice);
	}
}


