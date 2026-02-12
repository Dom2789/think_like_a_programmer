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
    void print_array(const std::vector<T>& t) {
        for (auto element: t) {
            std::cout << element << std::endl;
        }
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
    double array_median(const std::vector<int>& sorted_integers);

}

#endif