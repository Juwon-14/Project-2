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

        switch (choice) {
            case 1:
                std::cout << "Student ID: ";
                std::cin >> id;
                std::cout << "Student Name: ";
                std::cin.ignore();
                std::getline(std::cin, name);
                addStudent(id, name);
                break;
            case 2:
                std::cout << "Student ID: ";
                std::cin >> id;
                std::cout << "Date (YYYY-MM-DD): ";
                std::cin >> date;
                markAttendance(id, date);
                break;
            case 3:
                std::cout << "Student ID: ";
                std::cin >> id;
                showAttendance(id);
                break;
            case 4:
                saveToFile(filename);
                break;
            case 5:
                loadFromFile(filename);
                break;
            case 6:
                std::cout << "Exiting the program.\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

