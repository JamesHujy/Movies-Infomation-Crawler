//
// Created by 胡小赖 on 2018/7/1.
//

#include "TomatoControl.h"
TomatoControl::TomatoControl(std::string movie_list_year_path,std::string set_position_path,
        std::string downloaded_html_path, std::string got_url_path, Parser * _parser)//: Control()
{
    parser = _parser;
    num_downloaded_html = 0;
    //分别对应榜单年份路径，存储对应已完成的网站个数的路径，输出【榜单】html的路径与存储榜单html中电影url的路径
    set_preread_num_path(set_position_path);
    set_set_queue_path(got_url_path);
    object_path_head = parser->get_path()+"/tomato/"+parser->get_spidertype()+"/html/html";
    crowl_bug = new rottentomatoSpider;
    crowl_bug->change_type(_parser->get_spidertype());
    get_movie_list.change_type(_parser->get_spidertype());
    url_head = "https://www.rottentomatoes.com";
    url_tail = "/";
    movie_list_year_url_path = movie_list_year_path;
    std::ifstream fin1(set_position_path);
    fin1 >> read_position;
    fin1.close();

    //下载榜单html，获取电影链接并传入存储电影url的txt
    get_movie_list.change_filepath(std::move(downloaded_html_path));
    std::ifstream fin(movie_list_year_url_path);
    std::string input_list_url;
    if(_parser->get_spidertype() == "电影"){
        std::string year;
        fin>> year;
        fin.close();
        input_list_url = "https://www.rottentomatoes.com/top/bestofrt/?year=" + year;
        int temp = stoi(year) - 1;
        std::ofstream fout2(movie_list_year_path);
        fout2<<temp;
        fout2.close();
    }
    else if(_parser->get_spidertype() == "电视剧"){
        fin>>input_list_url;
        fin.close();
        
    }
    get_movie_list.change_url(input_list_url);
        get_movie_list.Downloadhtml();
        get_movie_list.readhtml();
        std::string got_url_part_total = get_movie_list.GetURL();
        int head = 0;
        for (int i = 0; i < got_url_part_total.size(); i++) {
            if (got_url_part_total[i] == ',') {
                std::string part = got_url_part_total.substr(head, i - head);
                std::string entire_url = url_head + part + url_tail;
                html_code_queue.push(entire_url);
                head = i + 1;
            }
            if (i == got_url_part_total.size() - 1) {
                std::string part = got_url_part_total.substr(head, i - head + 1);
                std::string entire_url = url_head + part + url_tail;
                html_code_queue.push(entire_url);
            }
        }
        object_path_tail = ".txt";
        //此处应该有清空url的操作与年份-1
}

void TomatoControl::get_html_save_and_analyse(Parser& parser,DataBase& dataBase)
{

    int times = 0;
    while (!(html_code_queue.empty()))
     {
        ++times;
        std::string fixed_filepath = object_path_head + std::to_string(read_position) + object_path_tail;
        read_position++;
        num_downloaded_html++;
        crowl_bug->change_filepath(fixed_filepath);
        std::string fixed_url = html_code_queue.front();
        crowl_bug->change_url(fixed_url);
        crowl_bug->Downloadhtml();
        html_code_queue.pop();
        //cease for about half a second
        for (int i = 0; i < 500000000; i++){}
        //还没有的分析html函数
        crowl_bug->readhtml();
        crowl_bug->create_factory();
        crowl_bug->analyse_info(parser,dataBase,*this);
    }
    std::ofstream fout2(get_preread_num_path());
    fout2 << read_position;
    fout2.close();
}