#include "crc32.cpp"
#include "console.cpp"
#include <iostream>
#include <fstream>
#include <string>



int main(int argc , char** argv , char** env){

  std::pair<uint_least32_t , char*> cons = console(argc , argv);
   uint_least32_t number = cons.first;
  char* file_path = cons.second;

   if (compare(file_path , "0xCAFEBABE") && number == 0) {
       return 0;
    }
    
    std::fstream file(file_path , std::ios::in | std::ios::binary);
    if (!file.is_open()){
        std::cout << "[-] Can not open this file\n";
        return 0;
    }
    file.seekg(0, std::ios::beg);

    unsigned char chr;
    unsigned char byte_arr[50];
    int pos = 0;

    while (!file.eof()){
        if (pos == 49){
            for (int i =0; i < 50 ; ++i){
                byte_arr[i] = 0;
            }
            pos = 0;
        }
        file.read(reinterpret_cast<char*>(&chr), 1);

        if (chr == 0xD) continue;
        if (chr == 0xA) {
            byte_arr[pos] = '\0';
            uint_least32_t temp_number = Crc32(byte_arr, pos);
            if (temp_number == number){
                std::cout<<"COngratulations!!!  " << "Password is:" << byte_arr<< std::endl;
                return 0;
            }
            for (int i =0; i < 50 ; ++i){
                byte_arr[i] = 0;
            }
             pos = 0;
        }else{
            byte_arr[pos] = chr;
            ++pos;
        }
    }
    file.close();
    std::cout<<"OK";
    return 0;
}