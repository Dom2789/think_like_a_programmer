#include "chapter3.h"
#include <vector>

namespace chapter3
{
    void hello_world()
    {
        std::cout << "Hello World \n";
    }

    int compare_by_grade(const void* a, const void* b)
    {
        const auto& studentA = reinterpret_cast<student &>(a);
        const auto& studentB = reinterpret_cast<student &>(b);
        return studentA.grade - studentB.grade;
    }

    void print_studentArray(const std::vector<student>& students)
    {
        for (const auto & student : students)
        {
            std::cout << "Student-ID: " << student.studentID << " Grade: " << student.grade << " Name: " << student.name << "\n";
        }
        std::cout << "\n";      
    }

    void insertion_sort_down(std::vector<student>& students) {
        for (size_t i = 1; i < students.size(); ++i) {
            const auto student_to_sort = students[i];
            size_t j = i;
            while (student_to_sort.grade < students[j-1].grade and j>0) {
                students[j] = students[j-1];
                j--;
            }
            students[j] = student_to_sort;
        }
    }

}
