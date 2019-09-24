//
// Created by 胡小赖 on 2018/6/11.
//

#include "baseSpider.h"
#include "TVOperaFactory.h"
#include "MovieFactory.h"
baseSpider::baseSpider() {}


baseSpider::baseSpider(std::string a,std::string b):url(a),filepath(b)
{
    html = new char [200000];
}
void baseSpider::Downloadhtml()
{
    const char *Website = url.data();
    FILE *fp;
    if ((fp = fopen(filepath.c_str(), "w")) == NULL)
    {
        std::cerr  << "fail to open the file";
    exit(0);
    }
    CURL *curl = nullptr;
    CURLcode res;
    curl = curl_easy_init();
    if (curl != nullptr)
    {
        curl_easy_setopt(curl, CURLOPT_URL, Website);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_HEADERDATA, fp);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        /* Perform the request, res will get the return code */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK) {
            std::cout << curl_easy_strerror(res);
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        /* always cleanup */
        curl_easy_cleanup(curl);
        fclose(fp);
    }
}

bool baseSpider::check(char ch,std::string&s,int&pt)
{
    int N=s.length();
    bool tmp=false;
    if(s[pt]=='~')
    {	if(++pt>=N)return false;
        if(s[pt]=='?')tmp=true;
        else if(s[pt]=='|')for(pt=pt-1;pt+2<N&&s[pt+1]=='|';pt+=2)tmp|=ch==s[pt+2];
        else if(s[pt]=='N')tmp=ch>='0'&&ch<='9';
    }
    else tmp=ch==s[pt];
    pt++;
    return tmp;
}

int baseSpider::check_string(char*File,int L,std::string&s,int pt1,int pt2,int pt3)
{	int tmp_pt1=pt1;
    for(;pt1<L&&pt2<pt3;pt1++)
        if(!check(File[pt1],s,pt2))
            return false;
    return pt1<L ? pt1-tmp_pt1:0;
}
void baseSpider::readhtml()
{
    std::ifstream in(filepath);
    std::string temp ;
    std::string str_html = "";
    while(!in.eof())
    {
        getline(in,temp);
        str_html += temp;
    }
    html = (char*)str_html.data();
}

std::string baseSpider::Match(char*File,std::string s)
{
    std::string answer="";
    int L=strlen(File),N=s.length(),pt0=0,lines=-1;
    File[L++]='`',File[L]='\0';
    if(s[0]=='~'&&s[1]=='%')
    {	lines=0;
        for(pt0=2;pt0+1<N&&(s[pt0]!='~'||s[pt0+1]!='%');pt0++)
            lines=lines*10+s[pt0]-48;
        s.erase(0,pt0+2);
        pt0=0;
    }
    while(pt0<N)
    {	if(s[pt0]=='`')
        {	int pt1=pt0+1,pt2;
            while(pt1<N&&s[pt1]!='`')pt1++;
            pt2=pt1+1;
            while(pt2<N&&s[pt2]!='`')pt2++;
            int num=0;
            for(int i=pt1+1;i<pt2;i++)num=num*10+s[i]-48;
            for(int i=1;i<=num;i++)s.insert(pt2+1,s,pt0+1,pt1-pt0-1);
            s.erase(pt0,pt2-pt0+1);
            N+=num*(pt1-pt0-1)-(pt2-pt0+1);
        }
        pt0++;
    }
    for(int i=0;i<L;i++)
    {	std::string result;
        int pt1=i,pt2=0,N=s.length(),lr=0;
        bool copy=false,flag=true;
        while(pt1<L&&pt2<N)
        {	if(s[pt2]=='~'&&pt2+1<N&&s[pt2+1]=='@')copy=true,pt2+=2;
            else if(s[pt2]=='~'&&pt2+1<N&&s[pt2+1]=='!')copy=false,pt2+=2;
            else if(s[pt2]=='~'&&pt2+1<N&&s[pt2+1]=='L')result.erase(--lr,1),pt2+=2;
            else if(s[pt2]=='~'&&pt2+1<N&&s[pt2+1]=='~')
            {	for(pt2+=2;pt2+1<N&&(s[pt2]!='~'||s[pt2+1]!='~');pt2++)
                    result.insert(lr++,1,s[pt2]);
                pt2+=2;
            }
            else if(s[pt2]=='~'&&pt2+1<N&&s[pt2+1]=='*')
            {	pt2+=2;
                if(pt2>=N)
                {	flag=false;
                    break;
                }
                bool tmp=true;
                if(pt2+1<N&&s[pt2]=='~'&&s[pt2+1]=='!')
                {	tmp=false;
                    pt2+=2;
                }
                int pt3=pt2,pt4=pt2;
                while(pt3+1<N)
                {	if(s[pt3]=='~'&&s[pt3+1]=='*')
                    {	pt4=pt3;
                        pt3=pt2;
                        break;
                    }
                    else if(s[pt3]=='~'&&s[pt3+1]=='/')
                    {	for(pt4=pt3+=2;pt4+1<N;pt4++)if(s[pt4]=='~'&&s[pt4+1]=='*')break;
                        break;
                    }
                    pt3++;
                }
                int tmp_pt1=pt1,tmp2_pt1;
                for(;tmp_pt1<L;tmp_pt1++)
                    if(check_string(File,L,s,tmp_pt1,pt3,pt4))
                        break;
                tmp2_pt1=tmp_pt1;
                tmp_pt1+=check_string(File,L,s,tmp_pt1,pt3,pt4);
                if(tmp_pt1>=L)
                {	flag=false;
                    break;
                }
                for(;pt1<tmp_pt1;pt1++)
                {	int tmp_len=0;
                    if(pt2!=pt3)pt1+=tmp_len=check_string(File,L,s,pt1,pt2,pt3-2);
                    if(pt1-tmp_len-1<tmp2_pt1&&pt1>=tmp2_pt1&&!tmp)copy=false;
                    if(pt1<L&&copy)
                    {   if (!tmp_len)result.insert(lr++, 1, File[pt1]);
                        else pt1--;
                    }
                }
                pt2=pt4+2;
            }
            else
            {	if(check(File[pt1],s,pt2))
                {	if(copy)result.insert(lr++,1,File[pt1]);
                    pt1++;
                    continue;
                }
                else
                {	flag=false;
                    break;
                }
            }
        }
        if(flag&&pt2==N)answer=answer+result+",",lines--;
        if(lines==0)break;
    }
    if(answer.length()>0)answer.erase(answer.length()-1,1);
    if(answer=="")answer="No found";
    return answer;
}

void baseSpider::change_filepath(std::string Des_filepath)
{
    filepath = Des_filepath;
}

void baseSpider::change_url(std::string Des_url)
{
    url = Des_url;
}

void baseSpider::analyse_info(Parser& parser,DataBase& dataBase,Control& control)
{
    change_match_symbol();
    std::vector<std::string> temp = parser.get_type();
    size_t len = parser.get_type().size();
    info.resize(15);

    for(int i = 0;i<len;i++)
    {
        info[i] = Match(html,match_symbol[temp[i]]);
        info.push_back(Match(html,match_symbol[temp[i]]));
    }


    Factory->createProduct(temp,info,parser,dataBase,control);
}
std::string baseSpider::GetURL(){
    return "";
}
void baseSpider::change_type(std::string _type) {
    type = _type;
}


//暂且提供一个默认实现
void baseSpider::change_match_symbol() {}
void baseSpider::create_factory(){
    if(type=="电影") Factory = new MovieFactory;
    if(type=="电视剧") Factory = new TVOperaFactory;
}