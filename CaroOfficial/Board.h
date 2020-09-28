#ifndef _BOARD_H_
#define _BOARD_H_

#include <iostream>
#include "Point.h"
#include "Common.h"
using namespace std;

#define WIN1 -1
#define WIN2 1
#define DRAW 0
#define CONTINUE 2

class _Board{ 
private: 
int _size;  
int _left, _top;  
_Point** _pArr;

public: 
	int getSize();
	int getLeft();
	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	_Board(int, int, int);
	~_Board();
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	//kiểm tra thắng thua
	int DuyetDoc(int, int);
	int DuyetNgang(int, int);
	int DuyetCheoPhai(int, int);
	int DuyetCheoTrai(int, int);
	int testBoard(int, int);

	void drawTableResult();
	void setPointcheck(int, int, int);
	_Point getPoint(int, int);
	//danh voi may
	int checkBoardWithMachine(int, int);
}; 


#endif

