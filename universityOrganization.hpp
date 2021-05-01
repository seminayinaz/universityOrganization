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
        void addPrerequisite(string prerequisite);
        string& getSemester(){
            return semester;
        }
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
        bool isProfessor();
        void addCourse(Course course);
        void removeCourse(string course);
        void setJournalPapers(int journalPapers);
        void setConferencePapers(int conferencePapers);
        void printCoursesOffered();
        void printInstructor(){
            cout << "Full Name: "  << fullName << "\nID: " << ID << "\nStarting Date: " << startingDate << "\nDepartment: " << department;
            cout << "\nLaboratory Name: " << laboratoryName << "\nJournal Papers: " << journalPapers << "\nConference Papers: " << conferencePapers;
            isProfessor() ? cout << "Professor\n" : cout << "not Professor\n";
        }
};
typedef map<string,vector<Course>> CourseOffered;
typedef map<string,vector<string>> FacultyMembers;
class Department : public Instructor {
    private:
        string deptName;
        string facultyName;
        string students; 
        string deptPresidentName;
        CourseOffered courseOffered;
        FacultyMembers facultyMembers;
    public:
        Department(string deptName, string facultyName, string students, string deptPresidentName);
        ~Department();
        void addCourse(Course course);
        void removeCourse(string course);
        void printCoursesOffered();
        
};
class UniversityMember{
    private:
        string fullName;
        int ID;
        int startingDate;
};

class Faculty : public Department {
    private:
        string departments;
    public:
        Faculty(string departments);
        ~Faculty();
        void addDepartment();
        void removeDepartment();

};
enum StudentClass {freshman, sophomore, junior, senior};
typedef map<string,vector<string>> Transcript;
class Student : public UniversityMember{
    private:
        StudentClass studentClass;
        string fullName;
        int ID;
        int startingDate;
        string takenCourses;
        string completedCourses;
        string letterGrades;
        int GPA;
        Transcript transcript;
    public:
        Student(string takenCourses, string completedCourses,string letterGrades,int GPA);
        ~Student();
        int getGPA();
        void printTranscript();
        void printStudent(){
            cout << "Full Name: "  << fullName << "\nID: " << ID << "\nStarting Date: " << startingDate << "\nTaken courses: " << takenCourses;
            cout << "\nCompleted courses: " << completedCourses << "\nLetter grades: " << letterGrades << "\nGPA: " << GPA ; 
        }

};
