#include <cstdlib>
#include <iostream>
#include "chapter3.h"
#include "chapter4.h"
#include "chapter5.h"
#include <string>
#include <vector>
#include <random>

using std::cout;
using std::endl;

constexpr int MAX = 20;
constexpr int RAND_NUMS_TO_GENERATE = 1000;

void linked_lists() {
    using namespace chapter4;
    // chapter 4
    // linked lists
    student_collection sc;
    list_node * node1 = new list_node;
    node1->student_num = 1001; node1->grade = 78;
    list_node * node2 = new list_node;
    node2->student_num = 1002; node2->grade = 93;
    list_node * node3 = new list_node;
    node3->student_num = 1003; node3->grade = 85;
    sc = node1;
    //node1->next = NULL;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    print_student_collection(sc);
    std::cout << "Grade average: " << average_grade(sc) << std::endl;
    add_record(sc, 1004,10);
    print_student_collection(sc);
    std::cout << "Grade average: " << average_grade(sc) << std::endl;
    add_record(sc, 1005,65);
    add_record(sc, 1006,100);
    print_student_collection(sc);
    std::cout << "Grade average: " << average_grade(sc) << std::endl;
};

void string_variable_length() {
    using namespace chapter4;
    array_string stringArray = new char[5];
    strcpy(stringArray, "hello");

    for (int i = 0; i < 5; ++i) {
        std::cout << character_at(stringArray, i);
    };
    std::cout << std::endl;
    append_tester();
    concatenate_tester();

};

void chapter_3() {
    using namespace chapter3;
    std::srand(std::time(nullptr));

    std::vector<student> studentArray = {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"},
        {28, 10011, "Tomy"},
        {10, 10011, "Paige"},
        {99, 10011, "Jimbo"},
        {98, 10012, "Tomy"}
    };

    std::vector<int> integerArray = {33,23,4,890,890,31,10009,675,1};
    std::vector<int> integerArrayDesc = {5,5,4,3,3,2,1};
    std::vector<int> random_integers(RAND_NUMS_TO_GENERATE);
    for (int i = 0; i < RAND_NUMS_TO_GENERATE; ++i) {
        random_integers[i] = std::rand() % MAX;
    }

    // exercise 3.7
    /*
    cout << "exercise 3.7\n";
    print_vector(integerArray);
    cout << array_mode(integerArray) << endl;
    print_vector(integerArrayDesc);
    cout << array_mode(integerArrayDesc) << endl;
    print_vector(random_integers);
    cout << array_mode(random_integers) << endl;
    */
    // exercise 3.8
    /*
    cout << "exercise 3.8\n\n";
    print_studentArray(studentArray);
    insertion_sort_ascending(studentArray, compare_by_grade);
    print_studentArray(studentArray);
    quartiles_student_grades(studentArray);
    */
    /*
    hello_world();
    print_studentArray(studentArray);
    insertion_sort_descending(studentArray, compare_by_grade);
    print_studentArray(studentArray);
    insertion_sort_ascending(studentArray, compare_by_name);
    print_studentArray(studentArray);
    hello_world();

    print_array(integerArray);
    std::cout << "check " << is_sorted_ascending(integerArray, integerArray.size()) << std::endl;
    std::cout << "after sorting:" << std::endl;
    insertion_sort_ascending(integerArray, compare_by_int);
    print_array(integerArray);
    std::cout << "check asc " << is_sorted_ascending(integerArray, integerArray.size()) << std::endl;
    std::cout << "check des " << is_sorted_descending(integerArray, integerArray.size()) << std::endl;
    print_array(integerArrayDesc);
    std::cout << "check asc " << is_sorted_ascending(integerArrayDesc, integerArrayDesc.size()) << std::endl;
    std::cout << "check des " << is_sorted_descending(integerArrayDesc, integerArrayDesc.size()) << std::endl;
    std::cout << "median:" << array_median(integerArray) << std::endl;
    std::cout << "median:" << array_median(integerArrayDesc) << std::endl;
    */
};

int main()
{
    cout << "Exercises from THINK LIKE A PROGRAMMER\n\n";
    linked_lists();
    string_variable_length();
    //chapter_3();
    return EXIT_SUCCESS;
}

