#include "mini_paint.h"

int check_size(vector <vector<char>> & background, int x1, int y1, int x2, int y2){
    if (x1 < 0)
        return 0;
    if (y1 < 0)
        return 0;
    if (x2 >= background[0].size())
        return background[0].size() - 1;
    if (y2 >= background.size())
        return background.size() - 1;
}
