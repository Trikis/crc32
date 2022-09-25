#include "crc32.cpp"
#include "console.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <filesystem>




void clear_create_files(){
   std::filesystem::remove("Passwords\\1.txt");
   std::filesystem::remove("Passwords\\2.txt");
   std::filesystem::remove("Passwords\\3.txt");
   std::filesystem::remove("Passwords\\4.txt");
}

unsigned char part(const char* file_path , uint_least32_t number){
    std::fstream file(file_path , std::ios::in | std::ios::binary);
    if (!file.is_open()){
        std::cout << "[-] Can not open this file\n" << file_path;
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
                std::cout<<"COngratulations!!!  " << "Password is: " << byte_arr<< std::endl;
                file.close();
                return 1;
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
    return 0;
}


class Thread{
    private:
        const char* filepath;
        std::thread* th;
        uint_least32_t number;
    public:
        Thread(const char* _file_path , uint_least32_t _number) : filepath(_file_path)  , number(_number){
            th = new std::thread([&](){
                unsigned char res = part(filepath , number);
            });
        }
        ~Thread(){
            std::filesystem::remove(filepath);
        }
        void join(){
            th->join();
        }
};

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

    std::vector<char* > content_arr;

    while (!file.eof()){
        char* tmp_str = new char[1000];
        file.read(tmp_str,1000);
        content_arr.push_back(tmp_str);
    }

    ll size = content_arr.size();
    for (int i =0; i < 4; ++i){
        ll left = (i * size) / 4;
        ll right = ((i + 1) * size) / 4;
        char curr_path[50] = "Passwords\\";
        curr_path[10] = 49 + i;
        curr_path[11] = '.';
        curr_path[12] = 't';
        curr_path[13] = 'x';
        curr_path[14] = 't';
        curr_path[15] = 0;
        std::fstream curr_file(curr_path , std::ios::out | std::ios::binary | std::ios::app);
        for (ll pos = left ; pos < right ; ++pos){
            curr_file.write(content_arr[pos] , 1000);
        }
        curr_file.close();
    }
    file.close();


    Thread th1("Passwords\\1.txt" , number);
    Thread th2("Passwords\\2.txt" , number);
    Thread th3("Passwords\\3.txt" , number);
    Thread th4("Passwords\\4.txt" , number);
    th1.join(); th2.join() ; th3.join() ; th4.join();
    clear_create_files();
    return 0;
}