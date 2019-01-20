#ifndef PROJEKT_CONTRAST_H
#define PROJEKT_CONTRAST_H


#include <opencv2/core/mat.hpp>

class Contrast {
public:
    void apply(cv::Mat frame, int* LUT);
    int* lut(double contrast);

};


#endif //PROJEKT_CONTRAST_H
