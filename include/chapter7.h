#ifndef CHAPTER7_
#define CHAPTER7_
#include <iostream>
#include <forward_list>
#include "chapter5.h"

namespace chapter7
{
    void hello_world();

    enum class first_student_policy { not_set, higher_grade, lower_student_number, name_comes_first };

    class sc_iterator7;

    class student_collection{
        typedef bool (* func_first_student_policy)(chapter5::student_record r1, chapter5::student_record r2);
        struct student_node {
            chapter5::student_record student_data;
            student_node* next;
        };
    public:
        student_collection();
        ~student_collection();
        friend class sc_iterator7;
        void add_record(const chapter5::student_record& new_student);
        chapter5::student_record get_record_with_number(int id_num);
        void remove_record(int id_num);
        void print_all_students();
        student_collection& operator= (const student_collection& rhs);
        sc_iterator7 first_item_iterator();
        // dependency injection
        void set_first_student_policy(first_student_policy f);
        chapter5::student_record first_student();
    private:
        func_first_student_policy _current_policy;
        typedef student_node* student_list;
        student_list _list_head;
        void delete_list(student_list& list_ptr);
        student_list deep_copy(const student_list original);
        static bool higher_grade(chapter5::student_record r1, chapter5::student_record r2);
        static bool lower_student_number(chapter5::student_record r1, chapter5::student_record r2);
        static bool name_comes_first(chapter5::student_record r1, chapter5::student_record r2);
    };

    class sc_iterator7
    {
    public:
        sc_iterator7();
        sc_iterator7(student_collection::student_node * initial);
        void advance();
        bool past_end();
        chapter5::student_record student();
    private:
        student_collection::student_node * current;
    };

    struct student_record {
        int student_num;
        int grade;
    };
    template <typename Container>
    void print_all_students(Container &students) {
        if (students.empty()) std::cout << "No students" << std::endl;
        else
        {
            std::cout << "Student collection:" << std::endl;
            for (auto student : students)
            {
                std::cout << " Student number: " << student.student_num << " grade: "  << student.grade << std::endl;
            }
            std::cout << std::endl;
        }
    };
    void add_record(std::forward_list<student_record> &students, int student_number, int grade);
    double average_grade(const std::forward_list<student_record> &students);
    void add_record(std::vector<student_record> &students, int student_number, int grade);

}

#endif