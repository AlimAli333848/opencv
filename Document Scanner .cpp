#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat imgOrginal, imgGray, imgCanny;

void  main() {



	// images processing importing

	string path = "Resources/paper.jpg";
	Mat img = imread(path);


	imshow("Image", img);
	waitKey(0);	// to hold the image until we press a key





}
