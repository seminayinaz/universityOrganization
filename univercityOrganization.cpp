#include <iostream>
#include "universityOrganization.hpp"

Course::Course(string semester, int ID, string syllabus, int numberOfHomeworks, int numberOfProjects):
    semester(semester), ID(ID), syllabus(syllabus), numberOfHomeworks(numberOfHomeworks), numberOfProjects(numberOfProjects){}

Course::~Course(){}

void Course::setSyllabus(string syllabus){
    this -> syllabus = syllabus;
}
void Course::addPrerequisite(string prerequisite){
    prerequisiteCourses.push_back(prerequisite);
}
