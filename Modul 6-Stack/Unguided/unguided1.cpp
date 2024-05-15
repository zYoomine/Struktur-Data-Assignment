// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include<iostream>
using namespace std;

const int Max = 100;
char Kata[Max]; // Deklarasi array bernama Kata sebagai stack
int Top = -1;

// Prosedur PushHuruf untuk menambahkan huruf pada stack
void PushHuruf(char Huruf) {
    if (Top < Max - 1) {
        Kata[++Top] = Huruf;
    }
}

// Fungsi PeekHurufPertama untuk melihat huruf atau elemen pertama yang disimpan pada stack
char PeekHurufPertama() {
    if (Top >= 0) {
        return Kata[Top];
    }
    return '\0';
}

// Fungsi isEmpty untuk memeriksa stack kosong atau tidak
bool isEmpty() {
    return (Top == -1);
}

// Fungsi CekPalindrom untuk memeriksa kata yang diinputkan user merupakan kata palindrom atau tidak
bool CekPalindrom(const char* InputKata, int Panjang) {
    // Memasukkan setengah huruf dari total huruf pada kata yang diinputkan user kedalam stack
    for (int i = 0; i < Panjang / 2; i++) {
        PushHuruf(InputKata[i]);
    }

    // Menentukan jumlah dari setengah karakter kedua dari kata yang diinputkan user 
    int Kedua = (Panjang % 2 == 0) ? Panjang / 2 : Panjang / 2 + 1;

    // Membandingkan setengah karakter kedua dengan setengah karakter pertama menggunakan fungsi PeekHurufPertama
    for (int i = Kedua; i < Panjang; i++) {
        if (Kata[Top--] != InputKata[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char InputKata[Max];
    cout << "--- CEK KATA PALINDROME ---" << endl;
    cout << "Masukkan kata yang ingin di cek : ";
    cin.getline(InputKata, Max); // Memasukkan setiap karakter/huruf yang diinputkan user kedalam array InputKata

    // Menghitung panjang string input
    int PanjangKata = 0;
    while (InputKata[PanjangKata] != '\0') {
        PanjangKata++;
    }

    // Mengecek kata yang diinputkan palindrom atau tidak menggunakan fungsi CekPalindrom
    if (CekPalindrom(InputKata, PanjangKata)) {
        cout << "Kata " << InputKata << " adalah Palindrom" << endl;  
    } else {
        cout << "Kata " << InputKata << " adalah bukan Palindrom" << endl;
    }
    
    return 0;
}