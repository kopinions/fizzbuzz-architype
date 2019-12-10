//
// Created by liufh on 2019/12/3.
//

#include <iostream>
#include "Teacher.h"
#include "Student.h"

using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void Teacher::add_rule(int rule) {
    if (Teacher::queue.empty()) {
        cerr << "no any student when add rule!" << endl;
        return;
    }
    for (vector<Student>::iterator it = queue.begin(); it != queue.end(); ++it) {
        it->add_rule(rule);
    }
}

void Teacher::give_number() {
    cout << "Please give three integer little than 10:" << endl;
    int input;
    int count = 0;
    if (!Teacher::special_numbers.empty()) {
        Teacher::special_numbers.clear();
    }
    while (cin >> input && count != 3) {
        if (count < 3) {
            if (input < 2) {
                cout << "the input value: " << input << " is little than 2, try again: " << endl;
                continue;
            }
            if (input >= 10) {
                cout << "the input value: " << input << " is greater than 10, try again: " << endl;
                continue;
            }

            if (!Teacher::get_special_number().empty()) {
                vector<int> numbers = Teacher::get_special_number();
                bool isSame = false;
                for (vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
                    if (*it == input) {
                        cout << "the input value: " << input << " has already in numbers, try again:" << endl;
                        isSame = true;
                        continue;
                    }
                }
                if (isSame) {
                    continue;
                }
            }
            Teacher::special_numbers.push_back(input);
            count++;
//            cout << "add input: " << input << " into special numbers" << " count = " << count << endl;
        }
    }
//    cout << "numbers size is " << Teacher::get_special_number().size() << endl;
}

void Teacher::queue_student() {
    for (int i = 0; i < 100; ++i) {
        Student *student = new Student(i);
        student->set_special_numbers(Teacher::special_numbers);
        Teacher::queue.push_back(*student);
    }
}

vector<Student> Teacher::get_queue() {
    return Teacher::queue;
}

vector<int> Teacher::get_special_number() {
    return Teacher::special_numbers;
}