#include"Menu.h"


void Menu()
{
	_Game::CountWin1 = 0;
	_Game::CountWin2 = 0;
	_Game::CountStep1 = 0;
	_Game::CountStep2 = 0;
	PlaySound(NULL, NULL, SND_ASYNC);
	system("cls");
	_Common::txtColor(14);
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t**                                                                                   **" << endl;
	cout << "\t\t**                     00000000                    XX                 XX             **" << endl;
	cout << "\t\t**                  00          00                   XX             XX               **" << endl;
	cout << "\t\t**                00              00                   XX         XX                 **" << endl;
	cout << "\t\t**              00                  00                   XX     XX                   **" << endl;
	cout << "\t\t**              00                  00                     XX XX                     **" << endl;
	cout << "\t\t**              00                  00                   XX     XX                   **" << endl;
	cout << "\t\t**              00                  00                 XX         XX                 **" << endl;
	cout << "\t\t**                00              00                 XX             XX               **" << endl;
	cout << "\t\t**                  00          00                 XX                 XX             **" << endl;
	cout << "\t\t**                     00000000                  XX                     XX           **" << endl;
	cout << "\t\t**                                                                                   **" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t***************************************************************************************" << endl;
	cout << "\t\t\t\t\t\tWELCOM TO CARO GAME" << endl;
	_Common::txtColor(11);
	cout << "\t\t\t\t\t***********************************" << endl;
	_Common::txtColor(11);
	cout << "\t\t\t\t\t*\t    ";
	_Common::txtColor(12);
	cout << "NEW GAME";
	_Common::txtColor(11);
	cout <<"              *" << endl;
	_Common::txtColor(11);
	cout << "\t\t\t\t\t*\t    LOAD GAME             *" << endl;
	cout << "\t\t\t\t\t*\t    HELP                  *" << endl;
	cout << "\t\t\t\t\t*\t    ABOUT                 *" << endl;
	cout << "\t\t\t\t\t*\t    EXIT GAME             *" << endl;
	cout << "\t\t\t\t\t***********************************" << endl;
	int x = selectMenu();
	processMenu(x);
}

void printMenu(int selection)
{
	switch (selection)
	{
	case 1:
		_Common::gotoXY(0, 22);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    EXIT GAME             *";
		_Common::gotoXY(52, 18);
		_Common::txtColor(12);
		cout << "NEW GAME";
		_Common::gotoXY(0, 19);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    LOAD GAME             *";
		
		_Common::gotoXY(0, 24);
		break;
	case 2:
		_Common::gotoXY(0, 18);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    NEW GAME              *";
		_Common::gotoXY(52, 19);
		_Common::txtColor(12);
		cout << "LOAD GAME";
		_Common::gotoXY(0, 20);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    HELP                  *";
		_Common::gotoXY(0, 24);
		break;
	case 3:
		_Common::gotoXY(0, 19);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    LOAD GAME             *";
		_Common::gotoXY(52, 20);
		_Common::txtColor(12);
		cout << "HELP";
		_Common::gotoXY(0, 21);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    ABOUT                 *";
		_Common::gotoXY(0, 24);
		break;
	case 4:
		_Common::gotoXY(0, 20);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    HELP                  *";
		_Common::gotoXY(52, 21);
		_Common::txtColor(12);
		cout << "ABOUT";
		_Common::gotoXY(0, 22);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    EXIT GAME             *";
		_Common::gotoXY(0, 24);
		break;
	case 5:
		_Common::gotoXY(0, 21);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    ABOUT                 *";
		_Common::gotoXY(52, 22);
		_Common::txtColor(12);
		cout << "EXIT GAME";
		_Common::gotoXY(0, 18);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t*\t    NEW GAME              *";
		_Common::gotoXY(0, 24);
		break;
	}
}

int selectMenu()
{
	int selection = 1;
	int choose = 0;
	while (1)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			switch (selection)
			{
			case 1: case 2: case 3: case 4:
				selection++;
				break;
			case 5:
				selection = 1;
				break;
			}
			printMenu(selection);

		}
		if (move == 'W' || move == 72)
		{
			switch (selection)
			{
			case 1:
				selection = 5;
				break;
			case 2: case 3: case 4: case 5:
				selection--;
				break;
			}
			printMenu(selection);
		}
		if (move == 13)
			return selection;
	}
}

void MenuNewGame(int selection)
{
	switch (selection)
	{
	case 1:
		_Common::gotoXY(42, 18);
		_Common::txtColor(12);
		cout << "PLAY WITH PERSON";
		_Common::gotoXY(0, 19);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t* PLAY WITH AI                    *";
		_Common::gotoXY(0, 20);
		break;
	case 2:
		_Common::gotoXY(0, 18);
		_Common::txtColor(11);
		cout << "\t\t\t\t\t* PLAY WITH PERSON                *";
		_Common::gotoXY(42, 19);
		_Common::txtColor(12);
		cout << "PLAY WITH AI";
		_Common::gotoXY(0, 20);
	}
}

