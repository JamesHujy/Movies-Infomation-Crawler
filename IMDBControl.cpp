//
// Created by 胡小赖 on 2018/7/1.
//

#include "IMDBControl.h"
IMDBControl::IMDBControl(std::string set_queue_path, std::string set_position_path,Parser* _parser)
        : Control(set_queue_path, set_position_path,_parser)
{
    object_path_head = parser->get_path()+"/IMDb/"+parser->get_spidertype()+"/html/html";
    crowl_bug = new IMDBSpider;
    crowl_bug->change_type(_parser->get_spidertype());
    crowl_bug->create_factory();
    url_head = "https://www.imdb.com/title/tt";
    url_tail = "/?ref_=inth_ov_tt";
}