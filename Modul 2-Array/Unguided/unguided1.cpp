#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel
  int n;

  // Meminta input jumlah data
  cout << "Masukkan jumlah data: ";
  cin >> n;

  // Deklarasi array
  int data[n];

  // Meminta input data
  for (int i = 0; i < n; i++) {
    cout << "Masukkan data ke-" << i + 1 << ": ";
    cin >> data[i];
  }

  // Menampilkan data
  cout << endl << "Data Array:" << endl;
  for (int i = 0; i < n; i++) {
    cout << data[i] << " ";
  }

  cout << endl << endl << "Nomor Genap" << endl;
  for (int i = 0; i < n; i++) {
    if (data[i] % 2 == 0) {
      cout << data[i] << " ";
    }
  }

  cout << endl << endl << "Nomor Ganjil" << endl;
  for (int i = 0; i < n; i++) {
    if (data[i] % 2 != 0) {
      cout << data[i] << " ";
    }
  }

  return 0;
}