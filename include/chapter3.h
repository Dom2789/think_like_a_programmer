#ifndef CHAPTER3_
#define CHAPTER3_
#include <iostream>

namespace chapter3
{
    struct student {
        int grade;
        int studentID;
        std::string name;
    };

    void hello_world();
    void print_studentArray(const std::vector<student>& students);
    int compare_by_grade(const void* a, const void* b);
    int compare_by_studentID(const void* a, const void* b);
    int compare_by_name(const void* a, const void* b);
    void insertion_sort_ascending(std::vector<student>& students , int (*compare_func)(const void*, const void*));
    void insertion_sort_descending(std::vector<student>& students , int (*compare_func)(const void*, const void*));

}

#endif