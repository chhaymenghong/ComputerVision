#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char)
{
	VideoCapture camera(0);
	if (!camera.isOpened()) {
		return -1;
	}
	Mat grayImage;
	Mat frame;
	namedWindow("canny", WINDOW_NORMAL);
	for (;;) {
		camera >> frame;
		cvtColor(frame, grayImage, CV_BGR2GRAY);
		GaussianBlur(grayImage, grayImage, Size(5, 5), 1.7, 1.7);
		Canny(grayImage, grayImage, 0, 30);
		imshow("canny", grayImage);
		if (waitKey(30) >= 0) {
			break;
		}
	}
	return 0;
}