#ifndef MINI_PAINT_H_INCLUDED
#define MINI_PAINT_H_INCLUDED
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;



void BACKGROUND_CHAR(vector <vector<char>> &background_char, int  width, int height, char ch);



void r(vector<vector<char>> &background, int x, int y, int width, int heigth, char ch);

void R(vector<vector<char>> &background_char, int x, int y, int width, int heigth, char ch);

//void c(vector<vector<char>> &background, int x1, int y1, int rudius, char ch);

void c(vector<vector<char>> &background, float x1, float y1, float radius, char ch);

void C(vector<vector<char>> &background, float x1, float y1, float radius, char ch);

void line_DDA(vector <vector<char>> &background, float x1, float y1, float x2, float y2, char ch);


void l_horizontalLine(vector <vector<char>> &background, int x, int y, int lenght, char ch);

void l_verticalLine(vector <vector<char>> &background, int x, int y, int lenght, char ch);

void L(vector <vector<char>> &background, float x1, float y1, float x2, float y2, char ch);

int main();


void open_file();

void run_programm(string file_name);

void print_vect(vector <vector<char>> &mass);

//void file_read_ex();

int itc_abs(int num);

long long itc_len(string str);

string itc_slice_str(string str, int start, int finish);

int itc_find_str(string str1, string str2);

vector <string> parse(string str);

long long itc_str_to_int(string str);


#endif // MINI_PAINT_H_INCLUDED
