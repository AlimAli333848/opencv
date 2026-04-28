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
	imshow("Image", img);
	waitKey(0);	// to hold the image until we press a key





}
