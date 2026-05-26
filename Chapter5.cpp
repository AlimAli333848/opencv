#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


// wraping 
void  main() {



	 

	string path = "Resources/cards.jpg";
	Mat img = imread(path);

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457} };
	Point2f src[4] = { {0.0f,0.0f},{w,0.0f},{405,395},{674,457} };



	imshow("Image", img);
	waitKey(0);	// to hold the image until we press a key





}
