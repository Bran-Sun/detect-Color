#include "ColorDetector.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>

void ColorDetector::setColorDistanceThreshold(int distance)
{
	if (distance<0)
		 distance=0;
	maxDist=distance;
}

int ColorDetector::getColorDistanceThreshold() const
{
	return maxDist;
}

void ColorDetector::setTargetColor(uchar blue,uchar green, uchar red)
{
	target=cv::Vec3b(blue,green,red);
}

void ColorDetector::setTargetColor(cv::Vec3b color)
{
	target=color;
}

cv::Vec3b ColorDetector::getTargetColor() const
{
	return target;
}

cv::Mat ColorDetector::process(const cv::Mat &image)
{
	cv::Mat output;
	cv::absdiff(image,cv::Scalar(target),output);
    std::vector<cv::Mat> images;
	cv::split(output,images);
	output=images[0]+images[1]+images[2];
	cv::threshold(output,output,maxDist,255,cv::THRESH_BINARY_INV);

	return output;
}

cv::Mat ColorDetector::operator()(const cv::Mat &image)
{
	return process(image);
}