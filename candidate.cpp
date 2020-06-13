#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class candidate {
    private:
        int ma, diemToan, diemVan, diemAnh;
        string ngaySinh, ten;
    public:
        void set(int ma, string ten, string ngaySinh, int diemToan, int diemVan, int diemAnh) {
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
        int getDiemToan() {
            return diemToan;
        }
        int getDiemVan() {
            return diemVan;
        }
        int getDiemAnh() {
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
                int ma, toan, van, anh;
                string birth, name;
                cout << "----NHAP THONG TIN THI SINH "<< i <<"----\n";
                cout << "Nhap ma so thi sinh: ";
                cin >> ma;
                cout << "Nhap ten thi sinh: ";
                cin.ignore();
                getline(cin, name);
                cout << "Nhap ngay sinh: ";
                getline(cin, birth);
                cout << "Nhap diem toan: ";
                cin >> toan;
                cout << "Nhap diem van: ";
                cin >> van;
                cout << "Nhap diem Anh: ";
                cin >> anh;
                temp.set(ma, name, birth, toan, van, anh);
                thiSinh.push_back(temp);
            }
        }
        void themThiSinh() {
            candidate temp;
            int ma, toan, van, anh;
            string birth, name;
            cout << "----THEM THI SINH VAO DANH SACH----\n";
            cout << "Nhap ma so thi sinh: ";
            cin >> ma;
            cout << "Nhap ten thi sinh: ";
            cin.ignore();
            getline(cin, name);
            cout << "Nhap ngay sinh: ";
            getline(cin, birth);
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
                cout << left << setw(8) << setfill(' ') << thiSinh[i].getDiemToan();
                cout << left << setw(8) << setfill(' ') << thiSinh[i].getDiemVan();
                cout << left << setw(8) << setfill(' ') << thiSinh[i].getDiemAnh() << "\n";
            }
        }
        int getSoLuong() {
            return soLuong;
        }
};
int main() {
    listCandidate list;
    int x=-1;
    bool empty=true;
    while (x) {
        cout << "----MENU----\n";
        cout << "Nhap 1 de khoi tao danh sach thi sinh.\n";
        cout << "Nhap 2 de them thi sinh vao danh sach.\n";
        cout << "Nhap 3 de xoa thi sinh nao do khoi danh sach.\n";
        cout << "Nhap 4 de xem danh sach thi sinh.\n";
        cout << "Nhap 0 de thoat chuong trinh.\n";
        cin >> x;
        cout << "**********\n";
        switch(x) {
            case 1:
                if (empty) {
                    empty=false;
                    list.khoiTaoDanhSach();
                } else {
                    cout << "Ban da khoi tao danh sach truoc do!!\n";
                }
                break;
            case 2:
                list.themThiSinh();
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
                    if (!list.getSoLuong()) empty=true;
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