#include "blur.h"
#include "filter.h"

void Blur::apply(cv::Mat frame) {
    auto obj =new Filter();
    obj->setMask(new int[25]{
            1,1,1,1,1,
            1,1,1,1,1,
            1,1,1,1,1,
            1,1,1,1,1,
            1,1,1,1,1
    }, 5);
    obj->apply(std::move(frame));
}
