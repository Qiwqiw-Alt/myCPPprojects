//
// Created by lenovo on 19/02/2026.
//

#ifndef STUDENTDATABASEMANAGEMENT_MYSQL__STUDENT_H
#define STUDENTDATABASEMANAGEMENT_MYSQL__STUDENT_H
#include <string>

using namespace std;

class Student {
private:
    string id;
    string name;
    string email;
    string major;
    int age;
    double gpa;
public:
    Student();

    Student(string id, string name, string email, string major, int age, double gpa);

    void setId(const string& id);
    void setName(const string& name);
    void setEmail(const string& email);
    void setMajor(const string& major);
    void setAge(int age);
    void setGPA(double gpa);

    [[nodiscard]] string getId() const;
    [[nodiscard]] string getName() const;
    [[nodiscard]] string getEmail() const;
    [[nodiscard]] string getMajor() const;
    [[nodiscard]] int getAge() const;
    [[nodiscard]] double getGPA() const;
};


#endif //STUDENTDATABASEMANAGEMENT_MYSQL__STUDENT_H