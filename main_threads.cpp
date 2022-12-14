#include "lib/main_func.h"
#include "lib/console.cpp"


int main(int argc , char** argv , char** env){

  Args cons = console(argc , argv);
  uint_least32_t number  = cons.first.first;
  char* param = cons.first.second;
  InputType type = cons.second;

   if (compare(param , "0xCAFEBABE") && number == 0) {
       return 0;
    }

    if (type == InputType::list){
        std::string res = list_with_threads(param ,number);
        std::cout << res;
    } else{
        std::string number_of_pass;
        std::cout << "[***] Input number of passwords to generate: ";
        std::cin >> number_of_pass;
        std::string result = thread_shit_with_regex(number , param , number_of_pass);
        std::cout << result;
    }
    return 0;
}