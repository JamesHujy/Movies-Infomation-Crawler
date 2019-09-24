//
// Created by 胡小赖 on 2018/6/29.
//

#include "DataBase.h"
#include <cstdio>


sqlite3* DataBase::db = nullptr;
int DataBase::rc = 0;
char* DataBase::zErrMsg = nullptr;

int DataBase::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i=0; i<argc; i++){
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
void DataBase::openDatabase(Parser& parser)
{
    std::string temp_str = parser.get_spidertype()+".db";
    const char* temp = temp_str.c_str();
    rc = sqlite3_open(temp, &db);
    if( rc ){
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }else{
        fprintf(stderr, "Opened database successfully\n");
    }
}

DataBase::DataBase(Parser& parser)
{
    useDatabase(parser);
}

void DataBase::deleteTable(std::string table_name)
{
    std::string deletetabletemp ="Drop table "+table_name;
    const char *deletetable = deletetabletemp.c_str();
    rc = sqlite3_exec(db, deletetable, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        
    }
}

static int callback(void *NotUsed,int argc, char **argv, char **azColName){
    int i;
    for(i=0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}


void DataBase::createTable(Parser& parser)
{
    std::string str_sqlcreate = "CREATE TABLE "+parser.get_webname()+"(ID INT PRIMARY KEY NOT NULL,";
    std::vector<std::string> info_type = parser.get_type();
    size_t len = info_type.size();

    for(int i = 0;i < len;i++)
    {
        if(i!=len-1)
        {
            str_sqlcreate += info_type[i];
            str_sqlcreate += " TEXT,";
        }
        else
        {
            str_sqlcreate += info_type[i];
            str_sqlcreate += " TEXT );";
        }
    }
//std::cout << str_sqlcreate <<std::endl;
    const char *sqlcreate = str_sqlcreate.c_str();
    rc = sqlite3_exec(db, sqlcreate, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Table create successfully\n");
    }
}

void DataBase::insertData(baseObject* object,int index,Parser& parser)
{

    std::string sqltemp = "INSERT INTO " +   parser.get_webname() + "(ID,";
    sqltemp+=parser.get_spidertype()+",";

    size_t len = object->Datalist.size();
    for(int i = 0;i < len;i++)
    {
        sqltemp += object->Datalist[i]->gettype();
        if(i != len - 1) sqltemp += ",";
    }
    sqltemp += ")VALUES ("+std::to_string(index)+", '"+solve_str(object->getname())+"','";
    for(int i = 0;i < len;i++)
    {
        sqltemp += solve_str(object->Datalist[i]->getvalue());
        if(i != len - 1) sqltemp += "', '";
    }
    sqltemp +="');";
    const char *sql = sqltemp.c_str();
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }else{
        fprintf(stdout, "Records created successfully\n");
    }
}

void DataBase::useDatabase(Parser& parser)
{

    openDatabase(parser);
    if(!IsTableExist(parser.get_webname())) createTable(parser);

}

bool DataBase::IsTableExist(const std::string& strTableName)
{
    std::string strFindTable = "SELECT COUNT(*) FROM sqlite_master where type ='table' and name ='" + strTableName + "'";

    char* sErrMsg = nullptr;

    int nTableNums = 0;
    if (sqlite3_exec(db, strFindTable.c_str(), &callback, &nTableNums, &sErrMsg) != SQLITE_OK)
    {
        return false;
    }
    //回调函数无返回值，则此处第一次时返回SQLITE_OK， 第n次会返回SQLITE_ABORT

    return nTableNums > 0;
}

std::string DataBase::solve_str(std::string str)
{
    std::string ans;
    size_t len = str.length();
    for(int i = 0; i < len;i++)
    {
        if(str[i]=='\'') ans+="''";
        else ans+=str[i];
    }
    return ans;
}