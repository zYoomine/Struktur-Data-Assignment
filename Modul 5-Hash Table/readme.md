# <h1 align="center">Laporan Praktikum Modul 5 Hash Table</h1>
<p align="center">Muhammad Ragiel Prastyo</p>
<p align="center">2311102183</p>
<p align="center">S1IF-11-E</p>

## Dasar Teori

### Hash Table

### 1. Pengertian Hash Table
Struktur data Hash Table adalah struktur data yang digunakan untuk menyimpan dan mengelola data dengan cepat dan efisien. Ini beroperasi dengan prinsip kunci-nilai, di mana setiap elemen data memiliki kunci yang unik yang digunakan untuk mengakses atau memanipulasinya. Hash Table (Tabel Hash) adalah struktur data yang mengorganisir data ke dalam pasangan kunci-nilai. Ini menggunakan fungsi hash untuk mengonversi kunci menjadi indeks dalam array. Dengan cara ini, akses ke data menjadi sangat cepat karena kita dapat langsung menghitung indeks tempat data disimpan. Ini cocok untuk pencarian, penyisipan, penghapusan, dan pembaruan data dalam waktu konstan , asalkan tidak ada konflik dalam fungsi hash (collision)[1].

Tabel hash adalah struktur data yang digunakan untuk menyimpan pasangan kunci/nilai. Ia menggunakan fungsi hash untuk menghitung indeks ke dalam array di mana elemen akan dimasukkan atau dicari. Dengan menggunakan fungsi hash yang baik maka hashing dapat berjalan dengan baik. Berdasarkan asumsi yang masuk akal, waktu rata-rata yang diperlukan untuk mencari elemen dalam tabel hash adalah O(1)[2].

### 2. Fungsi Hash Table
Fungsi utamanya pada data adalah mempercepat proses akses data. Hal ini berkaitan dengan peningkatan data dalam jumlah besar yang diproses oleh jaringan data global dan lokal. Hash table adalah solusi untuk membuat proses akses data lebih cepat dan memastikan bahwa data dapat dipertukarkan dengan aman [3].

Fungsi hash adalah fungsi apa pun yang dapat digunakan untuk memetakan kumpulan data berukuran sembarang ke kumpulan data berukuran tetap, yang dimasukkan ke dalam tabel hash. Nilai yang dikembalikan oleh fungsi hash disebut nilai hash, kode hash, jumlah hash, atau sekadar hash [2].

### 3. Operasi Hash Table
1. Pencarian (Search)
Digunakan untuk mencari elemen/data dalam Hash Table berdasarkan kunci atau indeksnya. Pencarian dilakukan dengan menggunakan fungsi hash untuk menghasilkan indeks elemen yang dicari.

2. Penyisipan (Insertion)
Operasi ini digunakan untuk menyisipkan elemen/data baru ke dalam Hash Table. Elemen baru akan ditempatkan pada indeks yang dihasilkan oleh fungsi hash.

3. Penghapusan (Deletion)
Digunakan untuk menghapus elemen/data dari Hash Table berdasarkan kunci atau indeksnya. Elemen yang dihapus akan dihapus dari indeks yang dihasilkan oleh fungsi hash.

4. Update
Operasi ini digunakan untuk mengubah nilai elemen/data yang sudah ada dalam Hash Table. Nilai elemen dapat diubah berdasarkan kunci atau indeksnya.

5. Collision Handling
Collision terjadi ketika dua atau lebih elemen memiliki indeks yang sama setelah melalui fungsi hash. Operasi ini digunakan untuk menangani collision dan memastikan bahwa elemen-elemen dengan indeks yang sama dapat disimpan dan diakses dengan benar.

6. Resize
Operasi ini digunakan untuk mengubah ukuran Hash Table jika jumlah elemen/data yang disimpan melebihi kapasitas yang ditentukan. Resize dilakukan untuk menjaga efisiensi dan kinerja Hash Table.

7. Iterasi
Operasi yang digunakan untuk mengakses dan memproses semua elemen/data yang ada dalam Hash Table secara berurutan.

### Teknik-Teknik Hash Table
Didalam hash table ada dua teknik yang umum digunakan saat data scientist melakukan hash table. Berikut ini penjelasannya:
1. Hashing

Hashing merupakan sebuah proses mengganti kunci yang diberikan atau string karakter menjadi nilai lain. Penggunaan hashing paling populer adalah pada hash table. Hash table menyimpan pasangan kunci dan nilai dalam daftar yang dapat diakses melalui indeksnya. Karena pasangan kunci dan nilai tidak terbatas, maka fungsinya akan memetakan kunci ke ukuran tabel dan kemudian nilainya menjadi indeks untuk elemen tertentu[3].

2. Linear Probing

Linear probing merupakan skema dalam pemrograman komputer untuk menyelesaikan collision pada hash table. Dalam skema ini, setiap sel dari hash table menyimpan satu pasangan kunci-nilai. Saat fungsi hash menyebabkan collision dengan memetakan kunci baru ke sel hash table yang sudah ditempati oleh kunci lain, maka linear probing akan mencari tabel untuk lokasi bebas terdekat dan menyisipkan kunci baru. 
Pencarian dilakukan dengan cara yang sama, yaitu dengan mencari tabel secara berurutan, mulai dari posisi yang diberikan oleh fungsi hash, hingga menemukan sel dengan kunci yang cocok atau sel kosong. Hash table adalah struktur data non trivial yang paling umum digunakan. Linear probing dapat memberikan kinerja tinggi karena lokasi referensi yang baik, namun lebih sensitif terhadap kualitas fungsi hash daripada beberapa skema resolusi collision lainnya[3].

