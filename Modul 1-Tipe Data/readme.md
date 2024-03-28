# <h1 align="center">Laporan Praktikum Modul 1 Tipe Data</h1>
<p align="center">Muhammad Ragiel Prastyo</p>
<p align="center">2311102183</p>
<p align="center">S1IF-11-E</p>

## Dasar Teori
Tipe data adalah sebuah pengklasifikasian data berdasarkan jenis data tersebut. Tipe data dibutuhkan agar kompiler dapat mengetahui bagaimana sebuah data akan digunakan. Tipe data yang akan dipelajari adalah sebagai berikut:
<pre>
1. Tipe Data Primitif
2. Tipe Data Abstrak
3. Tipe Data Koleksi
</pre>

### 1. Tipe Data Primitif
Tipe data primitif bagaikan batu bata pembangun program. Telah disediakan oleh bahasa pemrograman, mereka menyimpan data dasar seperti angka huruf, dan nilai benar/salah. Jumlah bit yang dialokasikan untuk setiap tipe data, tergantung pada bahasa pemrograman, compiler, dan sistem operasi.
Contoh dari tipe data primitif:
<pre>
1. Int: Menyimpan bilangan bulat.
2. Float: Menyimpan bilangan desimal.
3. Char: Menyimpan karakter.
4. Boolean: Menyimpan nilai benar/salah.
</pre>

### 2. Tipe Data Abstrak
Tipe data abstrak atau Abstrak Data Tipe(ADT) adalah tipe data buatan programmer dengan fleksibilitas tinggi. Tipe data ini dapat menyimpan berbagai jenis data, tidak hanya satu, kita dapat membuatnya sendiri. Fitur Class(C++) dan Struct(C) mirip kotak penyimpanan data dan Membungkus berbagai jenis data menjadi satu kesatuan. Perbedaannya Struct itu akses data secara default terbuka (public) sedangkan Class adalah Akses data secara default tersembunyi (private).

### 3. Tipe Data Koleksi
Tipe data koleksi dapat menyimpan banyak data yang bisa disimpan dengan rapi dan terstruktur. Ada beberapa tipe data koleksi yang umum 
digunakan dalam pemrograman, dan di antaranya adalah:
<pre>
1. Array: Menyimpan data dengan tipe sama dan akses menggunakan indeks, seperti kotak penyimpanan sepatu.
2. Vector: Mirip array, tapi lebih fleksibel. Kapasitasnya dapat bertambah otomatis, seperti rak buku yang dapat menampung buku baru.
3. Map: Menyimpan data dengan "kunci" unik, layaknya lemari arsip dengan kode unik untuk setiap dokumen.
</pre>

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
Kode diatas adalah kalkulator sederhana yang menggunakan tipe data primitif 'char' untuk operator dan 'float' untuk angka desimal, memungkinkan pengguna melakukan operasi aritmatika dasar.

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

```C++
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

### 1. Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas. Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

// Deklarasi fungsi untuk menghitung rata-rata
float hitungratarata(int nilai1, int nilai2, int nilai3) {
float ratarata = (nilai1 + nilai2 + nilai3) / 3.0f;
return ratarata;
}

// Fungsi utama
int main() {
  // Deklarasi variabel
  int nilaimatematika, nilaifisika, nilaikimia;
  float ratarata;

  // Memasukkan nilai ujian
  cout << "Masukkan nilai Matematika: ";
  cin >> nilaimatematika;

  cout << "Masukkan nilai Fisika: ";
  cin >> nilaifisika;

  cout << "Masukkan nilai Kimia: ";
  cin >> nilaikimia;

  // Menghitung rata-rata nilai
  ratarata = hitungratarata(nilaimatematika, nilaifisika, nilaikimia);

  // Menampilkan hasil
  cout << "Rata-rata nilai: " << ratarata << endl;

  return 0;
}
```
### Output:
![alt text](<Cuplikan layar 2024-03-13 142251.png>)

Program diatas menggunakan dua tipe data primitif: 'int' untuk menyimpan nilai ujian dan 'float' untuk menyimpan nilai rata-rata. Pada program ini juga menggunakan dua fungsi: 'hitungratarata' untuk menghitung rata-rata dari tiga nilai integer dan mengembalikan nilai float. 'main' sebagai fungsi utama yang mengelola input, perhitungan, dan output.

### Kesimpulan Tipe Data Primitif
Tipe data primitif adalah jenis data dasar yang digunakan untuk menyimpan nilai sederhana. Contoh tipe data primitif seperti int(bilangan bulat), float(bilangan desimal), char(karakter) dan bool(nilai boolean). Masing-masing tipe data primitif memiliki ukuran memori dan jangkauan nilai yang berbeda. Tipe data primitif digunakan dalam berbagai program untuk menyimpan dan memproses data.

### 2. Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
### Class
Fungsi:
<pre> 
-Mendefinisikan tipe data baru: Class memungkinkan untuk membuat tipe data baru yang kompleks dengan anggota data (variabel) dan fungsi (metode).
-Enkapsulasi data: Class melindungi data anggotanya dengan menyembunyikannya dan hanya memungkinkan akses melalui metode.
-Abstraksi: Class menyembunyikan detail implementasi dan hanya menunjukkan antarmuka yang dapat digunakan oleh program lain.
-Modularitas: Class memungkinkan untuk mengelompokkan kode terkait dan meningkatkan keterbacaan dan kemudahan penggunaan.
-Hierarki: Class dapat mewarisi properti dan metode dari class lain, memungkinkan reuse kode dan pembuatan hierarki kelas.
</pre>

### Contoh Program:

