//
// Created by 胡小赖 on 2018/7/1.
//

#ifndef OOPPROJECT_DOUBANCONTROL_H
#define OOPPROJECT_DOUBANCONTROL_H

#include "Control.h"
#include "doubanSpider.h"
class DoubanControl :public Control {

public:
    DoubanControl(std::string set_queue_path, std::string set_position_path,Parser* _parser);
    ~DoubanControl() { delete[] crowl_bug; };
};

#endif //OOPPROJECT_DOUBANCONTROL_H
