//
// Created by 胡小赖 on 2018/6/11.
//

#include "rottentomatoSpider.h"
rottentomatoSpider::rottentomatoSpider()
{

}

std::string rottentomatoSpider::GetURL()
{
    std::string url_symbol;
    if(type == "电影")
        url_symbol ="<td>`~?`8`<a href=\"~@/m/~*~!\" class=\"unstyled articleLink~*\"";
    else if (type == "电视剧")url_symbol="href='//www.rottentomatoes.com~@~*~!/'>~* [More]";
    return Match(html,url_symbol);
}

void rottentomatoSpider::change_match_symbol() {
    if (type == "电影"){
        match_symbol["电影"] = "<title>~@~*~!&~*";
        match_symbol["评分"] = "~%1~%Average Rating: </span>`~?`32`~@~*~!<~*`~L`36`";
        match_symbol["类型"] = "\"genre\":[\"~@~*~!\"~/]~*";
        match_symbol["导演"] = "\"meta-label subtle\">Directed By:~*<a href~*~*>~*~@~*~!<~*";
        match_symbol["编剧"] = "\"meta-label subtle\">Written By:~*<a href~*~*>~*~@~*~!<~*";
        match_symbol["上映日期"] = "\"meta-label subtle\">In Theaters:~*time datetime~*~*>~*~@~*~!<~*";
        match_symbol["票房"] = "\"meta-label subtle\">Box Office:~*\"meta-value\">~*~@~*~!<~*";
        match_symbol["时长"] = "\"meta-label subtle\">Runtime:~*datetime~*~*` `20`~*~@~*~!<~*`~L`17`";
        match_symbol["主演"] = "\"panel-heading\">Cast~*<span title=\"~*~@~*~!\"~*~~,~~~*<span title=\"~*~@~*~!\"~*";
        match_symbol["评论"] = "<div id=\"reviews\">~*<p>~*`~?`20`~@~*~!</p>~*";
    }
    else if(type == "电视剧"){
        match_symbol["电视剧"] = "<title>~@~*~!- Rotten Tomatoes~*";
        match_symbol["评分"] = "\"ratingValue\":~@~*~!}~*~~/100~~";
        match_symbol["类型"] = "\"titleGenre\": \"~@~*~!\",~*";
        match_symbol["导演"] = "Creator~*<a href~*~*>~*~@~*~!<~*";
        match_symbol["上映日期"] = "mpscall[\"cag[release]\"]=\"~@~*~!\"~*";
        match_symbol["评论"] = "<div id=\"movieSynopsis\" class=\"movie_synopsis clamp clamp-6 clearfix\">`~?`12`~@~*~!</div>~*";
    }
}