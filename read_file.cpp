#include "mini_paint.h"


/*void file_read_ex(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    bool bol = true;
    string comand_str, file_name;
    getline(cin, file_name);
    //if (file_name != "C:\Users\sofiy\OneDrive\Рабочий стол\Школа\Информатика\functions_c++\MINI_PAINT\operation.it.txt")
       // cout << "error";
    ifstream f;
    f.exceptions(ifstream::badbit | ifstream::failbit);
    while(bol){
    try{
    f.open(file_name);
    bol = false;
    SetConsoleTextAttribute(hConsole, 2);
    cout << "File opened successfully" << '\n';
    SetConsoleTextAttribute(hConsole, 7);
    }
    catch(const ifstream::failure &ex)
    {
    if(itc_slice_str(file_name, 0, itc_find_str(file_name, ".") - 1) != "operation"){
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Error: name file" << '\n';
            SetConsoleTextAttribute(hConsole, 7);}

        else if(itc_slice_str(file_name, itc_find_str(file_name, "."), itc_len(file_name)) != ".it"){
            SetConsoleTextAttribute(hConsole, 4);
            cout << "Error: Operation file has not correct extension" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
        }
        else{
        SetConsoleTextAttribute(hConsole, 4);
        cout << "Error: Operation file corrupted" << '\n';
        SetConsoleTextAttribute(hConsole, 0);}
    getline(cin, file_name);

     }

   }
   SetConsoleTextAttribute(hConsole, 7);
   int back_width, back_height, kol = 1;
   vector <vector<char>> background_char;
   char back_char;
    f >> back_width >> back_height >> back_char;

   while(f){
        char com;
        f >> com;
    if(com == 'L'){
    float lx1, ly1, lx2, ly2;
    char lch;
    f >> lx1 >> ly1 >> lx2 >> ly2 >> lch;
    L(background_char, lx1, ly1, lx2, ly2, lch);}

    if(com == 'r')}
    int rx, ry, rwidth, rheidth;
    char rch;
    f >> rx >> ry >> rwidth >> rheidth >> rch;
    r(background_char, rx, ry, rwidth, rheidth, rch);}

    if(com == 'R'){
    int Rx, Ry, Rwidth, Rheidth;
    char Rch;
    f >> Rx >> Ry >> Rwidth >> Rheidth >> Rch;
    R(background_char, Rx, Ry, Rwidth, Rheidth, Rch);}

    if(com == 'c'){
    float cx, cy, cradius;
    char cch;
    f >> cx >> cy >> cradius >> cch;
    c(background_char, cx, cy, cradius, cch);}

    if(com == 'C'){
    float Cx, Cy, Cradius;
    char Cch;
    f >> Cx >> Cy >> Cradius >> Cch;
    C(background_char, Cx, Cy, Cradius, Cch);}

        cout << comand_str<< endl;

   }
}*/

bool is_num(string str){
    int i = 0;
    if(str[0] == '-')
        str = itc_slice_str(str, 1, itc_len(str) - 1);
    while(i < itc_len(str)){
        if(str[i] < 48 || str[i] > 57){
            if (str[i] != '.')
                return true;}
        i++;
    }
    return false;
}

bool check_comands_bool(vector <string> &comand_vector, string com){

    if (com == "bc"){
        if(comand_vector.size() != 3)
            return true;

        else if(is_num(comand_vector[0]) || is_num(comand_vector[1]))
            return true;

        else if(itc_str_to_int(comand_vector[0]) <= 0 || itc_str_to_int(comand_vector[1]) <= 0)
            return true;

        else if(itc_str_to_int(comand_vector[0]) > 300 || itc_str_to_int(comand_vector[1]) > 300)
            return true;

    }
    else{
        if(comand_vector[0] != "R" && comand_vector[0] != "r" && comand_vector[0] != "C" && comand_vector[0] != "c" && comand_vector[0] != "L")
            return true;

        else if (comand_vector[0] == "R" || comand_vector[0] == "r" || comand_vector[0] == "L"){
            if(comand_vector.size() != 6)
                return true;

            else if(itc_str_to_int(comand_vector[1]) < 0 || itc_str_to_int(comand_vector[2]) < 0 || itc_str_to_int(comand_vector[3]) < 0 || itc_str_to_int(comand_vector[4]) < 0)
                return true;

            else if(is_num(comand_vector[1]) || is_num(comand_vector[2]) || is_num(comand_vector[3]) || is_num(comand_vector[4]))
                return true;
        }
        else if (comand_vector[0] == "c" || comand_vector[0] == "C"){
            if(comand_vector.size() != 5)
                return true;

            else if(is_num(comand_vector[1]) || is_num(comand_vector[2]) || is_num(comand_vector[3]))
                return true;

            else if(itc_str_to_int(comand_vector[1]) < 0 || itc_str_to_int(comand_vector[2]) < 0 || itc_str_to_int(comand_vector[3]) < 0)
                return true;
        }
}
return false;
}

