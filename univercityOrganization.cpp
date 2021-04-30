#include <iostream>
#include "universityOrganization.hpp"

Course::Course(string semester, int ID, string syllabus, int numberOfHomeworks, int numberOfProjects):
    semester(semester), ID(ID), syllabus(syllabus), numberOfHomeworks(numberOfHomeworks), numberOfProjects(numberOfProjects){}

Course::~Course(){
    prerequisiteCourses.clear();
}

void Course::setSyllabus(string syllabus){
    this -> syllabus = syllabus;
}
void Course::addPrerequisite(string prerequisite){
    prerequisiteCourses.push_back(prerequisite);
}

Instructor::Instructor(string fullName,int ID,int startingDate,int department,bool isProfessor,string laboratoryName):
    fullName(fullName),ID(ID),startingDate(startingDate),department(department),fullTime(isProfessor),laboratoryName(laboratoryName){}


Instructor::~Instructor(){}

bool Instructor::isProfessor(){
    if(fullTime)
        cout << "is a professor\n";
    else
        cout << "not a professor\n";
    return fullTime;
}

void Instructor::addCourse(Course course) {
    string semester = course.getSemester();
    courseOffered[semester].push_back(course);
    }

void Instructor::removeCourse(string course) {
    for(auto& semesterCourses : courseOffered) {
        vector<Course>& courses = semesterCourses.second;
        auto it = find(courses.begin(), courses.end(), course);
        if(it != courses.end()) {
          courses.erase(it);
          break;
        }
    }
}
void Instructor::printCoursesOffered() {
    for(auto& semesterCourses : courseOffered) {  
        cout << "semester: " << semesterCourses.first << "\ncourses:\n";
        for(auto& courses : semesterCourses.second)
          courses.printCourse();
        cout << '\n';
    }
}