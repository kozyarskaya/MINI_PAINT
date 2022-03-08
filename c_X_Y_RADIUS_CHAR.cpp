#include "mini_paint.h"

void c2(vector<vector<char>> &background, float x1, float y1, float radius, char ch){
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


void c(vector<vector<char>> &background, float x1, float y1, float radius, char ch){
    x1 = int(x1);
    y1 = int(y1);
    radius = int(radius);
    for(int y = 0; y < background.size(); y++){
        for (int x = 0; x < background[0].size(); x++){
           int  point = ((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));
           //int  point2 = ((x1 + x) * (x1 + x) + (y1 - y) * (y1 - y));
           //int  point3 = ((x1 - x) * (x1 - x) + (y1 + y) * (y1 + y));
           //int  point4 = ((x1 + x) * (x1 + x) + (y1 + y) * (y1 + y));
            //if (point < (radius * radius) || point2 < (radius * radius) || point3 < (radius * radius)|| point4 < (radius * radius))
              if (point >= (radius * radius) && point < (radius * radius) + radius)
                  background[y][x] = ch;
            }
    }
}
