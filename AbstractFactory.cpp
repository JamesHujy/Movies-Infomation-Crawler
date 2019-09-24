//
// Created by 胡小赖 on 2018/6/30.
//

#include "AbstractFactory.h"
void AbstractFactory::printproduct()
{
    int len = product_chain.size();
    for(int i = 0;i <len;i++)
        product_chain[i]->printObject();
}