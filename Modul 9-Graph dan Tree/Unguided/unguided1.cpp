// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int jumlahSimpul_2311102183;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul_2311102183;

    vector<string> simpul(jumlahSimpul_2311102183);
    for (int i = 0; i < jumlahSimpul_2311102183; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    vector<vector<int>> bobot(jumlahSimpul_2311102183, vector<int>(jumlahSimpul_2311102183));

    cout << "Silakan masukkan bobot antar simpul\n";
    for (int i = 0; i < jumlahSimpul_2311102183; ++i) {
        for (int j = 0; j < jumlahSimpul_2311102183; ++j) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> bobot[i][j];
        }
    }

    cout << "\n   ";
    for (const auto& s : simpul) {
        cout << s << " ";
    }
    cout << "\n";

    for (int i = 0; i < jumlahSimpul_2311102183; ++i) {
        cout << simpul[i] << " ";
        for (int j = 0; j < jumlahSimpul_2311102183; ++j) {
            cout << bobot[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}