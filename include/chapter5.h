#ifndef CHAPTER5_
#define CHAPTER5_
#include <iostream>

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
    class student_collection{
        private:
            struct student_node {
                student_record student_data;
                student_node* next;
            };
        public:
            student_collection();
            ~student_collection();
            student_collection(const student_collection& original);
            void add_record(const student_record& new_student);
            student_record get_record_with_number(int id_num);
            void remove_record(int id_num);
            void print_all_students();
            student_collection& operator= (const student_collection& rhs);
        private:
            typedef student_node* student_list;
            student_list _list_head;
            void delete_list(student_list& list_ptr);
            student_list deep_copy(const student_list original);
    };
}


#endif