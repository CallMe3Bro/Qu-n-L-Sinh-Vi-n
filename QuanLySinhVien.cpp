#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class SinhVien{
	private:
		int mssv; string name; float vdk; float ctmt; float oop; static int siso;
	
	public:
		void in(){
			cout << "\nNhap ho va ten: ";
			cin.ignore();
			getline(cin, name);
			cout << "\nNhap MSSV: ";
			cin >> mssv;
			cout << "\nNhap diem vdk: ";
			cin >> vdk;
			cout << "\nNhap diem ctmt: ";
			cin >> ctmt;
			cout << "\nNhap diem OOP: ";
			cin >> oop;
		}
		
		void out(){
			cout <<"\n"<<mssv<<"\t"<<name<<"\t\t"<<vdk<<"\t"<<ctmt<<"\t"<<oop<<"\t"<<tb()<<"\n";
		}
		
		float tb(){
			return (oop+vdk+ctmt)/3;
		}
		
		int get_mssv(){
			return mssv;
		}
		
		float get_vdk(){
			return vdk;
		}
		
		float get_ctmt(){
			return ctmt;
		}
		
		float get_oop(){
			return oop;
		}
		
		static void insiso(){
    		cout <<"\nSi so lop = :" << siso;
		}
		
		void edit_case_3(){
			cout <<"\nNhap diem VDK: ";
			cin >> vdk;
			cout <<"\nNhap diem CTMT: ";
			cin >> ctmt;
			cout <<"\nNhap diem OOP: ";
			cin >> oop;
		}
		
		bool operator<(SinhVien& other){
        	return get_mssv() < other.get_mssv();
    	}
};

class MENU{
	private:
		vector <SinhVien> ds;
	public:
		void in(){
			int n;
			cout << "\nNhap so luong sinh vien: ";
			cin >> n;
			ds.resize(ds.size() + n);
			for(int i = ds.size() - n; i < ds.size(); i ++){
				ds[i].in();
			}
		}
		
		void out(){
			cout << "\nMSSV\tName\t\t\tVDK\tCTMT\tOOP\tDiemTB\n";
			for(int i = 0; i < ds.size(); i ++){
				ds[i].out();
			}
			system("pause");
		}
		
		void case_3(){
			int mssv;
			cout <<"\nNhap MSSV can chinh sua: ";
			cin >> mssv;
			
			for(int i = 0; i < ds.size(); i ++){
				if(ds[i].get_mssv() == mssv){
					ds[i].edit_case_3();
					cout <<"\nDa chinh sua thong tin sinh vien co MSSV: "<< mssv << endl;
					system("pause");
					return;
				}
			}
			cout << "Khong tim thay sinh vien voi MSSV " << mssv << endl;
			system("pause");
		}
		
		void loc_diem_tb() {
        	float diemcanloc;
        	cout <<"\nNhap diem trung binh can loc: ";
        	cin >> diemcanloc;
        	cout << "\nDanh sach sinh vien co diem trung binh can loc la:\n";
        	for (int i = 0; i < ds.size(); i++) {
            	if (ds[i].tb() >= diemcanloc) {
                	ds[i].out();
            	}
        	}
        	cout <<"\nKhong co sinh vien tuong ung voi diem ban can loc!";
    	}
    	
    	void loc_diem_vdk() {
        	float diemcanloc;
        	cout <<"\nNhap diem trung binh mon VDK can loc: ";
        	cin >> diemcanloc;
        	cout << "\nDanh sach sinh vien co trung binh cua mon diem VDK can loc la:\n";
        	for (int i = 0; i < ds.size(); i++) {
            	if (ds[i].get_vdk() >= diemcanloc) {
                	ds[i].out();
            	}
        	}
        	cout <<"\nKhong co sinh vien tuong ung voi diem ban can loc!";
    	}
    	
    	void loc_diem_ctmt() {
        	float diemcanloc;
        	cout <<"\nNhap diem trung binh mon CTMT can loc: ";
        	cin >> diemcanloc;
        	cout << "\nDanh sach sinh vien co trung binh cua mon diem CMTM can loc la:\n";
        	for (int i = 0; i < ds.size(); i++) {
            	if (ds[i].get_ctmt() >= diemcanloc) {
                	ds[i].out();
            	}
        	}
        	cout <<"\nKhong co sinh vien tuong ung voi diem ban can loc!";
    	}
    	
    	void loc_diem_oop() {
        	float diemcanloc;
        	cout <<"\nNhap diem trung binh mon OOP can loc: ";
        	cin >> diemcanloc;
        	cout << "\nDanh sach sinh vien co trung binh cua mon diem OOP can loc la:\n";
        	for (int i = 0; i < ds.size(); i++) {
            	if (ds[i].get_oop() >= diemcanloc) {
                	ds[i].out();
            	}
        	}
        	cout <<"\nKhong co sinh vien tuong ung voi diem ban can loc!";
    	}
		
