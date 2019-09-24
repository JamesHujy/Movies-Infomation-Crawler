//
// Created by 胡小赖 on 2018/6/11.
//

#ifndef OOPPROJECT_BASEOBJECT_H
#define OOPPROJECT_BASEOBJECT_H

#include "baseData.h"
#include "dataFactory.h"
#include <vector>
#include <iostream>
#include <fstream>
#include "DataBase.h"

class DataBase;
class baseObject {
private:
    std::vector<baseData*> Datalist;
    int Datacount;
    std::string name;
    std::string savepath;
    std::map<std::string,std::string> match_symbol;
    void savetxt(int index,Parser& parser);
    void saveDatabase(int index,DataBase& database,Parser& parser);
public:
    baseObject(std::vector<std::string> info_type,std::vector<std::string> info);
    baseObject(){}
    friend class DataBase;
    virtual std::string getname();
    virtual int getCount();
    virtual void printObject();
    virtual void addData(std::string info_type,std::string info);
    virtual void saveObject(int index,Parser& parser,DataBase& dataBase);
    virtual ~baseObject();
};


#endif //OOPPROJECT_BASEOBJECT_H
