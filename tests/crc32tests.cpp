#include "gtest/gtest.h"
#include "main_func.cpp"


TEST(Password_from_list , no_threading_version_file_with_passwords_exists){
    std::string res1 = list_without_thread("Passwords\\passwords_list.txt" , 980537223); //exists 123456789a
    std::string res2 = list_without_thread("Passwords\\passwords_list.txt" , 3116885959); //exists BUSTER
    std::string res3 = list_without_thread("Passwords\\passwords_list.txt",	127154670); //exists bballer1
    std::string res4 = list_without_thread("Passwords\\passwords_list.txt" , 429525991);// exists p00per

    //ASSERT_EQ(res1  , "123456789a");
   // ASSERT_EQ(res2 , "BUSTER");
   // ASSERT_EQ(res3  , "bballer1");
    //ASSERT_EQ(res4  , "p00per");
}