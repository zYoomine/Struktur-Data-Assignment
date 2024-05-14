// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
void balikKalimat(string kalimat) {
    stack<char> tumpukan;

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char c : kalimat) {
        tumpukan.push(c);
    }

    string kalimatDibalik;
    // Mengambil karakter dari stack dan menyimpannya dalam kalimat yang dibalik
    while (!tumpukan.empty()) {
        kalimatDibalik += tumpukan.top();
        tumpukan.pop();
    }

    // Menampilkan kalimat yang sudah dibalik
    cout << "Kalimat terbalik : " << kalimatDibalik << endl;
}

int main() {
    string kalimat;

    // Meminta pengguna memasukkan sebuah kalimat
    cout << "Masukkan kalimat : ";
    getline(cin, kalimat);

    int jumlahKata = 1;
    // Menghitung jumlah kata dalam kalimat
    for (char c : kalimat) {
        if (c == ' ') {
            jumlahKata++;
        }
    }

    // Memeriksa apakah jumlah kata kurang dari 3
    if (jumlahKata < 3) {
        cout << "Kalimat harus terdiri dari minimal 3 kata" << endl;
    } else {
        // Memanggil fungsi untuk membalikkan kalimat dan menampilkan hasil kalimat yang sudah dibalik
        balikKalimat(kalimat);
    }

    return 0;
}