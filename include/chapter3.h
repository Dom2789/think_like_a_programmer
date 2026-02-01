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
}

#endif