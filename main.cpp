#include <cstdlib>
#include <iostream>
#include "chapter3.h"
#include "chapter4.h"
#include "chapter5.h"

using std::cout;
using std::cin;
//using namespace chapter3;

int main()
{
    cout << "excercises from THINK LIKE A PROGRAMMER\n";
    chapter3::hello_world();
    chapter4::hello_world();
    return EXIT_SUCCESS;
}