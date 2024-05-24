// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Fungsi Binary Search untuk mencari elemen dalam array dan mengembalikan indeksnya
int binarySearch(const vector<char>& arr, char target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        // Cek apakah target ada di tengah
        if (arr[middle] == target) {
            return middle;
        }

        // Jika target lebih besar, abaikan bagian kiri
        if (arr[middle] < target) {
            left = middle + 1;
        } else {
            // Jika target lebih kecil, abaikan bagian kanan
            right = middle - 1;
        }
    }

    // Jika target tidak ditemukan
    return -1;
}

int main() {
    string sentence;
    char target;

    cout << "\t==== BINARY SEARCH ====";

    // Input kalimat dari pengguna
    cout << "\nMasukkan sebuah kalimat: ";
    getline(cin, sentence);

    // Konversi string menjadi vector karakter dan abaikan spasi
    vector<char> data;
    for (char c : sentence) {
        if (c != ' ') {
            data.push_back(c);
        }
    }

    // Tampilkan data awal
    cout << "\nData          : ";
    for (char c : data) {
        cout << c << " ";
    }
    cout << endl;

    // Input karakter yang ingin dicari
    cout << "\nMasukkan huruf yang ingin Anda cari: ";
    cin >> target;

    // Urutkan data
    sort(data.begin(), data.end());

    // Tampilkan data yang sudah diurutkan
    cout << "\nData diurutkan: ";
    for (char c : data) {
        cout << c << " ";
    }
    cout << endl;

    // Cari karakter menggunakan Binary Search
    int index = binarySearch(data, target);

    if (index != -1) {
        cout << "\nData ditemukan pada index ke-" << index << endl;
    } else {
        cout << "\nData tidak ditemukan." << endl;
    }

    return 0;
}