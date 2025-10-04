#include <iostream>
using namespace std;
void tukar(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}
int binarySearchNama(string arr[], int n, string target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        if (arr[mid].substr(0, target.size()) == target) {
            return mid;
        }

        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; 
}
int main() {
    int n;
    string nama[1005], cari;
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
    
    cout << "\nMasukkan nama mahasiswa yang ingin dicari: ";
    getline(cin, cari);

    int pos = binarySearchNama(nama, n, cari);
    if (pos != -1) {
        cout << "Mahasiswa \"" << nama[pos] << "\" ditemukan pada absen ke-" << pos + 1 << endl;
    } else {
        cout << "Mahasiswa dengan nama \"" << cari << "\" tidak ditemukan." << endl;
    }
    
    return 0;
}
