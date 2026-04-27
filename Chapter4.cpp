//#include<opencv2/imgcodecs.hpp>
//#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;



// shapes and images 


void  main() {


	//  Blank images 
	Mat img(512,512,CV_8UC3, Scalar(255,255,255)); //255 white ,0, 267 pink

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),10);// scalar for colour defined // 512  half 256 // 10 for thickness
	circle(img, Point(256, 256), 155, Scalar(0, 69, 255), FILLED);

	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED); // 3 for thickness
	line(img, Point(130, 296), Point(382, 296), Scalar(255, 255, 255),3);



	putText(img, " computer visioon ",Point(137,262),FONT_HERSHEY_COMPLEX,1,Scalar(0,69,255),2);
	

	imshow("Images", img);
	
	


	waitKey(0);
}