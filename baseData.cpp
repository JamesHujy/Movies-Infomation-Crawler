//
// Created by 胡小赖 on 2018/6/11.
//

#include "baseData.h"
baseData::baseData(std::string _type,std::string _value)
{
    type = _type;
    value = _value;
}
baseData::baseData()
{
    type = "";
    value = "";
}

std::string baseData::gettype()
{
    return type;
}

std::string baseData::getvalue()
{
    return value;
}
baseData* baseData::SetData(std::string _type,std::string _value)
{
    return new baseData(_type,_value);
}