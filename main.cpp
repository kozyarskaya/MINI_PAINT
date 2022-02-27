#include <fstream>
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include "mini_paint.h"
using namespace std;

void print_vect(vector <vector<char>> &mass){
    for(int i = 0; i < mass.size(); i++){
        for (int j = 0; j < mass[i].size(); j++){
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}


void enter_vector(vector <int > &mass2, int n){
    int c;
  for(int i = 0; i < n; i++){
        cin >> c;
        mass2.push_back(c);
    }
}






int main(){

   cout << "HI, WELCOME TO MINI PAINT" << '\n';
    //getline(cin, file_name);
    //file_read_ex();
    open_file();
   // cout << itc_str_to_int("-23");
    //vector <vector<char>> background_char;

    /*int back_width, back_height;
    char back_char;
    cin >> back_width >> back_height >> back_char;*/

    /*float lx1, ly1, lx2, ly2;
    char lch;
    cin >> lx1 >> ly1 >> lx2 >> ly2 >> lch;*/

   /* int rx, ry, rwidth, rheidth;
    char rch;
    cin >> rx >> ry >> rwidth >> rheidth >> rch;*/

    /*int Rx, Ry, Rwidth, Rheidth;
    char Rch;
    cin >> Rx >> Ry >> Rwidth >> Rheidth >> Rch;*/

    /*float cx, cy, cradius;
    char cch;
    cin >> cx >> cy >> cradius >> cch;*/



    //BACKGROUND_CHAR(background_char, back_width, back_height, back_char);
  //BACKGROUND_CHAR(background_char, 25, 25, '&');
    //L(background_char, lx1, ly1, lx2, ly2, lch);
    //L(background_char, lx1, ly1, lx2, ly2, lch);
   // r(background_char, rx, ry, rwidth, rheidth, rch);
    //R(background_char, 1, 1, 6, 3, '*');
   //c(background_char, cx, cy, cradius, cch);
 //C(background_char, cx, cy, cradius, cch);
  //print_vect(background_char);
return 0;
}
