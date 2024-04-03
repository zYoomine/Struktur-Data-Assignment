// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <string>
using namespace std;

// Struktur data untuk node dalam linked list
struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

// Kelas LinkedList untuk mengelola linked list
class LinkedList {
private:
    Mahasiswa* head;

public:
    // Konstruktor untuk inisialisasi linked list
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di awal linked list
    void tambahDepan(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;

        // Jika linked list kosong, node baru menunjuk ke dirinya sendiri
        if (head == nullptr) {
            newNode->next = newNode;
        } else {
            // Cari node terakhir dan ubah next-nya menjadi node baru
            Mahasiswa* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        // Perbarui head untuk menunjuk ke node baru
        head = newNode;
    }

    // Fungsi untuk menambahkan node di belakang linked list
    void tambahBelakang(string nama, string nim) {
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->nim = nim;
        newNode->next = head;

        // Jika linked list kosong, node baru menunjuk ke dirinya sendiri
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            // Cari node terakhir dan ubah next-nya menjadi node baru
            Mahasiswa* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Fungsi untuk menambahkan node di tengah linked list setelah node tertentu
    void tambahTengah(string nama, string nim, int posisi) {
        Mahasiswa* newNode = new Mahasiswa;
        newNode->nama = nama;
        newNode->nim = nim;

        // Cari node sebelum posisi yang diinginkan
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
            // Jika mencapai akhir linked list sebelum posisi yang diinginkan
            if (temp == head) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
        }

        // Sisipkan node baru setelah node dengan posisi yang diinginkan
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Fungsi untuk mengubah data pada node pertama
    void ubahDepan(string namaBaru, string nimBaru) {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Simpan data lama
        string namaLama = head->nama;
        // Ubah data pada node pertama
        head->nama = namaBaru;
        head->nim = nimBaru;
        cout << "Data " << namaLama << " telah diganti dengan data " << namaBaru << endl;
    }

    // Fungsi untuk mengubah data pada node terakhir
    void ubahBelakang(string namaBaru, string nimBaru) {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Cari node terakhir
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        // Simpan data lama
        string namaLama = temp->nama;
        // Ubah data pada node terakhir
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data " << namaLama << " telah diganti dengan data " << namaBaru << endl;
    }

    // Fungsi untuk mengubah data pada node dengan posisi tertentu
    void ubahTengah(string namaBaru, string nimBaru, int posisi) {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Cari node pada posisi yang diinginkan
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi; i++) {
            temp = temp->next;
            // Jika mencapai akhir linked list sebelum posisi yang diinginkan
            if (temp == head) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
        }
        // Simpan data lama
        string namaLama = temp->nama;
        // Ubah data pada node yang ditemukan
        temp->nama = namaBaru;
        temp->nim = nimBaru;
        cout << "Data " << namaLama << " telah diganti dengan data " << namaBaru << endl;
    }

    // Fungsi untuk menghapus node pertama
    void hapusDepan() {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Jika linked list hanya memiliki satu node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        // Cari node terakhir dan ubah next-nya menjadi node kedua
        Mahasiswa* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        Mahasiswa* hapusNode = head;
        head = head->next;
        temp->next = head;
        cout << "Data " << hapusNode->nama << " berhasil dihapus." << endl;
        delete hapusNode;
    }

    // Fungsi untuk menghapus node terakhir
    void hapusBelakang() {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Jika linked list hanya memiliki satu node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        // Cari node kedua terakhir
        Mahasiswa* temp = head;
        while (temp->next->next != head) {
            temp = temp->next;
        }
        Mahasiswa* hapusNode = temp->next;
        temp->next = temp->next->next;
        cout << "Data " << hapusNode->nama << " berhasil dihapus." << endl;
        delete hapusNode;
    }

    // Fungsi untuk menghapus node dengan posisi tertentu
    void hapusTengah(int posisi) {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Jika linked list hanya memiliki satu node
        if (head->next == head) {
            delete head;
            head = nullptr;
            return;
        }
        // Cari node sebelum node pada posisi yang diinginkan
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
            // Jika mencapai akhir linked list sebelum posisi yang diinginkan
            if (temp->next == head) {
                cout << "Posisi tidak valid." << endl;
                return;
            }
        }
        // Hapus node pada posisi yang diinginkan
        Mahasiswa* hapusNode = temp->next;
        temp->next = temp->next->next;
        cout << "Data " << hapusNode->nama << " berhasil dihapus." << endl;
        delete hapusNode;
    }

