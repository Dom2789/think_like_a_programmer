#include "chapter3.h"
#include <vector>

namespace chapter3
{
    const int ARRAY_SIZE = 10;      
    void hello_world()
    {
        std::cout << "Hello World \n";
    }

    void print_studentArray(const std::vector<student>& students)
    {
        for (int i = 0; i < students.size(); i++)
        {
            std::cout << "Student-ID: " << students[i].studentID << " Grade: " << students[i].grade << " Name: " << students[i].name << "\n";
        }
        std::cout << "\n";      
    }

}
