#include <iostream>

#include <math.h>

#include "matrix.h"

#include "Image.h"

#include "Sinogram.h"

#define PI 3.14159265359

using namespace std;

int main() {

	Image Image;
	int ImageSizeX = 350;
	int ImageSizeY = 400;
	Image.setFoVx(450);
	Image.setFoVy(400);
	Image.resetImageSize(ImageSizeX, ImageSizeY);

	Sinogram sinogram1;
	sinogram1.loadSinogramFromTextFile("Sinogram_InVivo.txt", 557, 180);
	sinogram1.setLengthOfDetectorArray(750);

	double d_x = Image.getVoxelSizeX();
	double d_y = Image.getVoxelSizeY();
	double delta_D = sinogram1.getSizeOfSingleDetectorElement();
	double nX = Image.getImageSizeX();
	double nY = Image.getImageSizeY();
	double FOVx = Image.getFoVx();
	double FOVy = Image.getFoVy();

	int c = nX * nY * 180;
	for (int x = 1; x <= nX; x++) {
		for (int y = 1; y <= nY; y++) {

			double rx = (-FOVx / 2) + (x - 1) * d_x;
			double ry = (FOVy / 2) - (y - 1) * d_y;
			double sum = 0;

			for (int phi = 0; phi < 180; phi++) {
				double phi_Grad = (phi * PI) / 180;
				int p = rx * cos(phi_Grad) + ry * sin(phi_Grad);
				int P_z = round(p / 1.35);
				int position = 279 + P_z;
				sum = sum + sinogram1.sinogramElem(position, phi);
				c--;
				cout << "ops left: " << c << endl;
			}
			Image.set(x, y, sum);
		}
	}
	Image.storeImageInTextFile("Image1.txt");

	return 0;
}
