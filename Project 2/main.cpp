//
//  main.cpp
//  Project 2
//
//  Created by Juwon Hong on 11/17/24.
//

// main.cpp
#include "Student.h"

int main() {
    int choice, id;
    std::string name, date;
    std::string filename = "attendance.txt";
// Infinite loop to display the menu and take user input until the user decides to exit.
    while (true) {
        std::cout << "\nStudent Attendance Management System\n";
        std::cout << "1. Add Student\n";
        std::cout << "2. Mark Attendance\n";
        std::cout << "3. Show Attendance\n";
        std::cout << "4. Save to File\n";
        std::cout << "5. Load from File\n";
        std::cout << "6. Exit\n";
        std::cout << "Choose an option: ";
        std::cin >> choice;
// Process the user's choice using a switch statement
        switch (choice) {
            case 1:
                // Option 1: Add a new student
                std::cout << "Student ID: ";
                std::cin >> id;
                std::cout << "Student Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                addStudent(id, name);
                break;
            case 2:
                // Option 2: Mark attendance for a student
                std::cout << "Student ID: ";
                std::cin >> id;
                std::cout << "Date (YYYY-MM-DD): ";
                std::cin >> date;
                markAttendance(id, date);
                break;
            case 3:
                // Option 3: Show the attendance record of a specific student
                std::cout << "Student ID: ";
                std::cin >> id;
                showAttendance(id);
                break;
            case 4:
                // Option 4: Save attendance data to a file
                saveToFile(filename);
                break;
            case 5:
                // Option 5: Load attendance data from a file
                loadFromFile(filename);
                break;
            case 6:
                // Option 6: Exit the program
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                // Handle invalid menu choices.
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

