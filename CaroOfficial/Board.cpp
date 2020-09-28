#include "Board.h"

int _Board::getSize() { return _size; }
int _Board::getLeft() { return _left; }
int _Board::getTop() { return _top; }
int _Board::getXAt(int i, int j) {
	return _pArr[i][j].getX();
}
int _Board::getYAt(int i, int j) {
	return _pArr[i][j].getY();
}

_Board::_Board(int pSize, int pX, int pY) {
	_size = pSize;
	_left = pX;
	_top = pY;
	_pArr = new _Point*[pSize];
	for (int i = 0; i < pSize; i++)
		_pArr[i] = new _Point[pSize];
}
_Board::~_Board() {
	for (int i = 0; i < _size; i++)
		delete[] _pArr[i];
	delete[] _pArr;
}

void _Board::resetData() {
	if (_size == 0) return; // Phải gọi constructor trước khi resetData 
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			_pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ 
			_pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ 
			_pArr[i][j].setCheck(0);
		}
	}
}
void _Board::drawBoard() {
	//vẽ bàn cờ
	if (_pArr == NULL) return; // phải gọi constructor trước 
	for (int i = 0; i <= _size; i++) {
		for (int j = 0; j <= _size; j++) {
			_Common::gotoXY(_left + 4 * i, _top + 2 * j);
			_Common::txtColor(10);
			cout << ".";
		}
	}

	// vẽ viền cho bàn cờ
	for (int i = 0; i <= _size * 4 + 1; i++) {
		_Common::txtColor(14);
		//Vẽ viền trên
		_Common::gotoXY(_left + i - 1, _top - 1);
		cout << char(42);
		//Vẽ viền dưới
		_Common::gotoXY(_left + i - 1, _top + _size * 2 + 1);
		cout << char(42);
	}

	for (int j = 0; j < _size * 2 + 3; j++) {
		//vẽ viền trái
		_Common::gotoXY(_left - 1, _top + j - 1);
		cout << char(42);
		//vẽ viền phải
		_Common::gotoXY(_left + _size * 4 + 1, _top + j - 1);
		cout << char(42);
	}
	//Vẽ bảng kết quả
	_Board::drawTableResult();
	_Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());// di chuyển vào ô đầu 
}

void _Board::drawTableResult()
{
	_Common::txtColor(14);
	for (int i = 0; i <= _size * 5; i++) {
		//vẽ viền trên
		_Common::gotoXY(_left + _size * 4 + i + 1, _top - 1);
		cout << char(42);
		//vẽ viền dưới
		_Common::gotoXY(_left + _size * 4 + i + 1, _top + _size * 2 + 1);
		cout << char(42);
	}
	//vẽ viền phải 
	for (int i = 0; i < _size * 2 + 3; i++) {
		_Common::gotoXY(_left + _size * 9 + 1, _top + i - 1);
		cout << char(42);
	}
	//vẽ vạch chia cắt ô thứ 1
	for (int i = 0; i < _size * 5; i++)
	{
		_Common::gotoXY(_left + _size * 4 + i + 1, _top + 9);
		cout << "*";
	}
	//vẽ vạch chia ô thứ 2
	for (int i = 0; i < _size * 5; i++)
	{
		_Common::gotoXY(_left + _size * 4 + i + 1, _top + 15);
		cout << "*";
	}
}

int _Board::checkBoard(int pX, int pY, bool pTurn) {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0) {
				if (pTurn)
				{
					_pArr[i][j].setCheck(-1);// Nếu lượt hiện hành là true: c = -1 

				}
				else {
					_pArr[i][j].setCheck(1);// Nếu lượt hiện hành là false: c = 1 
				}
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}

