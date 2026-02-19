#include "Student.h"

#include <utility>
#include <string>
using namespace std;

Student::Student() {
    this->id = "unknown";
    this->name = "unknown";
    this->email = "unknown";
    this->major = "unknown";
    this->age = 0;
    this->gpa = 0;
}

Student::Student(string id, string name, string email, string major, int age, double gpa) {
    this->id = std::move(id);
    this->name = std::move(name);
    this->email = std::move(email);
    this->major = std::move(major);
    this->age = age;
    this->gpa = gpa;
}

void Student::setId(const string& id) { this->id = id; }
void Student::setName(const string& name) { this->name = name; }
void Student::setEmail(const string& email) { this->email = email; }
void Student::setMajor(const string& major) { this->major = major; }
void Student::setAge(int age) { this->age = age; }
void Student::setGPA(double gpa) { this->gpa = gpa; }

string Student::getId() const { return this->id; }
string Student::getName() const { return this->name; }
string Student::getEmail() const { return this->email; }
string Student::getMajor() const { return this->major; }
int Student::getAge() const { return this->age; }
double Student::getGPA() const { return this->gpa; }
