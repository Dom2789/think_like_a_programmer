#include "chapter5.h"
#include <ctime>

namespace chapter5
{
    void hello_world()
    {
        std::cout << "Hello World 5\n";
    }

    // default conctructor
    sc_iterator::sc_iterator()
    {
        current = nullptr;
    }

    // paramter cotr
    sc_iterator::sc_iterator(student_collection::student_node* initial)
    {
        current = initial;
    }

    void sc_iterator::advance()
    {
        if (current != nullptr)
            current = current->next;
    }

    bool sc_iterator::past_end()
    {
        return current == nullptr;
    }

    student_record sc_iterator::student()
    {
        if (current == nullptr)
        {
            student_record dummy(1, -1, "");
            return dummy;
        } else
        {
            return current->student_data;
        }
    }

    //}

    string::string()
    {
        _array = new char[0];
    }

    string::string(array_string& arr)
    {
        _array = arr;
        arr = nullptr;
    }

    string::array_string string::get_array() const
    {
        return _array;
    }

    void string::set_array(array_string &new_array)
    {
        _array = new_array;
        new_array = nullptr;
    }

    char string::character_at(int position) const
    {
        if (position >= length()) return 0;
        return _array[position];
    }

    int string::length() const
    {
        int length = 0;
        // counts chars without terminating 0
        while (_array[length]!= 0) length++;
        return length;
    };

    int string::length(array_string s) const
    {
        int length = 0;
        // counts chars without terminating 0
        while (s[length]!= 0) length++;
        return length;
    };

    void string::append (char c)
    {
        int length_old = length();

        array_string new_s = new char[length_old+2];
        // copy all characters from old string except terminating 0
        for (int i = 0; i < length_old; ++i) new_s[i] = _array[i];
        // append new character and put terminating 0
        new_s[length_old] = c;
        new_s[length_old+1] = 0;
        delete[] _array;
        _array = new_s;
    };

    void string::concatenate(array_string s2) {
        int length1 = length();
        int length2 = length(s2);
        array_string new_s = new char[length1+length2+1];
        for (int i = 0; i < length1; ++i) new_s[i] = _array[i];
        for (int i = 0; i < length2; ++i) new_s[length1+i] = s2[i];
        new_s[length1+length2] = 0;
        delete[] _array;
        _array = new_s;
    };

    int get_current_year() {
        std::time_t t = std::time(0); // Get current time
        const std::tm* now = std::localtime(&t);
        const int year = (now->tm_year + 1900);
        return year;
    }

    void automobile::print_data()
    {
        std::cout << get_model_year() << " " << get_manufacturer() << " " << get_model();
        std::cout << std::endl;
    }

    void automobile::print_age()
    {
        const int age = get_current_year() - get_model_year();
        std::cout << get_manufacturer() << " " << get_model() << " is " << age << " years old." << std::endl;
    }

    // default constructor
    automobile::automobile() {
        _manufacturer = "BMW";
        _model_name = "M3";
        _model_year = 1989;
    }

    // cotr
    automobile::automobile(const std::string &manufacturer, const std::string &model, int model_year) {
        _manufacturer = manufacturer;
        _model_name = model;
        _model_year = model_year;
    }

    void automobile::set_manufacturer(std::string manufacturer) {
        _manufacturer = manufacturer;
    }

    void automobile::set_model(std::string model) {
        _model_name = model;
    }

    void automobile::set_model_year(int new_year) {
        _model_year = new_year;
    }

    std::string automobile::get_manufacturer() {
        return _manufacturer;
    }

    std::string automobile::get_model() {
        return _model_name;
    }

    int automobile::get_model_year() {
        return _model_year;
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
        _current_policy = nullptr;
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

    student_collection::student_list student_collection::deep_copy(const student_list original){
        if (original == NULL)
        {
            return NULL;
        }
        student_list new_list = new student_node;
        new_list->student_data = original->student_data;
        student_node* old_loop_ptr = original->next;
        student_node* new_loop_ptr = new_list;
        while (old_loop_ptr != NULL)
        {
            new_loop_ptr->next = new student_node;
            new_loop_ptr = new_loop_ptr->next;
            new_loop_ptr->student_data = old_loop_ptr->student_data;
            old_loop_ptr = old_loop_ptr->next;
        }
        new_loop_ptr->next = NULL;
        return new_list;
    }

    student_collection& student_collection::operator=(const student_collection& rhs){
        if (this == &rhs)
        {
            delete_list(_list_head);
            _list_head = deep_copy(rhs._list_head);
        }
        return *this;
    }

    // copy constructor
    student_collection::student_collection(const student_collection& original)
    {
        _list_head = deep_copy(original._list_head);
    }

    sc_iterator student_collection::first_item_iterator()
    {
        return {_list_head};
    }

    void student_collection::set_first_student_policy(first_student_policy f)
    {
        _current_policy = f;
    }

    student_record student_collection::first_student()
    {
        if (_list_head == NULL || _current_policy == NULL)
        {
            student_record dummy = student_record(-1,-1,"");
            return dummy;
        }
        student_node* loop_ptr = _list_head;
        student_record first_student = loop_ptr->student_data;
        loop_ptr = loop_ptr->next;
        while (loop_ptr != NULL)
        {
            if (_current_policy(loop_ptr->student_data, first_student))
            {
                first_student = loop_ptr->student_data;
            }
            loop_ptr = loop_ptr->next;
        }
        return first_student;
    }
};
