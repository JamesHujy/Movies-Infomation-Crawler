//
// Created by 胡小赖 on 2018/7/1.
//

#ifndef OOPPROJECT_IMDBCONTROL_H
#define OOPPROJECT_IMDBCONTROL_H

#include "Control.h"
#include "IMDBSpider.h"
class IMDBControl : public Control {

public:
    IMDBControl(std::string set_queue_path, std::string set_position_path,Parser* parser1);
    ~IMDBControl() { delete crowl_bug; };
};


#endif //OOPPROJECT_IMDBCONTROL_H
