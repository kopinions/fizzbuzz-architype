#include <gtest/gtest.h>
#include <Teacher.h>
#include <Student.h>

using std::cout;
using std::endl;

TEST(StudentsTest, all_countoff_same_as_position_when_rule_is_empty) {
    Teacher *teacher = new Teacher();
    teacher->queue_student();
    vector<Student> students = teacher->get_queue();
    for(vector<Student>::iterator it = students.begin(); it != students.end(); ++it) {
        EXPECT_EQ(atoi(it->count_off().c_str()), it->getIndex());
    }
}

//how to test input operator
TEST(GivenNumberTest, three_num_should_little_than_ten) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    vector<int> numbers = teacher->get_special_number();
    EXPECT_EQ(numbers.size(), 3);
    EXPECT_LT(numbers.at(0), 10);
    EXPECT_LT(numbers.at(1), 10);
    EXPECT_LT(numbers.at(2), 10);
}

TEST(IsMultipleSingleNumberTest, is_multiple_single_number_should_print_Fixstr) {
    Teacher *teacher = new Teacher();
    teacher->queue_student();
    vector<Student> students = teacher->get_queue();
    const char *print_str = "Fizz";
    EXPECT_EQ(strcmp(students.at(9).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(18).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(27).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(36).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(45).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(54).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(63).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(72).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(81).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(90).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(99).test_handle_multiple_single_rule(9, print_str).c_str(), print_str), 0);
}

TEST(HighestPrioRuleTest, contains_special_number_should_print_Fizz) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    teacher->queue_student();
    teacher->add_rule(RULE_FOUR);
    vector<Student> students = teacher->get_queue();
    const char *print_str = "Fizz";
    int first = 3;
    EXPECT_EQ(strcmp(students.at(3).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(13).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(23).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(30).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(31).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(32).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(33).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(34).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(35).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(36).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(37).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(38).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(39).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(43).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(53).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(63).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(73).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(83).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(93).test_handle_highest_priority_rule(first).c_str(), print_str), 0);
}

TEST(FirstAndSecondRuleTest, multiple_1st_2nd_special_number_should_print_FizzBuzz) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    teacher->queue_student();
    teacher->add_rule(RULE_ONE);
    teacher->add_rule(RULE_TWO);
    vector<Student> students = teacher->get_queue();
    const char *print_str = "FizzBuzz";
    int first = 3;
    int second = 4;
    EXPECT_EQ(strcmp(students.at(12).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(24).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(36).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(48).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(96).count_off().c_str(), print_str), 0);
}

TEST(FirstAndSecondAndThirdRuleTest, multiple_1st_2nd_3rd_special_number_should_print_FizzBuzzWhizz) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    teacher->queue_student();
    teacher->add_rule(RULE_ONE);
    teacher->add_rule(RULE_TWO);
    teacher->add_rule(RULE_THREE);
    vector<Student> students = teacher->get_queue();
    const char *print_str = "FizzBuzzWhizz";
    int first = 3;
    int second = 4;
    int third = 5;
    EXPECT_EQ(strcmp(students.at(60).count_off().c_str(), print_str), 0);
}

TEST(SecondAndThirdRuleTest, multiple_2nd_3rd_special_number_should_print_FizzBuzzWhizz) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    teacher->queue_student();
    teacher->add_rule(RULE_ONE);
    teacher->add_rule(RULE_TWO);
    teacher->add_rule(RULE_THREE);
    vector<Student> students = teacher->get_queue();
    const char *print_str = "BuzzWhizz";
    int first = 3;
    int second = 4;
    int third = 5;
    EXPECT_EQ(strcmp(students.at(20).count_off().c_str(), print_str), 0);
}

TEST(FirstAndThirdRuleTest, multiple_1st_3rd_special_number_should_print_FizzWhizz) {
    Teacher *teacher = new Teacher();
    teacher->give_number();
    teacher->queue_student();
    teacher->add_rule(RULE_ONE);
    teacher->add_rule(RULE_TWO);
    teacher->add_rule(RULE_THREE);
    vector<Student> students = teacher->get_queue();
    const char *print_str = "FizzWhizz";
    int first = 3;
    int second = 4;
    int third = 5;
    EXPECT_EQ(strcmp(students.at(15).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(45).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(75).count_off().c_str(), print_str), 0);
    EXPECT_EQ(strcmp(students.at(90).count_off().c_str(), print_str), 0);
}
