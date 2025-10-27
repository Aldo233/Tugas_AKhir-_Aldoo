#include <iostream>
using namespace std;
const int SIZE = 10;
struct Reservasi {
    int noKamar;      
    string namaTamu;  
    Reservasi* next;  
};
void initTable(Reservasi* table[]) {
    for (int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}
int hashFunction(int noKamar) {
    return (noKamar % SIZE + SIZE) % SIZE; 
}
void checkIn(Reservasi* table[], int noKamar, string namaTamu) {
    int index = hashFunction(noKamar);
    Reservasi* cur = table[index];
    while (cur != nullptr) {
        if (cur->noKamar == noKamar) {
            cout << "GAGAL: Kamar " << noKamar << " sudah terisi oleh " 
                 << cur->namaTamu << ".\n";
            return;
        }
        cur = cur->next;
    }
    Reservasi* baru = new Reservasi;
    baru->noKamar = noKamar;
    baru->namaTamu = namaTamu;
    baru->next = table[index];
    table[index] = baru;
    cout << "BERHASIL: Tamu " << namaTamu << " check-in di Kamar " 
         << noKamar << " (di Bagian " << index << ").\n";
}
void checkOut(Reservasi* table[], int noKamar) {
    int index = hashFunction(noKamar);
    Reservasi* cur = table[index];
    Reservasi* prev = nullptr;
    while (cur != nullptr && cur->noKamar != noKamar) {
        prev = cur;
        cur = cur->next;
    }
    if (cur == nullptr) {
        cout << "GAGAL: Kamar " << noKamar << " tidak ditemukan (sudah kosong).\n";
        return;
    }
    if (prev == nullptr) {
        table[index] = cur->next;
    } else {
        prev->next = cur->next;
    }
    cout << "BERHASIL: Tamu " << cur->namaTamu << " check-out dari Kamar " 
         << noKamar << " (dari Bagian " << index << ").\n";
    delete cur; 
}
void cariTamu(Reservasi* table[], int noKamar) {
    int index = hashFunction(noKamar);
    Reservasi* cur = table[index];
    while (cur != nullptr) {
        if (cur->noKamar == noKamar) {
            cout << "INFO: Kamar " << noKamar << " diisi oleh: " 
                 << cur->namaTamu << "\n";
            return;
        }
        cur = cur->next;
    }
    cout << "INFO: Kamar " << noKamar << " saat ini KOSONG.\n";
}
void displayStatusHotel(Reservasi* table[]) {
    cout << "\n--- STATUS HOTEL SAAT INI ---\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Bagian " << i << ": ";
        Reservasi* tmp = table[i];
        if (tmp == nullptr) {
            cout << "[Kosong]";
        }
        while (tmp != nullptr) {
            cout << "(Kamar: " << tmp->noKamar << ", Tamu: " 
                 << tmp->namaTamu << ") -> ";
            tmp = tmp->next;
            if (tmp == nullptr) {
                cout << "NULL";
            }
        } cout << "\n";
    }
    cout << "-------------------------------\n";
}
int main() {
    Reservasi* hotel[SIZE];
    initTable(hotel); 
    checkIn(hotel, 101, "Budi");
    checkIn(hotel, 102, "Caca");
    checkIn(hotel, 201, "Ani");
    checkIn(hotel, 301, "Doni");
    checkIn(hotel, 15, "Eka");
    displayStatusHotel(hotel);
    cariTamu(hotel, 201); 
    cariTamu(hotel, 404); 
    checkOut(hotel, 201);
    displayStatusHotel(hotel);
    checkIn(hotel, 101, "Fajar"); 
    checkOut(hotel, 999);     
    return 0;
}