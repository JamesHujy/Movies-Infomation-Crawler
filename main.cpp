#include <iostream>
#include "Parser.h"
#include "Control.h"
#include "DoubanControl.h"
#include "IMDBControl.h"
#include "DataBase.h"
#include "TomatoControl.h"

using namespace std;
int main()
{
    Parser* mainParser = new Parser;
    mainParser->solve_info();
    int len = mainParser->get_type().size();
    DataBase* database = new DataBase(*mainParser);
    Control* spider_control;
    if(mainParser->get_webname()=="douban") spider_control = new
                DoubanControl("/Users/kingjames/Desktop/oopproject/豆瓣/"+mainParser->get_spidertype()+"/initial/initial_url.txt",
                              "/Users/kingjames/Desktop/oopproject/豆瓣/"+mainParser->get_spidertype()+"/initial/downloadnum.txt",mainParser);
    else if (mainParser->get_webname()=="IMDb") spider_control = new
                IMDBControl("/Users/kingjames/Desktop/oopproject/IMDb/"+mainParser->get_spidertype()+"/initial/initial_url.txt",
                            "/Users/kingjames/Desktop/oopproject/IMDb/"+mainParser->get_spidertype()+"/initial/downloadnum.txt",mainParser);
    else if (mainParser->get_webname() == "rottentomatoes") spider_control = new
                TomatoControl("/Users/kingjames/Desktop/oopproject/tomato/"+mainParser->get_spidertype()+"/initial/source_url.txt",
                              "/Users/kingjames/Desktop/oopproject/tomato/"+mainParser->get_spidertype()+"/initial/downloadnum.txt",
                              "/Users/kingjames/Desktop/oopproject/tomato/"+mainParser->get_spidertype()+"/initial/initial_url.txt",
                              "/Users/kingjames/Desktop/oopproject/tomato/"+mainParser->get_spidertype()+"/initial/url.txt",mainParser);
    spider_control->get_html_save_and_analyse(*mainParser,*database);
    cerr<<"Finish!\n";
    return 0;
}