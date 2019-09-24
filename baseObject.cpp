//
// Created by 胡小赖 on 2018/6/11.
//

#include "baseObject.h"
#include "DataBase.h"

std::string baseObject::getname()
{
    return name;
}
baseObject::baseObject(std::vector<std::string> info_type,std::vector<std::string> info)
{

    Datacount = 0;
    std::vector<std::string>::iterator it1 = info_type.begin();
    std::vector<std::string>::iterator it2 = info.begin();
    name = info[0];
    ++it1;
    ++it2;
    for(;it1!=info_type.end()&&it2!=info.end();++it1,++it2)
    {
        baseData * temp = dataFactory::createData(*it1,*it2);
        Datalist.push_back(temp);
        Datacount++;
    }
    savepath = "/Users/kingjames/Desktop/oopproject/info";
}

baseObject::~baseObject()
{
    std::vector<baseData*>::iterator it = Datalist.end();
    --it;
    for(;it!=Datalist.begin()-1;--it)
    {
        delete *it;
    }
}

void baseObject::printObject()
{

    std::cout << name <<std::endl;
    size_t len = Datalist.size();
    for(int i = 0;i < len;i++)
    {
        std::cout << Datalist[i]->gettype()<<":"<<Datalist[i]->getvalue()<<std::endl;

    }
    std::cout <<"**********"<<std::endl;
}

void baseObject::addData(std::string info_type,std::string info)
{
    baseData *temp = dataFactory::createData(info_type,info);
    Datalist.push_back(temp);
}

void baseObject::saveObject(int index,Parser& parser,DataBase& dataBase)
{
    savetxt(index,parser);
    saveDatabase(index,dataBase,parser);
}

void baseObject::savetxt(int index,Parser & parser)
{
    std::string save = savepath+"/"+parser.get_webname()+"/"+parser.get_spidertype()+std::to_string(index)+".txt";
    std::ofstream out(save);
    int len = Datacount;
    out << name <<std::endl;
    for(int i = 0;i< Datacount;i++)
        out << Datalist[i]->gettype() << ":" <<Datalist[i]->getvalue()<<std::endl;
}

void baseObject::saveDatabase(int index,DataBase& database,Parser& parser)
{
    database.insertData(this,index,parser);
}

int baseObject::getCount()
{
    return Datacount;
}