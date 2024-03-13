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