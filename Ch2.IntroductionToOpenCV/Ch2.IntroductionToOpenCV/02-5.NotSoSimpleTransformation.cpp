#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {

	cv::Mat img_rgb, img_pyrDown, img_gry, img_cny;

	cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("pyrDown", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("cat.jpg");

	cv::imshow("original", img_rgb);
	cv::pyrDown(img_rgb, img_pyrDown);
	cv::imshow("pyrDown", img_pyrDown);
	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::imshow("Gray", img_gry);
	cv::Canny(img_gry, img_cny, 10, 100, 3, true);
	cv::imshow("Canny", img_cny);

	cv::waitKey(0);

	return 0;
}
