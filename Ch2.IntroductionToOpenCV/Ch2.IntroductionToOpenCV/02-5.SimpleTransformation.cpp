#include <opencv2/opencv.hpp>

using namespace cv;

void simpleTransform(const Mat & image) {

	// Create some windows to show the input
	// and output images in.	//
	namedWindow("cat-in", WINDOW_AUTOSIZE);
	namedWindow("cat-out", WINDOW_AUTOSIZE);
	// Create a window to show our input image
	//
	imshow("cat-in", image);
	// Create an image to hold the smoothed output
	//
	Mat out;
	// Do the smoothing
	// ( Note: Could use GaussianBlur(), blur(), medianBlur() or bilateralFilter(). )
	//
	GaussianBlur(image, out, Size(5, 5), 3, 3);
	GaussianBlur(out, out, Size(5, 5), 3, 3);
	// Show the smoothed image in the output window
	//
	imshow("cat-out", out);
	// Wait for the user to hit a key, windows will self destruct
	//
	cv::waitKey(0);
}int main(int argc, char** argv){

	Mat img = imread("cat.jpg");

	if (img.empty()) return -1;

	simpleTransform(img);

	return 0;

}