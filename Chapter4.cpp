#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;



// shapes and images 


void  main() {


	//  Blank images 
	Mat img(512,512,CV_8UC3, Scalar(255,255,255)); //255 blue ,0, 267 pink

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),10);// scalar for colour defined // 512  half 256 // 10 for thickness
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), 3); // 3 for thickness
	

	imshow("Images", img);
	
	


	waitKey(0);
}