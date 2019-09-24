//
// Created by 胡小赖 on 2018/6/11.
//

#ifndef OOPPROJECT_IMDBSPIDER_H
#define OOPPROJECT_IMDBSPIDER_H


#include "baseSpider.h"
#include "Parser.h"
#include <map>
#include <stdio.h>
#include "MovieFactory.h"
#include "TVOperaFactory.h"

class IMDBSpider: public baseSpider {
public:
    std::string GetURL() override ;
    void change_match_symbol()override;
    IMDBSpider();
};


#endif //OOPPROJECT_IMDBSPIDER_H
