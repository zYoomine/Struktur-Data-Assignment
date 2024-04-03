# <h1 align="center">Laporan Praktikum Modul 4 Linked List Circular and Non Circular</h1>
<p align="center">Muhammad Ragiel Prastyo</p>
<p align="center">2311102183</p>
<p align="center">S1IF-11-E</p>

## Dasar Teori

### 1. Linked List Circular
Linked list circular adalah struktur data yang terdiri dari kumpulan node yang saling terhubung membentuk lingkaran. Setiap node memiliki data dan sebuah pointer yang menunjuk ke node berikutnya. Namun, tidak seperti linked list non-circular yang pointer terakhirnya menunjuk ke NULL, pointer terakhir pada linked list circular justru menunjuk kembali ke node pertama, sehingga membentuk lingkaran tertutup [1].
Beberapa karakteristik utama dari linked list circular :
1. Tidak memiliki awal dan akhir yang jelas.
2. Mudah melakukan operasi penyisipan dan penghapusan.
3. Cocok untuk implementasi struktur data queue (antrian) dan stack (tumpukan).
4. Memori sedikit lebih boros.

### 2. Linked List Non Circular
Linked list non circular adalah salah satu jenis struktur data yang digunakan untuk menyimpan dan mengorganisir data. Berbeda dengan linked list circular, pada linked list non circular, elemen terakhir tidak menunjuk kembali ke elemen pertama[2].
beberapa karakteristik dan jenis-jenis linked list non circular:
1. Singly Linked List (SLLNC) :
- Hanya dapat dilintasi dalam satu arah (dari simpul kepala ke simpul ekor).
- Setiap simpul memiliki dua bagian: nilai data dan pointer ke simpul berikutnya.

2. Doubly Linked List (DLLNC) :
- Dapat dilintasi dua arah.
- Setiap simpul memiliki dua pointer: satu menunjuk ke simpul berikutnya dan satu menunjuk ke simpul sebelumnya.

## Guided

### 1. Linked List Non Circular

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;
/// PROGRAM SINGLE LINKED LIST NON CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan List Kosong
bool isEmpty() {
    return head == NULL;
}

