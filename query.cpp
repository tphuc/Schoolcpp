#include "query.h"


string getClassByStudentId(string id){
    auto students = readCSV("db/students.csv");
    string clsname;
    for(int i = 0; i < students.size(); i++){
        if (id == students[i][0]){
            return students[i][5];
        }
    }
    return "Undefine";
}

vector<string> getCoursesByStudentId(string id){
    auto students = readCSV("db/students-courses.csv");
    vector<string> classes;

    for(int i=0; i < students.size(); i++){
        if(id == students[i][0]){
            classes.push_back(students[i][1]);
        }
    }
    auto courses = readCSV("db/courses.csv");
    vector<string> class_names;
    for(int i=0;i < classes.size(); i++){
        for (int j=0; j < courses.size(); j++){
            if(classes[i] == courses[j][0]){
                class_names.push_back(courses[j][1]);
                break;
            }
        }
    }
    return class_names;
}