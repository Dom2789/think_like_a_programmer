#ifndef CHAPTER4_
#define CHAPTER4_
#include <iostream>

namespace chapter4
{
    typedef char * array_string;
    void hello_world();
    char character_at(array_string s, int postion);
    void append (array_string& s, char c);
    void conactate(array_string& s1, array_string s2);
    int length(array_string s);
    void append_tester();
    void concatenate_tester();

}


#endif