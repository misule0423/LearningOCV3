#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char* argv[]) {

	cv::namedWindow("original", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Log_Polar", cv::WINDOW_AUTOSIZE);

	// ( Note: could capture from a camera by giving a camera id as an int.)
	//
	cv::VideoCapture capture("cat.avi");

	double fps = capture.get(cv::CAP_PROP_FPS);

	//std::cout << fps << std::endl;

	cv::Size size(
		(int)capture.get(cv::CAP_PROP_FRAME_WIDTH),		(int)capture.get(cv::CAP_PROP_FRAME_HEIGHT)
	);
	
	cv::VideoWriter writer;

	writer.open("C:\Users\MCL\Source\Repos\LearningOCV3\Ch2.IntroductionToOpenCV\Ch2.IntroductionToOpenCV", CV_FOURCC('M', 'J', 'P', 'G'), fps, size);

	cv::Mat logpolar_frame, bgr_frame;

	for (;;) {

		capture >> bgr_frame;

		if (bgr_frame.empty()) break; // end if done

		cv::imshow("original", bgr_frame);

		cv::logPolar(

			bgr_frame, // Input color frame
			logpolar_frame, // Output log-polar frame
			cv::Point2f( // Centerpoint for log-polar transformation
			bgr_frame.cols / 2, // x
			bgr_frame.rows / 2 // y
			),
			40, // Magnitude (scale parameter)
			cv::WARP_FILL_OUTLIERS // Fill outliers with 'zero'
		);

		cv::imshow("Log_Polar", logpolar_frame);

		writer << logpolar_frame;

		char c = cv::waitKey(10);

		if (c == 27) break; // allow the user to break out

	}

	capture.release();

}