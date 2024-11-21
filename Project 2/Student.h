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

// Struct to represent a student
struct Student {
    int id;
    std::string name;
    std::vector<std::string> attendance; 
};

// Function declarations for managing the student attendance system

// Adds a new student to the system
void addStudent(int id, const std::string& name);
// Marks attendance for a specific student on a given date
void markAttendance(int id, const std::string& date);
// Displays the attendance records of a specific student
void showAttendance(int id);
// Saves all student information and their attendance records to a file
void saveToFile(const std::string& filename);
// Loads student information and their attendance records from a file
void loadFromFile(const std::string& filename);

#endif
