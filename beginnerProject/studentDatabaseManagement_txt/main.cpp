#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <format>
#include <cstdlib>
using namespace std;

struct Student {
    string id;
    string name;
    string major;
    int age;
    double GPA;
};

vector<Student> students;

void initialDisplay();
void showAllStudents();
void addStudent(); // Create
void showStudentDetail(); // Read
void updateStudentDetail(); // Update
void removeStudent(); // Delete
void readData();
void writeData();
void writeDataAppend(const string& id, const string& name,const string& major, int age, double GPA);
string idGenerator();

int main() {
    readData();

    initialDisplay();

    return 0;
}

void initialDisplay() {
    int choice = -1;

    do {
        showAllStudents();
        cout << "\n=========== Welcome to Student Database Management ============\n";
        cout << "(1) Add new student" << endl;
        cout << "(2) Show Student Details" << endl;
        cout << "(3) Update Student Details" << endl;
        cout << "(4) Remove Student" << endl;
        cout << "(0) Exit" << endl;
        cout << "Enter your choice: "; cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: showStudentDetail(); break;
            case 3: updateStudentDetail(); break;
            case 4: removeStudent(); break;
            case 0: cout << "Exiting..." << endl; break;
            default: cout << "Please select the available choice!"; break;
        }
    } while (choice != 0);
}

void showAllStudents() {
    cout << "======================== Students List ========================\n";
    for (int i = 0; i < students.size(); i++) {
        cout << format("{}. {:<6} | {:<20} | {:<15} | {:.3f}\n", i + 1,
            students[i].id, students[i].name, students[i].major, students[i].GPA);
    }
    cout << "===============================================================" << endl;
}

void addStudent() {
    string name, major;
    int age;
    double GPA;

    char addAnotherStudent;

    do {
        string id = idGenerator();
        cout << "\n==================== Add new student menu =====================\n";
        cout << "Enter student name: "; getline(cin >> ws, name);
        cout << "Enter student major: "; getline(cin >> ws, major);
        do {
            cout << "Enter student age: "; cin >> age;
            if (age < 1) {
                cout << "Please enter the positive number!" << endl;
            }
        } while (age < 1);
        do {
            cout << "Enter student GPA: "; cin >> GPA;
            if (GPA < 1) {
                cout << "Please enter the positive number!" << endl;
            } else if (GPA > 4) {
                cout << "Please enter number between 1 and 4!" << endl;
            }
        } while (GPA < 1 && GPA > 4);

        students.push_back({id, name, major, age, GPA});
        writeDataAppend(id, name, major, age, GPA);

        cout << "Want to add another student? (y/n): "; cin >> addAnotherStudent;
    } while (addAnotherStudent == 'y' || addAnotherStudent == 'Y');
}

void showStudentDetail() {
    int maxStudent = students.size();
    int studentSerialNumber = -1;

    char showAnotherStudent;

    do {

        cout << "\n================== Show student detail menu ===================\n";
        showAllStudents();
        do {
            cout << "Enter the student serial number:"; cin >> studentSerialNumber;
            if (studentSerialNumber - 1 < 0 || studentSerialNumber - 1 > maxStudent - 1) {
                cout << "Please enter valid student serial number!" << endl;
            } else {
                const Student& stSelected = students[studentSerialNumber - 1];
                cout << "(1) Name: " << stSelected.name << endl;
                cout << "(2) Major: " << stSelected.major << endl;
                cout << "(3) Age  : " << stSelected.age << endl;
                cout << "(4) GPA  : " << stSelected.GPA << endl;
            }

            cout << "Want to see another student detail? (y/n): "; cin >> showAnotherStudent;
        } while (studentSerialNumber - 1 < 0 || studentSerialNumber - 1 > maxStudent - 1);
    } while (showAnotherStudent == 'y' || showAnotherStudent == 'Y');
}

