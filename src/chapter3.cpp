#include "chapter3.h"
#include <vector>

namespace chapter3
{
    void hello_world()
    {
        std::cout << "Hello World \n";
    }
    int compare_by_int(const void* a, const void* b) {
        const int int_a = *static_cast<const int*>(a);
        const int int_b = *static_cast<const int*>(b);
        return int_a - int_b;
    };

    int compare_by_grade(const void* a, const void* b)
    {
        student student_a = *static_cast<const student*>(a);
        student student_b = *static_cast<const student*>(b);
        return student_a.grade - student_b.grade;
    }

    int compare_by_studentID(const void* a, const void* b) {
        student student_a = *static_cast<const student*>(a);
        student student_b = *static_cast<const student*>(b);
        return student_a.studentID - student_b.studentID;
    }

    int compare_by_name(const void* a, const void* b) {
        student student_a = *static_cast<const student*>(a);
        student student_b = *static_cast<const student*>(b);
        int length;
        if (student_a.name.length() <= student_b.name.length()) {
            length = student_a.name.length();
        }else {
            length = student_b.name.length();
        }
        for (size_t i = 0; i < length; ++i) {
           int ret_value = student_a.name[i] - student_b.name[i];
            if (ret_value == 0) continue;
            else return ret_value;
        }
        if (student_a.name.length() <= student_b.name.length()) return -1;
        else return 1;
    }

    void print_studentArray(const std::vector<student>& students)
    {
        for (const auto & student : students)
        {
            std::cout << "Student-ID: " << student.studentID << " Grade: " << student.grade << " Name: " << student.name << "\n";
        }
        std::cout << "\n";      
    }

    void insertion_sort_descending(std::vector<student>& students, int (*compare_func)(const void*, const void*)){
        for (size_t i = 1; i < students.size(); ++i) {
            const auto student_to_sort = students[i];
            size_t j = i;
            while (compare_func(&student_to_sort, &students[j-1])>0 and j>0) {
                students[j] = students[j-1];
                j--;
            }
            students[j] = student_to_sort;
        }
    }

    double array_median(const std::vector<int>& sorted_integers) {
        const unsigned long size = sorted_integers.size();
        if (size%2 != 0) {
            return sorted_integers[size/2];
        }else {
            return (sorted_integers[size/2]+sorted_integers[size/2+1])/2.0;
        };
    };

    int array_mode(const std::vector<int>& integers) {
        int mode = 0;
        std::unordered_map<int, int> occurence;
        occurence[0] = 0;
        for (int number : integers) {
            // calculating frequency of occurence of every number
            if (occurence.find(number) != occurence.end()) {
                occurence[number] = 1;
            } else {
                occurence[number]++;
            }
            // checking if number is now the new mode
            if (occurence[mode] < occurence[number]) {
                mode = number;
            }
        }
        return mode;
    };
}
