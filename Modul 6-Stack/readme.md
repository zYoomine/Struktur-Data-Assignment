# <h1 align="center">Laporan Praktikum Modul 6 Stack</h1>
<p align="center">Muhammad Ragiel Prastyo</p>
<p align="center">2311102183</p>
<p align="center">S1IF-11-E</p>

## Dasar Teori
### Stack
Dalam konteks pemrograman, stack adalah struktur data yang mengikuti prinsip LIFO (Last-In, First-Out), yang berarti elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang diambil. Stack digunakan untuk mengelola urutan operasi atau pemanggilan fungsi, di mana setiap operasi atau pemanggilan fungsi baru ditempatkan di atas tumpukan dan operasi atau pemanggilan fungsi terakhir ditarik dari tumpukan.
Konsep dasar struktur data LIFO (Last-In, First-Out) pada stack adalah bahwa elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang diambil dari stack. Dalam struktur data ini, elemen yang baru ditambahkan (terakhir) akan diletakkan di atas elemen-elemen yang sudah ada sebelumnya, dan ketika elemen diambil, elemen yang terakhir ditambahkan (teratas) akan menjadi yang pertama diambil. Dengan demikian, elemen-elemen yang ada di bawahnya harus diambil terlebih dahulu sebelum mencapai elemen teratas stack.[1]

Stack terdiri dari beberapa jenis operasi, operasi utama dari Stack adalah Push dan Pop, namun terdapat pula operasi tambahan dari Stack yang juga penting. Adapun beberapa jenis operasi Stack adalah sebagai berikut.[2]
1. Push
Operasi Push merupakan proses operasi ketika kita ingin memasukkan sebuah elemen atau item ke dalam Stack. 

2. Pop
Operasi Pop dilakukan untuk menghapus sebuah elemen atau item dalam Stack.

3. Peek
Operasi Peek dilakukan untuk memungkinkan pengguna dapat melihat elemen di atas Stack dengan catatan tidak ada modifikasi apa pun dalam operasi ini.

4. int isFull
Operasi ini dilakukan untuk mengetahui apakah Stack sedang penuh atau tidak.

5. int isEmpty
Operasi ini dilakukan untuk mengetahui apakah Stack sedang kosong atau tidak.

6. int size
Operasi ini dilakukan untuk mengembalikan ukuran Stack atau jumlah total elemen yang ada dalam Stack tersebut.

7. int top
Operasi ini dilakukan untuk mengembalikan elemen terakhir yang dimasukkan di atas elemen lain tanpa menghapusnya.

## Guided

### Guided 1

```C++
// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
string arrayBuku[MAX_SIZE];
int top = 0;

// Fungsi untuk mengecek apakah stack telah penuh
bool isFull() {
    return (top == MAX_SIZE);
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty() {
    return (top == 0);
}

// Fungsi untuk menambahkan data ke atas stack
void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    } else {
        arrayBuku[top] = data;
        top++;
    }
}

// Fungsi untuk menghapus data teratas stack
void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] = "";
        top--;
    }
}

// Fungsi untuk melihat data ke-n di stack tanpa menghapusnya
void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        cout << "Posisi ke " << posisi << " adalah " << arrayBuku[index] << endl;
    }
}

// Fungsi untuk menghitung jumlah data yang ada di stack
int countStack() {
    return top;
}

// Fungsi untuk mengubah data pada posisi tertentu di stack
void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

// Fungsi untuk menghapus semua data pada stack
void destroyArrayBuku() {
    for (int i = top; i >= 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

// Fungsi untuk mencetak semua data pada stack
void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main() {
    // Contoh penggunaan fungsi pushArrayBuku()
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    // Contoh penggunaan fungsi cetakArrayBuku()
    cetakArrayBuku();
    cout << "\n";

    // Contoh penggunaan fungsi isFull() dan isEmpty()
    cout << "Apakah data stack penuh? " << isFull() << endl;
    cout << "Apakah data stack kosong? " << isEmpty() << endl;

    // Contoh penggunaan fungsi peekArrayBuku()
    peekArrayBuku(2);

    // Contoh penggunaan fungsi popArrayBuku()
    popArrayBuku();

    // Contoh penggunaan fungsi countStack()
    cout << "Banyaknya data = " << countStack() << endl;

    // Contoh penggunaan fungsi changeArrayBuku()
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();
    cout << "\n";

    // Contoh penggunaan fungsi destroyArrayBuku()
    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;

    // Contoh penggunaan fungsi countStack()
    cetakArrayBuku();
    return 0;
}
```
Source code diatas adalah program C++ yang mendefinisikan sebuah stack sederhana menggunakan array of string, yang dapat digunakan untuk menyimpan data buku. Program ini terdiri dari beberapa fungsi, seperti 'pushArrayBuku()' untuk menambahkan data ke atas stack, 'popArrayBuku()' untuk menghapus data teratas dari stack, 'peekArrayBuku()' untuk melihat data pada posisi tertentu di stack tanpa menghapusnya, 'cetakArrayBuku()' untuk mencetak semua data pada stack, dan beberapa fungsi lainnya yang digunakan untuk mengelola stack.

## Unguided

### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++

```