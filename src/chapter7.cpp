#include "chapter7.h"

namespace chapter7
{
    void hello_world()
    {
        std::cout << "Hello World 7\n";
    }

    // constructor
    student_collection::student_collection() {
        _list_head = nullptr;
        _current_policy = nullptr;
    }

    void student_collection::add_record(const chapter5::student_record& new_student) {
        auto* new_node = new student_node;
        new_node->student_data = new_student;
        new_node->next = _list_head;
        _list_head = new_node;
    };

    chapter5::student_record student_collection::get_record_with_number(int id_num) {
        student_node* loop_ptr = _list_head;
        while (loop_ptr != NULL && loop_ptr->student_data.get_id() != id_num) {
            loop_ptr = loop_ptr->next;
        }
        if (loop_ptr == NULL) {
            chapter5::student_record dummy_record(-1,-1,"");
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

    sc_iterator7 student_collection::first_item_iterator()
    {
        return {_list_head};
    }

    void student_collection::set_first_student_policy(first_student_policy f)
    {
        switch (f) {
        case first_student_policy::not_set:
            _current_policy = nullptr;
            break;
        case first_student_policy::higher_grade:
            _current_policy = higher_grade;
            break;
        case first_student_policy::lower_student_number:
            _current_policy = lower_student_number;
            break;
        case first_student_policy::name_comes_first:
            _current_policy  = name_comes_first;
            break;
        }

    }

    chapter5::student_record student_collection::first_student()
    {
        if (_list_head == nullptr || _current_policy == nullptr)
        {
            chapter5::student_record dummy = chapter5::student_record(-1,-1,"");
            return dummy;
        }
        student_node* loop_ptr = _list_head;
        chapter5::student_record first_student = loop_ptr->student_data;
        loop_ptr = loop_ptr->next;
        while (loop_ptr != nullptr)
        {
            if (_current_policy(loop_ptr->student_data, first_student))
            {
                first_student = loop_ptr->student_data;
            }
            loop_ptr = loop_ptr->next;
        }
        return first_student;
    }

    bool student_collection::higher_grade(chapter5::student_record r1, chapter5::student_record r2)
    {
        return r1.get_grade()>r2.get_grade();
    };
    bool student_collection::lower_student_number(chapter5::student_record r1, chapter5::student_record r2)
    {
        return r1.get_id()<r2.get_id();
    };
    bool student_collection::name_comes_first(chapter5::student_record r1, chapter5::student_record r2)
    {
        return strcmp(r1.get_name().c_str(), r2.get_name().c_str()) < 0;
    };

    // iterator class
    // default conctructor
    sc_iterator7::sc_iterator7()
    {
        current = nullptr;
    }

    // paramter cotr
    sc_iterator7::sc_iterator7(student_collection::student_node* initial)
    {
        current = initial;
    }

    void sc_iterator7::advance()
    {
        if (current != nullptr)
            current = current->next;
    }

    bool sc_iterator7::past_end()
    {
        return current == nullptr;
    }

    chapter5::student_record sc_iterator7::student()
    {
        if (current == nullptr)
        {
            chapter5::student_record dummy(1, -1, "");
            return dummy;
        } else
        {
            return current->student_data;
        }
    }

}