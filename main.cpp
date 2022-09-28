#include "lib/main_func.cpp"
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
    list_without_thread(param ,number);
  }else{
      std::string number_of_pass;
      std::cout << "[***] Input number of passwords to generate: ";
      std::cin >> number_of_pass;
      std::string sys_call = "Passwords\\scr_modules\\gen_reg.exe --reg " + std::string(param)  + " --num " + number_of_pass; 
      system(sys_call.c_str());
      list_without_thread("Passwords\\tmp_regex.txt" , number);
      std::filesystem::remove("Passwords\\tmp_regex.txt");
  }
  return 0;
}