#include "chapter5.h"

namespace chapter5
{
    void hello_world()
    {
        std::cout << "Hello World 5\n";
    }

    bool student_record::is_valid_grade(int new_grade) {
        if (new_grade >= 0 && new_grade <= 100) {
            return true;
        }
        return false;
    }

    int student_record::get_grade() {
        return _grade;
    };

    void student_record::set_grade(int new_grade) {
        if (is_valid_grade(new_grade)) {
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

    std::string student_record::letter_grade() {
        std::string letter_grade;
        if (is_valid_grade(_grade)) {
            switch (_grade) {
                case 93 ... 100:
                    letter_grade = "A";
                    break;
                case 90 ... 92:
                    letter_grade = "A-";
                    break;
                case 87 ... 89:
                    letter_grade = "B+";
                    break;
                case 83 ... 86:
                    letter_grade = "B";
                    break;
                case 80 ... 82:
                    letter_grade = "B-";
                    break;
                case 77 ... 79:
                    letter_grade = "C+";
                    break;
                case 73 ... 76:
                    letter_grade = "C";
                    break;
                case 70 ... 72:
                    letter_grade = "C-";
                    break;
                case 67 ... 69:
                    letter_grade = "D+";
                    break;
                case 60 ... 66:
                    letter_grade = "D";
                    break;
                case 0 ... 59:
                    letter_grade = "F";
                    break;
                default:
                    letter_grade = "ERROR ";
                    break;
            }
        } else {
            letter_grade = "ERROR ";
        }
        return letter_grade;
    };

};
