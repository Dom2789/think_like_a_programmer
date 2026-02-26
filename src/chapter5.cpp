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

    void student_record::print_record() {
        std::cout << " Student number: " << get_id();
        std::cout << " grade: "  << get_grade();
        std::cout << " name: " << get_name();
        std::cout << std::endl;
    }

    // constructor
    student_collection::student_collection() {
        _list_head = NULL;
    }

    void student_collection::add_record(const student_record& new_student) {
        auto* new_node = new student_node;
        new_node->student_data = new_student;
        new_node->next = _list_head;
        _list_head = new_node;
    };

    student_record student_collection::get_record_with_number(int id_num) {
        student_node* loop_ptr = _list_head;
        while (loop_ptr != NULL && loop_ptr->student_data.get_id() != id_num) {
            loop_ptr = loop_ptr->next;
        }
        if (loop_ptr == NULL) {
            student_record dummy_record(-1,-1,"");
            return dummy_record;
        } else {
            return loop_ptr->student_data;
        }
    };

    void student_collection::print_all_students() {
        student_node* loop_ptr = _list_head;
        while (loop_ptr != NULL) {
            loop_ptr->student_data.print_record();
            loop_ptr = loop_ptr->next;
        }
    };

    void student_collection::remove_record(int id_num) {
        student_node* loop_ptr = _list_head;
        student_node* loop_ptr_prev = NULL;
        while (loop_ptr != NULL && loop_ptr->student_data.get_id() != id_num) {
            loop_ptr_prev = loop_ptr;
            loop_ptr = loop_ptr->next;
        }
        if (loop_ptr == NULL) return;
        if (loop_ptr_prev == NULL) {
            _list_head = _list_head->next;
        } else {
            loop_ptr_prev->next = loop_ptr->next;
        }
        delete loop_ptr;
    };

    void student_collection::delete_list(student_list& list_ptr) {
        while (list_ptr != NULL) {
            student_node* temp = list_ptr;
            list_ptr = list_ptr->next;
            delete temp;
        }
    };

    // destructor
    student_collection::~student_collection() {
        delete_list(_list_head);
    }
};