int selectMenuNewGame() {
	int selection = 1;
	int choose = 0;
	while (1)
	{
		int move = _getch();
		move = toupper(move);
		if (move == 'S' || move == 80)
		{
			switch (selection)
			{
			case 1: case 2: case 3: case 4:
				selection++;
				break;
			case 5:
				selection = 1;
				break;
			}
			MenuNewGame(selection);

		}
		if (move == 'W' || move ==72)
		{
			switch (selection)
			{
			case 1:
				selection = 5;
				break;
			case 2: case 3: case 4: case 5:
				selection--;
				break;
			}
			MenuNewGame(selection);
		}
		if (move == 13)
			return selection;
		if (move == 27)
			Menu();
	}

}

void processMenu(int choose)
{
	switch (choose)
	{
	case 1:
		_Common::txtColor(11);
		_Common::gotoXY(0, 17);
		cout << "\t\t\t\t\t***********************************";
		_Common::gotoXY(0, 18);
		cout << "\t\t\t\t\t* ";
		_Common::txtColor(12);
		cout << "PLAY WITH PERSON";
		_Common::txtColor(11);
		cout << "                *";
		_Common::gotoXY(0, 19);
		cout << "\t\t\t\t\t* PLAY WITH AI                    *";
		_Common::gotoXY(0, 20);
		cout << "\t\t\t\t\t***********************************";
		//xóa viền dưới của menu chính
		for (int i = 0; i < 3; i++)
		{
			_Common::gotoXY(40, 21 + i);
			cout << "                                   ";
		}
		_Common::gotoXY(0, 20);

		switch (selectMenuNewGame())
		{
		case 1:
			newGame();
			break;
		case 2:
			newGameWithMachine();
			break;
		}
		break;
	case 2:
	{
		fstream fin;
		string a;
		int stop;
		do {
			//xóa màn hình tại vùng đó
			for (int i = 0; i < 5; i++)
			{
				_Common::gotoXY(41, 18 + i);
				cout << "                               ";
			}
			_Common::txtColor(12);
			_Common::gotoXY(41, 18);
			cout << "Nhap ten file de tai: ";
			_Common::gotoXY(41, 19);
			getline(cin, a);
			fin.open(a, ios::in);
			if (fin.fail())
				stop = 0;
			else
				stop = 2;
			if (stop == 0)
			{
				_Common::gotoXY(41, 20);
				cout << "Ten file khong ton tai!";
				_Common::gotoXY(41, 21);
				cout << "Press C to continue.";
				_Common::gotoXY(41, 22);
				cout << "Press Esc to turn back to Menu.";
				if (_getch() == 27)
				{
					stop = 1;
					Menu();
				}
			}

		} while (stop == 0);
		if(stop==2)
		loadGame(a);
	}
		break;
	case 3:
		help();
		break;
	case 4:
		about();
		break;
	case 5:
		exit(0);
	}
}

void newGameWithMachine()
{
	_Game g(BOARD_SIZE, LEFT, TOP); // Sinh viên tự định nghĩa các hằng số 
	g.startGame();
	_Common::gotoXY(BOARD_SIZE * 7 - 16, TOP + 1);
	_Common::txtColor(15);
	cout << "PLAYER 1 VS MACHINE";
	_Common::gotoXY(g.get_b()->getXAt(0, 0), g.get_b()->getYAt(0, 0));
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			if (g.getCommand() == 'A' || g.getCommand() == 75)
				g.moveLeft();
			if (g.getCommand() == 'W' || g.getCommand() == 72)
				g.moveUp();
			if (g.getCommand() == 'S' || g.getCommand() == 80)
				g.moveDown();
			if (g.getCommand() == 'D' || g.getCommand() == 77)
				g.moveRight();
			if (g.getCommand() == 13 || g.getCommand() == 32)
			{
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (g.processCheckBoardWithMachine())
				{
					switch (g.processFinishWithMachine())
					{
					case WIN1: case WIN2: case DRAW:

						if (g.askContinue() != 'Y')
						{
							_Common::gotoXY(100, 105);
							g.exitGame();
						}
						else 
						{
							g.startGame();
							_Common::gotoXY(BOARD_SIZE * 7 - 16, TOP + 1);
							_Common::txtColor(15);
							cout << "PLAYER 1 VS MACHINE";
							_Common::gotoXY(g.get_b()->getXAt(0, 0), g.get_b()->getYAt(0, 0));
						}
					}
				}
			}
		}
	}
}

