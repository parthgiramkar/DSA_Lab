#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Employee {
private:
    int employeeID;
    char name[50];
    char designation[50];
    float salary;

public:
    Employee(int id = 0, const char* n = "", const char* desig = "", float sal = 0.0) {
        employeeID = id;
        strcpy(name, n);
        strcpy(designation, desig);
        salary = sal;
    }

    int getEmployeeID() const {
        return employeeID;
    }

    void input() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Designation: ";
        cin.getline(designation, 50);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void display() const {
        cout << "\nEmployee Details:\n";
        cout << "ID: " << employeeID << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }

    void writeToFile(fstream& file) const {
        file.write((char*)this, sizeof(Employee));
    }

    void readFromFile(fstream& file) {
        file.read((char*)this, sizeof(Employee));
    }
};

void addEmployee(fstream& file) {
    Employee emp;
    emp.input();

    file.seekg(0, ios::beg);
    Employee temp;
    bool exists = false;

    while (file.read((char*)&temp, sizeof(Employee))) {
        if (temp.getEmployeeID() == emp.getEmployeeID()) {
            exists = true;
            break;
        }
    }

    if (exists) {
        cout << "Employee with ID " << emp.getEmployeeID() << " already exists!\n";
    } else {
        file.clear();
        file.seekp(0, ios::end);
        emp.writeToFile(file);
        cout << "Employee added successfully!\n";
    }
}

void deleteEmployee(fstream& file) {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    fstream tempFile("temp.dat", ios::out | ios::binary);
    file.seekg(0, ios::beg);
    Employee emp;
    bool found = false;

    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.getEmployeeID() == id) {
            found = true;
            cout << "Employee with ID " << id << " deleted.\n";
        } else {
            emp.writeToFile(tempFile);
        }
    }

    file.close();
    tempFile.close();

    if (!found) {
        cout << "Employee with ID " << id << " not found!\n";
    } else {
        remove("employee_data.dat");
        rename("temp.dat", "employee_data.dat");
    }

    file.open("employee_data.dat", ios::in | ios::out | ios::binary | ios::app);
}

void displayEmployee(fstream& file) {
    int id;
    cout << "Enter Employee ID to display: ";
    cin >> id;

    file.seekg(0, ios::beg);
    Employee emp;
    bool found = false;

    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.getEmployeeID() == id) {
            found = true;
            emp.display();
            break;
        }
    }

    if (!found) {
        cout << "Employee with ID " << id << " not found!\n";
    }
}

int main() {
    fstream file("employee_data.dat", ios::in | ios::out | ios::binary | ios::app);

    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                deleteEmployee(file);
                break;
            case 3:
                displayEmployee(file);
                break;
            case 4:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    file.close();
    return 0;
}




