## Guided

### 1. Guided 1

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;

public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }

    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;

    // Deletion
    ht.remove(4);

    // Traversal
    ht.traverse();

    return 0;
}
```
Program diatas merupakan implementasi dari struktur data hash table menggunakan metode chaining untuk menangani tabrakan(collision). Hash table digunakan untuk menyimpan pasangan key-value, yang memungkinkan operasi insertion, searching, deletion, dan traversal pada data. Fungsi utama program menunjukkan penggunaan hash table dengan melakukan operasi memasukkan, mencari, menghapus, dan menampilkan data.

### 2. Guided 2

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11;

// Class hash node
class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Class hash map
class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];

public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    // Insertion
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    // Deletion
    void remove(string name) {
        int hash_val = hashFunc(name);
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan nama
    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    // Tampilkan
    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah: " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah: " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus: " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "HashTable:" << endl;
    employee_map.print();

    return 0;
}
```
Program diatas merupakan implementasi dari struktur data hash table menggunakan chaining untuk menangani tabrakan(collision). Dalam program ini, terdapat kelas "HashMap" yang mengimplementasikan hash table menggunakan array dari vektor. Setiap entri dalam hash table berisi vektor yang menyimpan pointer ke objek "HashNode", yang merupakan pasangan key-value. Program ini memungkinkan operasi-insertion, removal, dan pencarian berdasarkan nama untuk data yang disimpan dalam hash table. Fungsi utama dari program ini adalah menunjukkan penggunaan hash table dengan memasukkan beberapa data karyawan beserta nomor teleponnya, kemudian mencari nomor telepon berdasarkan nama, menghapus entri untuk seorang karyawan, dan menampilkan isi dari hash table.

## Unguided

### Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
1. Setiap mahasiswa memiliki NIM dan nilai.
2. Program memiliki tampilan pilihan menu berisi poin 3.
3. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nila (80– 90).

```C++
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
```
### Output
1. Tampilan Menu
![alt text](<Cuplikan layar 2024-04-17 221853.png>)

2. Tampilan Tambah Data Baru
![alt text](<Cuplikan layar 2024-04-17 225310.png>)

3. Tampilan Hapus Data
![alt text](<Cuplikan layar 2024-04-17 225703.png>)

4. Tampilan Mencari Data Mahasiswa berdasarkan NIM
![alt text](<Cuplikan layar 2024-04-17 225716.png>)

5. Tampilan Mencari Data Mahasiswa berdasarkan Rentang Nilai (80-90)
![alt text](<Cuplikan layar 2024-04-17 225742.png>)

6. Tampilan Exit/Selesai Program
![alt text](<Cuplikan layar 2024-04-17 225807.png>)

Program diatas adalah implementasi sederhana dari struktur data hash table untuk menyimpan data mahasiswa berdasarkan NIM dan nilai. Ketika program dijalankan, pengguna diminta untuk memilih opsi dari menu yang tersedia. Opsi-opsi tersebut mencakup penambahan data mahasiswa, penghapusan data mahasiswa berdasarkan NIM, pencarian data mahasiswa berdasarkan NIM, pencarian data mahasiswa berdasarkan rentang nilai (80-90), dan keluar dari program. Setelah memilih opsi, program akan mengeksekusi operasi sesuai dengan pilihan pengguna dan memberikan feedback terkait hasil operasi yang dilakukan. Misalnya, ketika data mahasiswa ditambahkan, program akan memberikan konfirmasi bahwa data telah ditambahkan. Hasil pencarian data mahasiswa akan menampilkan NIM dan nilai dari mahasiswa yang ditemukan. Jika data tidak ditemukan, program akan memberikan pesan yang sesuai. Setelah selesai, program akan keluar dengan pesan "Program selesai."

## Kesimpulan 
Keuntungan utama dari hash table dibandingkan struktur data lainnya adalah efisiensi dan kecepatan. Waktu yang dibutuhkan untuk mengakses sebuah elemen cukup cepat sehingga bisa lebih diandalkan. Jadi, kita tidak perlu memakan waktu atau usaha besar untuk menyimpan dan mencari data yang diperlukan.

## Referensi
[1] Annisa. (2023, Sep.19) Struktur Data Hash Table: Pengertian, Cara Kerja dan Operasi Hash Table [online]. Available : https://fikti.umsu.ac.id/struktur-data-hash-table-pengertian-cara-kerja-dan-operasi-hash-table/

[2] https://www-hackerearth-com.translate.goog/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/?_x_tr_sl=en&_x_tr_tl=id&_x_tr_hl=id&_x_tr_pto=tc

[3] Algoritma. (2022, Mar.22) Pengertian Hash Table dan Cara Penggunaannya [online]. Available : https://algorit.ma/blog/hash-table-adalah-2022/?avia-element-paging=3#top