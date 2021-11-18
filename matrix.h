#ifndef MATRIX_H_
#define MATRIX_H_

#include <vector>

#include <string>

#include <fstream>

#include <iostream>

using namespace std;

class matrix {

    vector < double > m_Mat;
    int m_nRow;
	int m_nCol;

    public:

	// Constructor and desctructor
	matrix() {
		m_nCol = 0;
		m_nRow = 0;
	};
	virtual~matrix() {
		cout << "destructing";
	};

	// Assginment operator: m(i,j) gives access to the element in the i-th row and j-th column
	double elem(int row, int col) {
		return m_Mat[(row - 1) * m_nCol + col - 1];
	}

	// Load a matrix from a space-separated text (ASCII) file with filename "fName"
	bool loadFromFile(string fName, int mrow, int mcol) {
		ifstream myfile;
		myfile.open(fName.c_str());
		if (myfile.is_open()) {
			reset(mrow, mcol);
			for (int row = 1; row <= m_nRow; row++) {
				for (int col = 1; col <= m_nCol; col++) {
					double temp;
					myfile >> temp;
					set(row, col, temp);
				}
			}
			myfile.close();
			return 1;
		}
		else {
			cout << "Error reading the file!" << endl;
			return 0;
		}
	};

	// Store the current contents of the matrix in a space-separated text (ASCII) file with filename "fName"
	bool storeMatrixInTextFile(string fName) {
		ofstream myfile;
		myfile.open(fName.c_str());
		for (int row = 1; row <= m_nRow; row++) {
			for (int col = 1; col <= m_nCol; col++) {
				double temp = m_Mat[(row - 1) * m_nCol + col - 1];
                myfile << temp << " ";
			}
			myfile << endl;
		}
        myfile.close();
        return 1;
	};

	// Print current matrix content on the screen
	void print() {
		for (int row = 1; row <= m_nRow; row++) {
			for (int col = 1; col <= m_nCol; col++) {
				cout << m_Mat[(row - 1) * m_nCol + col - 1] << " ";
			}
			cout << endl;
		}
	};

	// Return the number of matrix columns
	int getNCols(void) {
		return m_nCol;
	};

	// Return the number of matrix rows
	int getNRows(void) {
		return m_nRow;
	};

	// Resize matrix to nrow x ncol and set elements to zero
	void reset(int  nrow, int ncol) {
		m_nRow = nrow;
		m_nCol = ncol;
		for (int row = 1; row <= m_nRow; row++) {
			for (int col = 1; col <= m_nCol; col++) {
				set(row, col, 0);
			}
		}
	};

	// Set the matrix element at location ("row","col") to "value"
	void set(int row, int col, double value) {
		m_Mat.insert(m_Mat.begin() + (row - 1) * m_nCol + col - 1, value);
	};

	void setAll(){
        for (int row = 1; row <= m_nRow; row++) {
            for (int col = 1; col <= m_nCol; col++) {
                cout << "input Matrix(" << row << "," << col << ") : ";
				double temp;
                cin >> temp;
                set(row, col, temp);
            }
        }
    };

};

#endif /* MATRIX_H_ */
