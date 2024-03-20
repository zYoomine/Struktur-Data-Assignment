#include <iostream>
using namespace std;

int main() {
  int arr[100]; 
  int n; 

  // Menu Utama
  cout << "\n## Program Menu Pencarian Nilai Array ##" << endl;
  cout << "1. Input Data Array" << endl;
  cout << "2. Cari Nilai Maksimum" << endl;
  cout << "3. Cari Nilai Minimum" << endl;
  cout << "4. Cari Nilai Rata-rata" << endl;
  cout << "5. Keluar" << endl;

  int pilihan;

  do {
    cout << "\nPilih menu (1-5): ";
    cin >> pilihan;

    switch (pilihan) {
      case 1: // Input Data Array
        cout << "\nMasukkan jumlah elemen array: ";
        cin >> n;

        cout << "\nMasukkan elemen array: " << endl;
        for (int i = 0; i < n; i++) {
          cin >> arr[i];
        }

        cout << "\nData array telah disimpan." << endl;
        break;

      case 2: // Cari Nilai Maksimum
        if (n <= 0) {
          cout << "\nArray belum diinput! Masukkan data array terlebih dahulu." << endl;
        } else {
          int max = arr[0];
          for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
              max = arr[i];
            }
          }

          cout << "\nNilai maksimum array: " << max << endl;
        }
        break;

      case 3: // Cari Nilai Minimum
        if (n <= 0) {
          cout << "\nArray belum diinput! Masukkan data array terlebih dahulu." << endl;
        } else {
          int min = arr[0];
          for (int i = 1; i < n; i++) {
            if (arr[i] < min) {
              min = arr[i];
            }
          }

          cout << "\nNilai minimum array: " << min << endl;
        }
        break;

      case 4: // Cari Nilai Rata-rata
        if (n <= 0) {
          cout << "\nArray belum diinput! Masukkan data array terlebih dahulu." << endl;
        } else {
          int sum = 0;
          for (int i = 0; i < n; i++) {
            sum += arr[i];
          }

          float rataRata = (float) sum / n;
          cout << "\nNilai rata-rata array: " << rataRata << endl;
        }
        break;

      case 5: // Keluar
        cout << "\nKeluar dari program..." << endl;
        break;

      default:
        cout << "\nPilihan tidak valid! Masukkan nomor menu (1-5)." << endl;
    }
  } while (pilihan != 5);

  return 0;
}