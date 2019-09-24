//
// Created by 胡小赖 on 2018/7/1.
//

#include "DoubanControl.h"
DoubanControl::DoubanControl(std::string set_queue_path, std::string set_position_path,Parser* _parser)
        :Control(set_queue_path, set_position_path,_parser)
{

    object_path_head = parser->get_path()+"/豆瓣/"+parser->get_spidertype()+"/html/html";
    crowl_bug = new doubanSpider;
    crowl_bug->change_type(_parser->get_spidertype());
    crowl_bug->create_factory();
    url_head = "https://movie.douban.com/subject/";
    url_tail = "/";
}