int _Board::DuyetDoc(int px, int py)
{
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int dong = (py - 2) / 2;
	int cot = (px - 3) / 4;
	int pointCheck;
	//duyệt trên xuống
	int check = getPoint(dong, cot).getCheck();
	for (int Dem = 1; Dem < 6 && dong + Dem < _size; Dem++)
	{
		pointCheck = getPoint(dong + Dem, cot).getCheck();
		if (check == pointCheck )
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	//duyệt dưới lên
	for (int Dem = 1; Dem < 6 && dong - Dem >= 0; Dem++)
	{
		pointCheck = getPoint(dong - Dem, cot).getCheck();
		if (check == pointCheck)
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	if (SoQuanDich != 2 && SoQuanTa == 4) return check;
	return 0;
}

int _Board::DuyetNgang(int px, int py)
{
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int dong = (py - 2) / 2;
	int cot = (px - 3) / 4;
	int pointCheck;
	int check = getPoint(dong, cot).getCheck();
	//duyệt bên phải
	for (int Dem = 1; Dem < 6 && cot + Dem < _size; Dem++)
	{
		pointCheck = getPoint(dong, cot + Dem).getCheck();
		if (check == pointCheck) 
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	//duyệt bên trái
	for (int Dem = 1; Dem < 6 && cot - Dem >= 0; Dem++)
	{
		pointCheck = getPoint(dong, cot - Dem).getCheck();
		if (check == pointCheck)
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	if (SoQuanDich != 2 && SoQuanTa == 4) return check;
	return 0;
}

int _Board::DuyetCheoPhai(int px, int py)
{
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int dong = (py - 2) / 2;
	int cot = (px - 3) / 4;
	int pointCheck;
	int check = getPoint(dong, cot).getCheck();
	//duyệt chéo xuống dưới
	for (int Dem = 1; Dem < 6 && dong + Dem < _size && cot + Dem < _size; Dem++)
	{
		pointCheck = getPoint(dong + Dem, cot + Dem).getCheck();
		if (check == pointCheck) 
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	//duyệt chéo lên trên
	for (int Dem = 1; Dem < 6 && dong - Dem >= 0 && cot - Dem >= 0; Dem++)
	{
		pointCheck = getPoint(dong - Dem, cot - Dem).getCheck();
		if (check == pointCheck)
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	if (SoQuanDich != 2 && SoQuanTa == 4) return check;
	return 0;
}

int _Board::DuyetCheoTrai(int px, int py)
{
	int SoQuanTa = 0;
	int SoQuanDich = 0;
	int dong = (py - 2) / 2;
	int cot = (px - 3) / 4;
	int pointCheck;
	int check = getPoint(dong, cot).getCheck();
	//duyệt chéo xuống dưới
	for (int Dem = 1; Dem < 6 && dong + Dem < _size && cot - Dem >= 0; Dem++)
	{
		pointCheck = getPoint(dong + Dem, cot - Dem).getCheck();
		if (check == pointCheck)
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break; //gặp ô trống
	}
	//duyệt chéo lên trên
	for (int Dem = 1; Dem < 6 && dong - Dem >= 0 && cot + Dem < _size; Dem++)
	{
		pointCheck = getPoint(dong - Dem, cot + Dem).getCheck();
		if (check == pointCheck)
			SoQuanTa++;
		else if (pointCheck != 0)
		{
			SoQuanDich++;
			break;
		}
		else break;//gặp ô trống
	}
	if (SoQuanTa != 2 && SoQuanTa == 4) return check;
	return 0;
}

int _Board::testBoard(int px,int py) {
	//return CheckWin();//neu thang
	//return checkDraw();//neu het ban co thi hoa

	////con khong thi tiep tuc danh
	int kq;
	kq = DuyetDoc(px, py);
	if (kq != 0) return kq;
	kq = DuyetNgang(px, py);
	if (kq != 0) return kq;
	kq = DuyetCheoPhai(px, py);
	if (kq != 0) return kq;
	kq = DuyetCheoTrai(px, py);
	if (kq != 0)return kq;
	return CONTINUE;
}

void _Board::setPointcheck(int x, int y, int info)
{
	_pArr[x][y].setCheck(info);
}

_Point _Board::getPoint(int x, int y)
{
	return _pArr[x][y];
}

//đánh với máy
int _Board::checkBoardWithMachine(int pX,int pY) {
	for (int i = 0; i < _size; i++) {
		for (int j = 0; j < _size; j++) {
			if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0) {
				_pArr[i][j].setCheck(-1);// Nếu lượt hiện hành là true: c = -1 
				return _pArr[i][j].getCheck();
			}
		}
	}
	return 0;
}
