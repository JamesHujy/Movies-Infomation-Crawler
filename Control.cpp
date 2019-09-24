//
// Created by 胡小赖 on 2018/6/30.
//

#include "Control.h"

int Control::get_num()
{
    return read_position;
}

Control::Control(std::string set_queue_path, std::string set_position_path,Parser* _parser):
        html_code_set_queue_path(set_queue_path), preread_num_of_url_path(set_position_path),parser(_parser)
{
    std::ifstream fin2(preread_num_of_url_path);
    fin2 >> read_position >> num_downloaded_html;
    fin2.close();
    std::ifstream fin1(html_code_set_queue_path);
    std::string temp;
    int times = 0;
    while (times < read_position&&fin1 >> temp) {
        html_code_set.insert(temp);
        ++times;
    }
    while(fin1>>temp){
        html_code_queue.push(temp);
    }
    //复原上次运行时的队列与set

    object_path_tail = ".txt";
    fin1.close();
}

void Control::set_set_queue_path(std::string a)
{
    html_code_set_queue_path = a;
}

std::string Control::get_set_queue_path()
{
    return html_code_set_queue_path;
}

void Control::set_preread_num_path(std::string a)
{
    preread_num_of_url_path = a;
}

std::string Control::get_preread_num_path()
{
    return preread_num_of_url_path;
}

void Control::get_html_save_and_analyse(Parser& parser,DataBase& dataBase)
{
    int times = 0;
    while (!(html_code_queue.empty()) && times < MAX_NUM_OF_HTML_DOWNLOADED/*添加边界条件*/) {
        ++times;
        std::string fixed_filepath = object_path_head +
                std::to_string(num_downloaded_html) + object_path_tail;

        crowl_bug->change_filepath(fixed_filepath);
        std::string& fixed_url = html_code_queue.front();
        crowl_bug->change_url(fixed_url);
        //爬虫工作

        crowl_bug->Downloadhtml();
        num_downloaded_html++;
        crowl_bug->readhtml();
        html_code_queue.pop();

        crowl_bug->analyse_info(parser,dataBase,*this);
        std::string got_url_part_total = crowl_bug->GetURL();
        int head = 0;
        for (int i = 0; i < got_url_part_total.size(); i++) {
            if (got_url_part_total[i] == ',') {
                std::string part = got_url_part_total.substr(head, i - head);
                std::string entire_url = url_head + part + url_tail;

                if (html_code_set.count(entire_url) == 0) {
                    html_code_queue.push(entire_url);
                    html_code_set.insert(entire_url);
                    read_position++;
                }
                head = i + 1;
            }
            if (i == got_url_part_total.size() - 1) {
                std::string part = got_url_part_total.substr(head, i - head + 1);
                std::string entire_url = url_head + part + url_tail;
                if (html_code_set.count(entire_url) == 0) {
                    html_code_queue.push(entire_url);
                    html_code_set.insert(entire_url);
                    read_position++;
                }
            }
        }
    }
    std::ofstream fout1(get_set_queue_path());
    for (auto i : html_code_set) {
        fout1 << i << '\n';
    }
    fout1<<"\n";

    while(html_code_queue.size() > 0){

        fout1 << html_code_queue.front() << '\n';
        html_code_queue.pop();
    }
    fout1.close();
    std::ofstream fout2(get_preread_num_path());
    fout2 << read_position<<std::endl<<num_downloaded_html;
    fout2.close();
};

Control::~Control()
{
    delete[] crowl_bug;
}