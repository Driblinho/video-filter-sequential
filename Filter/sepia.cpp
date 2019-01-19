#include "sepia.h"

void Sepia::apply(cv::Mat frame) {
    for (int i = 0; i < frame.rows; ++i) {
        for (int j = 0; j < frame.cols; ++j) {
            unsigned char * p = frame.ptr(i, j); // Y first, X after

            auto inputRed =  p[2];
            auto  inputGreen =  p[1];
            auto inputBlue = p[0];

            auto outputRed = (inputRed * .393) + (inputGreen *.769) + (inputBlue * .189);
            auto outputGreen = (inputRed * .349) + (inputGreen *.686) + (inputBlue * .168);
            auto outputBlue = (inputRed * .272) + (inputGreen *.534) + (inputBlue * .131);

            if(outputRed>255) outputRed=255;
            if(outputGreen>255) outputGreen=255;
            if(outputBlue>255) outputBlue=255;


            p[2]= static_cast<unsigned char>(outputRed); // R
            p[1] = static_cast<unsigned char>(outputGreen);   // G
            p[0] = static_cast<unsigned char>(outputBlue);//B


        }
    }
}
