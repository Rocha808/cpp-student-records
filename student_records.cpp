#include <iostream>
#include <string>
#include <cctype> // For toupper
#include <iomanip> // For fixed and setprecision

using namespace std;

// Namespace including helper functions
namespace StudentUtils {
    void formatName(string& name);
    void displayGradeLevel(int gradeLevel);
    void displayStudentInfo(const string& name, int gradeLevel, double gpa);
}

// To simplify the access of all namespace members
using namespace StudentUtils;

// Enumeration to define grade levels
enum Grade {FRESHMAN = 1, SOPHOMORE, JUNIOR, SENIOR};

int main() {
    
    //Declare variables used in main
    string name;
    int gradeLevel;
    double gpa;

    // Prompt the user for their name
    cout << "Enter student name: ";
    // To get all name character, including whitespaces
    getline(cin, name);
    cout << endl;

    // Prompt user for their grade level
    cout << "Enter grade level (1 = Freshman, 2 = Sophomore, 3 = Junior, 4 = Senior): ";
    cin >> gradeLevel;
    cout << endl;

    // Prompt the user for their GPA
    cout << "Enter GPA: ";
    cin >> gpa;
    cout << endl;

    // Call to displayStudentInfo function
    displayStudentInfo(name, gradeLevel, gpa);

    return 0;
}

// Definitions of the helper functions used from the StudentUtils namespace
namespace StudentUtils {

    // Function to capitalize each character in name
    void formatName(string& name) {
        for (int x = 0; x < name.length(); x++) {
            name[x] = toupper(name[x]);
        }
    }
    
    // Function to indirectly output enum
    void displayGradeLevel(int gradeLevel) {
        switch(gradeLevel) {
            case FRESHMAN:
                cout << "Freshman" << endl;
                break;
            case SOPHOMORE:
                cout << "Sophomore" << endl;
                break;
            case JUNIOR:
                cout << "Junior" << endl;
                break;
            case SENIOR:
                cout << "Senior" << endl;
                break;
            default:
                // Grade level validation
                cout << "Invalid grade level." << endl;
        }
    }
    
    // This function outputs name, grade level, and gpa
    void displayStudentInfo(const string& name, int gradeLevel, double gpa) {
        string formattedName = name;
        // Call to formatName function
        formatName(formattedName);

        cout << "Student Record:\n";
        cout << "Name: " << formattedName << endl;
        cout << "Grade Level: ";
        // Call to displayGradeLevel function
        displayGradeLevel(gradeLevel);
        // GPA validation
        if (gpa < 0 || gpa > 4) {
            cout << "Invalid GPA.";
        } else
            // Format GPA to two decimal places
            cout << "GPA: " << fixed << setprecision(2) << gpa << endl; 
    }
}
