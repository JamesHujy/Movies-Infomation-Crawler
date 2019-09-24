//
// Created by 胡小赖 on 2018/6/30.
//

#ifndef OOPPROJECT_CONTROL_H
#define OOPPROJECT_CONTROL_H

#define MAX_NUM_OF_HTML_DOWNLOADED 50

#include <iostream>
#include "Parser.h"
#include "baseSpider.h"
#include <iostream>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include "AbstractFactory.h"

class AbstractFactory;
class baseSpider;

class Control {
    //保存上次执行时的队列路径与队列头指针的位置
    std::string html_code_set_queue_path;//内含大量url
    std::string preread_num_of_url_path;
protected:
int num_downloaded_html;
    Parser* parser;
    //set 存储的是所有已下载过html的网页的完整网址，queue则是存储上次运行时仍在列中的完整网址
    std::set<std::string> html_code_set;
    std::queue<std::string> html_code_queue;
    baseSpider * crowl_bug;
    std::string object_path_head, object_path_tail;//用于合成目标存储所下载的html的txt位置
    std::string url_head, url_tail;
    int read_position;
    void set_set_queue_path(std::string a);
    std::string get_set_queue_path();
    void set_preread_num_path(std::string a);
    int get_num();
    std::string get_preread_num_path();
public:
    //初始化时输入上次执行的set与队列所存储的地址
    Control() { read_position = 0; }
    Control(std::string set_queue_path,std::string set_position_path,Parser* _parser);
    int get_now_number() {return num_downloaded_html;}
    virtual void get_html_save_and_analyse(Parser& parser,DataBase& dataBase);
    virtual ~Control() = 0;
};






#endif //OOPPROJECT_CONTROL_H
