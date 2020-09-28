#ifndef _COMMON_H_
#define _COMMON_H_
#define PI 3.14159265359
#include<iostream>
#include<Windows.h>
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"


using namespace std;

class _Common {
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);
	static void txtColor(int);
	static void start();
	static void setFontSize(int);
	static void print_string(char* string);
};


#endif
