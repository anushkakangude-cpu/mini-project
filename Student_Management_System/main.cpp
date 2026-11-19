#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

// Student class: demonstrates encapsulation using private data members.
class Student {
private:
    int rollNo;
    string name;
    string course;
    float marks;

public:
    Student() : rollNo(0), marks(0.0f) {}

    Student(int roll, string studentName, string studentCourse, float studentMarks)
        : rollNo(roll), name(studentName), course(studentCourse), marks(studentMarks) {}

    int getRollNo() const { return rollNo; }
    string getName() const { return name; }
    string getCourse() const { return course; }
    float getMarks() const { return marks; }

    void display() const {
        cout << "\nRoll Number : " << rollNo
             << "\nName        : " << name
             << "\nCourse      : " << course
             << "\nMarks       : " << marks << "/100\n";
    }

    // Save one student in a simple comma-separated format.
    void saveToFile(ofstream& out) const {
        out << rollNo << '\n' << name << '\n' << course << '\n' << marks << '\n';
    }
};

// StudentManagement class: handles the collection and file operations.
class StudentManagement {
private:
    vector<Student> students;
    const string fileName = "students.txt";

    int findStudentIndex(int rollNo) const {
        for (int i = 0; i < static_cast<int>(students.size()); ++i) {
            if (students[i].getRollNo() == rollNo) return i;
        }
        return -1;
    }

    void saveAll() const {
        ofstream out(fileName);
        for (const Student& student : students) student.saveToFile(out);
    }

    void loadAll() {
        ifstream in(fileName);
        if (!in) return;

        int roll;
        string name, course;
        float marks;
        while (in >> roll) {
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            if (!getline(in, name)) break;
            if (!getline(in, course)) break;
            if (!(in >> marks)) break;
            in.ignore(numeric_limits<streamsize>::max(), '\n');
            students.emplace_back(roll, name, course, marks);
        }
    }

    static void clearInput() {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    StudentManagement() { loadAll(); }

    void addStudent() {
        int roll;
        string name, course;
        float marks;

        cout << "Enter roll number: ";
        if (!(cin >> roll)) { clearInput(); cout << "Invalid roll number.\n"; return; }
        clearInput();

        if (findStudentIndex(roll) != -1) {
            cout << "A student with this roll number already exists.\n";
            return;
        }

        cout << "Enter student name: ";
        getline(cin, name);
        cout << "Enter course: ";
        getline(cin, course);
        cout << "Enter marks (0-100): ";
        if (!(cin >> marks) || marks < 0 || marks > 100) {
            clearInput();
            cout << "Please enter valid marks between 0 and 100.\n";
            return;
        }
        clearInput();

        students.emplace_back(roll, name, course, marks);
        saveAll();
        cout << "Student added successfully!\n";
    }

    void displayAll() const {
        if (students.empty()) {
            cout << "No student records found.\n";
            return;
        }
        cout << "\n========== STUDENT RECORDS ==========\n";
        for (const Student& student : students) student.display();
        cout << "\nTotal students: " << students.size() << '\n';
    }

    void searchStudent() const {
        int roll;
        cout << "Enter roll number to search: ";
        if (!(cin >> roll)) { clearInput(); cout << "Invalid roll number.\n"; return; }
        clearInput();

        int index = findStudentIndex(roll);
        if (index == -1) cout << "Student not found.\n";
        else { cout << "Student found:\n"; students[index].display(); }
    }

    void updateStudent() {
        int roll;
        cout << "Enter roll number to update: ";
        if (!(cin >> roll)) { clearInput(); cout << "Invalid roll number.\n"; return; }
        clearInput();

        int index = findStudentIndex(roll);
        if (index == -1) { cout << "Student not found.\n"; return; }

        string name, course;
        float marks;
        cout << "Enter new name: ";
        getline(cin, name);
        cout << "Enter new course: ";
        getline(cin, course);
        cout << "Enter new marks (0-100): ";
        if (!(cin >> marks) || marks < 0 || marks > 100) {
            clearInput();
            cout << "Please enter valid marks between 0 and 100.\n";
            return;
        }
        clearInput();

        students[index] = Student(roll, name, course, marks);
        saveAll();
        cout << "Student record updated successfully!\n";
    }

    void deleteStudent() {
        int roll;
        cout << "Enter roll number to delete: ";
        if (!(cin >> roll)) { clearInput(); cout << "Invalid roll number.\n"; return; }
        clearInput();

        int index = findStudentIndex(roll);
        if (index == -1) { cout << "Student not found.\n"; return; }

        students.erase(students.begin() + index);
        saveAll();
        cout << "Student record deleted successfully!\n";
    }

    void run() {
        int choice;
        do {
            cout << "\n========== STUDENT MANAGEMENT SYSTEM ==========\n"
                 << "1. Add Student\n"
                 << "2. Display All Students\n"
                 << "3. Search Student\n"
                 << "4. Update Student\n"
                 << "5. Delete Student\n"
                 << "0. Exit\n"
                 << "Enter your choice: ";

            if (!(cin >> choice)) {
                clearInput();
                cout << "Please enter a number from the menu.\n";
                continue;
            }
            clearInput();

            switch (choice) {
                case 1: addStudent(); break;
                case 2: displayAll(); break;
                case 3: searchStudent(); break;
                case 4: updateStudent(); break;
                case 5: deleteStudent(); break;
                case 0: cout << "Thank you for using the system!\n"; break;
                default: cout << "Invalid choice. Try again.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    StudentManagement system;
    system.run();
    return 0;
}
