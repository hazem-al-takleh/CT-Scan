#include "matrix.h"
#include "Sinogram.h"

int main(){

    matrix A;
    int mrow = 3;
    int mcol = 3;
    A.reset(mrow, mcol);
    //A.setAll();
    A.print();
    cout << endl;
    for (int row = 1; row <= mrow; row++) {
        for (int col = 1; col <= mcol; col++) {
            cout << row << "," << col << "=" << A.elem(row, col) << "\t";
            double val = row*col;
            A.set(row, col, val);
        }
    }
    cout << endl;
    A.print();

    Sinogram B;
    B.loadSinogramFromTextFile("Sinogram_InVivo.txt", 557, 180);
    for (int row = 1; row <= 557; row++) {
        for (int col = 1; col <= 180; col++) {
            cout << B.sinogramElem(row, col) << "\t";
        }
        cout << endl;
    }
    return 0;
}
