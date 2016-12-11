#ifndef COLORDETECTOR_H
#define COLORDETECTOR_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

class ColorDetector
{
private:
	int maxDist;
	cv::Vec3b target;

	cv::Mat result;
public:
	ColorDetector():maxDist(100),target(0,0,0) {}
    ColorDetector(uchar blue, uchar green, uchar red,int maxDist=100):maxDist(maxDist)
	{
		setTargetColor(blue,green,red);
	}
	void setColorDistanceThreshold(int distance);
	int getColorDistanceThreshold() const;
	void setTargetColor(uchar blue, uchar green, uchar red);
	void setTargetColor(cv::Vec3b color);
	cv::Vec3b getTargetColor() const;
	cv::Mat process(const cv::Mat &image);
	cv::Mat operator()(const cv::Mat &image);
};


#endif