		void case_4(){
			do{
				cout <<"\nChon phuong thuc ban muon loc: ";
				cout <<"\n1. Theo diem trung binh: ";
				cout <<"\n2. Theo mon hoc: ";
				cout <<"\n3. Thoat chuc nang loc diem: ";
				
				int choose;
				cout <<"\nNhap su lua chon: ";
				cin >> choose;
				
				switch (choose){
					case 1: 
						loc_diem_tb();
						break;
					case 2: 
						do{
							int choose_case2;
							cout << "\nChon mon ban muon loc: ";
							cout <<"\n1. Vi Dieu Khien: ";
							cout <<"\n2. Cau Truc May Tinh: ";
							cout <<"\n3. OOP: ";
							cout <<"\n4. Thoat chuc nang loc diem theo mon: ";
							
							cout <<"\nNhap su lua chon: ";
							cin >> choose_case2;
							switch (choose_case2){
								case 1:
									loc_diem_vdk();
									break;
								case 2:
									loc_diem_ctmt();
									break;
								case 3:
									loc_diem_oop();
									break;
								case 4:
									cout <<"Da Thoat chuc nang loc diem theo mon!"<<endl;
									system("pause");
									return;
								default:
									cout <<"\nLua chon khong hop le!!";
							}
						}while(true);	
					case 3:
						cout <<"Da Thoat chuc nang loc diem!"<<endl;
						return;
					default:
					cout <<"\nLua chon khong hop le!!";
				}
			}while(true);
		}
		
		void case_5(){
			int mssv;
			cout <<"\nNhap MSSV can xoa: ";
			cin >> mssv;
			
			for(int i = 0; i < ds.size(); i ++){
				if(ds[i].get_mssv() == mssv){
					ds.erase(ds.begin() + i);
					cout <<"\nDa xoa sinh vien co ma so: "<< mssv << endl;
					system("pause");
					return;
				}
			}
			cout <<"\nKhong tim thay sinh vien can xoa: ";
				system("pause");
		}
		
		void case_7(){
			int mssv;
			cout << "\nNhap MSSV can tim: ";
			cin >> mssv;
			
			for (int i = 0; i < ds.size(); i ++){
				if(ds[i].get_mssv() == mssv){
					cout <<"Sinh vien can tim la: ";
					cout << "\nMSSV\tTen\t\t\tOOP\tVDK\tKTMT\tDTB\n";
					ds[i].out();
					system("pause");
					return;
				}
			}
			cout <<"\nKhong tim thay sinh vien trong danh sach! ";
			system("pause");
		}
		
		int case_8(){
			int insiso;
			cout <<"\nSi so lop la: " << ds.size() <<endl;
			system("pause");
		}
		
		void case_9(){
			for(int i = 0; i < ds.size(); i++)
        		for(int j = i + 1; j < ds.size(); j++)
            		if(ds[j].tb() < ds[i].tb())
                		swap(ds[i], ds[j]);
    				cout << "Ten\t\t\tMSSV\tOOP\tVDK\tCTMT\tDTB\n";
    			for(int i = 0; i < ds.size(); i++) 
					ds[i].out();
    		system("pause");
		}
		
		void in_menu(){
			do{
				int choose;
				system("cls");
				cout <<"\n====================================MENU==================================\n";
				cout <<"\n1. Them sinh vien moi: ";
				cout <<"\n2. Xem danh sach sinh vien: ";
				cout <<"\n3. Chinh sua thong tin sinh vien: ";
				cout <<"\n4. Liet ke diem sinh vien: ";
				cout <<"\n5. Xoa sinh vien trong danh sach: ";
				cout <<"\n6. Sap xep sinh vien trong danh sach: ";
				cout <<"\n7. Tim kiem sinh vien: ";
				cout <<"\n8. Si so cua lop: ";
				cout <<"\n9. Sap xep diem trung binh: ";
				cout <<"\n10. Thoat MENU";
				
				cout <<"\nNhap su lua chon: ";
				cin >> choose;
				
				switch(choose){
					case 1:
						in();
						break;
					case 2:
						out();
						break;
					case 3:
						case_3();
						break;
					case 4:
						case_4();
						break;
					case 5:
						case_5();
						break;
					case 6:
						sort(ds.begin(), ds.end());
						break;
					case 7:
						case_7();
						break;
					case 8:
						case_8();
						break;
					case 9:
						case_9();
					case 10:
						cout <<"Da Thoat MENU"<<endl;
						return;
					default:
						cout <<"Lua chon khong hop le!!!";
				}
			}while(true);
		}
};


int main(){
	MENU menu;
	menu.in_menu();
}















