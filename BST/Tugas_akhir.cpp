#include <iostream>
using namespace std;
struct Node {
    int idPasien;
    Node* left;
    Node* right; 
    Node(int id) : idPasien(id), left(nullptr), right(nullptr) {}
};
Node* tambahPasien(Node* root, int id) {
    if (!root) {
        return new Node(id);
    }
    if (id < root->idPasien) {
        root->left = tambahPasien(root->left, id);
    } else if (id > root->idPasien) {
        root->right = tambahPasien(root->right, id);
    }
    return root; 
}
bool cariPasien(Node* root, int id) {
    if (!root) {
        return false;
    }
    if (root->idPasien == id) {
        return true;
    }
    if (id < root->idPasien) {
        return cariPasien(root->left, id);
    } else {
        return cariPasien(root->right, id);
    }
}
void cetakUrutan(Node* root) {
    if (!root) return; 
    cetakUrutan(root->left);  
    cout << root->idPasien << " ";  
    cetakUrutan(root->right); 
}
int main() {
    Node* dataPasien = nullptr; 
    int pilih, id;
    do {
        cout << "\n=== Sistem Pendaftaran Pasien (BST) ===\n";
        cout << "1. Tambah Pasien Baru\n";
        cout << "2. Cari Pasien\n";
        cout << "3. Cetak Semua ID Pasien (Terurut)\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        if (pilih == 1) {
            cout << "Masukkan ID Pasien: ";
            cin >> id;
            dataPasien = tambahPasien(dataPasien, id);
            cout << "Pasien dengan ID " << id << " berhasil didaftarkan.\n";       
        } else if (pilih == 2) {
            cout << "Masukkan ID Pasien yang dicari: ";
            cin >> id;
            if (cariPasien(dataPasien, id)) {
                cout << "Hasil: Pasien " << id << " ditemukan.\n";
            } else {
                cout << "Hasil: Pasien " << id << " tidak ditemukan.\n";
            }
        } else if (pilih == 3) {
            if (!dataPasien) {
                cout << "Belum ada pasien yang terdaftar.\n";
            } else {
                cout << "ID Pasien Terdaftar (terurut): ";
                cetakUrutan(dataPasien);
                cout << "\n";
            }
        } else if (pilih == 4) {
            cout << "Keluar dari program. Terima kasih!\n";
            
        } else {
            cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilih != 4); 
    return 0;
}