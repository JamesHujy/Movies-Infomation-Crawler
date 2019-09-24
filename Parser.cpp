//
// Created by 胡小赖 on 2018/6/29.
//
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include "Parser.h"

void Parser::solve_info()      //divide the info into different info_types
{
    std::vector<std::string> result;
    char DM[]="ORDSKTCA",
            DT[]="RKDSOCA",
            IM[]="RKDWOBTSCA",
            IT[]="RKWSTCA",
            RM[]="RKDWOBTSCA",
            RT[]="RKDOCA";
    std::string Web,Tp;
    std::string Info;
    char *A;
    std::cout<<"请问您希望获取哪个网站的信息？豆瓣请按下D，IMDb请按下I，烂番茄请按下R\n";

    for(std::cin>>Web;Web.length()>1||(Web[0]!='D'&&Web[0]!='I'&&Web[0]!='R');std::cin>>Web)
        std::cout<<"类型错误，请重新输入\n";

    if(Web[0]=='D') web_name="douban";
    else if(Web[0]=='I') web_name="IMDb";
    else if(Web[0]=='R') web_name="rottentomatoes";

    std::cout<<"请问您希望获取电影还是电视剧？电影请按下M，电视剧请按下T\n";
    for(std::cin>>Tp;Tp.length()>1||(Tp[0]!='M'&&Tp[0]!='T');std::cin>>Tp)
        std::cout<<"类型错误，请重新输入\n";
    //_main in main-491e6e.o

    if(Tp[0]=='M') spider_type="电影";
    else if(Tp[0]=='T') spider_type="电视剧";
    search_type.push_back(spider_type);
    std::cout<<"请问您希望获取什么信息？全部请按下A";

    if(Web[0]=='D'&&Tp[0]=='M')A=DM;
    else if(Web[0]=='D'&&Tp[0]=='T')A=DT;
    else if(Web[0]=='I'&&Tp[0]=='M')A=IM;
    else if(Web[0]=='I'&&Tp[0]=='T')A=IT;
    else if(Web[0]=='R'&&Tp[0]=='M')A=RM;
    else if(Web[0]=='R'&&Tp[0]=='T')A=RT;

    for(int i=0;i<strlen(A)-2;i++)
    {	if(A[i]=='D')std::cout<<"，导演请按下D";
        if(A[i]=='W')std::cout<<"，编剧请按下W";
        if(A[i]=='O')std::cout<<"，上映日期请按下O";
        if(A[i]=='R')std::cout<<"，评分请按下R";
        if(A[i]=='B')std::cout<<"，票房请按下B";
        if(A[i]=='S')std::cout<<"，主演请按下S";
        if(A[i]=='K')std::cout<<"，电影类型请按下K";
        if(A[i]=='C')std::cout<<"，评论请按下C";
        if(A[i]=='T')std::cout<<"，时长请按下T";
    }

    std::cout<<"\n";
    std::cin>>Info;
    for(int k=0;k<Info.length();k++)
    {	int flag=0;
        for(int i=0;i<strlen(A);i++)
            if(A[i]==Info[k])
                flag=1,i=strlen(A);
        if(flag)
        {	if(Info[k]=='A')
            {
                for(int j = 0;j<strlen(A);j++)
                {
                    if(A[j]=='D')search_type.push_back("导演");
                    if(A[j]=='W')search_type.push_back("编剧");
                    if(A[j]=='O')search_type.push_back("上映日期");
                    if(A[j]=='R')search_type.push_back("评分");
                    if(A[j]=='B')search_type.push_back("票房");
                    if(A[j]=='S')search_type.push_back("主演");
                    if(A[j]=='K')search_type.push_back("类型");
                    if(A[j]=='C')search_type.push_back("评论");
                    if(A[j]=='T')search_type.push_back("时长");
                }
                break;
            }
            if(Info[k]=='D')search_type.push_back("导演");
            if(Info[k]=='W')search_type.push_back("编剧");
            if(Info[k]=='O')search_type.push_back("上映日期");
            if(Info[k]=='R')search_type.push_back("评分");
            if(Info[k]=='B')search_type.push_back("票房");
            if(Info[k]=='S')search_type.push_back("主演");
            if(Info[k]=='K')search_type.push_back("类型");
            if(Info[k]=='C')search_type.push_back("评论");
            if(Info[k]=='T')search_type.push_back("时长");
        }
    }
    std::cout << "请输入您当前文件保存的路径,如：/Users/kingjames/Desktop/oopproject"<<std::endl;
    std::cin >> path;
    std::cout << "正在为您爬取信息，请通过Qt查看数据库中的信息"<<std::endl;
}

Parser::Parser()
{
    spider_type = "";
    web_name = "";
    path = "";
}
std::string Parser::get_spidertype()
{
    return spider_type;
}

std::string Parser::get_webname()
{
    return web_name;
}
std::vector<std::string> Parser::get_type()
{
    return search_type;
}

