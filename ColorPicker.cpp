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
	createTrackbar

}
