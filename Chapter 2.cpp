#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


void  main() {



	 

	string path = "Resources/test.png";

	// converting in gray scale
	
	


	Mat img = imread(path);
	Mat imgGray;
	Mat imgBlur;
	Mat imgCanny;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);



	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCanny, 50, 150);  // egde detector 


	imshow("Image", img);

	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);  // blurrr effects
	imshow("Image Canny", imgCanny);  // edge detection

	waitKey(0);	// to hold the image until we press a key





 }



