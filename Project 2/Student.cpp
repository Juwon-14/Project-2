//
//  Student.cpp
//  Project 2
//
//  Created by Juwon Hong on 11/17/24.
//

// Student.cpp
#include "Student.h"
#include <fstream>
#include <sstream>

std::vector<Student> students; 

// Adds a new student to the list
void addStudent(int id, const std::string& name) {
    students.push_back({id, name, {}});
    std::cout << "Student added: " << name << " (ID: " << id << ")\n";
}
// Marks attendance for a specific student on a given date
void markAttendance(int id, const std::string& date) {
    for (auto& student : students) {
        if (student.id == id) {
            student.attendance.push_back(date);
            std::cout << "Attendance recorded: " << student.name << " - " << date << "\n";
            return;
        }
    }
    std::cout << "No student found with that ID.\n";
}
// Displays attendance records for a specific student
void showAttendance(int id) {
    for (const auto& student : students) {
        if (student.id == id) {
            std::cout << "Student: " << student.name << " (ID: " << id << ")\n";
            std::cout << "Attendance records: ";
            if (student.attendance.empty()) {
                std::cout << "No attendance records available.\n";
            } else {
                for (const auto& date : student.attendance) {
                    std::cout << date << " ";
                }
                std::cout << "\n";
            }
            return;
        }
    }
    std::cout << "No student found with that ID.\n";
}
// Saves all student data to a file
void saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.id << "," << student.name << ",";
            for (const auto& date : student.attendance) {
                file << date << " ";
            }
            file << "\n";
        }
        file.close();
        std::cout << "Data saved to file successfully.\n";
    } else {
        std::cout << "Unable to open file.\n";
    }
}
// Loads student data from a file
void loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        students.clear();
        std::string line;
        while (getline(file, line)) {
            int id;
            std::string name, dates;
            std::stringstream ss(line);
            std::string idStr;
            // Parse the ID, name, and attendance dates
            getline(ss, idStr, ',');
            id = std::stoi(idStr);
            getline(ss, name, ',');
            getline(ss, dates);
             // Create a new Student struct
            Student student = {id, name, {}};
            std::stringstream dateStream(dates);
            std::string date;
            // Split the attendance dates and add them to the student
            while (dateStream >> date) {
                student.attendance.push_back(date);
            }
            students.push_back(student);
        }
        file.close();
        std::cout << "Data loaded from file successfully.\n";
    } else {
        std::cout << "Unable to open file.\n";
    }
}
