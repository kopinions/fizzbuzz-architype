//
// Created by liufh on 2019/12/3.
//
#ifndef FIZZBUZZ_TEACHER_H
#define FIZZBUZZ_TEACHER_H

#include <vector>
#include "Student.h"

using std::vector;

class Teacher {
public:
    void queue_student();
    vector<Student> get_queue();
    void give_number();
    vector<int> get_special_number();
    void add_rule(int rule);

private:
    vector<Student> queue{};
    vector<int> special_numbers;
};

#endif //FIZZBUZZ_TEACHER_H
