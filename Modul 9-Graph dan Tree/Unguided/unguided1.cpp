// NAMA : MUHAMMAD RAGIEL PRASTYO
// NIM  : 2311102183
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void displayMatrix(const vector<vector<int>>& matrix, const vector<string>& nodes) {
    int n = nodes.size();
    
    cout << "   ";
    for (int i = 0; i < n; ++i) {
        cout << setw(4) << nodes[i];
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        cout << setw(4) << nodes[i];
        for (int j = 0; j < n; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> n;

    vector<string> nodes(n);
    vector<vector<int>> distanceMatrix(n, vector<int>(n, 0));

    cout << "Silakan masukkan nama simpul:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> nodes[i];
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                cout << nodes[i] << "--> " << nodes[j] << " = ";
                cin >> distanceMatrix[i][j];
            } else {
                distanceMatrix[i][j] = 0; // jarak ke diri sendiri adalah 0
            }
        }
    }

    displayMatrix(distanceMatrix, nodes);

    return 0;
}