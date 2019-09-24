//
// Created by 胡小赖 on 2018/6/11.
//

#include "doubanSpider.h"
doubanSpider::doubanSpider():baseSpider(" "," ")
{

}
void doubanSpider::change_match_symbol() {
    if (type == "电影"){
        match_symbol["电影"] = "<title>`~?`8`~@~*~!(~*~L";
        match_symbol["上映日期"] = "content=\"~@`~N`4`-~N~N-~N~N(~*)~*~!";
        match_symbol["评分"] = "rating_num\" property=\"v:average\">~@~*~!<~*";
        match_symbol["导演"] = "\"v:directedBy\">~@~*~!<~*";
        match_symbol["主演"] = "~%3~%\" rel=\"v:starring\">~@~*~!<~*";
        match_symbol["类型"] = "<span property=\"v:genre\">~@~*~!<~*";
        match_symbol["时长"] = "<span property=\"v:runtime\"~*>~*~@~*~!<~*";
        match_symbol["评论"] = "<span property=\"v:summary\" class=\"\">`~?`38`~@~*~!`~?`36`<br />`~?`39`~/</span>~*`~L`24`";
    }
    else if(type == "电视剧"){
        match_symbol["电视剧"] = "<span property=\"v:itemreviewed\">~@~*~!<~*";
        match_symbol["评分"] = "<strong class=\"ll rating_num\" property=\"v:average\">~@~*~!<~*";
        match_symbol["类型"] = "</span> <span property=\"v:genre\">~@~*~!<~*";
        match_symbol["导演"] = "~%1~% rel=\"v:directedBy\">~@~*~!<~*";
        match_symbol["主演"] = "~%2~% rel=\"v:starring\">~@~*~!<~*";
        match_symbol["上映日期"] = "<span property=\"v:initialReleaseDate\" content=\"~@~*~!\"~*";
        match_symbol["评论"] = "~%1~%<span property=\"v:summary\" class=\"\">`~?`38`~@~*~!`~?`38`<br />`~?`38`~/</span>~*`~L`24`";
    }
}
std::string doubanSpider::GetURL()
{
    std::string url_symbol = "<a href=\"https://movie.douban.com/subject/~@~*~!/~*?from=subject-page";
    return Match(html,url_symbol);
}