void newGame()
{
	_Game g(BOARD_SIZE, LEFT, TOP); // Sinh viên tự định nghĩa các hằng số 
	g.startGame();
	_Common::gotoXY(BOARD_SIZE * 7 - 16, TOP + 1);
	_Common::txtColor(15);
	cout << "PLAYER 1 VS PLAYER 2";
	_Common::gotoXY(g.get_b()->getXAt(0, 0), g.get_b()->getYAt(0, 0));
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			if (g.getCommand() == 'A' || g.getCommand() == 75)
				g.moveLeft();
			if (g.getCommand() == 'W' || g.getCommand() == 72)
				g.moveUp();
			if (g.getCommand() == 'S' || g.getCommand() == 80)
				g.moveDown();
			if (g.getCommand() == 'D' || g.getCommand() == 77)
				g.moveRight();
			if (g.getCommand() == 13 || g.getCommand() == 32)
			{
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (g.processCheckBoard())
				{
					switch (g.processFinish())
					{
					case WIN1: case WIN2: case DRAW:

						if (g.askContinue() != 'Y')
						{
							_Common::gotoXY(100, 105);
							g.exitGame();
						}
						else
						{
							g.startGame();
							_Common::gotoXY(BOARD_SIZE * 7 - 16, TOP + 1);
							_Common::txtColor(15);
							cout << "PLAYER 1 VS PLAYER 2";
							_Common::gotoXY(g.get_b()->getXAt(0, 0), g.get_b()->getYAt(0, 0));
						}
					}
				}
			}
		}
	}
}

void loadGame(string a) {
	PlaySound("bgSound", NULL, SND_ASYNC);
	_Game g(BOARD_SIZE, LEFT, TOP); // Sinh viên tự định nghĩa các hằng số 
	g.loadGame(a);
	_Common::gotoXY(BOARD_SIZE * 7 - 16, TOP + 1);
	_Common::txtColor(15);
	cout << "PLAYER 1 VS PLAYER 2";
	_Common::gotoXY(g.get_b()->getXAt(0, 0), g.get_b()->getYAt(0, 0));
	while (g.isContinue()) {
		g.waitKeyBoard();
		if (g.getCommand() == 27) g.exitGame();
		else {
			if (g.getCommand() == 'A' || g.getCommand() == 75)
				g.moveLeft();
			if (g.getCommand() == 'W' || g.getCommand() == 72)
				g.moveUp();
			if (g.getCommand() == 'S' || g.getCommand() == 80)
				g.moveDown();
			if (g.getCommand() == 'D' || g.getCommand() == 77)
				g.moveRight();
			if (g.getCommand() == 13 || g.getCommand() == 32)
			{
				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục 
				if (g.processCheckBoard()) {
					switch (g.processFinish()) {
					case WIN1: case WIN2: case DRAW:
						g.askContinue();
						if (g.askContinue() != 'Y')
						{
							_Common::gotoXY(100, 105);
							g.exitGame();
						}
						else
						{
							g.startGame();
							_Common::gotoXY(BOARD_SIZE * 7 - 16, TOP + 1);
							_Common::txtColor(15);
							cout << "PLAYER 1 VS PLAYER 2";
							_Common::gotoXY(g.get_b()->getXAt(0, 0), g.get_b()->getYAt(0, 0));
						}
					}
				}

			}
		}
	}

}

void help() {
	system("cls");
	_Common::txtColor(14);
	cout << "\t========TRONG GIAO DIEN TRO CHOI========" << endl;
	_Common::txtColor(11);
	cout << "\t1. Su dung cac phim W, A, S, D hoac cac phim mui ten de di chuyen." << endl;
	_Common::txtColor(14);
	cout << "\t2. Su dung phim Space hoac Enter de thuc hien 1 nuoc danh." << endl;
	_Common::txtColor(11);
	cout << "\t3. Su dung ESC de thoat khoi tro choi." << endl;
	_Common::txtColor(14);
	cout << "\t******************************************" << endl;
	_Common::txtColor(11);
	cout << "\t============TRONG GIAO DIEN MENU============" << endl;
	_Common::txtColor(14);
	cout << "\t1. Su dung cac phim W, A, S, D hoac cac phim mui ten de di chuyen." << endl;
	_Common::txtColor(11);
	cout << "\t2. Nhan phim Enter de lua chon." << endl;
	_Common::txtColor(14);
	cout << "\t3. Cac chuc nang trong Menu:" << endl;
	_Common::txtColor(11);
	cout << "\t\t+ NEW GAME: Tao mot van choi moi." << endl;
	_Common::txtColor(14);
	cout << "\t\t+ LOAD GAME: Tai lai van choi con choi do truoc do." << endl;
	_Common::txtColor(11);
	cout << "\t\t+ HELP: Huong dan su dung." << endl;
	_Common::txtColor(14);
	cout << "\t\t+ ABOUT: Thong tin va lien he cua nguoi lam game." << endl;
	_Common::txtColor(11);
	cout << "\t\t+ EXIT: Thoat khoi chuong trinh." << endl;
	_Common::txtColor(14);
	system("pause");
}

void about() {
	system("cls");
	_Common::txtColor(11);
	cout << "\t=======DANH SACH THANH VIEN======" << endl;
	_Common::txtColor(14);
	cout << "\t1. 18600187 - Vu Cao Nguyen." << endl;
	cout << "\t2. 18600098 - Ton Duc Huan." << endl;
	cout << "\t3. 18600093 - Khuc Khai Hoan." << endl;
	_Common::txtColor(14);
	system("pause");
}