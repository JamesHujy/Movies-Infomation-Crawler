//
// Created by 胡小赖 on 2018/6/30.
//

#ifndef OOPPROJECT_ABSTRACTFACTORY_H
#define OOPPROJECT_ABSTRACTFACTORY_H


#include "baseObject.h"
#include "DataBase.h"
#include "Control.h"

class baseSpider;
class Control;

class AbstractFactory {
protected:
    std::vector<baseObject*> product_chain;
public:
    virtual void createProduct(std::vector<std::string> info_type,std::vector<std::string> info,
                       Parser& parser,DataBase& database,Control& control) = 0;
    virtual void printproduct();
};


#endif //OOPPROJECT_ABSTRACTFACTORY_H
