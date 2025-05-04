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






















/*
getline() means “get the entire line” of text.
It is used to read input from a stream (like cin or stringstream) into a string.
You can also specify a delimiter — a character that tells where to stop reading (for example, a comma ,).

<sstream>?
It is a C++ header file.
It allows you to use the stringstream class.
stringstream lets you treat a string like a stream (just like cin or cout) — meaning you can read from or write to a string using >> or getline().
#include <iostream>: For input and output using cin and cout.

#include <fstream>: For reading from and writing to files.

#include <string>: Allows use of string type.

#include <sstream>: Used to parse strings (like splitting using ,).

using namespace std;: So we don’t have to write std:: every time (e.g., cout instead of std::cout).

Structure Definition
cpp
Copy
Edit
struct Student {
    string rollNumber;
    string name;
    string division;
    string address;
};
This defines a structure called Student that contains four fields: roll number, name, division, and address. It is used to store information about each student.

Display All Students Function
cpp
Copy
Edit
void displayStudents(const string &filename) {
    ifstream file(filename);
Opens the file for reading using an input file stream (ifstream).

filename is passed by reference.

cpp
Copy
Edit
    if (!file.is_open()) {
        cout << "No records found.\n";
        return;
    }
Checks if the file was opened successfully.

If not, prints a message and exits the function.

cpp
Copy
Edit
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student s1;
Reads the file line-by-line.

stringstream is used to split each line using ,.

A Student object s1 is declared.

cpp
Copy
Edit
        getline(ss, s1.rollNumber, ',');
        getline(ss, s1.name, ',');
        getline(ss, s1.division, ',');
        getline(ss, s1.address, ',');
Each field is extracted from the line using getline() with comma as the delimiter.

cpp
Copy
Edit
        cout << "Roll Number: " << s1.rollNumber << "\n";
        cout << "Name: " << s1.name << "\n";
        cout << "Division: " << s1.division << "\n";
        cout << "Address: " << s1.address << "\n";
    }
    file.close();
}
Displays the student details.

Closes the file after reading all records.

Add Student Function
cpp
Copy
Edit
void addStudent(const string &filename) {
    ofstream file(filename, ios::app);
Opens the file for writing in append mode using ofstream.

cpp
Copy
Edit
    if (!file.is_open()) {
        cout << "Error opening file.\n";
        return;
    }
If the file fails to open, display an error and exit.

cpp
Copy
Edit
    Student s1;
    cout << "Enter roll number: ";
    cin >> s1.rollNumber;
    cin.ignore();
Takes roll number input.

cin.ignore() clears the newline left in the buffer.

cpp
Copy
Edit
    cout << "Enter name: ";
    getline(cin, s1.name);
    cout << "Enter division: ";
    getline(cin, s1.division);
    cout << "Enter address: ";
    getline(cin, s1.address);
Takes multi-word input for name, division, and address.

cpp
Copy
Edit
    file << s1.rollNumber << "," << s1.name << "," << s1.division << "," << s1.address << "\n";
    cout << "Student with roll number " << s1.rollNumber << " added successfully!\n";
    file.close();
}
Appends the student data to the file in CSV format.

Closes the file.

Delete Student Function
cpp
Copy
Edit
void deleteStudent(const string &filename) {
    string rollNumber;
    cout << "Enter roll number to delete: ";
    cin >> rollNumber;
Asks for the roll number of the student to delete.

cpp
Copy
Edit
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No records found.\n";
        return;
    }
Opens the original file for reading.

cpp
Copy
Edit
    ofstream tempFile("temp.txt");
    string line;
    bool found = false;
Opens a temporary file to write updated data.

found flag keeps track if the student was found.

cpp
Copy
Edit
    while (getline(file, line)) {
        stringstream ss(line);
        string currentRollNumber;
        getline(ss, currentRollNumber, ',');
Reads each line and extracts the roll number.

cpp
Copy
Edit
        if (currentRollNumber == rollNumber) {
            found = true;
            continue;
        }
        tempFile << line << "\n";
    }
If roll number matches, skip writing that record.

Otherwise, write the line to the new file.

cpp
Copy
Edit
    file.close();
    tempFile.close();
Closes both files.

cpp
Copy
Edit
    if (found) {
        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
        cout << "Student with roll number " << rollNumber << " deleted successfully!\n";
    } else {
        cout << "Student with roll number " << rollNumber << " not found.\n";
    }
}
If student found, deletes the original file and renames the temp file.

Otherwise, prints not found message.

Display Specific Student Function
cpp
Copy
Edit
void displayStudent(const string &filename) {
    string rollNumber;
    cout << "Enter roll number to display: ";
    cin >> rollNumber;
Asks user for a specific roll number to search for.

cpp
Copy
Edit
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "No records found.\n";
        return;
    }
    string line;
    bool found = false;
Opens file and initializes a found flag.

cpp
Copy
Edit
    while (getline(file, line)) {
        stringstream ss(line);
        Student s1;
        getline(ss, s1.rollNumber, ',');
        getline(ss, s1.name, ',');
        getline(ss, s1.division, ',');
        getline(ss, s1.address, ',');
Parses the current line into a Student object.
  if (s1.rollNumber == rollNumber) {
            found = true;
            cout << "Roll Number: " << s1.rollNumber << "\n";
            cout << "Name: " << s1.name << "\n";
            cout << "Division: " << s1.division << "\n";
            cout << "Address: " << s1.address << "\n";
            break;
        }
    }
If roll number matches, display student info and break the loop.

cpp
Copy
Edit
    if (!found) {
        cout << "Student with roll number " << rollNumber << " not found.\n";
    }
    file.close();
}
If not found, display message.

Closes the file.

Main Function
cpp
Copy
Edit
int main() {
    string fileName = "student.txt";
Defines the filename where all data will be stored.
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
Infinite loop to show menu repeatedly.

Takes user choice as input.






