//
// Created by ireq on 13.01.19.
//

#include "edge_detection.h"
#include "black_white.h"

void EdgeDetection::apply(cv::Mat frame) {

    auto filter_black_and_white = new BlackWhite();
    filter_black_and_white->apply(frame);

//    auto filterMask = new int[25]{
//            1,0,-1,
//            2,0,-2,
//            1,0,-1
//    };


    for (int i = 0; i < frame.rows; ++i) {
        for (int j = 0; j < frame.cols; ++j) {
            unsigned char * p = frame.ptr(i, j);

            auto threshold = 175;

            if(p[0]>threshold) p[0]=p[1]=p[2]=255;
            else p[0]=p[1]=p[2]=0;

            //printf("R: %d G: %d B: %d\n", p[2], p[1], p[0]);
        }
    }
}