/*
#include <iostream> – for input/output (cin, cout)

#include <fstream> – for file operations (fstream)

#include <cstring> – for string functions like strcpy()

using namespace std; – so we don’t need to write std::cout etc.

🔹 EMPLOYEE CLASS
cpp
Copy
Edit
class Employee {
Defines a class named Employee.

🔸 PRIVATE MEMBERS
cpp
Copy
Edit
private:
    int employeeID;
    char name[50];
    char designation[50];
    float salary;
These are the private variables to store:

employeeID: unique ID for employee

name: up to 50 characters

designation: job title

salary: employee's salary

🔸 CONSTRUCTOR
cpp
Copy
Edit
public:
    Employee(int id = 0, const char* n = "", const char* desig = "", float sal = 0.0) {
        employeeID = id;
        strcpy(name, n);
        strcpy(designation, desig);
        salary = sal;
    }
This constructor:

Initializes all fields (ID, name, designation, salary)

Uses strcpy() to copy text into character arrays

🔸 GETTER FUNCTION
cpp
Copy
Edit
int getEmployeeID() const {
    return employeeID;
}
Returns the employee's ID — useful to compare IDs later.

🔸 INPUT FUNCTION
cpp
Copy
Edit
void input() {
    cout << "Enter Employee ID: ";
    cin >> employeeID;
    cin.ignore();
    cout << "Enter Name: ";
    cin.getline(name, 50);
    cout << "Enter Designation: ";
    cin.getline(designation, 50);
    cout << "Enter Salary: ";
    cin >> salary;
}
Takes input for all fields.

cin.ignore() removes leftover newline before reading strings.

🔸 DISPLAY FUNCTION
cpp
Copy
Edit
void display() const {
    cout << "\nEmployee Details:\n";
    cout << "ID: " << employeeID << endl;
    cout << "Name: " << name << endl;
    cout << "Designation: " << designation << endl;
    cout << "Salary: " << salary << endl;
}
Prints the employee's details neatly.

🔸 FILE I/O FUNCTIONS
cpp
Copy
Edit
void writeToFile(fstream &file) const {
    file.write((char*)this, sizeof(Employee));
}
void readFromFile(fstream &file) {
    file.read((char*)this, sizeof(Employee));
}
writeToFile(): saves the whole object to a file

readFromFile(): reads object back from file

They use binary format ((char*)this) to store the object directly.

🔹 addEmployee FUNCTION
cpp
Copy
Edit
void addEmployee(fstream &file) {
    Employee emp;
    emp.input();
Takes a new employee as input.

cpp
Copy
Edit
    file.seekg(0, ios::beg);
Moves file pointer to beginning (for reading from start).

cpp
Copy
Edit
    Employee temp;
    bool exists = false;
    while (file.read((char*)&temp, sizeof(Employee))) {
        if (temp.getEmployeeID() == emp.getEmployeeID()) {
            exists = true;
            break;
        }
    }
Checks if employee with same ID already exists.

cpp
Copy
Edit
    if (exists) {
        cout << "Employee with ID " << emp.getEmployeeID() << " already exists!\n";
    } else {
        file.clear();
        file.seekp(0, ios::end);
        emp.writeToFile(file);
        cout << "Employee added successfully!\n";
    }
}
If exists: prints message.

Else: writes new employee to end of file.

🔹 deleteEmployee FUNCTION
cpp
Copy
Edit
void deleteEmployee(fstream &file) {
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
Asks user which employee ID to delete.

cpp
Copy
Edit
    fstream tempFile("temp.dat", ios::out | ios::binary);
Creates a temporary file to store all records except the one to be deleted.

cpp
Copy
Edit
    file.seekg(0, ios::beg);
    Employee emp;
    bool found = false;
    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.getEmployeeID() == id) {
            found = true;
            cout << "Employee with ID " << id << " deleted.\n";
        } else {
            emp.writeToFile(tempFile);
        }
    }
Copies all other records into temp.dat

Skips the one with matching ID

cpp
Copy
Edit
    file.close();
    tempFile.close();
Closes both files.

cpp
Copy
Edit
    if (!found) {
        cout << "Employee with ID " << id << " not found!\n";
    } else {
        remove("employee_data.dat");
        rename("temp.dat", "employee_data.dat");
    }
If found:

Deletes original file

Renames temp.dat to original file name

Then reopens file:

cpp
Copy
Edit
    file.open("employee_data.dat", ios::in | ios::out | ios::binary | ios::app);
}
🔹 displayEmployee FUNCTION
cpp
Copy
Edit
void displayEmployee(fstream &file) {
    int id;
    cout << "Enter Employee ID to display: ";
    cin >> id;
    file.seekg(0, ios::beg);
    Employee emp;
    bool found = false;
Reads all records to find matching ID.

cpp
Copy
Edit
    while (file.read((char*)&emp, sizeof(Employee))) {
        if (emp.getEmployeeID() == id) {
            found = true;
            emp.display();
            break;
        }
    }
    if (!found) {
        cout << "Employee with ID " << id << " not found!\n";
    }
}
Displays that employee’s details.

🔹 MAIN FUNCTION
cpp
Copy
Edit
int main() {
    fstream file("employee_data.dat", ios::in | ios::out | ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }
Opens or creates file for reading and writing in binary.

Shows error if it fails.

cpp
Copy
Edit
    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Display Employee\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
Displays menu repeatedly.

cpp
Copy
Edit
        switch (choice) {
            case 1:
                addEmployee(file);
                break;
            case 2:
                deleteEmployee(file);
                break;
            case 3:
                displayEmployee(file);
                break;
            case 4:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);
    file.close();
    return 0;
}
Calls the corresponding function based on user’s choice.

*/







