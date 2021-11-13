#include "connection.h"

#include <iostream>

// 初始化数据库连接
Connection::Connection()
{
    _conn = mysql_init(nullptr);
}

// 释放数据库连接资源
Connection::~Connection()
{
    if (_conn != nullptr)
    {
        mysql_close(_conn);
    }
}

// 连接数据库
bool Connection::connect(std::string ip,
                         unsigned short port,
                         std::string username,
                         std::string password,
                         std::string dbname)
{
    // 连接数据库
    MYSQL *p = mysql_real_connect(_conn, ip.c_str(), username.c_str(),
                                  password.c_str(), dbname.c_str(), port, nullptr, 0);
    return p != nullptr;
}

// 更新操作 insert/delete/update
bool Connection::update(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        // TODO LOG
        std::cout << "更新失败:" << sql << std::endl;
        return false;
    }
    return true;
}

// 查询操作 select
MYSQL_RES *Connection::query(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
    {
        // TODO LOG
        std::cout << "查询失败:" << sql << std::endl;
        return nullptr;
    }
    return mysql_use_result(_conn);
}
