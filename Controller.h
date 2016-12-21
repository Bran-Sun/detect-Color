#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "ColorDetector.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cstring>

class ColorDetectController 
{
private:
	ColorDetector *cdetect;
	cv::Mat image;
	cv::Mat result;
public:
	ColorDetectController()
	{
		cdetect=new ColorDetector();
	}
	void setColorDistanceThreshold(int distance);
	int getColorDistanceThreshold() const;
	void setTargetColor(unsigned char &red,unsigned char &green, unsigned char &blue);
	void getTargetColor(unsigned char &red,unsigned char &green, unsigned char &blue) const;
	bool setInputImage(std::string filename);
	const cv::Mat getInputImage() const;
	void process();
	cv::Mat getLastResult() const;
	~ColorDetectController();
};


#endif