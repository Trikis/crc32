#include <iostream>
#include <utility>
#include <stdint.h>
typedef long long ll;

unsigned char compare(const char* str1 ,const char* str2){
    int i = 0 ;
    while (str1[i] && str2[i]) {
        if (str1[i] != str2[i]) return 0;
        ++i;
    }

    if (str1[i] == 0 && str2[i] == 0) return 1;
    return 0;
}

ll pow(ll stepen){
    ll res = 1;
    for (int i =0; i < stepen ; ++i) res *= 10;
    return res;
}

std::pair< char , uint_least32_t> to_number(const char* crc_string){
    std::pair bad_pair = std::make_pair(0 , 0);
    int size = -1;
    for (int j =0; j <=10 ; ++j){
        if (crc_string[j] == '\0') {
            size = j; 
            break;
        }
    }
    if (size == -1) return bad_pair;
    for (int  i =0; i < size; ++i){
        if (!(crc_string[i] >= 48 && crc_string[i] <= 57)) return bad_pair;
    }

    ll res = 0;
    for (int pos = size - 1 ; pos >= 0 ; --pos){
        res += (crc_string[pos] - 48) * pow(size - 1 - pos);
    }

    uint_least32_t to_normal_res = res % 0x100000000 ;
    if (to_normal_res != res) return bad_pair;

    return std::make_pair(1 ,to_normal_res);
}


std::pair<uint_least32_t , char*> console(int argc , char** argv){

    char res_str[] = "0xCAFEBABE";
    std::pair<uint_least32_t , char*> bad_pair = std::make_pair(0 , res_str);

    if (argc == 1){
        std::cout<< "[-] Incorrect input. Use --help for more info" << std::endl;
        return bad_pair;
    }

    if (argc == 2){
        unsigned char state = compare(argv[1] , "--help");
        if (state){
            std::cout<< "Example : main.exe --crc 4157704578 --list Passwords\\passwords_list.txt"<<std::endl;
            std::cout<<"\t\t --crc your_unsigned_dec_crc_number"<<std::endl;
            std::cout<< "\t\t --list path_to_file_with_passwords"<<std::endl;
        }
        else {
            std::cout<< "[-] Incorrect input. Use --help for more info" << std::endl;
        }
        return bad_pair;
    }

    if (argc != 5){
        std::cout<< "[-] Incorrect input. Use --help for more info" << std::endl;
        return bad_pair;
    }

    if (!(compare(argv[1], "--crc") && compare(argv[3], "--list"))){
        std::cout<< "[-] Incorrect input. Use --help for more info" << std::endl;
        return bad_pair;
    }
    char* crc_string_number = argv[2];
    char* file_path = argv[4];

    std::pair<char , uint_least32_t> tmp = to_number(crc_string_number);
    char state = tmp.first;
    uint_least32_t res = tmp.second;
    if (state){
        return std::make_pair(res , file_path);
    }
    std::cout << "[-] Incorrect crc number"<<std::endl;
    return bad_pair;
}