// Tambah Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        head = head->next;
        delete hapus;
        if (head == NULL) tail = NULL;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head == tail) {
            head = tail = NULL;
        } else {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }
        Node *hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            int nomor = 1;
            while (nomor < posisi) {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus List
void clearList() {
    Node *bantu = head, *hapus;
    while (bantu != NULL) {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
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
Program ini adalah implementasi dari operasi dasar pada linked list non-circular. Program ini memungkinkan untuk melakukan operasi seperti menambahkan node di depan, di belakang, atau di tengah, menghapus node, menghitung jumlah node, serta mengubah nilai dari node tertentu.

### 2. Linked List Circular

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <string>
using namespace std;
/// PROGRAM SINGLE LINKED LIST CIRCULAR
// DEKLARASI STRUCT NODE
struct Node
{
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init()
{
    head = NULL;
    tail = head;
}

// PENGECEKAN
int isEmpty()
{
    if (head == NULL)
    return 1;// TRUE
    else
    return 0;// FALSE
}

// BUAT NODE BARU
void buatNode(string data)
{
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// HITUNG LIST
int hitungList()
{
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL)
    {
        jumlah++;
        bantu = bantu->next;
    }

    return jumlah;
}

// TAMBAH DEPAN
void insertDepan(string data)
{
    // BUAT NODE BARU
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
            tail = tail->next;
        }
        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// TAMBAH BELAKANG
void insertBelakang(string data)
{
    //BUAT NODE BARU
    buatNode(data);

    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        while (tail->next != head)
        {
           tail = tail->next; 
        }

        tail->next = baru;
        baru->next = head;
        tail = baru;
    }
}

//TAMBAH TENGAH
void insertTengah(string data, int posisi)
{
    if (isEmpty() == 1)
    {
        head = baru;
        tail = head;
        baru->next = head;
    }
    else
    {
        baru->data = data;
        //TRANSVERSING
        int nomor = 1;
        bantu = head;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

//HAPUS DEPAN
void hapusDepan()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;

        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// HAPUS BELAKANG
void hapusBelakang()
{
    if (isEmpty() == 0)
    {
        hapus = head;
        tail = head;
        if (hapus->next == head)
        {
            head = NULL;
            tail = NULL;

            delete hapus;
        }
        else
        {
            while (hapus->next != head)
            {
                hapus = hapus->next;
            }
            while (tail->next != hapus)
            {
                tail = tail->next;
            }
            tail->next = head;
            hapus->next = NULL;

            delete hapus;
        }
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// HAPUS TENGAH
void hapusTengah(int posisi)
{
    if (isEmpty() == 0)
    {
        //TRANSVERSING
        int nomor = 1;
        bantu = head;

        while (nomor < posisi -1)
        {
            bantu = bantu->next;
            nomor++;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;

        delete hapus;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

// HAPUS LIST
void clearList()
{
    if (head != NULL)
    {

        hapus = head->next;

        while (hapus != head)
        {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }
        delete head;
        head = NULL;
    }
    cout << "List Berhasil Terhapus!" << endl;
}

// TAMPILKAN LIST
void tampil()
{
    if (isEmpty() == 0)
    {
        tail = head;
        do
        {
            cout << tail->data << endl;
            tail = tail->next;
        }
        while (tail != head);
        cout << endl;
    }
    else
    {
        cout << "List Masih Kosong!" << endl;
    }
}

int main()
{
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();

    return 0;
}
```
Program ini merupakan implementasi dari operasi dasar pada linked list circular. Linked list circular adalah struktur data dimana setiap node memiliki pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk kembali ke node pertama (head).

## Unguided

### Buatlah program menu Linked List Circular untuk menyimpan Nama dan NIM mahasiswa, dengan menggunakan input dari user. Dengan perintah seperti dibawah ini:
1. Buatlah menu untuk menambahkan, mengubah, menghapus, dan melihat Nama dan NIM mahasiswa.
2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah)

Nama 	NIM 

Jawad 	23300001 

[Nama Anda] 	[NIM Anda] 

Farrel 	23300003 

Denis 	23300005 

Anis 	23300008 

Bowo 	23300015 

Gahar 	23300040 

Udin 	23300048 

Ucok 	23300050 

Budi 	23300099 

3. Lakukan perintah berikut: 
a. Tambahkan data berikut diantara Farrel dan Denis: 
	Wati 	2330004 
b. Hapus data Denis 
c. Tambahkan data berikut di awal: 
	Owi 	2330000 
d. Tambahkan data berikut di akhir: 
	David 	23300100 
e. Ubah data Udin menjadi data berikut: 
	Idin 	23300045 
f. Ubah data terkahir menjadi berikut: 
	Lucy 	23300101 
g. Hapus data awal 
h. Ubah data awal menjadi berikut: 
	Bagas 	2330002 
i. Hapus data akhir 
j. Tampilkan seluruh data 

```C++
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
```
### Output
1. Tampilan Menu
![alt text](<Cuplikan layar 2024-04-03 213442.png>)

2. Tampilan Data yang Telah Dimasukkan
![alt text](<Cuplikan layar 2024-04-03 213518.png>)

3. Tampilan Tambahan Data Diantara Farrel dan Denis
![alt text](<Cuplikan layar 2024-04-03 214016.png>)

4. Tampilan Hapus Data Denis
![alt text](<Cuplikan layar 2024-04-03 214030.png>)

5. Tampilan Tambahan Data Diawal
![alt text](<Cuplikan layar 2024-04-03 214045.png>)

6. Tampilan Tambahan Data Diakhir
![alt text](<Cuplikan layar 2024-04-03 214058.png>)

7. Tampilan Ubah Data Udin Menjadi Data Idin
![alt text](<Cuplikan layar 2024-04-03 214109.png>)

8. Tampilan Ubah Data Terakhir Menjadi Data Lucy
![alt text](<Cuplikan layar 2024-04-03 214119.png>)

9. Tampilan Hapus Data Awal
![alt text](<Cuplikan layar 2024-04-03 214130.png>)

10. Tampilan Ubah Data Awal Menjadi Data Bagas
![alt text](<Cuplikan layar 2024-04-03 214141.png>)

11. Tampilan Hapus Data Akhir
![alt text](<Cuplikan layar 2024-04-03 214150.png>)

12. Tampilan Seluruh Data 
![alt text](<Cuplikan layar 2024-04-03 214221.png>)

Program ini merupakan implementasi dari linked list circular untuk mengelola data mahasiswa. Pengguna dapat melakukan berbagai operasi seperti menambah, mengubah, atau menghapus data mahasiswa, serta menampilkan seluruh data yang tersimpan dalam linked list. Setiap operasi akan memberikan output yang sesuai dengan hasil operasi yang dilakukan, seperti menampilkan pesan berhasil saat menambah atau mengubah data, serta pesan error jika terjadi kesalahan dalam operasi. Program akan berjalan terus hingga pengguna memilih untuk keluar dari program.

## Kesimpulan
Pemilihan antara linked list non-circular dan circular tergantung pada kebutuhan dan karakteristik struktur data yang ingin diimplementasikan. Jika membutuhkan akses data berurutan dan operasi insertion dan deletion yang sering dilakukan di awal dan akhir, linked list non-circular adalah pilihan yang tepat. Namun, jika membutuhkan akses data fleksibel dan operasi insertion dan deletion yang sering dilakukan di semua node, linked list circular adalah pilihan yang lebih baik.

## Referensi
[1] S. jain, R. Saxena.(2017, Mei.24) Introduction to Circular Linked List [Online].Available: https://www.geeksforgeeks.org/circular-linked-list/

[2] Trivusi.(2022, Juli.22) Struktur Data Linked List: Pengertian, Karakteristik, dan Jenis-jenisnya [Online]. Available:  https://www.trivusi.web.id/2022/07/struktur-data-linked-list.html