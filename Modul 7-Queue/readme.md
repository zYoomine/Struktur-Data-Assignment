# <h1 align="center">Laporan Praktikum Modul 6 Stack</h1>
<p align="center">Muhammad Ragiel Prastyo</p>
<p align="center">2311102183</p>
<p align="center">S1IF-11-E</p>

## Dasar Teori
### Pengertian Queue
Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.

Prinsip FIFO pada Queue adalah seperti jejeran orang yang sedang menunggu antrean di supermarket di mana orang pertama yang datang adalah yang pertama dilayani (First In, First Out). Pada struktur data ini, urutan pertama (data yang akan dikeluarkan) disebut Front atau Head. Sebaliknya, data pada urutan terakhir (data yang baru saja ditambahkan) disebut Back, Rear, atau Tail. Proses untuk menambahkan data pada antrean disebut dengan Enqueue, sedangkan proses untuk menghapus data dari antrean disebut dengan Dequeue.

Queue memiliki peran yang penting dalam berbagai aplikasi dan algoritma. Salah satu fungsi utamanya adalah mengatur dan mengelola antrean tugas atau operasi secara efisien. Dalam sistem komputasi, ia digunakan untuk menangani tugas-tugas seperti penjadwalan proses, antrean pesan, dan manajemen sumber daya.[1]

### Operasi-operasi Dasar pada Queue
Queue adalah struktur data abstrak (ADT) yang memungkinkan operasi berikut:
1. Enqueue : Menambahkan elemen ke akhir antrian.
2. Dequeue: Menghapus elemen dari depan antrian.
3. IsEmpty: Memeriksa apakah antrian kosong.
4. IsFull: Memeriksa apakah antrian sudah penuh.
5. Peek: Mendapatkan nilai bagian depan antrian tanpa menghapusnya.
6. Initialize: Membuat antrian baru tanpa elemen data (kosong).[2]

## Guided

### Guided 1

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian depan
int back = 0;  // Penanda antrian belakang
string queueTeller[maksimalQueue]; // Array untuk antrian

// Fungsi pengecekan antrian penuh atau tidak
bool isFull() {
    if (back == maksimalQueue) {
         return true; // =1
    } else {
        return false;
    }
}

// Fungsi pengecekan antrian kosong atau tidak
bool isEmpty() {
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

// Fungsi menambahkan antrian
void enqueueAntrian(string data) {
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        if (isEmpty()) { // Kondisi ketika queue kosong
            queueTeller[0] = data;
            front++;
            back++;
        } else { // Antrian ada isi
            queueTeller[back] = data;
            back++;
        }
    }
}

// Fungsi mengurangi antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back - 1; i++) {
            queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

// Fungsi menghitung banyak antrian
int countQueue() {
    return back;
}

// Fungsi menghapus semua antrian
void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

// Fungsi melihat antrian
void viewQueue() {
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
Program ini mengimplementasikan antrian menggunakan array dalam bahasa C++, memungkinkan penambahan dan penghapusan elemen, pengecekan status antrian (penuh atau kosong), penghitungan jumlah elemen, pengosongan antrian, dan penampilan isi antrian.

## Unguided

### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* front = nullptr; // Penanda antrian depan
Node* back = nullptr;  // Penanda antrian belakang

// Fungsi pengecekan antrian penuh atau tidak
bool isFull() {
    return false; // Linked list tidak memiliki batas maksimal
}

// Fungsi pengecekan antrian kosong atau tidak
bool isEmpty() {
    return front == nullptr;
}

// Fungsi menambahkan antrian
void enqueueAntrian(string data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

// Fungsi mengurangi antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

// Fungsi menghitung banyak antrian
int countQueue() {
    int count = 0;
    Node* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi menghapus semua antrian
void clearQueue() {
    while (front != nullptr) {
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

// Fungsi melihat antrian
void viewQueue() {
    cout << "Data antrian teller:" << endl;
    Node* temp = front;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->data << endl;
        temp = temp->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
### Output
![alt text](<Cuplikan layar 2024-05-21 233958.png>)

Program ini adalah implementasi antrian menggunakan linked list dalam bahasa C++ yang mendukung beberapa operasi penting: menambahkan elemen ke antrian (enqueue), menghapus elemen dari antrian (dequeue), menghitung jumlah elemen dalam antrian, menghapus semua elemen dalam antrian, dan menampilkan semua elemen yang ada di antrian. Program ini juga memeriksa apakah antrian kosong, namun tidak memiliki batasan ukuran karena menggunakan struktur linked list yang dinamis.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

Mahasiswa* front = nullptr; // Penanda antrian depan
Mahasiswa* back = nullptr;  // Penanda antrian belakang

// Fungsi pengecekan antrian penuh atau tidak
bool isFull() {
    return false; // Linked list tidak memiliki batas maksimal
}

// Fungsi pengecekan antrian kosong atau tidak
bool isEmpty() {
    return front == nullptr;
}

// Fungsi menambahkan antrian
void enqueueAntrian(string nama, string nim) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = newNode;
        back = newNode;
    } else {
        back->next = newNode;
        back = newNode;
    }
}

// Fungsi mengurangi antrian
void dequeueAntrian() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
}

// Fungsi menghitung banyak antrian
int countQueue() {
    int count = 0;
    Mahasiswa* temp = front;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Fungsi menghapus semua antrian
void clearQueue() {
    while (front != nullptr) {
        Mahasiswa* temp = front;
        front = front->next;
        delete temp;
    }
    back = nullptr;
}

// Fungsi melihat antrian
void viewQueue() {
    cout << "Data antrian mahasiswa:" << endl;
    Mahasiswa* temp = front;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". Nama: " << temp->nama << ", NIM: " << temp->nim << endl;
        temp = temp->next;
        i++;
    }
}

int main() {
    enqueueAntrian("Ragiel", "2311102183");
    enqueueAntrian("Prastyo", "2311102123");
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "Jumlah antrian = " << countQueue() << endl;
    return 0;
}
```
### Output
![alt text](<Cuplikan layar 2024-05-21 234324.png>)

Program ini adalah implementasi struktur data antrian menggunakan linked list dalam bahasa C++ untuk mengelola data mahasiswa. Program memungkinkan penambahan, penghapusan, dan pengelolaan data mahasiswa dengan fitur pengecekan apakah antrian kosong, penghitungan jumlah mahasiswa dalam antrian, dan tampilan seluruh isi antrian.

## Kesimpulan
Queue adalah struktur data yang mengorganisir elemen-elemen dalam urutan FIFO (First In, First Out), mirip dengan antrean di supermarket. Prinsip dasarnya adalah elemen yang pertama dimasukkan akan menjadi yang pertama dikeluarkan. Queue penting dalam mengatur antrean tugas atau operasi dalam berbagai aplikasi komputasi. Operasi dasar pada Queue meliputi Enqueue (penambahan elemen), Dequeue (penghapusan elemen), IsEmpty (memeriksa apakah antrian kosong), IsFull (memeriksa apakah antrian penuh), Peek (mendapatkan nilai dari elemen depan tanpa menghapusnya), dan Initialize (membuat antrian kosong). Pemahaman tentang struktur data queue menjadi kunci untuk mengoptimalkan efisiensi dan kinerja aplikasi.

## Referensi
[1] Rizki M. (2023, Nov. 29) Struktur Data Queue: Pengertian, Fungsi, dan Jenisnya [online]. Available : https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/

[2] Trivusi. (2023, Juli. 01) Struktur Data Queue: Pengertian, Jenis, dan Kegunaannya [online]. Available : https://www.trivusi.web.id/2022/07/struktur-data-queue.html#comments