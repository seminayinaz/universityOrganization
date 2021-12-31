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
string& Course::getSemester(){
    return semester;
}
void Course::addPrerequisite(string prerequisite){
    prerequisiteCourses.push_back(prerequisite);
}

Instructor::Instructor(string fullName,int ID,int startingDate,string department,bool Professor,string laboratoryName):
    fullName(fullName),ID(ID),startingDate(startingDate),department(department),fullTime(Professor),laboratoryName(laboratoryName){}

Instructor::~Instructor(){}

void Instructor::setJournalPapers(int journalPapers){
    this-> journalPapers = journalPapers;
}
void Instructor::setConferencePapers(int conferencePapers){
    this-> conferencePapers = conferencePapers; 
}

bool Instructor::Professor(){
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

Department::Department(string deptName, string facultyName, string deptPresidentName):
    deptName(deptName), facultyName(facultyName), deptPresidentName(deptPresidentName){}

Department::~Department(){}

void Department::addCourse(Course course) {
    string semester = course.getSemester();
    courseOffered[semester].push_back(course);
    }
void Department::removeCourse(string course) {
    for(auto& semesterCourses : courseOffered) {
        vector<Course>& courses = semesterCourses.second;
        auto it = find(courses.begin(), courses.end(), course);
        if(it != courses.end()) {
          courses.erase(it);
          break;
        }
    }
}
void Department::printCoursesOffered() {
    for(auto& semesterCourses : courseOffered) {  
        cout << "semester: " << semesterCourses.first << "\ncourses:\n";
        for(auto& courses : semesterCourses.second)
          courses.printInstructor();
        cout << '\n';
    }
}
int Department::getNumOfStudent(){
    cout << "Öğrenci sayısını girin:";
    cin >> numOfStudent;
    return numOfStudent;
}
void Department::addStudent(string students){
    Students.push_back(students);
}

Faculty::Faculty(string departments,int numOfDepartment):
    departments(departments),numOfDepartment(numOfDepartment){}

Faculty::~Faculty(){}

void Faculty::addDepartment(string departments){
    Departments.push_back(departments);
}
int Faculty::getNumOfDepartment(){
    cout << "Department sayısını girin:";
    cin >> numOfDepartment;
    return numOfDepartment;
}
int Faculty::getNumOfAdjunctFacultyMembers(){
    cout << "Yardımcı Department sayısını girin:";
    cin >> numOfAdjunctFacultyMembers;
    return numOfAdjunctFacultyMembers;
}
int Faculty::getNumOfFacultyMember(){
    cout << "Fakülte üyesi sayısını girin:";
    cin >> numOfFacultyMember;
    return numOfFacultyMember;
}

Student::Student(string completedCourses,string letterGrades,float GPA):
    GPA(GPA),completedCourses(completedCourses),letterGrades(letterGrades){}

Student::~Student(){}

float Student::getGPA(){
    return GPA;
}
void Student::printTranscript() {
    for(auto& grade : transcript) { 
        vector<string>& takenCourses = grade.second; 
        cout << "taken courses: " << grade.first << "\nletter grades:\n";
        for(auto& lettergrade : grade.second)
          lettergrade.printStudent();
        cout << '\n';
    }
}
