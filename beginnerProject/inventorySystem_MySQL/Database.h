//
// Created by lenovo on 20/02/2026.
//

#ifndef INVENTORYSYSTEM_MYSQL_DATABASE_H
#define INVENTORYSYSTEM_MYSQL_DATABASE_H
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>

class Database {
protected:
    sql::Connection *conn;
public:
    Database();
    virtual ~Database();
    [[nodiscard]] bool isConnected() const;
    [[nodiscard]] sql::Connection *getConnection() const;
};


#endif //INVENTORYSYSTEM_MYSQL_DATABASE_H