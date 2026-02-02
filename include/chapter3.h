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
    void insertion_sort_up(std::vector<student>& students);
    void insertion_sort_down(std::vector<student>& students);

}

#endif