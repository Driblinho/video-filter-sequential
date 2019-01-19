#include "blur.h"
#include "filter.h"

void Blur::apply(cv::Mat frame) {
    auto obj =new Filter();
    obj->apply(frame);
}
