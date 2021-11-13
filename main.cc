#include "connection.h"

#include <iostream>

int main()
{
    Connection conn;
    conn.connect("127.0.0.1", 3306, "root", "123456", "connpool");

    char sql[1024] = {0};
    sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
            "zhang san", 20, "male");
    conn.update(sql);
}