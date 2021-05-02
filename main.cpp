#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "universityOrganization.hpp"

int main(){
    Course course("FALL2019",4352,"CS",4,3);
    course.printCourse();

    Instructor instructor("Aslı Yılmaz",2359,2017,"Engeneering",true,"Kimya");
    instructor.printInstructor();
    instructor.addCourse(Course("YAZ204","CS","FALL2020",false));
    instructor.printCoursesOffered();

    Student student("Seminay İnaz",3445, 2019,"YAZ104","CC",3.0);
    student.printStudent();
    return 0;
}