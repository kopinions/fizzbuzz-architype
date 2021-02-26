//
// Created by liufh on 2019/12/3.
//

#ifndef FIZZBUZZ_STUDENT_H
#define FIZZBUZZ_STUDENT_H

#include <vector>
#include <string>

using std::vector;
using std::string;

enum RuleType {
    RULE_ONE,
    RULE_TWO,
    RULE_THREE,
    RULE_FOUR
};

class Student {

public:
    Student(int i);
    string count_off();
    int getIndex() const;
    void add_rule(int rule_type);
    vector<int> get_rules() const;
    void set_special_numbers(vector<int> special_numbers);
    string test_handle_multiple_single_rule(int special_number, const char* str);
    string test_handle_highest_priority_rule(int special_number);

private:
    string handle_multiple_single_rule(int special_number, const char* str);
    string handle_highest_priority_rule(int special_number);

private:
    int index;
    vector<int> rules;
    vector<int> special_numbers;
};


#endif //FIZZBUZZ_STUDENT_H
