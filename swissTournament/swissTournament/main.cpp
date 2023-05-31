#include <stdlib.h>
#include <iostream>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
#include "football.cpp"

const std::string server = "tcp://127.0.0.1:3306";
const std::string username = "root";
const std::string password = "mikolaj";

sql::Driver* driver = get_driver_instance();
sql::Connection* con = driver->connect(server, username, password);
sql::Statement* stmt = con->createStatement();;
sql::ResultSet* res;

int main()
{
    std::setlocale(LC_ALL, "pl.utf-8");

    //connect to football database
    con->setSchema("football");

    //initialize the list of participants
    std::vector<Football> teams;
    res = stmt->executeQuery("SELECT name, strength_estimate, elo FROM countries ORDER BY 3 DESC");
    while (res->next()) {
        teams.push_back(Football(res->getString(1), res->getInt(2), res->getDouble(3)));
    }
    system("pause");
    return 0;
}