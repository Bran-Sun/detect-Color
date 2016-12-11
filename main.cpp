#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include "ColorDetector.h"
#include "Controller.h"

int main()
{
	std::string filename="star.jpg";
	ColorDetectController colordetect;
	colordetect.setInputImage(filename);
	colordetect.process();
    cv:;imshow("Iput Image",colordetect.getLastResult());
	cv::waitKey(0);
	return 0;
}