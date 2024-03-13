#include <iostream>
#include <map>
#include <string>
using namespace std;

struct mahasiswa 
{
    string nama;
    float ipk;
};

int main() 
{
    map <string, mahasiswa> datamahasiswa;

    // Menambahkan data mahasiswa ke map
    datamahasiswa["12345678"] = {"Bagas Dribble", 3.8};
    datamahasiswa["87654321"] = {"Windah Tol Cipularang", 3.5};

    // Mencari data mahasiswa dengan NIM
    string nim;
    cout << "Masukkan NIM: ";
    cin >> nim;

    if (datamahasiswa.find(nim) != datamahasiswa.end()) 
    {
        mahasiswa mahasiswa = datamahasiswa[nim];
        cout << "Nama: " << mahasiswa.nama << endl;
        cout << "IPK: " << mahasiswa.ipk << endl;
    } else {
        cout << "NIM tidak ditemukan." << endl;
    }
return 0;
}