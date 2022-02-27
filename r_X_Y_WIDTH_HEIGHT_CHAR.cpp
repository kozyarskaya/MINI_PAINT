#include "mini_paint.h"

void r(vector<vector<char>> &background, int x, int y, int width, int heigth, char ch){
    l_horizontalLine(background, x, y, width, ch);
    l_horizontalLine(background, x, y + heigth - 1, width, ch);
    l_verticalLine(background, x, y, heigth, ch);
    l_verticalLine(background, x + width - 1, y, heigth, ch);
}
