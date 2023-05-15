#include <iostream>
#include <vector>
#include <algorithm>
#include <mysqlx/xdevapi.h>
#include <mysqlx/xapi.h>
#include <mysql/jdbc.h>
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>

int main(){
    std::vector<int> testVector;
    for(int i = 0; i < 10; i++)testVector.push_back(i);
    std::cout<<testVector.size();
    sql::mysql::MySQL_Driver *driver;
sql::Connection *con;
sql::Statement *stmt;

driver = sql::mysql::get_mysql_driver_instance();
con = driver->connect("localhost", "root", "mikolaj");

    return 0;
}
