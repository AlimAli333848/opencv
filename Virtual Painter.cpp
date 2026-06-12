#include<opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>
using namespace std;
using namespace cv;

Mat img;
vector<vector<int>>newPoints;          // y is centre // third is the colour 




vector<vector<int>> mycolors{

	{124,48,117,143,170,255},{68,72,156,102,126,255} };   //purple //green 


vector<Scalar>myColorValues{ {255,0,255},{0,255,0} }; //purple // green



   Point getContours(Mat imgDil) {

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
	//drawContours(img, contours, -1, Scalar(255, 0, 255), 2);

	vector<vector<Point>> conPoly(contours.size());
	vector<Rect> boundRect(contours.size());
	Point myPoint(0, 0);

	for (int i = 0; i < contours.size(); i++)
	{
		int area = contourArea(contours[i]);
		cout << area << endl;
		string objectType;

		if (area > 1000)
		{
			float peri = arcLength(contours[i], true);
			approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
			cout << conPoly[i].size() << endl;
			boundRect[i] = boundingRect(conPoly[i]);

			myPoint.x = boundRect[i].x + boundRect[i].width / 2;
			myPoint.y = boundRect[i].y;
			

			
			drawContours(img, conPoly, i, Scalar(255, 0, 255), 2);
			rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
			
		}
	}
	return myPoint;
}






   void findcolor(Mat img) {
	   Mat imgHSV;


	   cvtColor(img, imgHSV, COLOR_BGR2HSV);
	   for (int i = 0; i < mycolors.size(); i++) {



		   Scalar lower(mycolors[i][0], mycolors[i][1], mycolors[i][2]);         // zero is purple  one is the green 
		   Scalar upper(mycolors[i][3], mycolors[i][4], mycolors[i][5]);
		   Mat mask;
		   inRange(imgHSV, lower, upper, mask);
		   imshow(to_string(i), mask);
		   Point myPoint = getContours(mask);
		   if (myPoint.x != 0 && myPoint.y != 0) {
			   newPoints.push_back({ myPoint.x,myPoint.y,i });    //i is the colour 
		   }

	   }
   }

   void DrawsCanvas(vector<vector<int>>newPoints, vector<vector<int>> mycolors) {

	   for (int i = 0; i < newPoints.size(); i++) {
		   circle(img, Point(newPoints[i][0]), Point(newPoints[i][1]))

   }

// webcam

void  main() {


	// zero for laptop  

	VideoCapture cap(0);
	

	while (true) {
		cap.read(img);
		findcolor(img);


		imshow("Image", img);
		waitKey(1);
	}




}