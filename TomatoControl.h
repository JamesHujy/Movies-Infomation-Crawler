//
// Created by 胡小赖 on 2018/7/1.
//

#ifndef OOPPROJECT_TOMATOCONTROL_H
#define OOPPROJECT_TOMATOCONTROL_H

#include "Control.h"
//because of the speciality of roasted tomatoes, we use movie lists to expand the database, but not BFS
//therefore an additional spider is needed to download and analyse the url in the movie lists html
//toamtospider默认构造函数？


#include "rottentomatoSpider.h"
class TomatoControl : public Control {
    rottentomatoSpider get_movie_list;
    std::string movie_list_year_url_path;
public:
TomatoControl(){};
    TomatoControl(std::string movie_list_path,std::string set_position_path,
                  std::string downloaded_html_path, std::string got_url_path, Parser* _parser);
    void get_html_save_and_analyse(Parser& parser,DataBase& dataBase) override ;
};




#endif //OOPPROJECT_TOMATOCONTROL_H
