#include "mini_paint.h"

void R(vector<vector<char>> &background_char, int x, int y, int width, int heigth, char ch){
    for(int i = 0; i < itc_abs(heigth); i++){
        for(int j = 0; j < itc_abs(width); j++){
            if ((x + j) < background_char[0].size() && (y + i) < background_char.size())
            background_char[y + i][x + j] = ch;
        }
    }
}
