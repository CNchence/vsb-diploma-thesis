#include "utils.h"
#include <opencv/cv.h>
#include <opencv2/imgproc.hpp>

std::string utils::matType2Str(int type) {
    std::string r;

    uchar depth = type & CV_MAT_DEPTH_MASK;
    uchar chans = 1 + (type >> CV_CN_SHIFT);

    switch (depth) {
        case CV_8U:  r = "8U"; break;
        case CV_8S:  r = "8S"; break;
        case CV_16U: r = "16U"; break;
        case CV_16S: r = "16S"; break;
        case CV_32S: r = "32S"; break;
        case CV_32F: r = "32F"; break;
        case CV_64F: r = "64F"; break;
        default:     r = "User"; break;
    }

    r += "C";
    r += (chans + '0');

    return r;
}

// http://answers.opencv.org/question/27695/puttext-with-black-background/
void ::utils::setLabel(cv::Mat &im, const std::string label, const cv::Point &origin, int padding, int fontFace, double scale
        , cv::Scalar fColor, cv::Scalar bColor, int thickness) {
    cv::Size text = cv::getTextSize(label, fontFace, scale, thickness, 0);
    cv::rectangle(im, origin + cv::Point(-padding - 1, padding + 2),
                  origin + cv::Point(text.width + padding, -text.height - padding - 2), bColor, CV_FILLED);
    cv::putText(im, label, origin, fontFace, scale, fColor, thickness, CV_AA);
}
