# <h1 align="center">Laporan Praktikum Modul 3 Single and Double Linked List</h1>
<p align="center">Muhammad Ragiel Prastyo</p>
<p align="center">2311102183</p>
<p align="center">S1IF-11-E</p>

## Dasar Teori
Linked List adalah struktur data linear yang terdiri dari kumpulan node (simpul) yang saling terhubung. Setiap node menyimpan data dan pointer (penunjuk) yang mengarah ke node berikutnya dalam list. Berbeda dengan array yang menyimpan data secara berurutan di memori, elemen-elemen dalam Linked List tidak ditempatkan secara berdekatan melainkan dihubungkan melalui pointer.

### 1. Single Linked List
Single linked list adalah struktur data linear dimana elemen-elemennya tidak disimpan di lokasi memori yang berdekatan, melainkan saling terhubung satu sama lain menggunakan pointer. Secara sederhana, bayangkan sebuah rangkaian kereta. Setiap kereta (node) memiliki gerbong (data) dan penyanghubung (pointer) ke kereta berikutnya.  Dengan pointer inilah kita bisa melacak elemen selanjutnya dalam list.
Berbeda dengan array yang elemennya disimpan berurutan di memori, single linked list lebih fleksibel karena penambahan dan penghapusan elemen bisa dilakukan dengan mudah tanpa perlu menggeser elemen lain.

### 2. Double Linked List
Double linked list adalah struktur data linear dimana elemen-elemennya berupa node yang tidak tersimpan berurutan di memori, melainkan saling terhubung dengan dua buah pointer, yaitu pointer sebelumnya (prev) dan pointer selanjutnya (next). Bisa dibayangkan sebagai gerbong kereta api yang saling terkait. Setiap gerbong (node) memiliki muatan (data) dan penghubung ke gerbong sebelumnya dan gerbong berikutnya (pointer).  Dengan pointer inilah kita bisa melacak elemen sebelumnya dan selanjutnya dalam list.
Double linked list memiliki beberapa kelebihan dibandingkan dengan single linked list seperti akses data lebih fleksibel dan penyisipan dan penghapusan elemen lebih mudah. Namun, double linked list juga memiliki kekurangan seperti memori yang dibutuhkan lebih besar.
 
## Guided

### 1. Latihan Single Linked List

```C++
#include <iostream>
using namespace std;
// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node

struct Node
{
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
    return true;
    else
    return false;
}

//Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node Baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node Baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;

    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;

        // Tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan()
{
    Node *hapus;

    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong" << endl;
    }
}

// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;

    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if(posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Tengah
void ubahTengah(int data, int posisi) 
{
    Node *bantu;
    if (isEmpty() == false) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Ubah Belakang
void ubahBelakang(int data) 
{
    if (isEmpty() == false) {
        tail->data = data;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

//Hapus List
void clearList() 
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

//Tampilkan List
void tampil() 
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false) {
        while (bantu != NULL) {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else {
        cout << "List masih kosong!" << endl;
    }
}

int main() 
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
Program diatas menunjukkan implementasi operasi dasar pada Single Linked List Non-Circular seperti inisialisasi list, penambahan data (depan, belakang, dan tengah), penghapusan data (depan, belakang, dan tengah), dan pengubahan data (depan, belakang, dan tengah). Output program menunjukkan hasil dari operasi-operasi tersebut pada list data.

### 2. Latihan Double Linked List

```C++
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        else {
            tail = newNode;
        }
        head = newNode;
    }
    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete temp;
    }
    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1: {
            int data;
            cout << "Enter data to add: ";
            cin >> data;
            list.push(data);
            break;
        }
        case 2: {
            list.pop();
            break;
        }
        case 3: {
            int oldData, newData;
            cout << "Enter old data: ";
            cin >> oldData;
            cout << "Enter new data: ";
            cin >> newData;
            bool updated = list.update(oldData, newData);
            if (!updated) {
                cout << "Data not found" << endl;
            }
            break;
        }
        case 4: {
            list.deleteAll();
            break;
        }
        case 5: {
            list.display();
            break;
        }
        case 6: {
            return 0;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
    return 0;
}
```
Program diatas mengimplementasikan Double Linked List dengan menu interaktif untuk melakukan operasi-operasi pada list data. Program ini memungkinkan pengguna untuk melakukan operasi dasar pada Doble Linked List untuk menambah, menghapus, mengubah, membersihkan, dan menampilkan data dalam list.

## Unguided

### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:

a.	Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

[Nama_anda]	[Usia_anda]

John	19

Jane	20

Michael	18

Yusuke	19

Akechi	20

Hoshino	18

Karin	18

b.	Hapus data Akechi

c.	Tambahkan data berikut diantara John dan Jane : Futaba	18

d.	Tambahkan data berikut diawal : Igor	20

e.	Ubah data Michael menjadi : Reyn	18

f.	Tampilkan seluruh data

```C++
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
```
### Output:
![alt text](<Cuplikan layar 2024-03-28 232155.png>)

Program ini memungkinkan pengguna untuk mengelola daftar data mahasiswa yang tersimpan dalam linked list. Pengguna dapat melakukan berbagai operasi pada data mahasiswa seperti menambah data, menghapus data, mengubah data dan menampilkan data.

### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Nama Produk	Harga

Originote	60.000

Somethinc	150.000

Skintific	100.000

Wardah	50.000

Hanasui	30.000

Case:

1.Tambahkan produk Azarine dengan harga 65000 diantara Somethinc dan Skintific

2.Hapus produk wardah

3.Update produk Hanasui menjadi Cleora dengan harga 55.000

4.Tampilkan menu seperti dibawah ini 

Toko Skincare Purwokerto

1.Tambah Data

2.Hapus Data

3.Update Data

4.Tambah Data Urutan Tertentu

5.Hapus Data Urutan Tertentu

6.Hapus Seluruh Data

7.Tampilkan Data

8.Exit

Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah ini :

Nama Produk	Harga

Originote	60.000

Somethinc	150.000

Azarine	65.000

Skintific	100.000

Cleora	55.000

```C++
// Nama : Muhammad Ragiel Prastyo
// NIM  : 2311102183
#include <iostream>
#include <string>
using namespace std;

