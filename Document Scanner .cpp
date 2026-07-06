#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat imgOrginal, imgGray, imgCanny, imgThre;
Mat  imgErode, imgDil, imgBlur;
vector<Point> intialPoints;


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

vector <Point> getContours(Mat image) {
	
		vector<vector<Point>> contours;
		vector<Vec4i> hierarchy;
	
		findContours(imgDil, image, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
		//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
	
		vector<vector<Point>> conPoly(contours.size());
		vector<Rect> boundRect(contours.size());


		vector<Point> biggest;
		int maxArea;
	
		for (int i = 0; i < contours.size(); i++)
		{
			int area = contourArea(contours[i]);
			cout << area << endl;
			string objectType;
	
			if (area > 1000)                // area  filtration
			{
				float peri = arcLength(contours[i], true);
				approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

				if (area > maxArea && conPoly[i].size()==4) {
					biggest = { conPoly[i][0],conPoly[i][1],conPoly[i][2],conPoly[i][3] };

					maxArea = area;

				}


				
	
				
				drawContours(imgOrginal, conPoly, i, Scalar(255, 0, 255), 2);
				rectangle(imgOrginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
				
			}
		}
		return biggest;
	}
	//

void 




void  main() {



	// images processing importing

	string path = "Resources/paper.jpg";

	Mat imgorginal = imread(path);

	resize(imgOrginal, imgOrginal, Size(), 0.5, 0.5);


	imgThre = preProcessing(imgorginal);
	

	 intialPoints =getContours(imgThre);



	


 



	imshow("Image", imgorginal);
	imshow("Image dialatioon", imgThre);
	waitKey(0);	// to hold the image until we press a key





}
