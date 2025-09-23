#include <iostream>
using namespace std;
int main() {
    int jumlah;
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah;
    cin.ignore(); 
    string nama[jumlah], npm[jumlah];
    float nilai1[jumlah], nilai2[jumlah], nilai3[jumlah], rata[jumlah];
    for (int i = 0; i < jumlah; i++) {
        cout << "\nData Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama: ";
        getline(cin, nama[i]);
        cout << "NPM: ";
        getline(cin, npm[i]);
        cout << "Nilai 1: ";
        cin >> nilai1[i];
        cout << "Nilai 2: ";
        cin >> nilai2[i];
        cout << "Nilai 3: ";
        cin >> nilai3[i];
        rata[i] = (nilai1[i] + nilai2[i] + nilai3[i]) / 3;
        cin.ignore(); 
    }
    cout << "\n=== Data Mahasiswa ===\n";
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama: " << nama[i]
             << " | NPM: " << npm[i]
             << " | Nilai: " << nilai1[i] << ", "
             << nilai2[i] << ", "
             << nilai3[i]
             << " | Rata-rata: " << rata[i] << endl;
    }
    return 0;
}
