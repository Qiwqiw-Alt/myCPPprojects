#include "Database.h"
#include <iostream>

using namespace std;

Database::Database() {
    try {
        sql::mysql::MySQL_Driver *driver = sql::mysql::get_driver_instance();
        conn = driver->connect("tcp://127.0.0.1:3306", "root", "");
        conn->setSchema("db_college_student"); // DB name
        cout << "Connection to database successfully created." << endl;
    } catch (sql::SQLException &e) {
        cerr << "Connection to database failed: " << e.what() << endl;
        conn = nullptr;
    }
}

Database::~Database() {
    if (conn != nullptr) {
        delete conn;
    }
}

bool Database::isConnected() const { return conn != nullptr; }

sql::Connection* Database::getConnection() const {return conn;}