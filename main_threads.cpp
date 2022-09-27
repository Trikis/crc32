#include "lib/main_func.cpp"
#include "lib/console.cpp"


int main(int argc , char** argv , char** env){

   std::pair<uint_least32_t , char*> cons = console(argc , argv);
   uint_least32_t number = cons.first;
   char* file_path = cons.second;

   if (compare(file_path , "0xCAFEBABE") && number == 0) {
       return 0;
    }

    list_with_threads(file_path ,number);
    return 0;
}