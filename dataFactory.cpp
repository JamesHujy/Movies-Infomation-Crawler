//
// Created by 胡小赖 on 2018/6/30.
//

#include "dataFactory.h"
baseData* dataFactory::createData(std::string _type,std::string _value)
{
    if(_type=="评分") return new Rate(_type,_value);
    else if(_type=="导演") return new Director(_type,_value);
    else if(_type=="编剧") return new Screenwriter(_type,_value);
    else if(_type=="主演") return new Actor(_type,_value);
    else if(_type=="时长") return new Runtime(_type,_value);
    else if(_type=="上映日期") return new Release_Date(_type,_value);
    else if(_type=="票房") return new BoxOffice(_type,_value);
    else if(_type=="类型") return new Genre(_type,_value);
    else if(_type=="评论") return new Review(_type,_value);
    else return nullptr;
}