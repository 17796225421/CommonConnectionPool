#include "connection.h"

#include <iostream>

int main(){
    Connection conn;
    if(conn.connect("127.0.0.1",3306,"root","123456","connpool")){
        std::cout<<"connection success!"<<std::endl;
    }
}