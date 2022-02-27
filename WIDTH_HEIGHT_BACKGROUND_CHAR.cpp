#include "mini_paint.h"

void BACKGROUND_CHAR(vector <vector<char>> &background_char, int  width, int height, char ch){
    vector <char> width_mass;
    vector <vector<char>> a;
    background_char = a;
    /*if(width < 0 || width >= 300)
        cout << "BACKGROUND_WIDTH_ERROR";
    else if(height < 0 || height >= 300)
        cout << "BACKGROUND_HEIGHT_ERROR";
    else{*/
    for(int i = 0; i < width; i++){
        width_mass.push_back(ch);
    }
    for(int j = 0; j < height; j++){
        background_char.push_back(width_mass);
       }
    //}
}
