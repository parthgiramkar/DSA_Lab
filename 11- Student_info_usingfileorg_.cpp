#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Student {
    string rollNumber;
    string name;
    string division;
    string address;
};

void displayStudents(const string &filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No records found.\n";
        return;
    }

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s1;
        getline(ss, s1.rollNumber, ',');
        getline(ss, s1.name, ',');
        getline(ss, s1.division, ',');
        getline(ss, s1.address, ',');

        cout << "Roll Number: " << s1.rollNumber << "\n";
        cout << "Name: " << s1.name << "\n";
        cout << "Division: " << s1.division << "\n";
        cout << "Address: " << s1.address << "\n";
    }
    file.close();
}

void addStudent(const string &filename) {
    ofstream file(filename, ios::app);
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return;
    }

    Student s1;
    cout << "Enter roll number: ";
    cin >> s1.rollNumber;
    cin.ignore(); // Clear input buffer
    cout << "Enter name: ";
    getline(cin, s1.name);
    cout << "Enter division: ";
    getline(cin, s1.division);
    cout << "Enter address: ";
    getline(cin, s1.address);

    file << s1.rollNumber << "," << s1.name << "," << s1.division << "," << s1.address << "\n";
    cout << "Student with roll number " << s1.rollNumber << " added successfully!\n";
    file.close();
}

void deleteStudent(const string &filename) {
    string rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No records found.\n";
        return;
    }

    ofstream tempFile("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        string currentRollNumber;
        getline(ss, currentRollNumber, ',');

        if (currentRollNumber == rollNumber) {
            found = true;
            continue; // Skip this line
        }
        tempFile << line << "\n";
    }

    file.close();
    tempFile.close();

    if (found) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Student with roll number " << rollNumber << " deleted successfully!\n";
    } else {
        cout << "Student with roll number " << rollNumber << " not found.\n";
    }
}

void displayStudent(const string &filename) {
    string rollNumber;
    cout << "Enter roll number to display: ";
    cin >> rollNumber;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No records found.\n";
        return;
    }

    string line;
    bool found = false;

    while (getline(file, line)) {
        stringstream ss(line);
        Student s1;
        getline(ss, s1.rollNumber, ',');
        getline(ss, s1.name, ',');
        getline(ss, s1.division, ',');
        getline(ss, s1.address, ',');

        if (s1.rollNumber == rollNumber) {
            found = true;
            cout << "Roll Number: " << s1.rollNumber << "\n";
            cout << "Name: " << s1.name << "\n";
            cout << "Division: " << s1.division << "\n";
            cout << "Address: " << s1.address << "\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNumber << " not found.\n";
    }

    file.close();
}

int main() {
    string fileName = "student.txt";
    while (true) {
        cout << "\n Student Information System \n";
        cout << "1. Add student\n";
        cout << "2. Delete student\n";
        cout << "3. Display all students\n";
        cout << "4. Display particular student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent(fileName);
                break;
            case 2:
                deleteStudent(fileName);
                break;
            case 3:
                displayStudents(fileName);
                break;
            case 4:
                displayStudent(fileName);
                break;
            case 5:
                cout << "Exiting system...\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
