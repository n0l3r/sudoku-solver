#include <bits/stdc++.h>
using namespace std;

#define SIZE 9

int main() {

    /*
    Board 9 x 9 :
   -------------------------
   | 0 0 0 | 0 0 0 | 0 0 0 |
   | 0 0 0 | 0 0 0 | 0 0 0 |
   | 0 0 0 | 0 0 0 | 0 0 0 |
   -------------------------
   | 0 0 0 | 0 0 0 | 0 0 0 |
   | 0 0 0 | 0 0 0 | 0 0 0 |
   | 0 0 0 | 0 0 0 | 0 0 0 |
   -------------------------
   | 0 0 0 | 0 0 0 | 0 0 0 |
   | 0 0 0 | 0 0 0 | 0 0 0 |
   | 0 0 0 | 0 0 0 | 0 0 0 |
   -------------------------
    */

    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0)); // board 9x9 dengan isi 0
    string _inFileName, _outFileName;

    cout << "Masukkan nama file input : ";
    cin >> _inFileName;

    cout << "Masukkan nama file output : ";
    cin >> _outFileName;

    freopen(_inFileName.c_str(), "r", stdin); // membuka file input
    freopen(_outFileName.c_str(), "w", stdout); // membuka file output

    // memasukkan isi board dari file input
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    // mencetak isi board ke file output
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    fclose(stdin); // menutup file input
    fclose(stdout); // menutup file output
    return 0;
    
} 