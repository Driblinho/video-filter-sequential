//
// Created by ireq on 13.01.19.
//

#ifndef PROJEKT_FILTER_H
#define PROJEKT_FILTER_H


#include <opencv2/core/mat.hpp>

class Filter {
    int* filterMask;
    int filterMaskSize;
public:
    void apply(cv::Mat frame);
    void setMask(int* mask, int size);
};


#endif //PROJEKT_FILTER_H
