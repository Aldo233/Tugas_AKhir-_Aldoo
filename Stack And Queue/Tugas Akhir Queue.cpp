#include <iostream>
using namespace std;
const int MAXN = 100;
string queueBioskop[MAXN];
int frontIdx = -1, rearIdx = -1;
bool isEmpty() {
    return frontIdx == -1;
}
bool isFull() {
    return (rearIdx + 1) % MAXN == frontIdx;
}
void enqueue(string nama) {
    if (isFull()) {
        cout << "Antrian penuh! Tidak bisa menambah pembeli lagi.\n";
        return;
    }
    if (isEmpty()) {
        frontIdx = rearIdx = 0;
    } else {
        rearIdx = (rearIdx + 1) % MAXN;
    }
    queueBioskop[rearIdx] = nama;
    cout << "Pembeli \"" << nama << "\" berhasil masuk ke antrian.\n";
}
void dequeue() {
    if (isEmpty()) {
        cout << "Antrian kosong! Tidak ada pembeli yang bisa dilayani.\n";
        return;
    }
    cout << "Pembeli \"" << queueBioskop[frontIdx] << "\" telah dilayani.\n";
    if (frontIdx == rearIdx) {
        frontIdx = rearIdx = -1; 
    } else {
        frontIdx = (frontIdx + 1) % MAXN;
    }
}
void peek() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Pembeli di depan antrian: " << queueBioskop[frontIdx] << '\n';
}
void display() {
    if (isEmpty()) {
        cout << "Antrian kosong!\n";
        return;
    }
    cout << "Isi antrian (depan ke belakang): ";
    int i = frontIdx;
    while (true) {
        cout << queueBioskop[i];
        if (i == rearIdx) break;
        cout << " -> ";
        i = (i + 1) % MAXN;
    }
    cout << '\n';
}
int main() {
    int pilih;
    string nama;
    do {
        cout << "\n=== ANTRIAN PEMBELIAN TIKET BIOSKOP ===\n";
        cout << "1. Tambah Pembeli (Enqueue)\n";
        cout << "2. Layani Pembeli (Dequeue)\n";
        cout << "3. Pembeli di Depan (Peek)\n";
        cout << "4. Lihat Semua Antrian\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore(); 
        if (pilih == 1) {
            cout << "Masukkan nama pembeli: ";
            getline(cin, nama);
            enqueue(nama);
        } 
        else if (pilih == 2) {
            dequeue();
        } 
        else if (pilih == 3) {
            peek();
        } 
        else if (pilih == 4) {
            display();
        } 
        else if (pilih == 5) {
            cout << "Terima kasih telah menggunakan sistem antrian bioskop!\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilih != 5);
    return 0;
}