#include "mini_paint.h"
/*void l_horizontalLine(vector <vector<char>> &background, int x, int y, int lenght, char ch){
    bool side = false;
    if (lenght < 0){
        side = true;
        lenght *= -1;
    }
    int i  = 0;
    while(i < lenght && i < background.size()){
    //for(int i = 0; i < lenght; i++){
        background[x][y] = ch;
        if(side)
            x -= 1;
        else
            x += 1;
        i++;
    }
}

void l_verticalLine(vector <vector<char>> &background, int x, int y, int lenght, char ch){
    bool side = false;
    if (lenght < 0){
        side = true;
        lenght *= -1;
    }
    int i  = 0;
    while(i < lenght && i < background.size()){
    //for(int i = 0; i < lenght; i++){
        background[y][x] = ch;
        if(side)
            y -= 1;
        else
            y += 1;
        i++;
    }
}*/



void l_horizontalLine(vector <vector<char>> &background, int x, int y, int lenght, char ch){
    bool side = false;
    if (lenght < 0){
        side = true;
        lenght *= -1;
    }
    for(int i = 0; i < lenght; i++){
        if (x < background[0].size() && y < background.size())
            background[y][x] = ch;
        if(side)
            x -= 1;
        else
            x += 1;
    }
}

void l_verticalLine(vector <vector<char>> &background, int x, int y, int lenght, char ch){
    bool side = false;
    if (lenght < 0){
        side = true;
        lenght *= -1;
    }
    for(int i = 0; i < lenght; i++){
        if (x < background[0].size() && y < background.size())
            background[y][x] = ch;
        if(side)
            y -= 1;
        else
            y += 1;
    }
}

int itc_abs(int num){
    if (num < 0)
        num *= -1;
    return num;
}

int itc_max(int a, int b){
    if (a > b)
        return a;
    return b;

}


void L(vector <vector<char>> &background, float x1, float y1, float x2, float y2, char ch)
{
	// ÷елочисленные значени€ координат начала и конца отрезка,
	// округленные до ближайшего целого
	int iX1 = int(x1);
	int iY1 = int(y1);
	int iX2 = int(x2);
	int iY2 = int(y2);

	// ƒлина и высота линии
	int deltaX = itc_abs(iX1 - iX2);
	int deltaY = itc_abs(iY1 - iY2);

	// —читаем минимальное количество итераций, необходимое
	// дл€ отрисовки отрезка. ¬ыбира€ максимум из длины и высоты
	// линии, обеспечиваем св€зность линии
	int length = itc_max(deltaX, deltaY);

	// особый случай, на экране закрашиваетс€ ровно один пиксел
	if (length == 0)
	{   if (iX1 < background[0].size() && iY1 < background.size())
            background[iX1][iY1] = ch;
		return;
	}

	// ¬ычисл€ем приращени€ на каждом шаге по ос€м абсцисс и ординат
	float dX = (x2 - x1) / length;
	float dY = (y2 - y1) / length;

	// Ќачальные значени€
	float x = x1;
	float y = y1;
	if (int(x)< background[0].size() && int(y) < background.size())
            background[y1][x1] = ch;

	// ќсновной цикл
	length++;
	while (length > 1)
	{
		x += dX;
		y += dY;
		if (int(x)< background[0].size() && int(y) < background.size())
            background[int(y)][int(x)] = ch;
        length--;
    	}
}

/*int itc_round(float num){
    int num2 = num * 10;
    int pl = 0;
    if (num2 % 10 >= 5)
        pl = 1;
    return (int(num) + pl);

}

void L2(vector <vector<char>> &background, float x1, float y1, float x2, float y2, char ch){
    x1 = int(x1);
    y1 = int(y1);
    x2 = int(x2);
    y2 = int(y2);
    int dy = y2 - y1;
    int dx = x1 - x2;
    if (dy == 0)
        l_horizontalLine(background, x1, y1, dx, ch);
    if (dx == 0)
        l_verticalLine(background, x1, y1, dy, ch);
    int signy = 1, signx = 1;
    if (dy < 0)
        signy = -1;
    if (dx < 0)
        signx = -1;
    int f = 0;
    int x = x1;
    int y = y1;
    if (x < background[0].size() && y < background.size())
    background[x][y] = ch;
    while(x < x2 && y < y2){
        if (itc_abs(dy) < itc_abs(dx)){
            f = f + dy * signy;
            if (f > 0){
                f = f - dx * signx;
                y = y + signy;
            }
            x = x - signx;
            if (x < background[0].size() && y < background.size())
            background[x][y] = ch;

        }
        else{
            f = f + dx * signx;
            if (f > 0){
                f = f - dy * signy;
                x = x - signx;
            }
            y = y + signy;
            if (x < background[0].size() && y < background.size())
            background[x][y] = ch;
        }
    }
}*/
