//
// Created by 胡小赖 on 2018/6/11.
//

#ifndef OOPPROJECT_BASESPIDER_H
#define OOPPROJECT_BASESPIDER_H

#include <iostream>
#include <fstream>
#include "AbstractFactory.h"
#include <curl/curl.h>
#include <map>
#include <vector>
#include <string>
#include "Control.h"

class AbstractFactory;
class Control;

class baseSpider {
    std::string url;
    std::string filepath;
    friend class control;
protected:
    AbstractFactory* Factory;
    std::map<std::string,std::string> match_symbol;
    std::vector<std::string> info;
    char* html;
    bool check(char ch,std::string&s,int&pt);
    int check_string(char*File,int L,std::string&s,int pt1,int pt2,int pt3);
    std::string Match(char*File,std::string match_symbol);

public:
std::string type;
    baseSpider();
    baseSpider(std::string a,std::string b);
    virtual std::string GetURL();
    virtual void change_filepath(std::string Des_filepath);
    virtual void change_url(std::string Des_url);
    void change_type(std::string _type);
    virtual void change_match_symbol();
    virtual void create_factory();
    void Downloadhtml();
    void readhtml();
    virtual void analyse_info(Parser& parser,DataBase& database,Control& control);
};


#endif //OOPPROJECT_BASESPIDER_H
