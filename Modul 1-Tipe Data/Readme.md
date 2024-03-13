# <h1 align="center">Laporan Praktikum Modul 1-Tipe Data</h1>
<p align="center">Muhammad Ragiel Prastyo</p>

## Dasar Teori

Berikan penjelasan teori terkait materi modul ini dengan bahasa anda sendiri serta susunan yang terstruktur per topiknya.

## Guided 

### 1. Tipe Data Primitif
```C++
#include <iostream>
using namespace std;
//main program
int main() 
{
    char op;
    float num1, num2;
    // It allows user to enter operator i.e. +, -, *, /
    cin >> op;
    // It allow user to enter the operands
    cin >> num1 >> num2;
    // Switch statement begins
    switch(op) {
        // If user enter +
        case '+':
            cout << num1 + num2;
            break;
        // If user enter - 
        case '-': 
            cout << num1 - num2; 
            break; 
        // If user enter * 
        case '*': 
            cout << num1 * num2; 
            break; 
        // If user enter / 
        case '/': 
            cout << num1 / num2; 
            break; 
        // If the operator is other than +, -, * or /, 
        // error message will display 
        default: 
            cout << "Error! operator is not correct"; 
    } // switch statement ends 
    return 0; 
}
```
Kode diastas adalah kalkulator sederhana yang menggunakan tipe data primitif 'char' untuk operator dan 'float' untuk angka desimal, memungkinkan pengguna melakukan operasi aritmatika dasar.

### 2. Tipe Data Abstrak
```C++
#include <iostream>

// Struct
struct Mahasiswa 
{
    const char *name;
    const char *address;
    int age;
};

int main() 
{
    // Menggunakan struct
    struct Mahasiswa mhs1, mhs2;
    // Mengisi nilai ke struct
    mhs1.name = "Dian";
    mhs1.address = "Mataram";
    mhs1.age = 22;
    mhs2.name = "Bambang";
    mhs2.address = "Surabaya";
    mhs2.age = 23;
    
    // mencetak isi struct 
    printf("## Mahasiswa 1 ##\n"); 
    printf("Nama: %s\n", mhs1.name); 
    printf("Alamat: %s\n", mhs1.address); 
    printf("Umur: %d\n", mhs1.age); 
    printf("## Mahasiswa 2 ##\n"); 
    printf("Nama: %s\n", mhs2.name); 
    printf("Alamat: %s\n", mhs2.address); 
    printf("Umur: %d\n", mhs2.age); 
    return 0; 
}
```
Kode diatas menunjukkan bagaimana struct dapat digunakan untuk mengelompokkan data terkait dan mengaksesnya dengan mudah. Struct merupakan contoh tipe data abstrak yang memungkinkan pengguna mendefinisikan struktur data mereka sendiri.

### 3. Tipe Data Koleksi
```C+++
#include <iostream>
using namespace std;

int main()
{
    //deklarasi dan inisialisasi array 
    int nilai[5]; 
    nilai[0] = 23; 
    nilai[1] = 50; 
    nilai[2] = 34; 
    nilai[3] = 78; 
    nilai[4] = 90; 
    
    //mencetak array 
    cout << "Isi array pertama :" << nilai[0] << endl; 
    cout << "Isi array kedua :" << nilai[1] << endl; 
    cout << "Isi array ketiga :" << nilai[2] << endl; 
    cout << "Isi array keempat :" << nilai[3] << endl; 
    cout << "Isi array kelima :" << nilai[4] << endl; 
    return 0;
}
```
Kode diatas menggunkan array yang berfungsi untuk menyimpan data secara berurutan dan mengaksesnya dengan mudah menggunakan indeks. Array merupakan contoh tipe data koleksi yang memungkinkan penyimpanan dan akses data secara efisien.

## Unguided 

### 1. [Soal]

```C++
#include <iostream>
using namespace std;

int main() {
    cout << "ini adalah file code unguided praktikan" << endl;
    return 0;
}
```
#### Output:
![alt text](<Cuplikan layar 2024-03-13 114931.png>)(https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/6d1727a8-fb77-4ecf-81ff-5de9386686b7)

Kode di atas digunakan untuk mencetak teks "ini adalah file code guided praktikan" ke layar menggunakan function cout untuk mengeksekusi nya.

#### Full code Screenshot:
![240309_10h21m35s_screenshot](https://github.com/suxeno/Struktur-Data-Assignment/assets/111122086/41e9641c-ad4e-4e50-9ca4-a0215e336b04)


## Kesimpulan
Ringkasan dan interpretasi pandangan kalia dari hasil praktikum dan pembelajaran yang didapat[1].

## Referensi
[1] I. Holm, Narrator, and J. Fullerton-Smith, Producer, How to Build a Human [DVD]. London: BBC; 2002.