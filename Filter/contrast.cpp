#include "contrast.h"

void Contrast::apply(cv::Mat frame, double contrast) {

    auto LUT = new int[256];
    for (int i = 0; i < 256; i++)
    {
        if ((contrast * (i - 127) + 127) > 255)
        {
            LUT[i] = 255;
        }
        else if ((contrast * (i - 127) + 127) < 0)
        {
            LUT[i] = 0;
        }
        else
        {
            LUT[i] = (int)(contrast * (i - 127) + 127);
        }
    }

    for (int i = 0; i < frame.rows; ++i) {
        for (int j = 0; j < frame.cols; ++j) {
            unsigned char * p = frame.ptr(i, j); // Y first, X after
            p[2] = static_cast<unsigned char>(LUT[p[2]]); //R
            p[1] = static_cast<unsigned char>(LUT[p[1]]);  //G
            p[0] = static_cast<unsigned char>(LUT[p[0]]); //B
        }
    }

}
