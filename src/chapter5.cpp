#include "chapter5.h"

namespace chapter5
{
    void hello_world()
    {
        std::cout << "Hello World 5\n";
    }

    int student_record::get_grade() {
        return _grade;
    };

    void student_record::set_grade(int new_grade) {
        if (new_grade >= 0 && new_grade <= 100) {
            _grade = new_grade;
        };
    };

    int student_record::get_id() const {
        return _id;
    };
    void student_record::set_id(int new_id) {
        _id = new_id;
    };

    std::string student_record::get_name() {
        return _name;
    };

    void student_record::set_name(std::string new_name) {
        _name = new_name;
    };

    // constructor
    student_record::student_record(int new_grade, int new_id, const std::string new_name) {
        set_grade(new_grade);
        set_id(new_id);
        set_name(new_name);
    };

    // default constructor
    student_record::student_record() {
        set_grade(0);
        set_id(-1);
        set_name("");
    };
};
