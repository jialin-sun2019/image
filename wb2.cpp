#include <iostream>
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	static const unsigned ratio = 5;
	static unsigned key = 0, counter = 0, hist[766] = { 0 };
	static float r_k = 0, g_k = 0, b_k = 0;
	static unsigned long long sum_r = 0, sum_g = 0, sum_b = 0, num = 0;
	cv::Mat img_src = cv::imread("./data/10.jpg");
	cv::Mat img_out = cv::Mat(img_src.rows, img_src.cols, img_src.type());
	cv::Mat sum = cv::Mat::ones(img_src.rows, img_src.cols, CV_16UC1);
	std::vector<cv::Mat> imageRGB;
	cv::split(img_src, imageRGB);
	memset(hist, 0, 766 * sizeof(unsigned));
	for (int i = 0; i < sum.rows; i++) {
		for (int j = 0; j < sum.cols; j++) {
			sum.at<cv::uint16_t>(i, j) = img_src.at<cv::Vec3b>(i, j)[2] + img_src.at<cv::Vec3b>(i, j)[1] \
			                           + img_src.at<cv::Vec3b>(i, j)[0];
		}
	}
	for (int i = 0; i < sum.rows; i++) {
		for (int j = 0; j < sum.cols; j++) {
			hist[sum.at<cv::uint16_t>(i, j)]++;
		}
	}
	for (int i = 765; i >= 0; i--) {
		num += hist[i];
		if (num > img_src.rows * img_src.cols * ratio / 100) {
			key = i;
			break;
		}
	}
	for (int i = 0; i < sum.rows; i++) {
		for (int j = 0; j < sum.cols; j++) {
			if (sum.at<cv::uint16_t>(i, j) >= key) {
				sum_r += img_src.at<cv::Vec3b>(i, j)[2];
				sum_g += img_src.at<cv::Vec3b>(i, j)[1];
				sum_b += img_src.at<cv::Vec3b>(i, j)[0];
				counter++;
			}
		}
	}
	r_k = 255.0F / sum_r * (float)counter;
	g_k = 255.0F / sum_g * (float)counter;
	b_k = 255.0F / sum_b * (float)counter;
	imageRGB[2] *= r_k;
	imageRGB[1] *= g_k;
	imageRGB[0] *= b_k;
	cv::merge(imageRGB, img_out);

	cv::namedWindow("source");
	cv::namedWindow("result");
	cv::imshow("source", img_src);
	cv::imshow("result", img_out);
	cv::waitKey(0);
	return 0;
}
