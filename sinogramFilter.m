getImageSizeX = 400;
getImageSizeY = 350;
K = zeros(getImageSizeX, getImageSizeY);
ImageFoVx = 450;
ImageFoVy = 400;
sinogram = importdata('Sinogram_InVivo.txt');
getLengthOfDetectorArray = 750/2;
d_x = ImageFoVx/getImageSizeX;
d_y = ImageFoVy/getImageSizeY;
SS = size(sinogram);
getNumberOfDetectorElements = SS(1);
delta_D = getLengthOfDetectorArray/getNumberOfDetectorElements
nX = getImageSizeX;
nY = getImageSizeY;
FOVx = ImageFoVx;
FOVy = ImageFoVy;
c = nX * nY;

for x = 1:nX
    for y = 1:nY
        rx = (-FOVx / 2) + (x - 1) * d_x;
        ry = (FOVy / 2) - (y - 1) * d_y;
        sum = 0;
        
        B_k = sqrt(rx^2+ry^2);
        K(x,y)= B_k;
        c = c - 1
    end
end
W_Bild=abs(ifft2(ifftshift(image.*K)));