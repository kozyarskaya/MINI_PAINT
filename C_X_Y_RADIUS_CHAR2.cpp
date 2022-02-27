#include "mini_paint.h"

void C(vector<vector<char>> &background, float x1, float y1, float radius, char ch){
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
              if (point <= (radius * radius) + 2)
                  background[y][x] = ch;
            }

    }
}
