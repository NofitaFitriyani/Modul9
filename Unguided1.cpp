#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int Nofita_2311102001;  // Variabel dengan NIM

int main() {
    int jumlahSimpul;
    cout << "Silakan masukkan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> simpul(jumlahSimpul);
    vector<vector<int>> busur(jumlahSimpul, vector<int>(jumlahSimpul, 0));

    // Memasukkan nama-nama simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Simpul " << i + 1 << " : ";
        cin >> simpul[i];
    }

    // Memasukkan bobot antar simpul
    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << simpul[i] << "--> " << simpul[j] << " = ";
            cin >> busur[i][j];
        }
    }

    // Menampilkan matriks ketetanggaan
    cout << endl;
    cout << setw(10) << " ";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << simpul[i];
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << setw(10) << simpul[i];
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << setw(10) << busur[i][j];
        }
        cout << endl;
    }

    return 0;
}
