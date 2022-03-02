#include "mini_paint.h"

void c(vector<vector<char>> &background, float x1, float y1, float radius, char ch){
    x1 = int(x1);
    y1 = int(y1);
    radius = int(radius);
    int x = 0, y = radius, gap = 0, delta = (2 - 2 * radius);
    while (y >= 0)
            {   if (itc_abs((x1 + x)) < background[0].size() && itc_abs((y1 + y)) < background.size())
                    background[y1 + y][x1 + x] = ch;
                if (itc_abs((x1 + x)) < background[0].size() && itc_abs((y1 - y)) < background.size())
                    background[y1 - y][x1 + x] = ch;
                if (itc_abs((x1 - x)) < background[0].size() && itc_abs((y1 + y)) < background.size())
                    background[y1 + y][x1 - x] = ch;
                if (itc_abs((x1 - x)) < background[0].size() && itc_abs((y1 - y)) < background.size())
                    background[y1 - y][x1 - x] = ch;

                gap = 2 * (delta + y) - 1;
                if (delta < 0 && gap <= 0){
                    x++;
                    delta += 2 * x + 1;
                }
                else if (delta > 0 && gap > 0){
                    y--;
                    delta -= 2 * y + 1;
                }
                else{
                    x++;
                    delta += 2 * (x - y);
                    y--;
                }
            }
        }
