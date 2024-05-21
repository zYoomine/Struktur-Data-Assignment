// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
using namespace std;

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int cari = 8;
int i;
int panjangArray = sizeof(arr)/ sizeof(arr[0]);
bool ketemu = false;

int main () {
    for (i = 0; i<panjangArray; i++) {
        if (arr[i] == cari) {
            ketemu == true;
            break;
        } else {
            i++;
        }
    }
    cout << cari << " terdapat pada indeks ke-" << i;
}