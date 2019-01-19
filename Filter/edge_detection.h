//
// Created by ireq on 13.01.19.
//

#ifndef PROJEKT_EDGE_DETECTION_H
#define PROJEKT_EDGE_DETECTION_H


#include <opencv2/core/mat.hpp>

class EdgeDetection {
public:
    void apply(cv::Mat frame);
};


#endif //PROJEKT_EDGE_DETECTION_H
