#include <iostream>
using namespace std;

struct tanggal 
{
    int hari;
    int bulan;
    int tahun;
};

int main() 
{
    tanggal hariIni;
    hariIni.hari = 13;
    hariIni.bulan = 3;
    hariIni.tahun = 2024;
    
    cout << "Tanggal hari ini: " << hariIni.hari << "/" << hariIni.bulan << "/" << hariIni.tahun << endl;
    return 0;
}