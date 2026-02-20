//
// Created by lenovo on 19/02/2026.
//

#ifndef STUDENTDATABASEMANAGEMENT_MYSQL__DATABASE_H
#define STUDENTDATABASEMANAGEMENT_MYSQL__DATABASE_H
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

#endif //STUDENTDATABASEMANAGEMENT_MYSQL__DATABASE_H