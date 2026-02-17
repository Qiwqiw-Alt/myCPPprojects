#include <iostream>
#include <string>
#include <format>
#include  <vector>

using namespace std;

int main() {
    int currentSemester;
    int numberOfCourses;

    // Input the student's semester
    cout << "\n=== CGPA Calculator === \n";
    cout << "Current semester: ";
    cin >> currentSemester;

    // Input the student's number of courses on every semester
    cout << format("\nEnter number of courses for semester {}: ", currentSemester);
    cin >> numberOfCourses;


    // Input the courses name, courses credit, and courses grade on every semester
    vector <string> courseNames(numberOfCourses);
    vector <int> courseCredits(numberOfCourses);
    vector <double> courseGrades(numberOfCourses);

    double totalGrades = 0;
    int totalCredits = 0;


    for (int i = 0; i < numberOfCourses; i++) {
        cout << format("\n --- Course #{} ---\n", i + 1);
        cout << "Course name: "; cin.ignore();  getline(cin, courseNames[i]);
        cout << "Course credit: "; cin >> courseCredits[i];
        cout << "Course grade: "; cin >> courseGrades[i];

        totalGrades += courseGrades[i];
        totalCredits += courseCredits[i];
    }

    double gpa = (totalCredits > 0) ? (totalGrades / courseNames.capacity()) : 0;
    string header = format(
         "\n================================================================\n"
         "Semester: {} | Total Credits: {} | GPA: {:.2f}\n"
         "================================================================",
         currentSemester, totalCredits, gpa
     );
    cout << header << endl;

    for (int i = 0; i < numberOfCourses; i++) {
        cout << format("{}. {:<20} | Credit: {} | Grade: {:.2f}\n",
                       i + 1, courseNames[i], courseCredits[i], courseGrades[i]);
    }

    cout << "================================================================" << endl;

    return 0;
}