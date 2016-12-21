#include<opencv2/opencv.hpp>
#include "Controller.h"

int main()
{
	std::string filename="star.jpg";
	ColorDetectController colordetect;
	colordetect.setInputImage(filename);
	colordetect.process();
    cv::imshow("Input Image",colordetect.getLastResult());
	cv::waitKey(0);
	return 0;
}