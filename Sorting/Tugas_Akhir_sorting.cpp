#include <iostream>
using namespace std;
void tukar(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}
int main() {
    int n;
    string nama[1005];
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;
    cout << "Masukkan nama mahasiswa:" << endl;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        getline(cin, nama[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (nama[j] > nama[j + 1]) {
                tukar(nama[j], nama[j + 1]);
            }
        }
    }
    cout << "\nDaftar absen setelah diurutkan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << nama[i] << endl;
    }
    return 0;
}
