#include"mini_paint.h"

vector <string> parse(string str){
    vector <string> mass;
    string new_str = "";
    bool bol = true;
    for (int i = 0; i < itc_len(str); i++){
            if(str[i] == ' ' and bol){
                mass.push_back(new_str);
                new_str = "";
                bol = false;
                }
            if(str[i] != ' '){
                new_str += str[i];
                bol = true;

            }
    }
        mass.push_back(new_str);
    return mass;
}
