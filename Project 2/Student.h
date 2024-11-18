//
//  Student.h
//  Project 2
//
//  Created by Juwon Hong on 11/17/24.
//

// Student.h
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>

struct Student {
    int id;
    std::string name;
    std::vector<std::string> attendance; // Attendance records
};

// Function declarations
void addStudent(int id, const std::string& name);
void markAttendance(int id, const std::string& date);
void showAttendance(int id);
void saveToFile(const std::string& filename);
void loadFromFile(const std::string& filename);

#endif
