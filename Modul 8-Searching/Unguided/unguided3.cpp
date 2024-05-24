// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

// Fungsi untuk melakukan pencarian sekuensial dan menghitung kemunculan target
int sequentialSearch(int data[], int size, int target) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == target) {
            count++;
        }
    }
    return count;
}

int main() {
    // Inisialisasi array dengan data yang diberikan
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int size = sizeof(data) / sizeof(data[0]);
    int target = 4;

    // Menghitung banyaknya angka 4 dalam data menggunakan pencarian sekuensial
    int jumlahKemunculan = sequentialSearch(data, size, target);

    // Menampilkan hasil pencarian
    cout << "Banyaknya angka " << target << " dalam data tersebut adalah: " << jumlahKemunculan << endl;

    return 0;
}