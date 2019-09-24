//
// Created by 胡小赖 on 2018/6/30.
//

#include "TVOperaFactory.h"

void TVOperaFactory::createProduct(std::vector<std::string> info_type,std::vector<std::string> info,
                                 Parser& parser,DataBase& database,Control& control)
{
    baseObject * object = new TVOpera(info_type,info);
    product_chain.push_back(object);
    object->printObject();
    object->saveObject(control.get_now_number(),parser,database);
}