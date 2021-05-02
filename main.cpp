#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include "universityOrganization.hpp"

int main(){
    Instructor instructor;
    instructor.addCourse(Course("SPRING2020",2345,"CS","YAZ206",5,3));
    instructor.addCourse(Course("FALL2020",1372,"CE","YAZ204",4,4));

    return 0;
}