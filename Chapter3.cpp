#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


void  main() {

	string path = "Resources/test.png";
	Mat img = imread(path);

	resize (img, );


	imshow("Images", img);

	waitKey(0);
}