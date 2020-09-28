#include "Common.h"

void _Common::gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void _Common::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void _Common::txtColor(int x) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
void _Common::setFontSize(int FontSize)
{
	CONSOLE_FONT_INFOEX info = { 0 };
	info.cbSize = sizeof(info);
	info.dwFontSize.Y = FontSize;
	info.FontWeight = FW_NORMAL;
	wcscpy_s(info.FaceName, L"Lucida Console");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
}

void _Common::start()
{
	PlaySound("MainTitle", NULL, SND_ASYNC);
	_Common::gotoXY(0, 7);
	_Common::txtColor(12);
	int t = 150;
	cout << "\t\t***************************************************************************************" << endl; Sleep(t);
	cout << "\t\t***************************************************************************************" << endl; Sleep(t);
	cout << "\t\t**                                                                                   **" << endl; Sleep(t);
	cout << "\t\t**                     00000000                    XX                 XX             **" << endl; Sleep(t);
	cout << "\t\t**                  00          00                   XX             XX               **" << endl; Sleep(t);
	cout << "\t\t**                00              00                   XX         XX                 **" << endl; Sleep(t);
	cout << "\t\t**              00                  00                   XX     XX                   **" << endl; Sleep(t);
	cout << "\t\t**              00                  00                     XX XX                     **" << endl; Sleep(t);
	cout << "\t\t**              00                  00                   XX     XX                   **" << endl; Sleep(t);
	cout << "\t\t**              00                  00                 XX         XX                 **" << endl; Sleep(t);
	cout << "\t\t**                00              00                 XX             XX               **" << endl; Sleep(t);
	cout << "\t\t**                  00          00                 XX                 XX             **" << endl; Sleep(t);
	cout << "\t\t**                     00000000                  XX                     XX           **" << endl; Sleep(t);
	cout << "\t\t**                                                                                   **" << endl; Sleep(t);
	cout << "\t\t***************************************************************************************" << endl; Sleep(t);
	cout << "\t\t***************************************************************************************" << endl; Sleep(t);

	_Common::print_string("WELCOM TO CARO GAME");
	Sleep(2000);
	for (int i = 7; i < 15; i++)
	{
		system("cls");
		_Common::gotoXY(0, 7);
		_Common::txtColor(i);
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
		_Common::txtColor(i+1);
		cout << "\n\n\t\t\t\t\t\tWELCOM TO CARO GAME" << endl;
		Sleep(1000);
	}
	system("cls");
	
}

void _Common::print_string(char* string)
{
	int len = strlen(string);
	int i, j, n;
	char buf[32] = {};
	printf("\n\n");
	int loop = 0;
	_Common::txtColor(10);
	// Vòng lặp vô hạn dùng để in hàng chữ chạy liên tục.
	while (loop<1) {
		// Vòng lặp để in và di chuyển hàng chữ qua trái đến khi ký tự đầu chạm điểm giới hạn trái
		for (j = 1; j <= len; j++) {
			fflush(stdout);
			n = 50 + len - j;
			strncpy_s(buf, string, j);
			for (i = 0; i < n; i++)
				printf(" ");
			for (i = 0; i < j; i++)
				printf("%c", buf[i]);
			printf("\r"); // Giữ con trỏ luôn nằm trên 1 hàng
			Sleep(100);
		}

		loop++;
	}
}

