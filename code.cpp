#include <iostream>
#include <string>
#include <unordered_map> // Thu vi?n Dictionary (Hash Map)

using namespace std;

struct Student {
    string name;
    float cpa;
    bool gender;
    string gmail;
};

// S? d?ng unordered_map: Key là MSSV (int), Value là thông tin Student
unordered_map<int, Student> studentList;

void addStudent() {
    int mssv;
    cout << "Nhap MSSV: ";
    cin >> mssv;
    cin.ignore();

    // Dictionary giúp ki?m tra t?n t?i c?c nhanh v?i phuong th?c .count()
    if (studentList.count(mssv)) {
        cout << "MSSV da ton tai!\n";
        return;
    }

    Student sv;
    cout << "Nhap ten: "; getline(cin, sv.name);
    cout << "Nhap CPA: "; cin >> sv.cpa;
    cout << "Gioi tinh (1 = Nam, 0 = Nu): "; cin >> sv.gender;
    cin.ignore();
    cout << "Nhap Gmail: "; getline(cin, sv.gmail);

    // Thêm ho?c c?p nh?t trong Dictionary ch? b?ng toán t? []
    studentList[mssv] = sv;
    cout << "Them thanh cong!\n";
}

void removeStudent() {
    int mssv;
    cout << "Nhap MSSV can xoa: "; cin >> mssv;

    // .erase() tr? v? s? lu?ng ph?n t? dã xóa (0 ho?c 1)
    if (studentList.erase(mssv)) {
        cout << "Xoa thanh cong!\n";
    } else {
        cout << "Khong tim thay MSSV!\n";
    }
}

void findStudent() {
    int mssv;
    cout << "Nhap MSSV can tim: "; cin >> mssv;

    // Tìm ki?m ph?n t? b?ng .find()
    auto it = studentList.find(mssv);
    if (it == studentList.end()) {
        cout << "Khong ton tai MSSV\n";
        return;
    }

    // it->first là Key (MSSV), it->second là Value (Student)
    Student& sv = it->second;
    cout << "\n--- THONG TIN SINH VIEN ---\n";
    cout << "MSSV: " << it->first << "\n";
    cout << "Ho ten: " << sv.name << "\n";
    cout << "CPA: " << sv.cpa << "\n";
    cout << "Gioi tinh: " << (sv.gender ? "Nam" : "Nu") << "\n";
    cout << "Gmail: " << sv.gmail << "\n";
}

void updateStudent() {
    int mssv;
    cout << "Nhap MSSV can cap nhat: "; cin >> mssv;
    cin.ignore();

    if (studentList.find(mssv) == studentList.end()) {
        cout << "MSSV khong ton tai!\n";
        return;
    }

    Student &sv = studentList[mssv]; // L?y tham chi?u d? s?a tr?c ti?p
    string tmp;

    cout << "Nhap ten moi (bo trong de giu nguyen): ";
    getline(cin, tmp);
    if (!tmp.empty()) sv.name = tmp;

    cout << "Nhap CPA moi (-1 de giu nguyen): ";
    float cpa; cin >> cpa; cin.ignore();
    if (cpa >= 0) sv.cpa = cpa;

    cout << "Nhap gioi tinh moi (1/0, -1 de giu nguyen): ";
    int gt; cin >> gt; cin.ignore();
    if (gt == 0 || gt == 1) sv.gender = (gt == 1);

    cout << "Nhap Gmail moi (bo trong de giu nguyen): ";
    getline(cin, tmp);
    if (!tmp.empty()) sv.gmail = tmp;

    cout << "Cap nhat thanh cong!\n";
}

void printAll() {
    cout << "\n===== DANH SACH SINH VIEN =====\n";
    if (studentList.empty()) {
        cout << "(Danh sach rong)\n";
    } else {
        for (const auto& pair : studentList) {
            cout << "------------------------\n";
            cout << "MSSV: " << pair.first << "\n";
            cout << "Ho ten: " << pair.second.name << "\n";
            cout << "CPA: " << pair.second.cpa << "\n";
            cout << "Gioi tinh: " << (pair.second.gender ? "Nam" : "Nu") << "\n";
            cout << "Gmail: " << pair.second.gmail << "\n";
        }
    }
    cout << "===============================\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n===== MENU (DICTIONARY) =====\n";
        cout << "1. Them sinh vien\n2. Xoa sinh vien\n3. Tim sinh vien\n4. Cap nhat sinh vien\n5. In toan bo danh sach\n0. Thoat\nChon: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: removeStudent(); break;
            case 3: findStudent(); break;
            case 4: updateStudent(); break;
            case 5: printAll(); break;
            case 0: return 0;
            default: cout << "Lua chon khong hop le!\n";
        }
    }
}
