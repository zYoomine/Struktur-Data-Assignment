// NAMA : Muhammad Ragiel Prastyo
// NIM  : 2311102183
#include <iostream>
#include <string>
using namespace std;

// Node untuk menyimpan data mahasiswa
struct Node {
    string nama;
    int usia;
    Node* next;

    // Constructor untuk inisialisasi node
    Node(string nama, int usia) {
        this->nama = nama;
        this->usia = usia;
        next = nullptr;
    }
};

// Kelas LinkedList untuk mengelola linked list
class LinkedList {
private:
    Node* head;

public:
    // Constructor untuk inisialisasi linked list
    LinkedList() {
        head = nullptr;
    }

    // Fungsi untuk menambahkan node di awal linked list
    void tambah_depan(string nama, int usia) {
        Node* new_node = new Node(nama, usia);
        new_node->next = head;
        head = new_node;
    }

    // Fungsi untuk menambahkan node di akhir linked list
    void tambah_belakang(string nama, int usia) {
        Node* new_node = new Node(nama, usia);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    // Fungsi untuk menambahkan node di tengah linked list setelah node tertentu
    void tambah_tengah(string nama, int usia, string nama_setelah) {
        Node* new_node = new Node(nama, usia);
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama_setelah) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Node tidak ditemukan." << endl;
            return;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }

    // Fungsi untuk menghapus node dengan nama tertentu
    void hapus(string nama) {
        Node* temp = head;
        Node* prev = nullptr;

        // Cari node dengan nama yang cocok
        while (temp != nullptr && temp->nama != nama) {
            prev = temp;
            temp = temp->next;
        }

        // Jika nama ditemukan, hapus node
        if (temp != nullptr) {
            if (prev == nullptr) {
                // Jika node adalah node pertama
                head = temp->next;
            } else {
                // Jika node bukan node pertama
                prev->next = temp->next;
            }
            delete temp;
            cout << "Data " << nama << " telah dihapus." << endl;
        } else {
            cout << "Data tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk mengubah data node dengan nama tertentu
    void ubah_data(string nama, string nama_baru, int usia_baru) {
        Node* temp = head;
        while (temp != nullptr && temp->nama != nama) {
            temp = temp->next;
        }
        if (temp != nullptr) {
            temp->nama = nama_baru;
            temp->usia = usia_baru;
            cout << "Data " << nama << " telah diubah menjadi " << nama_baru << " " << usia_baru << "." << endl;
        } else {
            cout << "Data tidak ditemukan." << endl;
        }
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void tampilkan_data() {
        Node* temp = head;
        cout << "Data Mahasiswa:" << endl;
        while (temp != nullptr) {
            cout << temp->nama << "\t" << temp->usia << endl;
            temp = temp->next;
        }
    }
};

int main() {
    char lanjut;

    do {
        LinkedList linkedList;

        // Meminta data pengguna
        string nama;
        int usia;

        // Memasukkan data pengguna
        cout << "Masukkan nama Anda: ";
        cin >> nama;
        cout << "Masukkan usia Anda: ";
        cin >> usia;
        linkedList.tambah_depan(nama, usia);

        // Meminta data mahasiswa lainnya dari pengguna
        cout << "Masukkan data (Nama dan Usia), pisahkan dengan spasi dan akhiri dengan 'selesai': " << endl;
        do {
            cin >> nama;
            if (nama == "selesai") break;
            cin >> usia;
            linkedList.tambah_belakang(nama, usia);
        } while (true);

        // Hapus data
        cout << "Masukkan nama yang akan dihapus: ";
        cin >> nama;
        linkedList.hapus(nama);

        // Tambahkan data di tengah
        cout << "Masukkan nama yang ingin dimasukkan: ";
        cin >> nama;
        cout << "Masukkan usia yang ingin dimasukkan: ";
        cin >> usia;
        cout << "Masukkan nama setelahnya: ";
        string nama_setelah;
        cin >> nama_setelah;
        linkedList.tambah_tengah(nama, usia, nama_setelah);

        // Tambahkan data di awal
        cout << "Masukkan nama yang ingin dimasukkan di awal: ";
        cin >> nama;
        cout << "Masukkan usia yang ingin dimasukkan di awal: ";
        cin >> usia;
        linkedList.tambah_depan(nama, usia);

        // Ubah data
        cout << "Masukkan nama yang akan diubah: ";
        cin >> nama;
        cout << "Masukkan nama baru: ";
        string nama_baru;
        cin >> nama_baru;
        cout << "Masukkan usia baru: ";
        int usia_baru;
        cin >> usia_baru;
        linkedList.ubah_data(nama, nama_baru, usia_baru);

        // Tampilkan data
        linkedList.tampilkan_data();

        cout << "Apakah Anda ingin melanjutkan (y/n)? ";
        cin >> lanjut;
    } while (lanjut == 'y' || lanjut == 'Y');

    return 0;
}