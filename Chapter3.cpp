#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;


void  main() {

	string path = "Resources/test.png";
	Mat img = imread(path);
	Mat imResize;
	Mat imgCrop;


	//cout << img.size()<<endl; // find the image size 

	resize (img,imResize,Size(640,480)); // rezise func

	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);

	imshow("Images", img);
	imshow("REsize ", imResize);
	imshow("crop images ", imgCrop);

	waitKey(0);
}