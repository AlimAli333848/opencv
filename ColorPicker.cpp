#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>

#include<iostream>
using namespace std;
using namespace cv;



Mat imgHSV, mask, imgColor;
int hmin = 0, smin = 110, vmin = 153;
int hmax = 19, smax = 240, vmax = 255;
VideoCapture cap(0);
Mat img;
int main() {


	namedWindow("Trackerbars", (640, 200));   //window creatted 
	createTrackbar("Hue Min", "Trackerbars", &hmin, 179);
	createTrackbar("Hue Max", "Trackerbars", &hmax, 179);
	createTrackbar("Sat Min", "Trackbars", &smin, 255);
	createTrackbar("Sat Max", "Trackerbars", &max, 255);
	createTrackbar("Val Min", "trackbars", &vmin, 255);
	createTrackbar("Val Max", "Trackbars", &vmax, 255);
	while (true) {
		cap.read(img);
		cvtColor(img, imgHSV, COLOR_BGR2HSV);
	Scalar lower (hmin, smin, vmin);
	Scalar  upper(hmax, smax, vmax);


	inRange(imgHSV, lower, upper, mask);


	cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << endl;



	imshow("Image", img);
	imshow("mask", mask);


	waitKey(1);
	}



}
