#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;



//void  main() {



	// images processing importing 
	//string path = "Resources/test.png";
	//Mat img = imread(path);
	//imshow("Image", img);
	//waitKey(0);	// to hold the image until we press a key




	
//}


void  main() {



	// video processing importing 
	string path = "Resources/test_video.mp4";
	VideoCapture cap(path);	
	Mat img;

	while (true) {
		cap.read(img);
	
	
	imshow("Image", img);
	waitKey(20);	
}




}