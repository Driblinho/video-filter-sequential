#ifndef PROJEKT_BLUR_H
#define PROJEKT_BLUR_H


#include <opencv2/core/mat.hpp>

class Blur {
    int* filterMask;
public:
    void apply(cv::Mat frame);
};


#endif //PROJEKT_BLUR_H
