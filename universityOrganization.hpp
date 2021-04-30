#include <iostream>
#include <string>
#include <vector>

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
        void printCourse(){
            cout << "semester: "  << semester << "\nID: " << ID << "\nNumber Of Homeworks: " << numberOfHomeworks ;
            cout << "\nNumber Of Projects: " << numberOfProjects << "\nPrerequisite Courses: " ;
            for (auto& prerequisite : prerequisiteCourses)
                cout << prerequisite << ",";
            cout << "\n";
        }

};