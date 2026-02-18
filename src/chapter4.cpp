#include "chapter4.h"

namespace chapter4
{
    void hello_world()
    {
        std::cout << "Hello World 4\n";
    }

    // variable lenght string

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

    array_string substring(array_string s, int start, int length) {
        array_string new_s = new char[length+1];
        for (int i = 0; i < length; ++i) {
            if (s[start+1]==0) break;
            new_s[i] = s[start+i];
        }
        new_s[length] = 0;
        return new_s;
    };

    int find_substring(array_string s, array_string substring, int len_s, int len_sub) {
        // finds first occurrence of substring
        for (int i = 0; i < len_s; ++i) {
            if (len_sub > len_s - i) {break;}
            else {
                bool found = true;
                for (int j = 0; j < len_sub; ++j) {
                    if (s[i+j] != substring[j]){
                        found = false;
                        break;
                    }
                }
                if (found == true) {
                    return i;
                }
            }
        };
        return -1;
    };

    void replace_string(array_string source, array_string target, array_string replace_text) {
        // not the most efficient because first part of the string gets searched again and again
        int len_target = length(target);
        int first_occurence;
        do {
            int len_source = length(source);
            first_occurence = find_substring(source, target, len_source, len_target);
            if (first_occurence != -1) {
                array_string tail = new char[len_source-first_occurence-len_target+1];
                for (int i = 0; i < len_source-first_occurence-len_target; ++i) {
                    tail[i] = source[i+first_occurence+len_target];
                }
                tail[len_source-first_occurence-len_target] = 0;
                std::cout << source << std::endl;
                source = substring(source, 0 , first_occurence);
                concatenate(source, replace_text);
                concatenate(source, tail);
                std::cout << tail << std::endl;
                std::cout << source << std::endl;
                delete[] tail;
            };
        }while (first_occurence!=-1);
    };

    // string with length as first entry
    char character_at_l(array_string_l s, int postion) {
        return s[postion+1];
    };

    void append_l (array_string_l& s, char c) {
        array_string_l new_s = new char[s[0]+2];
        // copy all characters from old string except terminating 0
        for (int i = 1; i <= s[0]; ++i) new_s[i] = s[i];
        // append new character and put terminating 0
        new_s[s[0]+1] = c;
        new_s[s[0]] = s[0]+1;
        delete[] s;
        s = new_s;
    };

    void concatenate_l(array_string_l &s1, array_string_l s2) {
        array_string_l new_s = new char[s1[0]+s2[0]+1];
        for (int i = 0; i < s1[0]; ++i) new_s[i] = s1[i];
        for (int i = 0; i < s2[0]; ++i) new_s[s1[0]+i] = s2[i];
        new_s[s1[0]+s2[0]] = 0;
        delete[] s1;
        s1 = new_s;
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