void read_opened_file(string file_name){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string comand_str;
    vector <string> back_vector;
    ifstream file(file_name);
    getline(file, comand_str);
    back_vector = parse(comand_str);
    bool check_back = check_comands_bool(back_vector, "bc");
    while(getline(file, comand_str)){
        vector <string> comand_vect;
        comand_vect = parse(comand_str);
        bool check_com = check_comands_bool(comand_vect, "com");
        if(check_back || check_com){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: comand  " << comand_str <<'\n';
            SetConsoleTextAttribute(hConsole, 7);
            return;
        }
    }
    run_programm(file_name);
}

void open_file(){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    bool bol = true;
    string file_name;
    cout << "Enter file name:" << '\n';
    getline(cin, file_name);
    ifstream f;
    while(bol){
        f.open(file_name);
        if(itc_find_str(file_name, " ") != -1){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: a lot of arguments" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
            }
        else if(itc_slice_str(file_name, 0, itc_find_str(file_name, ".") - 1) != "operation"){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: name file" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
            }
        else if(itc_slice_str(file_name, itc_find_str(file_name, "."), itc_len(file_name)) != ".it"){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: Operation file has not correct extension" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
            }
        else if(!f.is_open()){
            SetConsoleTextAttribute(hConsole, 12);
            cout << "Error: Operation file corrupted" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
            }
        else{
            bol = false;
            SetConsoleTextAttribute(hConsole, 2);
            cout << "File opened successfully" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
         }
    if(bol)
        getline(cin, file_name);
    }
    read_opened_file(file_name);
}



/*void check_comands(vector <string> &comand_vector, string com){
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (com == "bc"){
        if(comand_vector.size() > 3){
            SetConsoleTextAttribute(hConsole, 3);
            cout << "Error: background count of arguments" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(is_num(comand_vector[0]) || is_num(comand_vector[1])){
            SetConsoleTextAttribute(hConsole, 3);
            cout << "Error: background arguments type" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
        }
        else if(itc_str_to_int(comand_vector[0]) <= 0 || itc_str_to_int(comand_vector[1]) <= 0){
                SetConsoleTextAttribute(hConsole, 3);
                cout << "Error: background negative arguments" << '\n';
                SetConsoleTextAttribute(hConsole, 7);
            }
    }
    else{
        if (comand_vector[0] == "R" || comand_vector[0] == "r" || comand_vector[0] == "L"){
            if(comand_vector.size() > 6){
                SetConsoleTextAttribute(hConsole, 3);
                cout << "Error: comand count of arguments" << '\n';
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(itc_str_to_int(comand_vector[1]) <= 0 || itc_str_to_int(comand_vector[2]) <= 0 || itc_str_to_int(comand_vector[3]) <= 0 || itc_str_to_int(comand_vector[4]) <= 0){
                SetConsoleTextAttribute(hConsole, 3);
                cout << "Error: comand negative arguments" << '\n';
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(is_num(comand_vector[1]) || is_num(comand_vector[2]) || is_num(comand_vector[3]) || is_num(comand_vector[4])){
            SetConsoleTextAttribute(hConsole, 3);
            cout << "Error: comand arguments type" << '\n';
            SetConsoleTextAttribute(hConsole, 7);
            }
        }
        else if (comand_vector[0] == "c" || comand_vector[0] == "C"){
            if(comand_vector.size() > 5){
                SetConsoleTextAttribute(hConsole, 3);
                cout << "Error: comand count of arguments" << '\n';
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(is_num(comand_vector[1]) || is_num(comand_vector[2]) || is_num(comand_vector[3])){
                SetConsoleTextAttribute(hConsole, 3);
                cout << "Error: comand arguments type" << '\n';
                SetConsoleTextAttribute(hConsole, 7);
            }
            else if(itc_str_to_int(comand_vector[1]) <= 0 || itc_str_to_int(comand_vector[2]) <= 0 || itc_str_to_int(comand_vector[3]) <= 0){
                SetConsoleTextAttribute(hConsole, 3);
                cout << "Error: comand negative arguments" << '\n';
                SetConsoleTextAttribute(hConsole, 7);
                }

        }
}
}*/

