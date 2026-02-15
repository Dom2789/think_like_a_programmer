#include <cstdlib>
#include <iostream>
#include "chapter3.h"
#include "chapter4.h"
#include "chapter5.h"
#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <array>

using std::cout;
using std::endl;
using std::cin;
//using namespace chapter3;

constexpr int MAX = 20;
constexpr int RAND_NUMS_TO_GENERATE = 1000;

int main()
{
    std::srand(std::time(nullptr));
    cout << "exercises from THINK LIKE A PROGRAMMER\n";

    std::vector<chapter3::student> studentArray = {
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

    // chapter 4
    // linked lists
    chapter4::student_collection sc;
    chapter4::list_node * node1 = new chapter4::list_node;
    node1->student_num = 1001; node1->grade = 78;
    chapter4::list_node * node2 = new chapter4::list_node;
    node2->student_num = 1002; node2->grade = 93;
    chapter4::list_node * node3 = new chapter4::list_node;
    node3->student_num = 1003; node3->grade = 85;
    sc = node1;
    //node1->next = NULL;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;
    node1 = node2 = node3 = NULL;
    chapter4::print_student_collection(sc);
    std::cout << "Grade average: " << chapter4::average_grade(sc) << std::endl;
    chapter4::add_record(sc, 1004,10);
    chapter4::print_student_collection(sc);
    std::cout << "Grade average: " << chapter4::average_grade(sc) << std::endl;
    chapter4::add_record(sc, 1005,65);
    chapter4::add_record(sc, 1006,100);
    chapter4::print_student_collection(sc);
    std::cout << "Grade average: " << chapter4::average_grade(sc) << std::endl;

    // string variable lenght
    /*
    chapter4::array_string stringArray = new char[5];
    strcpy(stringArray, "hello");

    for (int i = 0; i < 5; ++i) {
        std::cout << chapter4::character_at(stringArray, i);
    };
    std::cout << std::endl;
    chapter4::append_tester();
    chapter4::concatenate_tester();
    */
    // exercise 3.7
    /*
    cout << "exercise 3.7\n";
    chapter3::print_vector(integerArray);
    cout << chapter3::array_mode(integerArray) << endl;
    chapter3::print_vector(integerArrayDesc);
    cout << chapter3::array_mode(integerArrayDesc) << endl;
    chapter3::print_vector(random_integers);
    cout << chapter3::array_mode(random_integers) << endl;
    */
    // exercise 3.8
    /*
    cout << "exercise 3.8\n\n";
    chapter3::print_studentArray(studentArray);
    chapter3::insertion_sort_ascending(studentArray, chapter3::compare_by_grade);
    chapter3::print_studentArray(studentArray);
    chapter3::quartiles_student_grades(studentArray);
    */
    /*
    chapter3::hello_world();
    chapter3::print_studentArray(studentArray);
    chapter3::insertion_sort_descending(studentArray, chapter3::compare_by_grade);
    chapter3::print_studentArray(studentArray);
    chapter3::insertion_sort_ascending(studentArray, chapter3::compare_by_name);
    chapter3::print_studentArray(studentArray);
    chapter4::hello_world();

    chapter3::print_array(integerArray);
    std::cout << "check " << chapter3::is_sorted_ascending(integerArray, integerArray.size()) << std::endl;
    std::cout << "after sorting:" << std::endl;
    chapter3::insertion_sort_ascending(integerArray, chapter3::compare_by_int);
    chapter3::print_array(integerArray);
    std::cout << "check asc " << chapter3::is_sorted_ascending(integerArray, integerArray.size()) << std::endl;
    std::cout << "check des " << chapter3::is_sorted_descending(integerArray, integerArray.size()) << std::endl;
    chapter3::print_array(integerArrayDesc);
    std::cout << "check asc " << chapter3::is_sorted_ascending(integerArrayDesc, integerArrayDesc.size()) << std::endl;
    std::cout << "check des " << chapter3::is_sorted_descending(integerArrayDesc, integerArrayDesc.size()) << std::endl;
    std::cout << "median:" << chapter3::array_median(integerArray) << std::endl;
    std::cout << "median:" << chapter3::array_median(integerArrayDesc) << std::endl;
    */
    return EXIT_SUCCESS;
}