#include <iostream>
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include "Filter/black_white.h"
#include "Filter/sepia.h"
#include "Filter/blur.h"
#include "Filter/contrast.h"
#include "Filter/edge_detection.h"

using namespace cv;

int main(int argc, char *argv[])
{
    VideoCapture cap(argv[1]);
    if(!cap.isOpened())  // check if we succeeded
        return -1;

    auto filter_black_and_white = new BlackWhite();
    auto filter_sepia = new Sepia();
    auto filter_blur = new Blur();
    auto filter_contrast = new Contrast();
    auto filter_edge_detection = new EdgeDetection();

    for(int i=0;;i++) {



        Mat frame;
        cap >> frame;
        //if(i<1500) continue;

        if (strcmp(argv[2], "sepia") == 0) {
            filter_sepia->apply(frame);
        } else if (strcmp(argv[2], "czarno-bialy") == 0) {
            filter_black_and_white->apply(frame);
        } else if (strcmp(argv[2], "rozmycie") == 0) {
            filter_blur->apply(frame);
        } else if (strcmp(argv[2], "kontrast") == 0) {
            filter_contrast->apply(frame, 1.0);
        } else if (strcmp(argv[2], "wykrywanie-krawedzi") == 0) {
            frame = filter_edge_detection->getEdge(frame);
        }

        imshow("Podgląd", frame);
        if(waitKey(30) >= 0) break;

    }
    return 0;
}