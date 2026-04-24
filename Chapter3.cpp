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


	//cout << img.size()<<endl; // find the image size 

	resize (img,imResize,Size(640,480)); // rezise func

	imshow("Images", img);
	imshow("REsize ", imResize);

	waitKey(0);
}