void updateStudentDetail() {
    const int maxStudent = students.size();
    int studentSerialNumber = -1;
    int detailNumber = -1;

    char updateAnotherStudent;

    do {
        cout << "\n================== Update student detail menu =================\n";
        showAllStudents();
        do {
            cout << "Enter the student serial number:"; cin >> studentSerialNumber;
            if (studentSerialNumber - 1 < 0 || studentSerialNumber - 1 > maxStudent - 1) {
                cout << "Please enter valid student serial number!" << endl;
            } else {
                Student &stSelected = students[studentSerialNumber - 1];
                cout << "(1) Name: " << stSelected.name << endl;
                cout << "(2) Major: " << stSelected.major << endl;
                cout << "(3) Age  : " << stSelected.age << endl;
                cout << "(4) GPA  : " << stSelected.GPA << endl;
                cout << "(0) Cancel" << endl;
                do {
                    cout << "Enter the detail you want to change: "; cin >> detailNumber;

                    switch (detailNumber) {
                        case 0:
                            return;
                        case 1:
                            cout << "Enter new name: "; getline(cin >> ws, stSelected.name);
                            writeData();
                            break;
                        case 2:
                            cout << "Enter new major: "; getline(cin >> ws, stSelected.major);
                            writeData();
                            break;
                        case 3:
                            cout << "Enter new age: "; cin >> stSelected.age;
                            writeData();
                            break;
                        case 4:
                            cout << "Enter new GPA: "; cin >> stSelected.GPA;
                            writeData();
                            break;
                        default:
                            cout << "Please select the correct detail number!";
                            break;
                    }
                } while (detailNumber < 0 || detailNumber > 4);
            }

            cout << "Want to update another student detail? (y/n): "; cin >> updateAnotherStudent;
        } while (studentSerialNumber - 1 < 0 || studentSerialNumber - 1 > maxStudent - 1);
    } while (updateAnotherStudent == 'y' || updateAnotherStudent == 'Y');
}

void removeStudent() {
    int maxStudent = students.size();
    int studentSerialNumber = -1;

    char removeAnotherStudent;

    do {
        cout << "\n==================== Remove student  menu =====================\n";
        showAllStudents();
        do {
            cout << "Enter the student serial number:"; cin >> studentSerialNumber;
            if (studentSerialNumber - 1 < 0 || studentSerialNumber - 1 > maxStudent - 1) {
                cout << "Please enter valid student serial number!" << endl;
            } else {
                cout << format("Student with id {} removed", students[studentSerialNumber - 1].id) << endl;;
                students.erase(students.begin() + studentSerialNumber - 1);
                writeData();
            }

            cout << "Want to remove another student? (y/n): "; cin >> removeAnotherStudent;
        } while (studentSerialNumber - 1 < 0 || studentSerialNumber - 1 > maxStudent - 1);
    } while (removeAnotherStudent == 'y' || removeAnotherStudent == 'Y');
}

void readData() {
    students.clear();

    if (ifstream myFile("students.txt"); myFile.is_open()) {
        string line, tempAge, tempGPA;
        while (getline(myFile, line)) {
            stringstream ss(line);
            Student st;

            getline(ss, st.id, '|');
            getline(ss, st.name, '|');
            getline(ss, st.major, '|');
            getline(ss, tempAge, '|');
            getline(ss, tempGPA);

            st.age = stoi(tempAge);
            st.GPA = stod(tempGPA);

            students.push_back(st);
        }
        myFile.close();
    }
}

void writeData() {
    if (ofstream myFile("students.txt"); myFile.is_open()) {
        for (auto &[id, name, major, age, GPA] : students) {
            myFile << id << "|" << name << "|" << major << "|" << age << "|" << GPA << "\n";
        }
        myFile.close();
    }
}

void writeDataAppend(const string& id, const string& name,const string& major, const int age, const double GPA) {
    if (ofstream myFile("students.txt", ios::app); myFile.is_open()) {
        myFile << id << "|" << name << "|" << major << "|" << age << "|" << GPA << "\n";
        myFile.close();
    }
}

string idGenerator() {
    int max = 0;
    for (const Student& st: students) {
        try {
            string idStr = st.id.substr(2);
            if (int num = stoi(idStr); num > max) {
                max = num;
            }
        } catch (exception e) {
            cout << e.what() << endl;
        }
    }

    return format("ST{:03}", max + 1);
}