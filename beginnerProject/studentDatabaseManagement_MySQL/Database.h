//
// Created by lenovo on 19/02/2026.
//

#ifndef STUDENTDATABASEMANAGEMENT_MYSQL__DATABASE_H
#define STUDENTDATABASEMANAGEMENT_MYSQL__DATABASE_H
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/statement.h>
#include <jdbc/cppconn/prepared_statement.h>
#include <jdbc/cppconn/resultset.h>

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