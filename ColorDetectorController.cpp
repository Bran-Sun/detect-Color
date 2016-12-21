
#include "ColorDetector.h"
#include "Controller.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
void  ColorDetectController::setColorDistanceThreshold(int distance)
{
	cdetect->setColorDistanceThreshold(distance);
}

int ColorDetectController::getColorDistanceThreshold() const
{
	return cdetect->getColorDistanceThreshold();
}

void ColorDetectController::setTargetColor(unsigned char &red,unsigned char &green, unsigned char &blue)
{
	cdetect->setTargetColor(blue,green,red);
}

void ColorDetectController::getTargetColor(unsigned char &red,unsigned char &green, unsigned char &blue) const
{
	cv::Vec3b color=cdetect->getTargetColor();
	red=color[2];
	green=color[1];
	blue=color[0];
}

bool ColorDetectController::setInputImage(std::string filename)
{
	image=cv::imread(filename);
	return !image.empty();
}

const cv::Mat ColorDetectController::getInputImage() const
{
	return image;
}

void ColorDetectController::process()
{
	result=cdetect->process(image);
}

cv::Mat ColorDetectController::getLastResult() const
{
	return result;
}

ColorDetectController::~ColorDetectController()
{
	delete cdetect;
}