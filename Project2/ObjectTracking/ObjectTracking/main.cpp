#include "opencv2/opencv.hpp"
#include<opencv\highgui.h>

using namespace cv;

int main(int, char)
{
	Mat image;
	VideoCapture capture;
	capture.open(0);
	if (!capture.isOpened()) {
		return -1;
	}
	while (1) {
		capture >> image;
		imshow("Tracking", image);
		if (waitKey(10) >= 0) {
			return 0;
		}
		
	}
	return 0;
}