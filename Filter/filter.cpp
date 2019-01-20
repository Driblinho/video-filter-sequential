#include <iostream>
#include "filter.h"

void Filter::apply(cv::Mat frame) {

    for (int i = 0; i < frame.rows; ++i) {
        for (int j = 0; j < frame.cols; ++j) {


            unsigned char* centerPxl = frame.ptr(i, j); // Y first, X after

            int sumR=0;
            int sumG=0;
            int sumB=0;

            if(!filterMask) {
                filterMask = new int[25]{
                        1,1,2,1,1,
                        1,2,4,2,1,
                        2,4,8,4,2,
                        1,2,4,2,1,
                        1,1,2,1,1
                };
                filterMaskSize = 5;
            }



            int margin = ((filterMaskSize-1)/2);
            int fidx=0;
            for (int k = i - margin; k <= i + margin; ++k) {
                for (int l = j-margin; l <= j + margin; ++l,++fidx) {

                    unsigned char* currentPxl = frame.ptr(k, l); // Y first, X after

                    if(k<0 || l<0 || k>frame.rows || l>frame.cols)
                        continue;
                    sumR+= currentPxl[2]*filterMask[fidx]; // R
                    sumG+= currentPxl[1]*filterMask[fidx];  // G
                    sumB+= currentPxl[0]*filterMask[fidx]; //B

                }
            }

            sumR/=filterMaskSize*filterMaskSize;
            sumG/=filterMaskSize*filterMaskSize;
            sumB/=filterMaskSize*filterMaskSize;

            centerPxl[2] = static_cast<unsigned char>((sumR > 255) ? 255 : sumR);
            centerPxl[1] = static_cast<unsigned char>((sumG > 255) ? 255 : sumG);
            centerPxl[0] = static_cast<unsigned char>((sumB > 255) ? 255 : sumB);
        }
    }

}

void Filter::setMask(int *mask, int filterMaskSize) {
    this->filterMask = mask;
    this->filterMaskSize = filterMaskSize;
}
