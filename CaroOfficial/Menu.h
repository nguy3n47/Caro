#ifndef _MENU_H_
#define _MENU_H_
#include<iostream>
#include"Game.h"
using namespace std;

void Menu();
void printMenu(int selection);
int selectMenu();
void processMenu(int choose);
void newGame();
void newGameWithMachine();
void loadGame(string a);
void help();
void about();
void MenuNewGame(int selection);
int selectMenuNewGame();
#endif
