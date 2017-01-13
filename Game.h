#include "Graphics.h"
#include <queue>

struct el {
	int x, y;
};
class Game
{
public:
	
	Game( class MainWindow& wnd );
	void Go();
private:
	void ComposeFrame();
	void UpdateTank1();
	void UpdateTank2();
	void UpdateBot();
	void Realtank(int l , int h,int dir,int x,int y,int z,int owner);
	void Drawmeniu(int x,int y);
	void Drawnewgame(int x, int y);
	bool Valid(int x, int y); 
	void Proiectil(); 
	void Lee();

private:
	MainWindow& wnd;
	Graphics gfx;
	void DrawRune(int x, int y);
	void Gameover(int x,int y); 
	void DrawMesajviata(int x, int y);
	void Drawpause(int x, int y);
	void Drawproiectil(int x, int y,int r,int b,int g);
	void Drawwinner(int x, int y);
	void Drawp1(int x, int y);
	void Drawp2(int x, int y);
	void Drawbots(int x, int y);
	void Drawzid(int x, int y);
	bool Tank1(int i, int j);
	int Modul(int x);
	int rx = rand() % 630;
	int ry = rand() % 550;

private:
	int x = 610, y = 530; 
	int x2 = 100, y2 = 100;
	int x3 = 350, y3 = 130;
	int viata = 3;
	int playing = true;
	int pauza = false;
	int viata2 = 3;
	int viata3 = 3;
	int val = 1;
	int n1 = 0;
	int n2 = 0;
	int n3 = 0;
	int dir = 0; 
	int dir2 = 0;
	int dir3 = 0;
	int speed = 2;
	int speed2 = 2;
	int tip_joc = 0;
	int nr_proiectile = 0; 
	const int lins = 650; 
	const int cols = 590;
	int p[10][3]; 
	int proiectil[1000][5];
	std::queue<el>Q;
	int Zid[10][2];
	bool ok = false;
	int di[4] = { -1,1,0,0 };
	int dj[4] = { 0,0,1,-1 };
	void Initializari();
	void Border(); 
	void Drawimages(); 
	int dist[400][400];
	short tr[400][400];
	bool Valid2(int i, int j,int i2,int j2);
	void Runa_viata(int i,int j,int q);
};

