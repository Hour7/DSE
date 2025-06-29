#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, double> grades;

    // Add student names and grades
    grades["Dara"] = 85.5;
    grades["Sokha"] = 92.0;
    grades["Bopha"] = 78.5;

    // Update Dara's grade
    grades["Dara"] = 88.5;

    // Print all students and their grades
    for (auto student : grades) {
        cout << student.first << ": " << student.second << endl;
    }

    // Check if "Thida" exists
    if (grades.count("Thida")) {
        cout << "Thida exists.\n";
    } else {
        cout << "Thida does not exist.\n";
    }

    return 0;
}
