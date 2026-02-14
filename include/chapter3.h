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
    template <typename T>
    void print_vector(const std::vector<T>& t) {
        for (auto element: t) {
            std::cout << element << ", ";
        }
        std::cout << std::endl;
    };
    template <typename T, size_t N>
    void print_array(const std::array<T, N>& t) {
        for (const auto element: t) {
            std::cout << element << ", ";
        }
        std::cout << std::endl;
    };
    int compare_by_grade(const void* a, const void* b);
    int compare_by_studentID(const void* a, const void* b);
    int compare_by_name(const void* a, const void* b);
    int compare_by_int(const void* a, const void* b);
    template <typename Container>
    void insertion_sort_ascending(Container& container, int (*compare_func)(const void*, const void*)){
        for (size_t i = 1; i < container.size(); ++i) {
            const auto element_to_sort = container[i];
            size_t j = i;
            while (compare_func(&element_to_sort, &container[j-1])<0 and j>0) {
                container[j] = container[j-1];
                j--;
            }
            container[j] = element_to_sort;
        }
    }
    void insertion_sort_descending(std::vector<student>& students , int (*compare_func)(const void*, const void*));
    void quartiles_student_grades(std::vector<student>& students);
    double array_median(const std::vector<int>& sorted_integers);
    template <typename Container>
    bool is_sorted_ascending(const Container& container, const size_t size) {
        for (size_t i = 1; i < size; ++i) {
            if (container[i-1] > container[i]) {
                return false;
            }
        }
        return true;
    }
    template <typename Container>
    bool is_sorted_descending(const Container& container, const size_t size) {
        for (size_t i = 1; i < size; ++i) {
            if (container[i-1] < container[i]) {
                return false;
            }
        }
        return true;
    }
    int array_mode(const std::vector<int>& integers);
}

#endif