//
// Created by 胡小赖 on 2018/6/11.
//

#include "IMDBSpider.h"
IMDBSpider::IMDBSpider()
{}
void IMDBSpider::change_match_symbol() {
    if (type == "电影"){
        match_symbol["电影"] = "<title>~@~*~!- IMDb~*</title>";
        match_symbol["评分"] = "<span class=\"rating\">~@~*~!<~*";
        match_symbol["类型"] = "<a href=\"/genre/~@~*~!?~*ref_=tt_stry_gnr\"";
        match_symbol["导演"] = "<span itemprop=\"director\" itemscope itemtype=~*\"name\">~*~@~*~!<~*";
        match_symbol["编剧"] = "~%1~%<span itemprop=\"creator\" itemscope itemtype=~*\"name\">~*~@~*~!<~*";
        match_symbol["上映日期"] = "title=\"See more release dates\" >~@~*~! (~*";
        match_symbol["票房"] = "<h4 class=\"inline\">Budget:</h4>~@~*~!<~*`~L`13`";
        match_symbol["时长"] = "Runtime:</h4>~*M\">~*~@~*~!<~*";
        match_symbol["主演"] = "~%2~%<img height=\"44\" width=\"32\" alt=\"~@~*~!\"~*";
        match_symbol["评论"] = "<span itemprop=\"description\">~@~*~!</span>~*";
    }
    else if(type == "电视剧"){
        match_symbol["电视剧"] = "<title>~@~*~!&quot;~/- IMDb~*</title>";
        match_symbol["评分"] = "<span class=\"rating\">~@~*~!<~*";
        match_symbol["类型"] = "<a href=\"/genre/~@~*~!?~*ref_=tt_stry_gnr\"";
        match_symbol["编剧"] = "<span itemprop=\"creator\" itemscope itemtype=~*\"name\">~*~@~*~!<~*";
        match_symbol["主演"] = "~%2~%<img height=\"44\" width=\"32\" alt=\"~@~*~!\"~*";
        match_symbol["时长"] = "Runtime:</h4>~*M\">~*~@~*~!<~*";
        match_symbol["评论"] = "<span itemprop=\"description\">~@~*~!</span>~*";
    }
}
std::string IMDBSpider::GetURL()
{
    std::string url_symbol = "<a href=\"/title/tt~@~?~?~?~?~?~?~?~!/?ref";
    return Match(html,url_symbol);
}
