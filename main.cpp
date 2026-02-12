#include <cstdlib>
#include <iostream>
#include "chapter3.h"
#include "chapter4.h"
#include "chapter5.h"
#include <string>

using std::cout;
using std::cin;
//using namespace chapter3;

int main()
{
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
        {98, 10012, "Tomy"}
    };

    std::vector<int> integerArray = {33,23,4,890,31,10009,675,1};
    /*
    chapter3::hello_world();
    chapter3::print_studentArray(studentArray);
    chapter3::insertion_sort_descending(studentArray, chapter3::compare_by_grade);
    chapter3::print_studentArray(studentArray);
    chapter3::insertion_sort_ascending(studentArray, chapter3::compare_by_name);
    chapter3::print_studentArray(studentArray);
    chapter4::hello_world();
    */
    chapter3::print_array(integerArray);
    std::cout << "sorted:" << std::endl;
    chapter3::insertion_sort_ascending(integerArray, chapter3::compare_by_int);
    chapter3::print_array(integerArray);
    std::cout << "median:" << chapter3::array_median(integerArray) << std::endl;
    return EXIT_SUCCESS;
}