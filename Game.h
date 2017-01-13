#pragma once

#include "Keyboard.h"
#include "Graphics.h"
#include "Mouse.h"

class Game
{
public:

	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateTank1();
	void UpdateTank2();
	//void UpdateBot();
	void Realtank(int l , int h,int dir,int x,int y,int z);
	void Realtank2(int l, int h, int dir, int x, int y, int z);
	bool Valid(int x, int y);
	void Proiectil();

private:
	MainWindow& wnd;
	Graphics gfx;
	void DrawRunaDamage(int x, int y);
	void DrawRune(int x, int y);
	void Gameover(int x,int y);
	void DrawMesajviata(int x, int y);
	void DrawViata(int x, int y,int r,int b,int g);
	void Drawproiectil(int x, int y,int r,int b,int g);
	void Updatezid();
	void Labirint();
	int dxd = rand() % 630;
	int dyd = rand() % 550;
	int rx = rand() % 630;
	int ry = rand() % 550;
	//int coordonate[650][550];
	
private:
	int x = 100, y = 400;
	int x2 = 100, y2 = 100;
	int x3 = 550, y3 = 130;
	int damage = 1;
	int damage1 = 1;
	int damage2 = 1;
	int viata = 3;
	int viata2 = 3;
	int viata3 = 3;
	bool zid[800][800];
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int dir = 0;
	int dir2 = 0;
	int dir3 = 0;
	int speed = 2;
	int speed2 = 2;
	int nr_proiectile = 0;
	const int lins = 650;
	const int cols = 590;
	int p[10][3];
	int proiectil[10000][5];

	bool eaten[10];
	bool ok = false;
	void Initializari();
	void Ok(int x, int y);
	void Border();
	void Drawimages();
	void RunaDamage(int x, int y, int q);
	void Runa_viata(int i,int j,int q);
};
