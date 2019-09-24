//
// Created by 胡小赖 on 2018/6/11.
//

#ifndef OOPPROJECT_BASEDATA_H
#define OOPPROJECT_BASEDATA_H

#include <iostream>
#include <map>

class baseData {
private:
    std::string type;
    std::string value;

public:
    baseData(std::string _type,std::string _value);
    baseData();
    virtual baseData* SetData(std::string _type,std::string _value);
    std::string gettype();
    std::string getvalue();
};


#endif //OOPPROJECT_BASEDATA_H
