#include <gtest/gtest.h>
#include "../lib/main_func.h"
#include "../lib/console.cpp"


TEST(Password_from_list , no_threading_version_file_with_passwords_exists){
    std::string res1 = list_without_thread("Passwords\\password_list.txt" , 980537223); //exists 123456789a
    std::string res2 = list_without_thread("Passwords\\password_list.txt" , 3116885959); //exists BUSTER
    std::string res3 = list_without_thread("Passwords\\password_list.txt",	127154670); //exists bballer1
    std::string res4 = list_without_thread("Passwords\\password_list.txt" , 429525991); //exists p00per

    ASSERT_EQ(res1  , "123456789a");
    ASSERT_EQ(res2 , "BUSTER");
    ASSERT_EQ(res3  , "bballer1");
    ASSERT_EQ(res4  , "p00per");
}

TEST(Password_from_list , no_threading_version_file_with_passwords_exists_no_such_file){
    std::string res = list_without_thread("qwert321\\password_list.txt" , 980537223); //exists "[-] Can not open this file\n"
    ASSERT_EQ(res , "[-] Can not open this file\n");
}

TEST(Password_from_list , no_threading_version_file_with_passwords_exists_no_matches){
    std::string res = list_without_thread("Passwords\\password_list.txt" , 	1988263785); //exists ""
    ASSERT_EQ(res , "");
}



TEST(Password_from_list , threading_version_file_with_passwords_exists){
    std::string res1 = list_with_threads("Passwords\\password_list.txt" , 980537223); //exists 123456789a
    std::string res2 = list_with_threads("Passwords\\password_list.txt" , 3116885959); //exists BUSTER
    std::string res3 = list_with_threads("Passwords\\password_list.txt",	127154670); //exists bballer1
    std::string res4 = list_with_threads("Passwords\\password_list.txt" , 429525991); //exists p00per

    ASSERT_EQ(res1  , "123456789a");
    ASSERT_EQ(res2 , "BUSTER");
    ASSERT_EQ(res3  , "bballer1");
    ASSERT_EQ(res4  , "p00per");
}

TEST(Password_from_list , threading_version_file_with_passwords_exists_no_such_file){
    std::string res = list_with_threads("qwert321\\password_list.txt" , 980537223); //exists "[-] Can not open this file\n"
    ASSERT_EQ(res , "[-] Can not open this file\n");
}

TEST(Password_from_list , threading_version_file_with_passwords_exists_no_matches){
    std::string res = list_with_threads("Passwords\\password_list.txt" , 	1988263785); //exists ""
    ASSERT_EQ(res , "");
}


TEST(Passwords_from_regex , no_threading_version){
    std::string res1 = shit_with_regex(2724056820 , "[A-Z]{4}ETHISLABA" , "50000000"); // exists "IHATETHISLABA"
    std::string res2 = shit_with_regex(318978690 , "[a-z]{1}lkhjasdfhsldkgfhs4irg" , "1"); //exists ""

    ASSERT_EQ(res1 , "IHATETHISLABA");
    ASSERT_EQ(res2 , "");
}

TEST(Passwords_from_regex , threading_version){
    std::string res1 = thread_shit_with_regex(2724056820 , "[A-Z]{4}ETHISLABA" , "50000000"); // exists "IHATETHISLABA"
    std::string res2 = thread_shit_with_regex(318978690 , "[a-z]{1}lkhjasdfhsldkgfhs4irg" , "1"); //exists ""

    ASSERT_EQ(res1 , "IHATETHISLABA");
    ASSERT_EQ(res2 , "");
}

//Консоль тестировать не буду, она и так рабочая а работяги дофига