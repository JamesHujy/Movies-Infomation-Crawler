//
// Created by 胡小赖 on 2018/6/11.
//

#ifndef OOPPROJECT_DOUBANSPIDER_H
#define OOPPROJECT_DOUBANSPIDER_H

#include "baseSpider.h"
#include "Parser.h"
#include <map>
#include <stdio.h>
#include "MovieFactory.h"
#include "TVOperaFactory.h"

class doubanSpider:public baseSpider {
public:
    doubanSpider();
    void change_match_symbol()override;
    std::string GetURL() override ;
};


#endif //OOPPROJECT_DOUBANSPIDER_H