```C++
#include <iostream>
#include <string>
using namespace std;

class Mahasiswa {
private:
  string nama;
  string nim;
  float ipk;

public:
  // Setter dan getter untuk nama, nim dan ipk
  void setnama(string nilai) {
    nama = nilai;
  }

  string getnama() const {
    return nama;
  }

  void setnim(string nilai) {
    nim = nilai;
  }

  string getnim() const {
    return nim;
  }

  void setIpk(float nilai) {
    ipk = nilai;
  }

  float getIpk() const {
    return ipk;
  }

  // Menampilkan detail mahasiswa
  void cetakInfo() {
    cout << "Nama: " << getnama() << endl;
    cout << "NIM: " << getnim() << endl;
    cout << "IPK: " << getIpk() << endl;  
  }
};

int main() 
{
    Mahasiswa mhs1;
    mhs1.setnama("Bagas Dribble");
    mhs1.setnim("12345678");
    mhs1.setIpk(3.6);
    cout << "Data Mahasiswa: \n";
    mhs1.cetakInfo();
    return 0;
}
```
### Output
![alt text](<Cuplikan layar 2024-03-13 234954.png>)

Program ini menunjukkan contoh penggunaan class untuk menyimpan dan mengelola data mahasiswa. Class 'Mahasiswa' menyediakan metode untuk mengakses dan memanipulasi data anggota, dan fungsi 'main' menunjukkan cara menggunakan class untuk menyimpan dan menampilkan informasi mahasiswa.

### Struct
Fungsi:
<pre>
-Mirip dengan class: Struct memiliki fungsi yang mirip dengan class dalam mendefinisikan tipe data baru dengan anggota data dan fungsi.
-Perbedaan utama: Secara default, anggota data struct bersifat public, sedangkan anggota data class bersifat private.
-Kesederhanaan: Struct umumnya digunakan untuk struktur data sederhana yang tidak memerlukan enkapsulasi data yang ketat.
</pre>

### Contoh Program

```C++
#include <iostream>
using namespace std;

struct tanggal 
{
    int hari;
    int bulan;
    int tahun;
};

int main() 
{
    tanggal hariIni;
    hariIni.hari = 13;
    hariIni.bulan = 3;
    hariIni.tahun = 2024;
    
    cout << "Tanggal hari ini: " << hariIni.hari << "/" << hariIni.bulan << "/" << hariIni.tahun << endl;
    return 0;
}
```
### Output
![alt text](<Cuplikan layar 2024-03-13 235032.png>)

Pada program diatas, struct 'tanggal' mendefenisikan struktur data sederhana untuk menyimpan tanggal. Anggota datanya bersifat public secara default. program ini langsung mengakses dan memodifikasi anggota data tanggal tanpa metode khusus.

### 3. Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari array dengan map.

```C++
#include <iostream>
#include <map>
#include <string>
using namespace std;

struct mahasiswa 
{
    string nama;
    float ipk;
};

int main() 
{
    map <string, mahasiswa> datamahasiswa;

    // Menambahkan data mahasiswa ke map
    datamahasiswa["12345678"] = {"Bagas Dribble", 3.8};
    datamahasiswa["87654321"] = {"Windah Tol Cipularang", 3.5};

    // Mencari data mahasiswa dengan NIM
    string nim;
    cout << "Masukkan NIM: ";
    cin >> nim;

    if (datamahasiswa.find(nim) != datamahasiswa.end()) 
    {
        mahasiswa mahasiswa = datamahasiswa[nim];
        cout << "Nama: " << mahasiswa.nama << endl;
        cout << "IPK: " << mahasiswa.ipk << endl;
    } else {
        cout << "NIM tidak ditemukan." << endl;
    }
return 0;
}
```
### Output
![alt text](<Cuplikan layar 2024-03-13 235118.png>)

Program tersebut menggunakan struct 'mahasiswa' untuk menyimpan nama dan IPK mahasiswa. Dan juga penggunaan map pada 'datamahasiswa' untuk menyimpan data mahasiswa dengan NIM sebagai kunci dan objek 'mahasiswa' sebagai nilai. Program ini berinteraksi dengan pengguna untuk mencari data mahasiswa berdasarkan NIM.

### Array
Konsep array adalah struktur data yang menyimpan koleksi elemen berurutan dalam memori. Elemen diakses menggunakan indeks numerik yang dimulai dari 0. Misalnya, elemen pertama memiliki indeks 0, elemen kedua memiliki indeks 1, dan seterusnya. Elemen dalam array dapat memiliki nilai yang sama. Kita bisa memiliki banyak elemen dengan nilai "apple" di dalam array. Dalam array, elemen diproses atau diakses berdasarkan urutannya. Array cocok untuk menyimpan data yang perlu diproses atau diakses secara berurutan. Misalnya, daftar nilai ujian siswa, antrian pesan, atau koordinat dalam game.

### Map
Konsep Map adalah struktur data yang menyimpan koleksi elemen dalam bentuk pasangan kunci-nilai (key-value). Nilai diakses menggunakan kunci (key) yang bersifat unik. Tidak boleh ada duplikasi kunci dalam map. Kunci dalam map harus unik, tetapi nilai dapat memiliki duplikat. Urutan elemen dalam map tidak relevan dan bisa berubah-ubah. Map cocok untuk menyimpan data yang perlu diakses dengan cepat berdasarkan pengenal unik. Misalnya, data mahasiswa dengan NIM sebagai kunci.


## Kesimpulan
Kesimpulannya materi yang diberi pada modul 1 kali ini masih mudah dipahami.

## Referensi
[1] https://www.codepolitan.com/interactive-coding/php/lessons/34/

[2] https://en.cppreference.com/book/intro/classes

[3] https://www.geeksforgeeks.org/difference-between-array-and-map/ 
