//
// Created by 胡小赖 on 2018/6/30.
//

#ifndef OOPPROJECT_TVOPERAFACTORY_H
#define OOPPROJECT_TVOPERAFACTORY_H


#include "AbstractFactory.h"
#include "TVOpera.h"
#include <vector>



class TVOperaFactory: public AbstractFactory {
public:
    void createProduct(std::vector<std::string> info_type,std::vector<std::string> info,
                       Parser& parser,DataBase& database,Control& control) override ;

};


#endif //OOPPROJECT_TVOPERAFACTORY_H
