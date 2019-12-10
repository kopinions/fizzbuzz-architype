#include <iostream>
#include "Teacher.h"
#include "Student.h"

using std::cout;
using std::endl;

int main(int argc, char ** argv) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    teacher->queue_student();
    teacher->add_rule(RULE_FOUR);
    teacher->add_rule(RULE_ONE);
    teacher->add_rule(RULE_TWO);
    teacher->add_rule(RULE_THREE);
    vector<Student> students = teacher->get_queue();
    for (vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        cout << "Student[" << it->getIndex() << "] count off ===>" << it->count_off() << endl;
    }
    return 0;
}

