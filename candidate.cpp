#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <cmath>

using namespace std;

map <int,int> mpMaSo;
int toVal(string s) {
    int temp=0;
    for (int i=0; i<s.length(); i++) {
        temp=temp*10+(s[i]-'0');
    }
    return temp;
}
bool checkNgaySinh(string ngaySinh) {
    string day="", month="", year="";
    int count=0;
    for (int i=0; i<ngaySinh.length(); i++) {
        if (ngaySinh[i]=='/') count ++;
        else 
            if (ngaySinh[i]<'0' || ngaySinh[i]>'9') return false;
    }
    if (count!=2) return false;
    int k=0;
    while (ngaySinh[k]!='/') {
        day+=ngaySinh[k];
        k++;
    }
    k++;
    while (ngaySinh[k]!='/') {
        month+=ngaySinh[k];
        k++;
    }
    k++;
    while (k<ngaySinh.length()) {
        year+=ngaySinh[k];
        k++;
    }
    if (day=="" || month=="" || year=="") return false;
    int numDay=toVal(day), numMonth=toVal(month), numYear=toVal(year);
    switch(numMonth) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (numDay>31) return false;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (numDay>30) return false;
            break;
        case 2:
            if ((numYear%100==0 && numYear%400==0) || numYear%4==0) {
                if (numDay>29) return false;
            } else {
                if (numDay>28) return false;
            }
            break;
        default:
            return false;
    }
    return true;
}
bool checkTen(string ten) {
    for (int i=0; i<ten.length(); i++) {
        if (ten[i]<'a' || ten[i]>'z')
            if (ten[i]<'A' || ten[i]>'Z')
                if (ten[i]!=' ') return false;
    }
    return true;
}
class candidate {
    private:
        int ma;
        float diemToan, diemVan, diemAnh;
        string ngaySinh, ten;
    public:
        void set(int ma, string ten, string ngaySinh, float diemToan, float diemVan, float diemAnh) {
            this->ma=ma;
            this->ten=ten;
            this->ngaySinh=ngaySinh;
            this->diemToan=diemToan;
            this->diemVan=diemVan;
            this->diemAnh=diemAnh;
        }
        void xuat() {
            cout << "Ma so thi sinh: " << ma << "\n";
            cout << "Ten thi sinh: " << ten << "\n";
            cout << "Ngay sinh: " << ngaySinh << "\n";
            cout << "Diem toan: " << diemToan << "\n";
            cout << "Diem van: " << diemVan << "\n";
            cout << "Diem Anh: " << diemAnh << "\n";
        }
        int getMa() {
            return ma;
        }
        string getTen() {
            return ten;
        }
        string getNgaySinh() {
            return ngaySinh;
        }
        float getDiemToan() {
            return diemToan;
        }
        float getDiemVan() {
            return diemVan;
        }
        float getDiemAnh() {
            return diemAnh;
        }
};
class listCandidate {
    private:
        int soLuong=0;
        vector<candidate> thiSinh;
    public:
        void khoiTaoDanhSach() {
            cout << "Nhap so luong thi sinh: ";
            cin >> soLuong;
            for (int i=0; i<soLuong; i++) {
                candidate temp;
                int ma;
                float toan, anh, van;
                string birth, name;
                cout << "----NHAP THONG TIN THI SINH "<< i+1 <<"----\n";
                cout << "Nhap ma so thi sinh: ";
                cin >> ma;
                while (mpMaSo[ma] || ma<0) {
                    cout << "Thi sinh " << ma << " da dang ki.\n";
                    cout << "Moi ban nhap lai.\n";
                    cout << "Nhap ma so thi sinh: ";
                    cin >> ma;
                }
                mpMaSo[ma]++;
                cout << "Nhap ten thi sinh: ";
                cin.ignore();
                getline(cin, name);
                while (!checkTen(name)) {
                    cout << "Ten khong hop le!\n";
                    cout << "Moi ban nhap lai ten: ";
                    getline(cin, name);
                }
                cout << "Nhap ngay sinh(day/month/year): ";
                cin >> birth;
                while (!checkNgaySinh(birth)) {
                    cout << "Ngay sinh khong hop le, ban vui long nhap lai.\n";
                    cout << "Nhap ngay sinh(day/month/year): ";
                    cin >> birth;
                }
                cout << "Nhap diem toan: ";
                cin >> toan;
                while (toan<0 && toan>10) {
                    cout << "Diem khong hop le!\n";
                    cout << "Moi ban nhap lai diem toan: ";
                    cin >> toan;
                }
                cout << "Nhap diem van: ";
                cin >> van;
                while (van<0 && van>10) {
                    cout << "Diem khong hop le!\n";
                    cout << "Moi ban nhap lai diem van: ";
                    cin >> van;
                }
                cout << "Nhap diem Anh: ";
                cin >> anh;
                while (anh<0 && anh>10) {
                    cout << "Diem khong hop le!\n";
                    cout << "Moi ban nhap lai diem Anh: ";
                    cin >> anh;
                }
                temp.set(ma, name, birth, toan, van, anh);
                thiSinh.push_back(temp);
            }
        }
        void themThiSinh() {
            candidate temp;
            int ma;
            float toan, anh, van;
            string birth, name;
            cout << "----THEM THI SINH VAO DANH SACH----\n";
            cout << "Nhap ma so thi sinh: ";
            cin >> ma;
            while (mpMaSo[ma] || ma<0) {
                cout << "Thi sinh " << ma << " da dang ki.\n";
                cout << "Moi ban nhap lai.\n";
                cout << "Nhap ma so thi sinh: ";
                cin >> ma;
            }
            mpMaSo[ma]++;
            cout << "Nhap ten thi sinh: ";
            cin.ignore();
            getline(cin, name);
            while (!checkTen(name)) {
                cout << "Ten khong hop le!\n";
                cout << "Moi ban nhap lai ten: ";
                getline(cin, name);
            }
            cout << "Nhap ngay sinh(day/month/year): ";
            cin >> birth;
            while (!checkNgaySinh(birth)) {
                cout << "Ngay sinh khong hop le, ban vui long nhap lai.\n";
                cout << "Nhap ngay sinh(day/month/year): ";
                cin >> birth;
            }
            cout << "Nhap diem toan: ";
            cin >> toan;
            cout << "Nhap diem van: ";
            cin >> van;
            cout << "Nhap diem Anh: ";
            cin >> anh;
            temp.set(ma, name, birth, toan, van, anh);
            thiSinh.push_back(temp);
            soLuong++;
        }
        void xoaThiSinh(int ma) {
            bool erase=false;
            for (int i=0; i<soLuong; i++) {
                if (thiSinh[i].getMa()==ma) {
                    thiSinh.erase(thiSinh.begin()+i);
                    erase=true;
                    soLuong--;
                    break;
                }
            }
            if (!erase) {
                cout << "Xoa that bai vi khong co thi sinh voi ma so "<< ma << "!\n";
            } else {
                cout << "Xoa thi sinh voi ma so " << ma << " thanh cong.\n"; 
            }
        }
        void xuat() {
            cout << "----DANH SACH THI SINH----\n";
            cout << left << setw(8) << setfill(' ') << "Ma so";
            cout << left << setw(30) << setfill(' ') << "Ho va ten";
            cout << left << setw(20) << setfill(' ') << "Ngay sinh";
            cout << left << setw(8) << setfill(' ') << "Toan";
            cout << left << setw(8) << setfill(' ') << "Van";
            cout << left << setw(8) << setfill(' ') << "Anh" << "\n";
            for (int i=0; i<soLuong; i++) {
                cout << left << setw(8) << setfill(' ') << thiSinh[i].getMa();
                cout << left << setw(30) << setfill(' ') << thiSinh[i].getTen();
                cout << left << setw(20) << setfill(' ') << thiSinh[i].getNgaySinh();
                cout << left << setw(8) << setfill(' ') << roundf(thiSinh[i].getDiemToan()*100)/100;
                cout << left << setw(8) << setfill(' ') << roundf(thiSinh[i].getDiemVan()*100)/100;
                cout << left << setw(8) << setfill(' ') << roundf(thiSinh[i].getDiemAnh()*100)/100 << "\n";
            }
        }
        int getSoLuong() {
            return soLuong;
        }
};
int main() {
    listCandidate list;
    int luaChon=-1;
    bool empty=true;
    while (luaChon) {
        cout << "----MENU----\n";
        cout << "Nhap 1 de khoi tao danh sach thi sinh.\n";
        cout << "Nhap 2 de them thi sinh vao danh sach.\n";
        cout << "Nhap 3 de xoa thi sinh nao do khoi danh sach.\n";
        cout << "Nhap 4 de xem danh sach thi sinh.\n";
        cout << "Nhap 0 de thoat chuong trinh.\n";
        cin >> luaChon;
        cout << "**********\n";
        if (!list.getSoLuong()) empty=true;
        switch(luaChon) {
            case 1:
                if (empty) {
                    empty=false;
                    list.khoiTaoDanhSach();
                } else {
                    cout << "Ban da khoi tao danh sach truoc do!!\n";
                }
                break;
            case 2:
                if (empty) {
                    cout << "Ban chua co danh sach thi sinh de them!\n";
                    cout << "Moi ban nhap 1 de khoi tao danh sach.\n";
                } else {
                    list.themThiSinh();
                }
                break;
            case 3:
                if (empty) {
                    cout << "Danh sach cua ban khong co thi sinh nao de xoa!\n";
                    cout << "Moi ban nhap 1 de khoi tao danh sach.\n";
                } else {
                    int ma;
                    cout << "Nhap ma so thi sinh ban can xoa: ";
                    cin >> ma;
                    list.xoaThiSinh(ma);
                }
                break;
            case 4:
                if (empty) {
                    cout << "Ban chua khoi tao danh sach hoac ban da xoa het thi sinh khoi danh sach!\n";
                    cout << "Moi ban nhap 1 de khoi tao danh sach.\n";
                } else {
                    list.xuat();
                }
                break;
            case 0:
                cout << "Cam on ban da su dung chuong trinh cua toi <3";
                break;
            default:
                cout << "Khong co lua chon nay, moi ban lua chon lai.";
        }
        cout << "\n\n";
    }
    return 0;
}
