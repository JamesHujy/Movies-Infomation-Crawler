//
// Created by 胡小赖 on 2018/6/30.
//

#ifndef OOPPROJECT_MOVIEFACTORY_H
#define OOPPROJECT_MOVIEFACTORY_H

#include <iostream>
#include "AbstractFactory.h"
#include "baseObject.h"
#include "Movie.h"
#include <vector>


class MovieFactory: public AbstractFactory {
public:
    void createProduct(std::vector<std::string> info_type,std::vector<std::string> info,
                                     Parser& parser,DataBase& database,Control& control) override ;
};


#endif //OOPPROJECT_MOVIEFACTORY_H
