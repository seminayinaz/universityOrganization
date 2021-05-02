#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#pragma once

using namespace std;

class Course{
    private:
        string semester;
        int ID;
        string syllabus;
        int numberOfHomeworks;
        int numberOfProjects;
        vector<string> prerequisiteCourses;

    public:
        Course(string semester, int ID, string syllabus, int numberOfHomeworks, int numberOfProjects);
        ~Course();
        void setSyllabus(string syllabus);
        void percentageOfTheHomeworks();
        void percentageOfTheProjects();
        void percentageOfTheMidterm();
        void percentageOfTheFinal();
        void addPrerequisite(string prerequisite);
        string& getSemester();
        void printCourse(){
            cout << "semester: "  << semester << "\nID: " << ID << "\nNumber Of Homeworks: " << numberOfHomeworks ;
            cout << "\nNumber Of Projects: " << numberOfProjects << "\nPrerequisite Courses: " ;
            for (auto& prerequisite : prerequisiteCourses)
                cout << prerequisite << ",";
            cout << "\n";
        }
};

typedef map<string,vector<Course>> CourseOffered;
class Instructor : public UniversityMember {
    private:
        string fullName;
        int ID;
        int startingDate;
        int department;
        bool fullTime;
        int journalPapers;
        int conferencePapers;
        string laboratoryName;
        CourseOffered courseOffered;
    public:
        Instructor(string fullName,int ID,int startingDate,int department,bool isProfessor,string laboratoryName);
        ~Instructor();
        bool Professor();
        void addCourse(Course course);
        void removeCourse(string course);
        void setJournalPapers(int journalPapers);
        void setConferencePapers(int conferencePapers);
        void printCoursesOffered();
        void printInstructor(){
            cout << "Full Name: "  << fullName << "\nID: " << ID << "\nStarting Date: " << startingDate << "\nDepartment: " << department;
            cout << "\nLaboratory Name: " << laboratoryName << "\nJournal Papers: " << journalPapers << "\nConference Papers: " << conferencePapers;
            Professor() ? cout << "Professor\n" : cout << "not Professor\n";
        }
};
typedef map<string,vector<Course>> CourseOffered;
typedef vector<string> FacultyMembers;
class Department {
    private:
        string deptName;
        string facultyName; 
        string deptPresidentName;
        CourseOffered courseOffered;
        FacultyMembers facultyMembers;
        int numOfStudent;
        vector<string> Students;
    public:
        Department(string deptName, string facultyName, string deptPresidentName);
        ~Department();
        int getNumOfStudent();
        void addStudent(string students);
        int removeStudent();
        void addCourse(Course course);
        void removeCourse(string course);
        void printCoursesOffered();
        void addFacultyMembers(FacultyMembers facultyMembers);
        void removeFacultyMembers();
        void printNameFacultyMembers();
        void findFacultyMembers();
        void findCourse();
};
class UniversityMember{
    private:
        string fullName;
        int ID;
        int startingDate;
};

class Faculty {
    private:
        string departments;
        int numOfDepartment;
        int numOfFacultyMember;
        int numOfAdjunctFacultyMembers;
        vector<string> Departments;
    public:
        Faculty(string departments, int numOfDepartment);
        ~Faculty();
        void addDepartment(string departments);
        void removeDepartment();
        int getNumOfDepartment();
        int getNumOfFacultyMember();
        void addFacultyMember(FacultyMembers facultyMembers);
        void removeFacultyMember();
        void printCourseOffered();
        void printFacultyMember();
        void getFullTimeFacultyMember(bool fullTime);
        int getNumOfAdjunctFacultyMembers();

};
enum StudentClass {freshman, sophomore, junior, senior};
typedef map<string,vector<string>> Transcript;
class Student : public UniversityMember{
    private:
        string fullName;
        int ID;
        int startingDate;
        string takenCourses;
        string completedCourses;
        string letterGrades;
        int GPA;
        Transcript transcript;
        StudentClass studentClass;
    public:
        Student(string takenCourses, string completedCourses,string letterGrades,int GPA);
        ~Student();
        int getGPA();
        void failedCourses();
        void studentGrade();
        void printTranscript();
        void printStudent(){
            cout << "Full Name: "  << fullName << "\nID: " << ID << "\nStarting Date: " << startingDate << "\nTaken courses: " << takenCourses;
            cout << "\nCompleted courses: " << completedCourses << "\nLetter grades: " << letterGrades << "\nGPA: " << GPA ; 
        }
};
