#ifndef CHAPTER5_
#define CHAPTER5_
#include <iostream>

#include "chapter4.h"

namespace chapter5
{
    void hello_world();
    int get_current_year();
    class string
    {
        typedef char * array_string;
        public:
            string();
            string(array_string &arr);
            char character_at(int position) const;
            void append (char c);
            void concatenate(array_string s2);
            array_string get_array() const;
            void set_array(array_string &new_array);
            int length() const;

        private:
            array_string _array;
            int length(array_string s) const;

    };
    class automobile
    {
        public:
            automobile();
            automobile(const std::string &manufacturer, const std::string &model, int model_year);
            void set_manufacturer(std::string manufacturer);
            void set_model(std::string model);
            void set_model_year(int new_year);
            std::string get_manufacturer();
            std::string get_model();
            int get_model_year();
            void print_data();
            void print_age();
        private:
            std:: string _manufacturer;
            std:: string _model_name;
            int _model_year;
    };
    class student_record {
        public:
            student_record();
            student_record(int new_grade, int new_id, std::string new_name);
            int get_grade();
            void set_grade(int new_grade);
            int get_id() const;
            void set_id(int new_id);
            std::string get_name();
            void set_name(std::string new_name);
            std::string letter_grade();
            void print_record();
        private:
            int _grade;
            int _id;
            std::string _name;
            bool is_valid_grade(int new_grade);
    };
    class sc_iterator;
    class student_collection{
        typedef bool (* first_student_policy)(student_record r1, student_record r2);
        struct student_node {
            student_record student_data;
            student_node* next;
        };
    public:
        student_collection();
        student_collection(const student_collection& original);
        ~student_collection();
        friend class sc_iterator;
        void add_record(const student_record& new_student);
        student_record get_record_with_number(int id_num);
        void remove_record(int id_num);
        void print_all_students();
        student_collection& operator= (const student_collection& rhs);
        sc_iterator first_item_iterator();
        // dependency injection
        void set_first_student_policy(first_student_policy f);
        student_record first_student();
    private:
        first_student_policy _current_policy;
        typedef student_node* student_list;
        student_list _list_head;
        void delete_list(student_list& list_ptr);
        student_list deep_copy(const student_list original);
    };
    class sc_iterator
    {
    public:
        sc_iterator();
        sc_iterator(student_collection::student_node * initial);
        void advance();
        bool past_end();
        student_record student();
    private:
        student_collection::student_node * current;
    };
    // function to inject into method set_first_student_policy of class student_collection
    inline bool higher_grade(student_record r1, student_record r2)
    {
        return r1.get_grade()>r2.get_grade();
    };
    inline bool lower_student_number(student_record r1, student_record r2)
    {
        return r1.get_id()<r2.get_id();
    };
    inline bool name_comes_first(student_record r1, student_record r2)
    {
        return strcmp(r1.get_name().c_str(), r2.get_name().c_str()) < 0;
    };
}

#endif