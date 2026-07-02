#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat imgOrginal, imgGray, imgCanny, imgThre;
Mat  imgErode, imgDil, imgBlur;


Mat preProcessing(Mat img)
{
	cvtColor(img, imgGray, COLOR_BGR2GRAY);



	GaussianBlur(imgGray, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCanny, 25, 75);  // egde detector
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

	dilate(imgCanny, imgDil, kernel);
	//erode(imgDil, imgErode, kernel);

	return imgDil;





}


void  main() {



	// images processing importing

	string path = "Resources/paper.jpg";

	Mat imgorginal = imread(path);

	resize(imgOrginal, imgOrginal, Size(), 0.5, 0.5);


	imgThre = preProcessing(imgorginal);
	


 



	imshow("Image", imgorginal);
	imshow("Image dialatioon", imgThre);
	waitKey(0);	// to hold the image until we press a key





}
