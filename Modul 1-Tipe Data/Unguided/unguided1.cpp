#include <iostream>
using namespace std;

// Deklarasi fungsi untuk menghitung rata-rata
float hitungRataRata(int nilai1, int nilai2, int nilai3) {
  float rataRata = (nilai1 + nilai2 + nilai3) / 3.0f;
  return rataRata;
}

// Fungsi utama
int main() {
  // Deklarasi variabel
  int nilaiMatematika;
  int nilaiFisika;
  int nilaiKimia;
  float rataRata;

  // Memasukkan nilai ujian
  cout << "Masukkan nilai Matematika: ";
  cin >> nilaiMatematika;

  cout << "Masukkan nilai Fisika: ";
  cin >> nilaiFisika;

  cout << "Masukkan nilai Kimia: ";
  cin >> nilaiKimia;

  // Menghitung rata-rata nilai
  rataRata = hitungRataRata(nilaiMatematika, nilaiFisika, nilaiKimia);

  // Menampilkan hasil
  cout << "Rata-rata nilai: " << rataRata << endl;

  return 0;
}