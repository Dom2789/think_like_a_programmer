#include "chapter4.h"

namespace chapter4
{
    void hello_world()
    {
        std::cout << "Hello World 4\n";
    }

    void append_tester() {
        array_string a = new char[5];
        a[0] = 'a'; a[1] = 'b'; a[2] = 'c'; a[3] = 'd'; a[4] = 0;
        append(a, '!');
        std::cout << a << std::endl;
        array_string b = new char[5];
        b[0] = 0;
        append(b, '!');
        std::cout << b << std::endl;
    };

    char character_at(array_string s, int postion) {
        return s[postion];
    };

    int length(array_string s) {
        int length = 0;
        // counts chars without terminating 0
        while (s[length]!= 0) length++;
        return length;
    };

    void append(array_string& s, char c) {
        int length_old = length(s);

        array_string new_s = new char[length_old+2];
        // copy all characters from old string except terminating 0
        for (int i = 0; i < length_old; ++i) new_s[i] = s[i];
        // append new character and put terminating 0
        new_s[length_old] = c;
        new_s[length_old+1] = 0;
        delete[] s;
        s = new_s;
    };

    void concatenate(array_string& s1, array_string s2) {
        int length1 = length(s1);
        int length2 = length(s2);
        array_string new_s = new char[length1+length2+1];
        for (int i = 0; i < length1; ++i) new_s[i] = s1[i];
        for (int i = 0; i < length2; ++i) new_s[length1+i] = s2[i];
        new_s[length1+length2] = 0;
        delete[] s1;
        s1 = new_s;
    };

    void concatenate_tester() {
        array_string a = new char[6];
        a[0] = 'H'; a[1] = 'e'; a[2] = 'l'; a[3] = 'l'; a[4] = 'o'; a[5] = 0;
        array_string b = new char[7];
        b[0] = 'W'; b[1] = 'o'; b[2] = 'r'; b[3] = 'l'; b[4] = 'd'; b[5] = '!'; b[6] = 0;
        std::cout << a << " + " << b << std::endl;
        concatenate(a,b);
        std::cout << a << std::endl;
        array_string c = new char[1];
        c[0] = 0;
        concatenate(c ,a);
        std::cout << c << std::endl << a << std::endl;
        std::cout << (void *) c << std::endl << (void *) a << std::endl;

    };

    //linked list

    void print_student_collection(const student_collection& sc) {
        std::cout << "Student collection:" << std::endl;
        list_node* loop_ptr = sc;
        do {
            std::cout << "Addr: " << (void *) loop_ptr;
            std::cout << " Student number: " << loop_ptr->student_num << " grade: "  << loop_ptr->grade << std::endl;
            loop_ptr = loop_ptr->next;
        } while (loop_ptr!=NULL);
        std::cout << std::endl;
    };

    void add_record(student_collection& sc, int student_num, int grade) {
        list_node* new_node = new list_node;
        new_node->student_num = student_num;
        new_node->grade = grade;
        new_node->next = sc;
        sc = new_node;
    };

    double average_grade(student_collection sc) {
        if (sc == NULL) return 0.0;
        double sum_grades = 0;
        int counter = 0;
        list_node* loop_ptr = sc;
        do {
            counter++;
            sum_grades = sum_grades + loop_ptr->grade;
            loop_ptr = loop_ptr->next;
        } while (loop_ptr!=NULL);
        return sum_grades/counter;
    };

}