// Struktur node untuk linked list
struct Node
{
    string nama_produk;
    int harga;
    Node *prev;
    Node *next;
};

// Kelas untuk Doubly Linked List
class DoublyLinkedList
{
private:
    Node *head; 
    Node *tail; 
public:
    // Konstruktor
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void NewFunction(Node *newNode)
    {
        tail->next = newNode;
    }

    // Fungsi untuk menyisipkan node di akhir linked list
    void insertAtEnd(string nama_produk, int harga)
    {
        Node *newNode = new Node();
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;
        newNode->next = nullptr;
        if (head == nullptr)
        {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    // Fungsi untuk menghapus node dengan nama produk tertentu
    void deleteNode(string nama_produk)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong." << endl;
            return;
        }
        if (head->nama_produk == nama_produk)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }
        Node *temp = head;
        while (temp != nullptr && temp->nama_produk != nama_produk)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Node dengan nama produk " << nama_produk << " tidak ditemukan." << endl;
            return;
        }
        if (temp->next != nullptr)
        {
            temp->next->prev = temp->prev;
        }
        temp->prev->next = temp->next;
        delete temp;
    }

    // Fungsi untuk mengubah harga dari node dengan nama produk tertentu
    void updateData(string nama_produk, int hargaBaru, string namaBaru)
    {
        Node *current = head;
        while (current != NULL)
        {
            if (current->nama_produk == nama_produk)
            {
                current->harga = hargaBaru;
                current->nama_produk = namaBaru;
                cout << "Data produk " << nama_produk << " berhasil diupdate!" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    // Fungsi untuk menambahkan data pada urutan Node tertentu
    void tambahDataUrutanTertentu(string nama_produk, int harga, int urutan)
    {
        Node *newNode = new Node();
        newNode->nama_produk = nama_produk;
        newNode->harga = harga;

        Node *current = head;
        int pos = 1;
        while (current != NULL && pos < urutan)
        {
            current = current->next;
            pos++;
        }

        if (current == NULL)
        {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != NULL)
            current->next->prev = newNode;
        current->next = newNode;
        cout << "Berhasil menambahkan data!" << endl;
    }

    // Fungsi untuk menghapus node berdasarkan urutan yang ditentukan
    void hapusDataUrutanTertentu(int urutan)
    {
        if (head == nullptr)
        {
            cout << "Linked List Kosong." << endl;
            return;
        }

        Node *current = head;
        int pos = 0;
        while (current != nullptr && pos < urutan)
        {
            current = current->next;
            pos++;
        }

        if (current == nullptr || current == tail)
        {
            cout << "Urutan tidak valid" << endl;
            return;
        }

        if (current == head)
        {
            head = current->next;
            if (head != nullptr)
                head->prev = nullptr;
        }
        else if (current == tail)
        {
            tail = current->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Data pada urutan " << urutan << " berhasil dihapus!" << endl;
    }

    // Fungsi untuk menghapus semua node dalam linked list
    void deleteAll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = nullptr;
    }

    // Fungsi untuk menampilkan seluruh data dalam linked list
    void display()
    {
        Node *temp = head;
        cout << "\nNama Produk\tHarga" << endl;
        while (temp != nullptr)
        {
            cout << temp->nama_produk << "   \t" << temp->harga << endl;
            temp = temp->next;
        }
    }
};

int main()
{
    DoublyLinkedList produkList;
    string nama_produk, namaBaru;
    int harga, hargaBaru, urutan;

    // Menambahkan data produk sesuai permintaan
    produkList.insertAtEnd("Originote", 60000);
    produkList.insertAtEnd("Somethinc", 150000);
    produkList.insertAtEnd("Skintific", 100000);
    produkList.insertAtEnd("Wardah", 50000);
    produkList.insertAtEnd("Hanasui", 30000);

    // Menampilkan menu
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Exit" << endl;

    int choice;
    while (true)
    {
        cout << "\nMasukkan pilihan Anda: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "Masukkan nama produk: ";
            cin >> nama_produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            produkList.insertAtEnd(nama_produk, harga);
            cout << "Berhasil menambahkan data!" << endl;
            break;
        }
        case 2:
        {
            cout << "Masukkan nama produk yang akan dihapus: ";
            cin >> nama_produk;
            produkList.deleteNode(nama_produk);
            cout << "Data dengan nama " << nama_produk << " berhasil dihapus!" << endl;
            break;
        }
        case 3:
        {
            cout << "Masukkan nama produk yang akan diupdate: ";
            cin >> nama_produk;
            cout << "Masukkan nama produk baru: ";
            cin >> namaBaru;
            cout << "Masukkan harga baru: ";
            cin >> hargaBaru;
            produkList.updateData(nama_produk, hargaBaru, namaBaru);
            break;
        }
        case 4:
        {
            cout << "Masukkan nama produk: ";
            cin >> nama_produk;
            cout << "Masukkan harga: ";
            cin >> harga;
            cout << "Masukkan urutan: ";
            cin >> urutan;
            produkList.tambahDataUrutanTertentu(nama_produk, harga, urutan);
            break;
        }
        case 5:
        {
            int urutan;
            cout << "Masukkan urutan produk yang akan dihapus: ";
            cin >> urutan;
            produkList.hapusDataUrutanTertentu(urutan);
            break;
        }
        case 6:
        {
            produkList.deleteAll();
            cout << "Semua data telah dihapus!" << endl;
            break;
        }
        case 7:
        {
            produkList.display();
            break;
        }
        case 8:
        {
            cout << "Terima Kasih!!" << endl;
            return 0;
        }
        default:
        {
            cout << "Pilihan tidak valid. Silakan pilih kembali." << endl;
            break;
        }
        }
    }
    return 0;
}
```
### Output:
1.Untuk menampilkan nama produk dan harga awal yang belum di ubah-ubah
![alt text](<Cuplikan layar 2024-03-28 233858.png>)

2.Menambah nama produk dan harga baru di urutan tertentu
![alt text](<Cuplikan layar 2024-03-28 233930.png>)

3.Menghapus nama produk dan harga dengan menginputkan nama produknya
![alt text](<Cuplikan layar 2024-03-28 233945.png>)

4.Mengupdate nama produk dan harga lama dengan nama produk dan harga yang baru
![alt text](<Cuplikan layar 2024-03-28 234001.png>)

5.Menampilkan menu akhir produk dan harganya yang sudah ditambah, hapus dan update.
![alt text](<Cuplikan layar 2024-03-28 234016.png>)

6.Tampilan output keseluruhan
![alt text](<Cuplikan layar 2024-03-28 235003.png>)

Program di atas merupakan implementasi Doubly Linked List yang menyimpan data produk skincare beserta harganya. Setiap node dalam linked list memiliki dua elemen, yaitu nama_produk dan harga. Output program-program diatas memberikan informasi tentang data produk yang tersimpan dalam doubly linked list. Pengguna dapat menambahkan, menghapus, memperbarui, dan melihat data produk.

## Kesimpulan
Single linked list dan double linked list adalah dua jenis struktur data linear yang populer. Keduanya menggunakan node untuk menyimpan data, namun memiliki beberapa perbedaan penting.
Single linked list lebih hemat memori dan efisien untuk penelusuran searah. Masing-masing node dalam single linked list hanya memiliki satu pointer yang menunjuk ke node selanjutnya. Hal ini membuatnya ideal untuk situasi di mana memori terbatas dan penelusuran data hanya dilakukan dari awal ke akhir.
Double linked list menyediakan akses data dua arah dan kemudahan modifikasi list. Masing-masing node dalam double linked list memiliki dua pointer, yaitu pointer ke node sebelumnya dan pointer ke node selanjutnya. Hal ini memungkinkan penelusuran data dari depan ke belakang dan sebaliknya, serta penyisipan dan penghapusan elemen di tengah list dengan mudah.

## Referensi
[1] https://www.geeksforgeeks.org/data-structures/linked-list/

[2] https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html
