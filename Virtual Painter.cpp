#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;
vector<vector<int>> mycolors{

	{124,48,117,143,170,255},{68,72,156,102,126,255} };   //purple //green 


	vector<Scalar>myColorValues{  {255,0,255},{0,255,0}}; //purple // green







void findcolor(Mat img) {
	Mat imgHSV;


	cvtColor(img, imgHSV, COLOR_BGR2HSV);
	for (int i = 0; i < mycolors.size(); i++) {



		Scalar lower(mycolors[i][0], mycolors[i][1],mycolors[i][2]);
		Scalar upper(mycolors[i][3], mycolors[i][4],mycolors[i][5]);
		Mat mask;
		inRange(imgHSV, lower, upper, mask);
		imshow(to_string(i), mask);
	}

}

// webcam

void  main() {


	// zero for laptop  

	VideoCapture cap(0);
	Mat img;

	while (true) {
		cap.read(img);
		findcolor(img);


		imshow("Image", img);
		waitKey(1);
	}




}