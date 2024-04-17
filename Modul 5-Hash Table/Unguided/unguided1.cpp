// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <vector>
#include <list>
using namespace std;

// Struktur data untuk menyimpan data mahasiswa
struct Mahasiswa {
    int nim;
    int nilai;
};

// Kelas untuk Hash Table
class HashTable {
private:
    static const int tableSize = 10;
    vector<list<Mahasiswa>> table;

    // Fungsi hash sederhana
    int hashFunction(int nim) {
        return nim % tableSize;
    }

public:
    // Konstruktor
    HashTable() {
        table.resize(tableSize);
    }

    // Fungsi untuk menambahkan data mahasiswa
    void addData(int nim, int nilai) {
        int index = hashFunction(nim);
        Mahasiswa mhs;
        mhs.nim = nim;
        mhs.nilai = nilai;
        table[index].push_back(mhs);
    }

    // Fungsi untuk menghapus data mahasiswa berdasarkan NIM
    void deleteData(int nim) {
        int index = hashFunction(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->nim == nim) {
                table[index].erase(it);
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    void searchDataByNIM(int nim) {
        int index = hashFunction(nim);
        for (const auto &mhs : table[index]) {
            if (mhs.nim == nim) {
                cout << "Data mahasiswa dengan NIM " << nim << " ditemukan. Nilainya: " << mhs.nilai << endl;
                return;
            }
        }
        cout << "Data mahasiswa dengan NIM " << nim << " tidak ditemukan." << endl;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
    void searchDataByRange(int minNilai, int maxNilai) {
        for (const auto &bucket : table) {
            for (const auto &mhs : bucket) {
                if (mhs.nilai >= minNilai && mhs.nilai <= maxNilai) {
                    cout << "NIM: " << mhs.nim << ", Nilai: " << mhs.nilai << endl;
                }
            }
        }
    }
};

int main() {
    HashTable mahasiswaTable;

    // Menambahkan data mahasiswa secara langsung
    mahasiswaTable.addData(1111, 82);
    mahasiswaTable.addData(2222, 89);
    mahasiswaTable.addData(3333, 79);
    mahasiswaTable.addData(4444, 66);
    mahasiswaTable.addData(5555, 94);
    mahasiswaTable.addData(6666, 90);

    int choice;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Tambah Data Mahasiswa\n";
        cout << "2. Hapus Data Mahasiswa\n";
        cout << "3. Cari Data Mahasiswa berdasarkan NIM\n";
        cout << "4. Cari Data Mahasiswa berdasarkan Rentang Nilai (80-90)\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int nim, nilai;
                cout << "Masukkan NIM: ";
                cin >> nim;
                cout << "Masukkan Nilai: ";
                cin >> nilai;
                mahasiswaTable.addData(nim, nilai);
                cout << "Data telah ditambahkan." << endl;
                break;
            }
            case 2: {
                int nim;
                cout << "Masukkan NIM mahasiswa yang ingin dihapus: ";
                cin >> nim;
                mahasiswaTable.deleteData(nim);
                cout << "Data telah dihapus." << endl;
                break;
            }
            case 3: {
                int nim;
                cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
                cin >> nim;
                mahasiswaTable.searchDataByNIM(nim);
                break;
            }
            case 4: {
                cout << "Data Mahasiswa dengan Nilai antara 80 dan 90:\n";
                mahasiswaTable.searchDataByRange(80, 90);
                break;
            }
            case 0: {
                cout << "Program selesai.\n";
                break;
            }
            default:
                cout << "Pilihan tidak valid. Silakan pilih kembali.\n";
        }
    } while (choice != 0);

    return 0;
}