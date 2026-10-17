#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Structure to hold student details
struct Student {
    int rollNumber;
    string name;
    float mathMarks;
    float cppMarks;
    float percentage;
    char grade;
};

// Function to calculate Grade based on percentage
char calculateGrade(float perc) {
    if (perc >= 85) return 'A';
    if (perc >= 70) return 'B';
    if (perc >= 50) return 'C';
    return 'F';
}

int main() {
    int choice;

    do {
        cout << "\n=================================" << endl;
        cout << "   STUDENT REPORT CARD SYSTEM    " << endl;
        cout << "=================================" << endl;
        cout << "1. Add Student Record (Save to File)" << endl;
        cout << "2. Display All Report Cards" << endl;
        cout << "3. Exit Application" << endl;
        cout << "---------------------------------" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Student s;
            cout << "Enter Roll Number: ";
            cin >> s.rollNumber;
            cin.ignore();
            cout << "Enter Student Name: ";
            getline(cin, s.name);
            cout << "Enter Marks for Mathematics (out of 100): ";
            cin >> s.mathMarks;
            cout << "Enter Marks for C++ Programming (out of 100): ";
            cin >> s.cppMarks;

            // Calculations
            s.percentage = (s.mathMarks + s.cppMarks) / 2.0;
            s.grade = calculateGrade(s.percentage);

            // Open file in Append mode to add data without deleting old data
            ofstream outFile("students.txt", ios::app);
            if (outFile.is_open()) {
                outFile << s.rollNumber << "," << s.name << "," << s.mathMarks << "," 
                        << s.cppMarks << "," << s.percentage << "," << s.grade << "\n";
                outFile.close();
                cout << "\nRecord saved permanently to students.txt!" << endl;
            } else {
                cout << "\n Error: Could not open data file." << endl;
            }

        } else if (choice == 2) {
            ifstream inFile("students.txt");
            if (!inFile.is_open()) {
                cout << "\n No records found. Add a student record first!" << endl;
            } else {
                cout << "\n--- ALL STUDENT REPORT CARDS ---" << endl;
                string line;
                // Read the file line by line and print it
                while (getline(inFile, line)) {
                    cout << line << endl; 
                }
                inFile.close();
            }

        } else if (choice == 3) {
            cout << "\n Exiting Report Card System. Goodbye!" << endl;
        } else {
            cout << "\n Invalid choice! Please select 1, 2, or 3." << endl;
        }

    } while (choice != 3);

    return 0;
}