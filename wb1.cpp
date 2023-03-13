#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main() // 灰度世界法白平衡
{
	cv::Mat img_src = cv::imread("data/49.jpg");
	cv::Mat img_out = cv::Mat(img_src.rows, img_src.cols, img_src.type());
	std::vector<cv::Mat> imageRGB;
	cv::split(img_src, imageRGB);
	double R, G, B;
	R = cv::mean(imageRGB[2])[0];
	G = cv::mean(imageRGB[1])[0];
	B = cv::mean(imageRGB[0])[0];
	double KR, KG, KB;
	KR = (R + G + B) / (3 * R);
	KG = (R + G + B) / (3 * G);
	KB = (R + G + B) / (3 * B);
	imageRGB[2] = imageRGB[2] * KR;
	imageRGB[1] = imageRGB[1] * KG;
	imageRGB[0] = imageRGB[0] * KB;
	cv::merge(imageRGB, img_out);
	cv::namedWindow("source");
	cv::namedWindow("result");
	cv::imshow("source", img_src);
	cv::imshow("result", img_out);
	cv::waitKey(0);
	return 0;
}
