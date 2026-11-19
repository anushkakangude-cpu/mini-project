# Student Management System (C++ OOP)

A beginner-friendly, menu-driven Student Management System built using C++. It is suitable for an Object-Oriented Programming mini project and can be uploaded directly to GitHub.

## Features
- Add a student
- Display all student records
- Search by roll number
- Update a student record
- Delete a student record
- Save records in `students.txt` so data remains available after closing the program
- Basic input validation and duplicate roll-number checking

## OOP concepts used
1. **Class and Object:** `Student` and `StudentManagement` are classes; `system` is an object.
2. **Encapsulation:** Student data members are private and accessed through public getter functions.
3. **Abstraction:** The menu calls simple methods such as `addStudent()` and `deleteStudent()` without exposing their internal implementation.
4. **Constructors:** The `Student` constructors initialize student objects.
5. **File Handling:** `ifstream` and `ofstream` load and save student records.

## Requirements
- A C++ compiler (g++ recommended)
- C++11 or later

## Run the project

### Windows (MinGW / g++)
Open a terminal in this folder and run:

```bash
g++ -std=c++11 main.cpp -o student_management
student_management.exe
```

### Linux / macOS
```bash
g++ -std=c++11 main.cpp -o student_management
./student_management
```

You can also open the folder in VS Code and run the commands in its integrated terminal.

## Data storage
The program automatically creates `students.txt` in the current working directory when the first record is saved. Keep this file if you want to retain your records. It is intentionally excluded from Git by `.gitignore` because it contains local test data.

## Suggested demo
1. Add a student with roll number `101`.
2. Add another student with roll number `102`.
3. Display all students.
4. Search for roll number `101`.
5. Update the details of roll number `102`.
6. Delete roll number `101`.
7. Exit and run the program again to demonstrate file storage.

## GitHub upload

Create a new empty repository on GitHub, then run these commands inside this project folder:

```bash
git init
git add .
git commit -m "Add Student Management System OOP project"
git branch -M main
git remote add origin https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
git push -u origin main
```

Replace the URL with your own GitHub repository URL.

## Project structure

```text
Student_Management_System/
├── main.cpp
├── README.md
└── .gitignore
```
