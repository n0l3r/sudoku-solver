#include <bits/stdc++.h>
using namespace std;

#define SIZE 9
#define matrix vector<vector<int>>

bool isSafe(matrix board, int row, int col, int val) {
    for(int j = 0; j < board.size(); j++) {
        if(board[row][j] == val) return false;   // cek baris
    }
    for(int j = 0; j < board.size(); j++) {
        if(board[j][col] == val) return false;   // cek kolom
    }

    int square = sqrt(board.size());             // cek kotak yang sedang dikerjakan
    row -= (row % square);
    col -= (col % square);

    for(int i = row; i < row + square; i++) {
        for(int j = col; j < col + square; j++) {
            if(board[i][j] == val) return false;
        }
    }

    return true;
}

bool solver(matrix &board) {
    int row, col;
    bool isZero = 0;

    for(row = 0; row < board.size(); row++) {
        for(col = 0; col < board.size(); col++) {
            if(board[row][col] == 0) {
                isZero = true;
                break;
            }
        }
        if(isZero) break;
    }    

    if(!isZero) return true;

    for(int i = 1; i <= board.size(); i++) {
        if(isSafe(board, row, col, i)) {
            board[row][col] = i;
            if(solver(board) == true){
                return true;
            } else{
                board[row][col] = 0;
            }
        }
    }

    return false;
}

void printBoard(matrix &board) {
    for (int i = 0; i < SIZE; i++) {
        if(i % 3 == 0) cout << "-------------------------" << endl;
        for (int j = 0; j < SIZE; j++) {
            if(j % 3 == 0) cout << "| ";
            cout << board[i][j] << " ";
        }
        cout << "|" << endl;
    }
    cout << "-------------------------" << endl;
}

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

    matrix board(SIZE, vector<int>(SIZE, 0)); // board 9x9 dengan isi 0
    string _inFileName, _outFileName;

    cout << "Masukkan nama file input : ";
    cin >> _inFileName;

    cout << "Masukkan nama file output : ";
    cin >> _outFileName;

    freopen(_inFileName.c_str(), "r", stdin); // membuka file input
    // freopen(_outFileName.c_str(), "w", stdout); // membuka file output

    // memasukkan isi board dari file input
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cin >> board[i][j];
        }
    }

    solver(board);

    // mencetak isi board ke file output
    printBoard(board);
    fclose(stdin); // menutup file input
    // fclose(stdout); // menutup file output
    return 0;
    
} 