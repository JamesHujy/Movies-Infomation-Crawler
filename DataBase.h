//
// Created by 胡小赖 on 2018/6/29.
//

#ifndef OOPPROJECT_DATABASE_H
#define OOPPROJECT_DATABASE_H

#include "cstdlib"
#include <sqlite3.h>
#include <fstream>
#include <iostream>
#include "Parser.h"
#include "baseObject.h"

class baseObject;

class DataBase {
public:
    void useDatabase(Parser &parser);
    void insertData(baseObject *object, int index, Parser &parser);
    explicit DataBase(Parser& parser);

private:
    static sqlite3 *db;
    static int rc;
    static char *zErrMsg;
    bool IsTableExist(const std::string& strTableName);
    void openDatabase(Parser &parser);
    void deleteTable(std::string table_name);
    std::string solve_str(std::string str);   //solve the syntax error brought by "'"
    void createTable(Parser &parser);
    static int callback(void *NotUsed, int argc, char **argv, char **azColName);
};

#endif //OOPPROJECT_DATABASE_H
