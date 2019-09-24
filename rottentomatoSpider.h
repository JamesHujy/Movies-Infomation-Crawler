//
// Created by 胡小赖 on 2018/6/11.
//

#ifndef OOPPROJECT_ROTTENTOMATOSPIDER_H
#define OOPPROJECT_ROTTENTOMATOSPIDER_H


#include "baseSpider.h"
#include "Parser.h"
#include <map>
#include <stdio.h>
#include "MovieFactory.h"
#include "TVOperaFactory.h"

class rottentomatoSpider: public baseSpider {
public:
    std::string GetURL();
    rottentomatoSpider();
    void change_match_symbol();
};


#endif //OOPPROJECT_ROTTENTOMATOSPIDER_H
