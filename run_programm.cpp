#include "mini_paint.h"

void run_programm(string file_name){
    vector <string> back_vector;
    string comand_str;
    ifstream f(file_name);
     //getline(file, comand_str);
   int back_width, back_height, kol = 1;
   vector <vector<char>> background_char;
   string back_char;
    f >> back_width >> back_height >> back_char;
    BACKGROUND_CHAR(background_char, back_width, back_height, back_char[0]);
   while(!f.eof()){
        char com = ' ';
        f >> com;
    if(com == 'L'){
        float lx1, ly1, lx2, ly2;
        string lch;
        f >> lx1 >> ly1 >> lx2 >> ly2 >> lch;
        L(background_char, lx1, ly1, lx2, ly2, lch[0]);
    }

    else if(com == 'r'){
        int rx, ry, rwidth, rheidth;
        string rch;
        f >> rx >> ry >> rwidth >> rheidth >> rch;
        r(background_char, rx, ry, rwidth, rheidth, rch[0]);
    }

    else if(com == 'R'){
        int Rx, Ry, Rwidth, Rheidth;
        string Rch;
        f >> Rx >> Ry >> Rwidth >> Rheidth >> Rch;
        R(background_char, Rx, Ry, Rwidth, Rheidth, Rch[0]);
    }

    else if(com == 'c'){
        float cx, cy, cradius;
        string cch;
        f >> cx >> cy >> cradius >> cch;
        c(background_char, cx, cy, cradius, cch[0]);
    }

    else if(com == 'C'){
        float Cx, Cy, Cradius;
        char Cch;
        f >> Cx >> Cy >> Cradius >> Cch;
        C(background_char, Cx, Cy, Cradius, Cch);
   }
   }
   print_vect(background_char);
   return;
}


void run_programm2(string file_name){
    ifstream f(file_name);
    string comand_str;
    // getline(file, comand_str);
   int back_width, back_height, kol = 1;
   vector <vector<char>> background_char;
   string back_char;
    f >> back_width >> back_height >> back_char;
    BACKGROUND_CHAR(background_char, back_width, back_height, back_char[0]);
   while(getline(f, comand_str)){
        char com;
        f >> com;
    if(com == 'L'){
    float lx1, ly1, lx2, ly2;
    string lch;
    f >> lx1 >> ly1 >> lx2 >> ly2 >> lch;
    //L(background_char, lx1, ly1, lx2, ly2, lch[0]);
    }

    if(com == 'r'){
    int rx, ry, rwidth, rheidth;
    string rch;
    f >> rx >> ry >> rwidth >> rheidth >> rch;
    //r(background_char, rx, ry, rwidth, rheidth, rch[0]);
   }

    if(com == 'R'){
    int Rx, Ry, Rwidth, Rheidth;
    string Rch;
    f >> Rx >> Ry >> Rwidth >> Rheidth >> Rch;
    R(background_char, Rx, Ry, Rwidth, Rheidth, Rch[0]);
    }

    if(com == 'c'){
    float cx, cy, cradius;
    string cch;
    f >> cx >> cy >> cradius >> cch;
    //c(background_char, cx, cy, cradius, cch[0]);
    }

    if(com == 'C'){
    float Cx, Cy, Cradius;
    char Cch;
    f >> Cx >> Cy >> Cradius >> Cch;
   // C(background_char, Cx, Cy, Cradius, Cch);
   }
   }
    print_vect(background_char);
}
