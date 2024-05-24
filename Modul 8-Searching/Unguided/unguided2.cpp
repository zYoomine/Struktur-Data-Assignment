// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah string
int countVowels(string str) {
    int count = 0;
    for (char c : str) {
        // Mengonversi karakter menjadi huruf kecil untuk memudahkan perbandingan
        if (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u') {
            count++;
        }
    }
    return count;
}

int main() {
    string kalimat;
    cout << "\t === Menghitung Banyaknya Huruf Vocal Dalam Sebuah Kalimat ===" << endl;
    // Meminta pengguna memasukkan sebuah kalimat
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);

    // Menghitung banyaknya huruf vokal dalam kalimat
    int jumlahVokal = countVowels(kalimat);

    // Menampilkan jumlah huruf vokal dalam kalimat
    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;

    return 0;
}