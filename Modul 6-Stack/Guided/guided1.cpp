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