//
// Created by ireq on 13.01.19.
//

#ifndef PROJEKT_FILTER_H
#define PROJEKT_FILTER_H


#include <opencv2/core/mat.hpp>

class Filter {
    int* filterMask;
public:
    void apply(cv::Mat frame);
    void setMask(int* mask);
};


#endif //PROJEKT_FILTER_H
