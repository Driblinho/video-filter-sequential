#ifndef PROJEKT_CONTRAST_H
#define PROJEKT_CONTRAST_H


#include <opencv2/core/mat.hpp>

class Contrast {
public:
    void apply(cv::Mat frame, double contrast);

};


#endif //PROJEKT_CONTRAST_H
