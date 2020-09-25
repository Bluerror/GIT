#include <opencv2/opencv.hpp>
using namespace cv;
int main()
{

	cv::Mat scrM = imread("C:\\Users\\Lenovo\\Pictures\\±ÚÖ½\\1.JPG");
	cv::Mat deepMat;
	cv::Mat shallowMat;
	shallowMat= scrM;
	scrM.copyTo (deepMat);
	//imshow("scr3", scrM);
	//imshow("scr", deepMat);
	//imshow("scr1", shallowMat);
	int height = scrM.rows;
	int width = scrM.cols;
	for (int j=0;j< height; j++)
	{
		for (int i=0;i < width; i++)
		{
			uchar average = (scrM.at<Vec3b>(j, i)[0] + scrM.at<Vec3b>(j, i)[1] + scrM.at<Vec3b>(j, i)[2]) / 3;
			scrM.at<Vec3b>(j, i)[0] = average;
			scrM.at<Vec3b>(j, i)[1] = average;
			scrM.at<Vec3b>(j, i)[2] = average;
		}
	}
	imshow("scr2", deepMat);
	imshow("scr3", shallowMat);
	waitKey(0);
	return 0;
}