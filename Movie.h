//
// Created by 胡小赖 on 2018/6/30.
//

#ifndef OOPPROJECT_MOVIE_H
#define OOPPROJECT_MOVIE_H


#include "baseObject.h"

class Movie: public baseObject {
public:
    Movie();
    Movie(std::vector<std::string> info_type,std::vector<std::string> info);
    ~Movie(){}
};


#endif //OOPPROJECT_MOVIE_H
