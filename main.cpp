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
    remove_record(sc, 1006);
    print_student_collection(sc);
    remove_record(sc, 1002);
    print_student_collection(sc);
    add_record(sc, 1010,10);
    print_student_collection(sc);
    remove_record(sc, 1003);
    print_student_collection(sc);
    std::cout << "Grade average: " << average_grade(sc) << std::endl;
};

void endless_integer() {
    using namespace chapter4;
    int integer, integer2 = 0;
    //std::cin >> integer;
    //auto endless_integer = create_endless_integer(integer);
    //print_endless_integer(endless_integer);
    //print_endless_integer_recursive(endless_integer);
    //std::cout << std::endl;
    std::cin >> integer;
    auto endless_integer1 = create_endless_integer(integer);
    std::cin >> integer2;
    auto endless_integer2 = create_endless_integer(integer2);
    auto sum = sum_endless_integer(endless_integer1, endless_integer2);
    print_endless_integer_recursive(sum);
    std::cout << std::endl;
};

void string_variable_length() {
    using namespace chapter4;
    array_string a = new char[6];
    a[0] = 'W'; a[1] = 'e'; a[2] = 'r'; a[3] = 0; a[4] = 'o'; a[5] = 0;
    array_string b = new char[12];
    b[0] = 'W'; b[1] = 'e'; b[2] = 'o'; b[3] = 'W'; b[4] = 'e'; b[5] = 'r'; b[6] = 'i'; b[7] = 'y'; b[8] = 'W'; b[9] = 'e'; b[10] = 'r'; b[11] = 0;
    array_string c = new char[5];
    c[0] = 'Y'; c[1] = 'E'; c[2] = 'S'; c[3] = '!'; c[4] = 0;

    //append_tester();
    //concatenate_tester();
    replace_string(b, a, c);

};

void string_l(){
    using namespace chapter4;
    array_string_l a = new char[6];
    a[0] = 5; a[1] = 'e'; a[2] = 'r'; a[3] = 'z'; a[4] = 'o'; a[5] = 'g';
    array_string_l b = new char[2];
    b[0] = 2; b[1] = 'p'; b[2] = 't';
    print_l(a);
    std::cout << character_at(a,2) << std::endl;
    concatenate_l(a,b);
    print_l(a);
    append_l(a, '!');
    print_l(a);
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

void class_tester() {
    using namespace chapter5;
    auto sc = new student_collection;
    sc->add_record(student_record(100, 10001, "Tom"));
    sc->add_record(student_record(2, 10002, "Sasha"));
    sc->add_record(student_record(67, 10003, "Alistair"));
    sc->add_record(student_record(31, 10004, "Erin"));

    auto student = sc->get_record_with_number(10003);
    student.print_record();
    std::cout << std::endl;
    sc->print_all_students();

};

int main()
{
    cout << "Exercises from THINK LIKE A PROGRAMMER\n";
    class_tester();
    //endless_integer();
    //linked_lists();
    //string_variable_length();
    //string_l();
    //chapter_3();
    return EXIT_SUCCESS;
}

