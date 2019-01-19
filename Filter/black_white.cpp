#include "black_white.h"

void BlackWhite::apply(cv::Mat frame) {

    for (int i = 0; i < frame.rows; ++i) {
        for (int j = 0; j < frame.cols; ++j) {
            unsigned char * p = frame.ptr(i, j); // Y first, X after
            auto YUV = static_cast<unsigned char>(0.299 * p[2] + 0.587 * p[1] + 0.114 * p[0]);
            p[2]= YUV; // R
            p[1] = YUV;  // G
            p[0] = YUV; //B

        }
    }

}
