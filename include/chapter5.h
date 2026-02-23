#ifndef CHAPTER5_
#define CHAPTER5_
#include <iostream>

namespace chapter5
{
    void hello_world();
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
        private:
            int _grade;
            int _id;
            std::string _name;
            bool is_valid_grade(int new_grade);
    };
}


#endif