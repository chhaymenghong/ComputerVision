#include "opencv2/opencv.hpp"

using namespace cv;



void trackBar(int, void*){};

int main(int, char)
{
	Mat image;
	Mat grayImage;
	Mat hsvImage;
	Mat thresholdImage;
	VideoCapture capture;
	capture.open(0);

	char TrackbarName[10];
	namedWindow("select color", 0);
	int hMin = 0;
	int hMax = 256;

	int sMin = 0;
	int sMax = 256;

	int vMin = 0;
	int vMax = 256;
	//sprintf(TrackbarName, "min H", hMin);
	//sprintf(TrackbarName, "max H", hMax);

	createTrackbar("Min H", "select color", &hMin, hMax, trackBar);
	createTrackbar("Max H", "select color", &hMax, hMax, trackBar);

	createTrackbar("Min S", "select color", &sMin, sMax, trackBar);
	createTrackbar("Max S", "select color", &sMax, sMax, trackBar);

	createTrackbar("Min V", "select color", &vMin, vMax, trackBar);
	createTrackbar("Min V", "select color", &vMax, vMax, trackBar);


	if (!capture.isOpened()) {
		return -1;
	}
	while (1) {
		capture >> image;
		imshow("Tracking", image);
		if (waitKey(10) >= 0) {
			return 0;
		}
		//cvtColor(image, grayImage, CV_RGB2GRAY);
		//imshow("Gray Image", grayImage);

		cvtColor(image, hsvImage, COLOR_BGR2HSV);
		//imshow("HSV image", hsvImage);

		inRange(hsvImage, Scalar(hMin, sMin, vMin), Scalar(hMax, sMax, vMax), thresholdImage);
		imshow("ThresholdImage", thresholdImage);
		
	}
	return 0;
}