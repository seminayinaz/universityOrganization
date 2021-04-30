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
        string getSemester(){
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
class Instructor{
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
        void printCoursesOffered();
        void printInstructor(){
            cout << "Full Name: "  << fullName << "\nID: " << ID << "\nStarting Date: " << startingDate << "\nDepartment: " << department;
            cout << "\nLaboratory Name: " << laboratoryName << "\nJournal Papers: " << journalPapers << "\nConference Papers: " << conferencePapers;
            isProfessor() ? cout << "Professor\n" : cout << "not Professor\n";
        }


};