//
// Created by 胡小赖 on 2018/6/29.
//

#ifndef OOPPROJECT_PARSER_H
#define OOPPROJECT_PARSER_H

#include <iostream>
#include <vector>

class Parser {
public:
    /*static*/ std::vector<std::string> get_type();
    /*static*/ std::string get_spidertype();
    /*static*/ std::string get_webname();
    std::string get_path(){return path;}
    void solve_info();
    Parser();
private:
    std::string path;
    /*static*/ int info_num;
    /*static*/ //std::string* info_type;
    /*static*/ std::vector<std::string> search_type;
    /*static*/ std::string spider_type;
    /*static*/ std::string web_name;
    /*static*/ std::string info;
};


#endif //OOPPROJECT_PARSER_H
