#ifndef SINOGRAM_H_
#define SINOGRAM_H_

#include "matrix.h"

using namespace std;

class Sinogram {

    matrix m_RawData;
    double m_pMax; // Length of detector array : 2*m_pMax [mm];

    public:

	// Constructor and desctructor
	Sinogram() {
		m_pMax = 0;
        matrix m_RawData;
	};
    virtual~Sinogram() {
		cout << "destructing";
	};

    // Assginment operator: sino(p,phi) gives access to the element belonging to lateral
    // position "p" in [mm] and rotation angle "phi" in degrees. Returns -1000 for (phi,p)
    // combinations outside the valid range
    double sinogramElem(int p, int phi) {
		return m_RawData.elem(p, phi);
	};

    // Load the sinogram specified by "fName".
    bool loadSinogramFromTextFile(string fName, int mrow, int mcol) {
        return m_RawData.loadFromFile(fName, mrow, mcol);
    };

    // Return the total number of detector elements
    int getNumberOfDetectorElements(void) {
        return m_RawData.getNRows();
    };

    // Return the total number of different angular positions
    int getNumberOfAngularPositions(void) {
        return m_RawData.getNCols();
    };

    // Return the total total length of the detector array in [mm]
    double getLengthOfDetectorArray(void) {
        return 2 * m_pMax;
    };

    // Return the lateral size of a single detector element in [mm]
    double getSizeOfSingleDetectorElement(void) {
		return getLengthOfDetectorArray()/getNumberOfDetectorElements();
	};

    // Set the total total length of the detector array to "pMax" (im [mm])
    void setLengthOfDetectorArray(double pMax) {
        m_pMax = pMax / 2;
    };

};

#endif /* SINOGRAM_H_ */