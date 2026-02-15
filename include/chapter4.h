#ifndef CHAPTER4_
#define CHAPTER4_
#include <iostream>

namespace chapter4
{
    typedef char * array_string;
    void hello_world();
    // variable length string
    char character_at(array_string s, int postion);
    void append (array_string& s, char c);
    void conactate(array_string& s1, array_string s2);
    int length(array_string s);
    void append_tester();
    void concatenate_tester();
    array_string substring(array_string s, int start, int length);
    // linked list
    struct list_node {
        int student_num;
        int grade;
        list_node * next;
    };
    typedef list_node * student_collection;
    void print_student_collection(const student_collection& sc);
    void add_record(student_collection& sc, int student_num, int grade);
    double average_grade(student_collection sc);

}


#endif