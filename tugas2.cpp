#include <iostream>
using namespace std;

const int MAX = 100;

struct Pesanan {
    char nama[50];
    char jenisRoti[50];
    int totalHarga;
};

Pesanan antrean[MAX];
Pesanan riwayat[MAX];

int depan = 0, belakang = 0;
int jumlahRiwayat = 0;

void ambilAntrean() {
    if (belakang >= MAX) {
        cout << "Antrean penuh!\n";
        return;
    }
    cout << "Nama Pembeli: "; cin.ignore(); cin.getline(antrean[belakang].nama, 50);
    cout << "Jenis Roti: "; cin.getline(antrean[belakang].jenisRoti, 50);
    cout << "Total Harga: "; cin >> antrean[belakang].totalHarga;
    belakang++;
    cout << "Pesanan berhasil ditambahkan.\n";
}

void layaniPembeli() {
    if (depan == belakang) {
        cout << "Antrean kosong!\n";
        return;
    }
    cout << "Melayani pesanan atas nama " << antrean[depan].nama << endl;
    riwayat[jumlahRiwayat++] = antrean[depan];
    depan++;
}

void tampilkanAntrean() {
    if (depan == belakang) {
        cout << "Tidak ada antrean.\n";
        return;
    }
    cout << "\nDaftar Antrean:\n";
    for (int i = depan; i < belakang; i++) {
        cout << i - depan + 1 << ". " << antrean[i].nama << " - " 
             << antrean[i].jenisRoti << " - Rp" << antrean[i].totalHarga << endl;
    }
}

void batalkanPesanan() {
    if (depan == belakang) {
        cout << "Tidak ada antrean.\n";
        return;
    }
    belakang--;
    cout << "Pesanan atas nama " << antrean[belakang].nama << " dibatalkan.\n";
}

void tampilkanRiwayat() {
    if (jumlahRiwayat == 0) {
        cout << "Belum ada pesanan yang dilayani.\n";
        return;
    }
    cout << "\nRiwayat Pesanan:\n";
    for (int i = 0; i < jumlahRiwayat; i++) {
        cout << i + 1 << ". " << riwayat[i].nama << " - "
             << riwayat[i].jenisRoti << " - Rp" << riwayat[i].totalHarga << endl;
    }
}

void menu() {
    int pilihan;
    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Ambil Antrean\n";
        cout << "2. Layani Pembeli\n";
        cout << "3. Tampilkan Antrean\n";
        cout << "4. Batalkan Pesanan Terakhir\n";
        cout << "5. Tampilkan Riwayat\n";
        cout << "6. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: ambilAntrean(); break;
            case 2: layaniPembeli(); break;
            case 3: tampilkanAntrean(); break;
            case 4: batalkanPesanan(); break;
            case 5: tampilkanRiwayat(); break;
            case 6: cout << "Terima kasih.\n"; break;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);
}

int main() {
    menu();
    return 0;
}
