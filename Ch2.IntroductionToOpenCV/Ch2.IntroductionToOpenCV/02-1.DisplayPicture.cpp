#include <iostream>
#include <opencv2\highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

	Mat img = imread("cat.jpg");

	if (img.empty()) return -1;

	namedWindow("Cat", CV_WINDOW_AUTOSIZE);

	imshow("Cat", img);

	waitKey(0);

	destroyWindow("Cat");

	return 0;

}