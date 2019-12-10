//
// Created by liufh on 2019/12/3.
//
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include "Student.h"

using std::stringstream;
using std::cout;
using std::endl;
using std::find;
using std::cerr;

Student::Student(int i) {
    Student::index = i;
}

void Student::add_rule(int rule_type) {
    Student::rules.push_back(rule_type);
}

vector<int> Student::get_rules() const {
    return Student::rules;
}

void Student::set_special_numbers(vector<int> special_numbers) {
    Student::special_numbers = special_numbers;
}

string Student::handle_highest_priority_rule(int special_number) {
    int index_1 = Student::index / 10;
    int index_2 = Student::index % 10;
    if ((special_number == index_1) || (special_number == index_2)) {
        return "Fizz";
    } else {
        return "handle_below";
    }
}

string Student::test_handle_highest_priority_rule(int special_number) {
    int index_1 = Student::index / 10;
    int index_2 = Student::index % 10;
    if ((special_number == index_1) || (special_number == index_2)) {
        return "Fizz";
    } else {
        return "handle_below";
    }
}

string Student::handle_multiple_single_rule(int special_number, const char *str) {
    if (Student::index >= special_number) {
        int index_1 = Student::index / special_number;
        int index_2 = Student::index % special_number;
        if ((index_1 > 0) && (0 == index_2)) {
            string str_obj(str);
            return str_obj;
        }
    }
    return "handle_below";
}

string Student::test_handle_multiple_single_rule(int special_number, const char *str) {
    if (Student::index >= special_number) {
        int index_1 = Student::index / special_number;
        int index_2 = Student::index % special_number;
        if ((index_1 > 0) && (0 == index_2)) {
            string str_obj(str);
            return str_obj;
        }
    }
    return "handle_below";
}

bool has_rule(vector<int> rules, int rule_type) {
    bool has_contain = false;
    for (vector<int>::const_iterator it = rules.begin(); it != rules.end(); ++it) {
        if (*it == rule_type) {
            has_contain = true;
        }
    }
    return has_contain;
}

string Student::count_off() {
    bool has_rule_flag = !get_rules().empty();
    string result;
    if (has_rule_flag) {
        if (special_numbers.empty()) {
            cerr << "has rule but has no special numbers!" << endl;
            return "ERROR";
        }
        vector<int> rules = get_rules();
//        cout << "rules size = " << rules.size() << endl;
        if (has_rule(rules, RULE_FOUR)) {
            result = handle_highest_priority_rule(special_numbers.at(0));
            if (strcmp(result.c_str(), "Fizz") == 0) {
                return result;
            }
        }
        if (has_rule(rules, RULE_ONE)) {
//            cout << "has rule_one " << endl;
            result = handle_multiple_single_rule(special_numbers.at(0), "Fizz");
        }
        if (has_rule(rules, RULE_TWO)) {
//            cout << "has rule_two " << "and after rule_one result = " << result << endl;
            string tmp_1 = handle_multiple_single_rule(special_numbers.at(1), "Buzz");
//            cout << "after rule_two tmp_1 = " << tmp_1 << endl;
            if (strcmp(tmp_1.c_str(), "Buzz") == 0) {
                if (strcmp(result.c_str(), "Fizz") == 0) {
//                    cout << "tmp_1 is Buzz and result is Fizz" << endl;
                    result += tmp_1;
//                    cout << " connect tmp_1 and result =" << result << endl;
                } else {
                    result = tmp_1;
                }
            }
        }
        if (has_rule(rules, RULE_THREE)) {
//            cout << "has rule_three " << "and after rule_two result = " << result << endl;
            string tmp_2 = handle_multiple_single_rule(special_numbers.at(2), "Whizz");
            if (strcmp(tmp_2.c_str(), "Whizz") == 0) {
                if (strcmp(result.c_str(), "handle_below") != 0) {
                    result += tmp_2;
                } else {
                    result = tmp_2;
                }
            }
        }

        if (strcmp(result.c_str(), "handle_below") == 0) {
            stringstream ss;
            ss << Student::index;
            string str = ss.str();
//            cout << " student index = " << Student::index << " str = " << str << endl;
            return str;
        } else {
//            cout << " student index = " << Student::index << " result = " << result << endl;
            return result;
        }
//        result = handle_highest_priority_rule(special_numbers.at(0));
    } else {
        //There is no any rule
        stringstream ss;
        ss << Student::index;
        string str = ss.str();
        return str;
    }
}

int Student::getIndex() const {
    return Student::index;
}