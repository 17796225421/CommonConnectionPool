#include "connection.h"
#include "connectionpool.h"

#include <iostream>

int main()
{
    Connection conn;
    conn.connect("127.0.0.1", 3306, "root", "123456", "chat");

    /*Connection conn;
	char sql[1024] = { 0 };
	sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
		"zhang san", 20, "male");
	conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
	conn.update(sql);*/

    clock_t begin = clock();

    std::thread t1([]()
              {
                  //ConnectionPool *cp = ConnectionPool::getConnectionPool();
                  for (int i = 0; i < 2500; ++i)
                  {
                      /*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
                      Connection conn;
                      char sql[1024] = {0};
                      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                              "zhang san", 20, "male");
                      conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
                      conn.update(sql);
                  }
              });
    std::thread t2([]()
              {
                  //ConnectionPool *cp = ConnectionPool::getConnectionPool();
                  for (int i = 0; i < 2500; ++i)
                  {
                      /*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
                      Connection conn;
                      char sql[1024] = {0};
                      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                              "zhang san", 20, "male");
                      conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
                      conn.update(sql);
                  }
              });
    std::thread t3([]()
              {
                  //ConnectionPool *cp = ConnectionPool::getConnectionPool();
                  for (int i = 0; i < 2500; ++i)
                  {
                      /*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
                      Connection conn;
                      char sql[1024] = {0};
                      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                              "zhang san", 20, "male");
                      conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
                      conn.update(sql);
                  }
              });
    std::thread t4([]()
              {
                  //ConnectionPool *cp = ConnectionPool::getConnectionPool();
                  for (int i = 0; i < 2500; ++i)
                  {
                      /*char sql[1024] = { 0 };
			sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
				"zhang san", 20, "male");
			shared_ptr<Connection> sp = cp->getConnection();
			sp->update(sql);*/
                      Connection conn;
                      char sql[1024] = {0};
                      sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
                              "zhang san", 20, "male");
                      conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
                      conn.update(sql);
                  }
              });

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    clock_t end = clock();
    std::cout << (end - begin) << "ms" << std::endl;

#if 0
	for (int i = 0; i < 10000; ++i)
	{
		Connection conn;
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		conn.connect("127.0.0.1", 3306, "root", "123456", "chat");
		conn.update(sql);

		/*shared_ptr<Connection> sp = cp->getConnection();
		char sql[1024] = { 0 };
		sprintf(sql, "insert into user(name,age,sex) values('%s',%d,'%s')",
			"zhang san", 20, "male");
		sp->update(sql);*/
	}
#endif

    return 0;
}