    // Fungsi untuk menampilkan seluruh data mahasiswa
    void tampilkan() {
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        Mahasiswa* temp = head;
        cout << "   DATA MAHASISWA  " << endl;
        cout << "NAMA\t\tNIM" << endl;
        cout << "========================" << endl;
        do {
            cout << temp->nama << "\t\t" << temp->nim << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Fungsi untuk menghapus seluruh data dalam linked list
    void hapusList() {
        // Jika linked list kosong, keluarkan pesan error
        if (head == nullptr) {
            cout << "Linked list kosong." << endl;
            return;
        }
        // Hapus semua node satu per satu
        Mahasiswa* temp = head;
        Mahasiswa* nextNode;
        do {
            nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
        head = nullptr;
        cout << "Linked list telah dihapus." << endl;
    }
};

int main() {
    LinkedList linkedList;
    int pilihan;
    string nama, nim, namaBaru, nimBaru;
    int posisi;

    // Memasukkan data sesuai urutan yang diberikan
    linkedList.tambahBelakang("Jawad", "23300001");
    linkedList.tambahBelakang("Ragiel", "2311102183");
    linkedList.tambahBelakang("Farrel", "23300003");
    linkedList.tambahBelakang("Denis", "23300005");
    linkedList.tambahBelakang("Anis", "23300008");
    linkedList.tambahBelakang("Bowo", "23300015");
    linkedList.tambahBelakang("Gahar", "23300040");
    linkedList.tambahBelakang("Udin", "23300048");
    linkedList.tambahBelakang("Ucok", "23300050");
    linkedList.tambahBelakang("Budi", "23300099");

    do {
        cout << "\n-PROGRAM SINGLE LINKED LIST CIRCULAR-" << endl;
        cout << "=====================================" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. Hapus List" << endl;
        cout << "11. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Operasi: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n-Tambah Depan-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM  : ";
                cin >> nim;
                linkedList.tambahDepan(nama, nim);
                cout << "Data telah ditambahkan." << endl;
                break;
            case 2:
                cout << "\n-Tambah Belakang-" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM  : ";
                cin >> nim;
                linkedList.tambahBelakang(nama, nim);
                cout << "Data telah ditambahkan." << endl;
                break;
            case 3:
                cout << "\n-Tambah Tengah-" << endl;
                cout << "Masukkan Nama                      : ";
                cin >> nama;
                cout << "Masukkan NIM                       : ";
                cin >> nim;
                cout << "Masukkan Posisi (Dihitung dari 1)  : ";
                cin >> posisi;
                linkedList.tambahTengah(nama, nim, posisi);
                cout << "Data telah ditambahkan." << endl;
                break;
            case 4:
                cout << "\n-Ubah Depan-" << endl;
                cout << "Masukkan Nama baru : ";
                cin >> namaBaru;
                cout << "Masukkan NIM baru  : ";
                cin >> nimBaru;
                linkedList.ubahDepan(namaBaru, nimBaru);
                break;
            case 5:
                cout << "\n-Ubah Belakang-" << endl;
                cout << "Masukkan Nama baru : ";
                cin >> namaBaru;
                cout << "Masukkan NIM baru  : ";
                cin >> nimBaru;
                linkedList.ubahBelakang(namaBaru, nimBaru);
                break;
            case 6:
                cout << "\n-Ubah Tengah-" << endl;
                cout << "Masukkan Nama baru                 : ";
                cin >> namaBaru;
                cout << "Masukkan NIM baru                  : ";
                cin >> nimBaru;
                cout << "Masukkan Posisi (Dihitung dari 1)  : ";
                cin >> posisi;
                linkedList.ubahTengah(namaBaru, nimBaru, posisi);
                break;
            case 7:
                cout << "\n-Hapus Depan-" << endl;
                linkedList.hapusDepan();
                break;
            case 8:
                cout << "\n-Hapus Belakang-" << endl;
                linkedList.hapusBelakang();
                break;
            case 9:
                cout << "\n-Hapus Tengah-" << endl;
                cout << "Masukkan Posisi (Dihitung dari 1)  : ";
                cin >> posisi;
                linkedList.hapusTengah(posisi);
                break;
            case 10:
                cout << "\n-Hapus List-" << endl;
                linkedList.hapusList();
                break;
            case 11:
                cout << "\n-TAMPILKAN-" << endl;
                linkedList.tampilkan();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    return 0;
}