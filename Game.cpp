#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
}

void Game::Go()
{
		gfx.BeginFrame();
		//DrawRuneDamage();
		Updatezid();
		if(viata>0)
			UpdateTank1();
		if(viata2>0)
			UpdateTank2();
		/*if (viata3 > 0)
			UpdateBot();*/
		Border();
		Proiectil();
		Labirint();
		Drawimages();
		ComposeFrame();
		gfx.EndFrame();
}


/*void Game::DrawRuneDamage(int x, int y)
{

}*/



void Game::Labirint()
{	

	/*for (int i = 1; i <= 650; i++)
		for (int j = 1; j <= 550; j++)
			coordonate[i][j] = 0;*/
	int i, j;
	for (i = 6; i < 650; i++)
		for (j = 61; j <= 65; j++)
			if ((i < 50 || i>110) && (i < 540 || i>600) && (i < 295 || i>355))
			{
				
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 121; j <= 125; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
			{
				
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 181; j <= 185; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
			{
				
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 241; j <= 245; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
			{
				
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 301; j <= 305; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
			{
				
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 361; j <= 365; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
			{
			
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 421; j <= 425; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
			{
			
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 481; j <= 485; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
			{
				
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
	for (i = 6; i < 650; i++)
		for (j = 541; j <= 545; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
			{
			
				gfx.PutPixel(i, j, 0, 0, 0);
				//coordonate[i][j] = 1;
			}
			
	for(i=6;i<649;i++)
		for(j=66;j<121;j++)
			gfx.PutPixel(i, j, 180, 44,44);

}

/*void Game::verificareziduri()
{
	int coordonate[650][550];
	int i, j;
	for (i = 1; i <= 650; i++)
		for (j = 1; j <= 550; j++)
			coordonate[i][j] = 0;
}*/
bool Game::Valid(int x, int y)
{
	int i, j;
	if (x - 5 < 5 || x > lins - 5 || y - 4 < 5 || y > cols - 10) return false;
	else
		for (i = 150; i < 650; i++)
			for (j = 150; j <= 550; j++)
				if(x==i&&y==j)
			return false;
		else
			return true;
		/*for (i = 6; i < 650; i++)
			for (j = 61; j <= 65; j++)
				if ((i < 50 || i>110) && (i < 540 || i>600) && (i < 295 || i>355))
					return false;
				else
					return true;*/
	/*else
		if (coordonate[x][y] == 1)
			return false;
		else
			return true;*/
	/*for (i = 6; i < 650; i++)
		for (j = 61; j <= 65; j++)
			if ((x<50 || x>110) && (x<540 || x>600) && (x<295 || x>355)) return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 121; j <= 125; j++)
			if ((x<185 || x>245) && (x<400 || x>460))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 181; j <= 185; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 241; j <= 245; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 301; j <= 305; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 361; j <= 365; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 421; j <= 425; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 481; j <= 485; j++)
			if ((i<185 || i>245) && (i<400 || i>460))
				return false;
	return true;
	for (i = 6; i < 650; i++)
		for (j = 541; j <= 545; j++)
			if ((i<50 || i>110) && (i<540 || i>600) && (i<295 || i>355))
				return false;
	return true;*/

}

void Game::DrawRunaDamage(int x, int y)
{
	/*int i, j;
	for(i=x;i<=x+20;i++)
		for(j=y;j<=y+20;j++)
			gfx.PutPixel(i, j, 38,22,153);*/

	gfx.PutPixel(x , y , 38, 22, 153);
	gfx.PutPixel(x+1, y, 38, 22, 153);
	gfx.PutPixel(x+2, y, 38, 22, 153);
	gfx.PutPixel(x+3, y, 38, 22, 153);
	gfx.PutPixel(x+4, y, 38, 22, 153);
	gfx.PutPixel(x+5, y, 38, 22, 153);
	gfx.PutPixel(x+6, y, 38, 22, 153);
	gfx.PutPixel(x+7, y, 38, 22, 153);
	gfx.PutPixel(x + 8, y, 38, 22, 153);
	gfx.PutPixel(x + 9, y, 38, 22, 153);
	gfx.PutPixel(x + 10, y, 38, 22, 153);
	gfx.PutPixel(x + 11, y, 38, 22, 153);
	gfx.PutPixel(x + 12, y, 38, 22, 153);
	gfx.PutPixel(x + 13, y, 38, 22, 153);
	gfx.PutPixel(x + 14, y, 38, 22, 153);

	gfx.PutPixel(x-1, y+1, 38, 22, 153);
	gfx.PutPixel(x, y + 1, 38, 22, 153);
	gfx.PutPixel(x+1, y + 1, 38, 22, 153);
	gfx.PutPixel(x+2, y + 1, 38, 22, 153);
	gfx.PutPixel(x+3, y + 1, 38, 22, 153);
	gfx.PutPixel(x+4, y + 1, 38, 22, 153);
	gfx.PutPixel(x+5, y + 1, 38, 22, 153);
	gfx.PutPixel(x+6, y + 1, 38, 22, 153);
	gfx.PutPixel(x+7, y + 1, 38, 22, 153);
	gfx.PutPixel(x+8, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 1, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 1, 38, 22, 153);

	gfx.PutPixel(x -2, y + 2, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 2, 38, 22, 153);
	gfx.PutPixel(x, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 2, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 2, 38, 22, 153);

	gfx.PutPixel(x - 3, y + 3, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 3, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 3, 38, 22, 153);
	gfx.PutPixel(x, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 3, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 3, 38, 22, 153);

	gfx.PutPixel(x - 4, y + 4, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 4, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 4, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 4, 38, 22, 153);
	gfx.PutPixel(x, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 4, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 4, 38, 22, 153);

	gfx.PutPixel(x - 5, y + 5, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 5, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 5, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 5, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 5, 38, 22, 153);
	gfx.PutPixel(x, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 5, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 5, 38, 22, 153);

	
	gfx.PutPixel(x - 6, y + 6, 38, 22, 153);
	gfx.PutPixel(x - 5, y + 6, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 6, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 6, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 6, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 6, 38, 22, 153);
	gfx.PutPixel(x, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 6, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 6, 38, 22, 153);

	gfx.PutPixel(x - 7, y + 7, 38, 22, 153);
	gfx.PutPixel(x - 6, y + 7 ,38, 22, 153);
	gfx.PutPixel(x - 5, y + 7, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 7, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 7, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 7, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 7, 38, 22, 153);
	gfx.PutPixel(x, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 7, 38, 22, 153);
	gfx.PutPixel(x + 21, y + 7, 38, 22, 153);

	gfx.PutPixel(x - 8, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 7, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 6, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 5, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 8, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 8, 38, 22, 153);
	gfx.PutPixel(x, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 21, y + 8, 38, 22, 153);
	gfx.PutPixel(x + 22, y + 8, 38, 22, 153);

	gfx.PutPixel(x - 9, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 8, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 7, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 6, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 5, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 9, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 9, 38, 22, 153);
	gfx.PutPixel(x, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 21, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 22, y + 9, 38, 22, 153);
	gfx.PutPixel(x + 23, y + 9, 38, 22, 153);

	gfx.PutPixel(x - 8, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 7, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 6, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 5, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 10, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 10, 38, 22, 153);
	gfx.PutPixel(x, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 21, y + 10, 38, 22, 153);
	gfx.PutPixel(x + 22, y + 10, 38, 22, 153);

	gfx.PutPixel(x - 7, y + 11, 38, 22, 153);
	gfx.PutPixel(x - 6, y + 11, 38, 22, 153);
	gfx.PutPixel(x - 5, y + 11, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 11, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 11, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 11, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 11, 38, 22, 153);
	gfx.PutPixel(x, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 11, 38, 22, 153);
	gfx.PutPixel(x + 21, y + 11, 38, 22, 153);

	gfx.PutPixel(x - 6, y + 12, 38, 22, 153);
	gfx.PutPixel(x - 5, y + 12, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 12, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 12, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 12, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 12, 38, 22, 153);
	gfx.PutPixel(x, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 12, 38, 22, 153);
	gfx.PutPixel(x + 20, y + 12, 38, 22, 153);

	gfx.PutPixel(x - 5, y + 13, 38, 22, 153);
	gfx.PutPixel(x - 4, y + 13, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 13, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 13, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 13, 38, 22, 153);
	gfx.PutPixel(x, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 13, 38, 22, 153);
	gfx.PutPixel(x + 19, y + 13, 38, 22, 153);

	gfx.PutPixel(x - 4, y + 14, 38, 22, 153);
	gfx.PutPixel(x - 3, y + 14, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 14, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 14, 38, 22, 153);
	gfx.PutPixel(x, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 14, 38, 22, 153);
	gfx.PutPixel(x + 18, y + 14, 38, 22, 153);

	gfx.PutPixel(x - 3, y + 15, 38, 22, 153);
	gfx.PutPixel(x - 2, y + 15, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 15, 38, 22, 153);
	gfx.PutPixel(x, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 15, 38, 22, 153);
	gfx.PutPixel(x + 17, y + 15, 38, 22, 153);

	gfx.PutPixel(x - 2, y + 16, 38, 22, 153);
	gfx.PutPixel(x - 1, y + 16, 38, 22, 153);
	gfx.PutPixel(x, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 16, 38, 22, 153);
	gfx.PutPixel(x + 16, y + 16, 38, 22, 153);

	gfx.PutPixel(x - 1, y + 17, 38, 22, 153);
	gfx.PutPixel(x, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 17, 38, 22, 153);
	gfx.PutPixel(x + 15, y + 17, 38, 22, 153);

	gfx.PutPixel(x, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 1, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 2, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 3, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 4, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 5, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 6, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 7, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 8, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 9, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 10, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 11, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 12, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 13, y + 18, 38, 22, 153);
	gfx.PutPixel(x + 14, y + 18, 38, 22, 153);

}

void Game::Updatezid()
{
	int i, j;
	for (i = 6; i < 650; i++)
		for (j = 6; j < 590; j++)
			gfx.PutPixel(i, j, 117, 107, 107);
}

void Game::UpdateTank1()
{
	int cnt = 10;
	Realtank(x,y,dir,61,142,25);

	if (wnd.kbd.KeyIsPressed(VK_UP) && wnd.kbd.KeyIsPressed(VK_LEFT) && Valid(x-speed+25,y-speed+25) && Valid(x - speed, y - speed))
		x -= speed, y -= speed, dir = 0;
	else if (wnd.kbd.KeyIsPressed(VK_UP) && wnd.kbd.KeyIsPressed(VK_RIGHT) && Valid(x + speed+25, y - speed+25) && Valid(x + speed, y - speed))
		x += speed, y -= speed, dir = 0;
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && wnd.kbd.KeyIsPressed(VK_LEFT)&& Valid(x - speed+25, y + speed+25) && Valid(x - speed, y + speed))
		x -= speed, y += speed, dir = 1;
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && wnd.kbd.KeyIsPressed(VK_RIGHT) && Valid(x + speed+25, y + speed+25) && Valid(x + speed, y + speed))
		x += speed, y += speed, dir = 1;
	else if (wnd.kbd.KeyIsPressed(VK_LEFT) && Valid(x-speed+25,y) && Valid(x - speed, y))
		x -= speed , dir = 3;
	else if (wnd.kbd.KeyIsPressed(VK_RIGHT) && Valid(x + speed+25,y) && Valid(x + speed, y))
		x+=speed, dir = 2;

	else if (wnd.kbd.KeyIsPressed(VK_UP) && Valid(x,y - speed+25) && Valid(x, y - speed))
		y-=speed, dir = 0;
	else if (wnd.kbd.KeyIsPressed(VK_DOWN) && Valid(x, y + speed+25) && Valid(x, y + speed))
		y+=speed, dir = 1;
	
}

void Game::UpdateTank2()
{
	int cnt = 10;
	Realtank2(x2, y2, dir2,255,255,0);
	/*for (int i = x2; i <= x2 + 25; ++i)
		for (int j = y2; j <= y2 + 25; ++j) {
			if (Valid(i, j)) // daca i,j se afla in teren
				gfx.PutPixel(i, j, 0, 255, 0);

			Runa_viata(i, j,2);
		}*/
	// instructiuni pt cand se apasa vreo sageata
	unsigned char sus = 'W';
	unsigned char jos = 'S';
	unsigned char stanga = 'A';
	unsigned char dreapta = 'D';
	int x = x2, y = y2;
	if (wnd.kbd.KeyIsPressed(sus) && wnd.kbd.KeyIsPressed(stanga) && Valid(x - speed2+25, 25+y - speed2)&& Valid(x - speed2 , y - speed2))
		x -= speed2, y -= speed2, dir2 = 0;
	else if (wnd.kbd.KeyIsPressed(sus) && wnd.kbd.KeyIsPressed(dreapta) && Valid(x + speed2+25, 25+y - speed2) && Valid(x + speed2, y - speed2))
		x += speed2, y -= speed2, dir2 = 0;
	else if (wnd.kbd.KeyIsPressed(jos) && wnd.kbd.KeyIsPressed(stanga) && Valid(x - speed2+25, y +25+ speed2) && Valid(x - speed2, y + speed2))
		x -= speed2, y += speed2, dir2 = 1;
	else if (wnd.kbd.KeyIsPressed(jos) && wnd.kbd.KeyIsPressed(dreapta) && Valid(x + speed2+25, 25+y + speed2) && Valid(x + speed2, y + speed2))
		x += speed2, y += speed2, dir2 = 1;
	else if (wnd.kbd.KeyIsPressed(stanga) && Valid(x - speed2+25, y) && Valid(x - speed2, y))
		x -= speed2, dir2 = 3;
	else if (wnd.kbd.KeyIsPressed(dreapta) && Valid(x + speed2+25, y) && Valid(x + speed2, y))
		x += speed2, dir2 = 2;

	else if (wnd.kbd.KeyIsPressed(sus) && Valid(x, y - speed2+25) && Valid(x, y - speed2))
		y -= speed2, dir2 = 0;
	else if (wnd.kbd.KeyIsPressed(jos) && Valid(x, y + speed2+25) && Valid(x, y + speed2))
		y += speed2, dir2 = 1;
	x2 = x, y2 = y; 
}

/*void Game::UpdateBot()
{
	int i, j;
	
	if (x < x3)
		x3 -= 2, dir3 = 3;
	else if (x == x3) {
		int dx = x3;
		int dy = y3;
		if (!dir2)dx += 13;
		else if (dir2 == 1)dx += 13, dy += 25;
		else if (dir2 == 2)dx += 25, dy += 13;
		else dy += 13;
		if (n3 < 5) {
			++nr_proiectile;
			++n3;
			int j = nr_proiectile;
			proiectil[j][0] = dx;
			proiectil[j][1] = dy;
			proiectil[j][2] = 1;
			proiectil[j][3] = 3;
		}
	}
	else if (x > x3)
		x3 += 2, dir3 = 2;
	Realtank(x3, y3, 1, 255, 255, 255);
	
}*/

void Game::Realtank(int l,int h,int dir,int x,int y,int z)
{
	int i, j;
	for (i = l - 5; i <= l; i++)
		for (j = h - 4; j <= h+34; j++)
			gfx.PutPixel(i, j, 64, 25, 135);
	for (i = l + 22; i <= l + 27; i++)
		for (j = h - 4; j <= h + 34; j++)
			gfx.PutPixel(i, j, 64, 25, 135);
	for (i = l; i <= l + 22; i++)
		for (j = h; j <= h + 30; j++) {
			Runa_viata(i, j, 1);
			RunaDamage(i, j, 1);
			gfx.PutPixel(i, j, x, y, z);
		}
	for (i = l + 5; i <= l + 17; i++)
		for (j = h + 5; j <= h + 17; j++)
			gfx.PutPixel(i, j, 88, 94, 133);
	if(!dir)
		for (i = l + 10; i <= l + 12; i++)
			for (j = h - 10; j <= h + 11; j++)
				gfx.PutPixel(i, j, 78, 80, 96);
	else if(dir == 1)
		for (i = l + 10; i <= l + 12; i++)
			for (j = h+11; j <= h + 32; j++)
				gfx.PutPixel(i, j, 78, 80, 96);
	else if(dir == 3)
		for (i = l+10; i >=l-11; i--)
			for (j = h+11; j <= h + 13; j++)
				gfx.PutPixel(i, j, 78, 80, 96);
	else
		for (i = l + 10; i <= l + 31; i++)
			for (j = h + 11; j <= h + 13; j++)
				gfx.PutPixel(i, j, 78, 80, 96);

}

void Game::Realtank2(int l, int h, int dir, int x, int y, int z)
{
	int i, j;
	for (i = l - 5; i <= l; i++)
		for (j = h - 4; j <= h + 34; j++)
			gfx.PutPixel(i, j, 64, 25, 135);
	for (i = l + 22; i <= l + 27; i++)
		for (j = h - 4; j <= h + 34; j++)
			gfx.PutPixel(i, j, 64, 25, 135);
	for (i = l; i <= l + 22; i++)
		for (j = h; j <= h + 30; j++) {
			Runa_viata(i, j, 2);
			RunaDamage(i, j, 2);
			gfx.PutPixel(i, j, x, y, z);
		}
	for (i = l + 5; i <= l + 17; i++)
		for (j = h + 5; j <= h + 17; j++)
			gfx.PutPixel(i, j, 88, 94, 133);
	if (!dir)
		for (i = l + 10; i <= l + 12; i++)
			for (j = h - 10; j <= h + 11; j++)
				gfx.PutPixel(i, j, 78, 80, 96);
	else if (dir == 1)
		for (i = l + 10; i <= l + 12; i++)
			for (j = h + 11; j <= h + 32; j++)
				gfx.PutPixel(i, j, 78, 80, 96);
	else if (dir == 3)
		for (i = l + 10; i >= l - 11; i--)
			for (j = h + 11; j <= h + 13; j++)
				gfx.PutPixel(i, j, 78, 80, 96);
	else
		for (i = l + 10; i <= l + 31; i++)
			for (j = h + 11; j <= h + 13; j++)
				gfx.PutPixel(i, j, 78, 80, 96);

}

/*void Game::UpdateBot()
{
int i, j;

if (x < x3)
x3 -= 2, dir3 = 3;
else if (x == x3) {
int dx = x3;
int dy = y3;
if (!dir2)dx += 13;
else if (dir2 == 1)dx += 13, dy += 25;
else if (dir2 == 2)dx += 25, dy += 13;
else dy += 13;
if (n3 < 5) {
++nr_proiectile;
++n3;
int j = nr_proiectile;
proiectil[j][0] = dx;
proiectil[j][1] = dy;
proiectil[j][2] = 1;
proiectil[j][3] = 3;
}
}
else if (x > x3)
x3 += 2, dir3 = 2;
Realtank(x3, y3, 1, 255, 255, 255);

}*/
void Game::Proiectil()
{
	int dx,dy,directie,owner;
	bool gata;
	for (int i = 1; i <= nr_proiectile; ++i) {
		directie = proiectil[i][2];
		owner = proiectil[i][3];
		
		if (!directie)proiectil[i][1]-=3;
		else if (directie == 1)proiectil[i][1]+=3;
		else if (directie == 2)proiectil[i][0]+=3; // scad cu 2 ca sa se miste mai rpd proiectilul :)
		else proiectil[i][0]-=3;
		gata = true;
		if ((owner == 1 && !viata)||(owner==2&&!viata2)) {
			proiectil[i][0] = proiectil[nr_proiectile][0];
			proiectil[i][1] = proiectil[nr_proiectile][1];
			proiectil[i][2] = proiectil[nr_proiectile][2];
			proiectil[i][3] = proiectil[nr_proiectile][3];
			--nr_proiectile;
			--i;
		}
		
		if (!Valid(proiectil[i][0], proiectil[i][1]) || !Valid(proiectil[i][0]+19,proiectil[i][1]+19))
		{
			proiectil[i][0] = proiectil[nr_proiectile][0];
			proiectil[i][1] = proiectil[nr_proiectile][1];
			proiectil[i][2] = proiectil[nr_proiectile][2];
			proiectil[i][3] = proiectil[nr_proiectile][3];
			--nr_proiectile;
			--i;
			if (owner == 1)--n1;
			else if(owner == 2)--n2;
			else --n3;
			gata = false;
		}
		else {
			dx = proiectil[i][0];
			dy = proiectil[i][1];

			if (owner == 1 && dx >= x2 && dx <= x2 + 25 && dy >= y2 && dy <= y2 + 25) {
				proiectil[i][0] = proiectil[nr_proiectile][0];
				proiectil[i][1] = proiectil[nr_proiectile][1];
				proiectil[i][2] = proiectil[nr_proiectile][2];
				proiectil[i][3] = proiectil[nr_proiectile][3];
				--nr_proiectile;
				--i;
				--n1;
				--viata2;
				gata = false;
			}
			else if (owner == 2 && dx >= x && dx <= x + 25 && dy >= y && dy <= y + 25) {
				proiectil[i][0] = proiectil[nr_proiectile][0];
				proiectil[i][1] = proiectil[nr_proiectile][1];
				proiectil[i][2] = proiectil[nr_proiectile][2];
				proiectil[i][3] = proiectil[nr_proiectile][3];
				--nr_proiectile;
				--i;
				--n2;
				--viata;
				gata = false;
			}
			else if (owner == 3 && dx >= x && dx <= x + 25 && dy >= y && dy <= y + 25) {
				proiectil[i][0] = proiectil[nr_proiectile][0];
				proiectil[i][1] = proiectil[nr_proiectile][1];
				proiectil[i][2] = proiectil[nr_proiectile][2];
				proiectil[i][3] = proiectil[nr_proiectile][3];
				--nr_proiectile;
				--i;
				--n3;
				--viata;
				gata = false;
			}
			else if (owner == 1 && dx >= x3 && dx <= x3 + 25 && dy >= y3 && dy <= y3 + 25) {
				proiectil[i][0] = proiectil[nr_proiectile][0];
				proiectil[i][1] = proiectil[nr_proiectile][1];
				proiectil[i][2] = proiectil[nr_proiectile][2];
				proiectil[i][3] = proiectil[nr_proiectile][3];
				--nr_proiectile;
				--i;
				--n1;
				--viata3;
				gata = false;
			}
		}
		if(gata){
			int xx = proiectil[i][0];
			int yy = proiectil[i][1];
			if (owner == 1)
				Drawproiectil(xx, yy, 24, 182, 96);
			else
				Drawproiectil(xx, yy, 112, 112, 112);
			Ok(xx,yy);
		}
	}
}
void Game::DrawRune(int x, int y)
{

	gfx.PutPixel(x-1, y+1, 224, 39, 39);
	gfx.PutPixel(x+1, y+1, 224, 39, 39);

	gfx.PutPixel(x-2, y+2, 224, 39, 39);
	gfx.PutPixel(x-1, y+2, 224, 39, 39);
	gfx.PutPixel(x+1, y+2, 224, 39, 39);
	gfx.PutPixel(x+2, y+2, 224, 39, 39);

	gfx.PutPixel(x - 3, y + 3, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 3, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 3, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 3, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 3, 224, 39,39);
	gfx.PutPixel(x + 3, y + 3, 224, 39, 39);

	gfx.PutPixel(x - 4, y + 4, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 4, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 4, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 4, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 4, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 4, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 4, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 4, 224, 39, 39);

	gfx.PutPixel(x - 5, y + 5, 224, 39, 39);
	gfx.PutPixel(x - 4, y + 5, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 5, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 5, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 5, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 5, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 5, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 5, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 5, 224, 39, 39);
	gfx.PutPixel(x + 5, y + 5, 224, 39, 39);

	gfx.PutPixel(x - 6, y + 6, 224, 39, 39);
	gfx.PutPixel(x - 5, y + 6, 224, 39, 39);
	gfx.PutPixel(x - 4, y + 6, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 6, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 6, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 6, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 6, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 6, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 6, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 6, 224, 39, 39);
	gfx.PutPixel(x + 5, y + 6, 224, 39, 39);
	gfx.PutPixel(x + 6, y + 6, 224, 39, 39);

	gfx.PutPixel(x - 7, y + 7, 224, 39, 39);
	gfx.PutPixel(x - 6, y + 7, 224, 39, 39);
	gfx.PutPixel(x - 5, y + 7, 224, 39, 39);
	gfx.PutPixel(x - 4, y + 7, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 7, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 7, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 5, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 6, y + 7, 224, 39, 39);
	gfx.PutPixel(x + 7, y + 7, 224, 39, 39);

	for (int i = x - 7; i <= x + 7; i++)
		for (int j = y + 7; j <= y + 21; j++)
			gfx.PutPixel(i, j, 224, 39, 39);


	gfx.PutPixel(x - 1, y + 28, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 28, 224, 39, 39);

	gfx.PutPixel(x - 2, y + 27, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 27, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 27, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 27, 224, 39, 39);

	gfx.PutPixel(x - 3, y + 26, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 26, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 26, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 26, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 26, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 26, 224, 39, 39);

	gfx.PutPixel(x - 4, y + 25, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 25, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 25, 224,39, 39);
	gfx.PutPixel(x - 1, y + 25, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 25, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 25, 224, 39,39);
	gfx.PutPixel(x + 3, y + 25, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 25, 224, 39, 39);

	gfx.PutPixel(x - 5, y + 24, 224, 39, 39);
	gfx.PutPixel(x - 4, y + 24, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 24, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 24, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 24, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 24, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 24, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 24, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 24, 224, 39, 39);
	gfx.PutPixel(x + 5, y + 24, 224, 39, 39);

	gfx.PutPixel(x - 6, y + 23, 224, 39, 39);
	gfx.PutPixel(x - 5, y + 23, 224, 39, 39);
	gfx.PutPixel(x - 4, y + 23, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 23, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 23, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 23, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 23, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 23, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 23, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 23, 224, 39, 39);
	gfx.PutPixel(x + 5, y + 23, 224, 39, 39);
	gfx.PutPixel(x + 6, y + 23, 224, 39, 39);

	gfx.PutPixel(x - 7, y + 22, 224, 39, 39);
	gfx.PutPixel(x - 6, y + 22, 224, 39, 39);
	gfx.PutPixel(x - 5, y + 22, 224, 39, 39);
	gfx.PutPixel(x - 4, y + 22, 224, 39, 39);
	gfx.PutPixel(x - 3, y + 22, 224, 39, 39);
	gfx.PutPixel(x - 2, y + 22, 224, 39, 39);
	gfx.PutPixel(x - 1, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 1, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 2, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 3, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 4, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 5, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 6, y + 22, 224, 39, 39);
	gfx.PutPixel(x + 7, y + 22, 224, 39, 39);
	
	int i = x;
	for (int j = y; j <= y+28; j++)
		gfx.PutPixel(i, j, 165, 56, 56);
	int j = y + 22;
	for(int i=x-7;i<=x+7;i++)
		gfx.PutPixel(i, j, 165, 56, 56);
j = y + 7;
	for (int i = x - 7; i <= x + 7; i++)
		gfx.PutPixel(i, j, 165,56,56);
}
void Game::Gameover(int x, int y)
{
	gfx.PutPixel(49 + x, 0 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 0 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 0 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 1 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 2 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 3 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 4 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 5 + y, 0, 118, 11);
	gfx.PutPixel(35 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 5 + y, 0, 142, 13);
	gfx.PutPixel(52 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 5 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 6 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 7 + y, 0, 142, 13);
	gfx.PutPixel(79 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 7 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 8 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 9 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 9 + y, 0, 118, 11);
	gfx.PutPixel(34 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 10 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 11 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 12 + y, 0, 142, 13);
	gfx.PutPixel(36 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 12 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 13 + y, 0, 142, 13);
	gfx.PutPixel(57 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 13 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 14 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 15 + y, 0, 25, 2);
	gfx.PutPixel(25 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 15 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 16 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 17 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 18 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 19 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 20 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 21 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 22 + y, 0, 25, 2);
	gfx.PutPixel(62 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 22 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 23 + y, 0, 3, 0);
	gfx.PutPixel(18 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 23 + y, 0, 25, 2);
	gfx.PutPixel(63 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 23 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 24 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 25 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 26 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 27 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 28 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 29 + y, 0, 25, 2);
	gfx.PutPixel(64 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 29 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 30 + y, 0, 25, 2);
	gfx.PutPixel(81 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 30 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 31 + y, 0, 70, 6);
	gfx.PutPixel(11 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 31 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 32 + y, 0, 118, 11);
	gfx.PutPixel(62 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 32 + y, 0, 25, 2);
	gfx.PutPixel(79 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 32 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 33 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 33 + y, 0, 25, 2);
	gfx.PutPixel(8 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 34 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 35 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 36 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(37 + x, 37 + y, 0, 70, 6);
	gfx.PutPixel(38 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 37 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 38 + y, 0, 70, 6);
	gfx.PutPixel(39 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 38 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 39 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 40 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 40 + y, 0, 70, 6);
	gfx.PutPixel(12 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 41 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 42 + y, 0, 25, 2);
	gfx.PutPixel(4 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 42 + y, 0, 25, 2);
	gfx.PutPixel(13 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 42 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 43 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 44 + y, 0, 3, 0);
	gfx.PutPixel(78 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 44 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 45 + y, 0, 118, 11);
	gfx.PutPixel(38 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 45 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 46 + y, 0, 118, 11);
	gfx.PutPixel(78 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 46 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(27 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(38 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 47 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(39 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 48 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 49 + y, 0, 142, 13);
	gfx.PutPixel(1 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(40 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(41 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 49 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(8 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(18 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 50 + y, 0, 142, 13);
	gfx.PutPixel(41 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(42 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(43 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(44 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(45 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(46 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(56 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(75 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 50 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 55 + y, 0, 118, 11);
	gfx.PutPixel(49 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 55 + y, 0, 3, 0);
	gfx.PutPixel(67 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 55 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 56 + y, 0, 142, 13);
	gfx.PutPixel(19 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 56 + y, 0, 142, 13);
	gfx.PutPixel(47 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 56 + y, 0, 25, 2);
	gfx.PutPixel(51 + x, 56 + y, 0, 25, 2);
	gfx.PutPixel(52 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 56 + y, 0, 25, 2);
	gfx.PutPixel(80 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 56 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 57 + y, 0, 25, 2);
	gfx.PutPixel(10 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 57 + y, 0, 118, 11);
	gfx.PutPixel(19 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 57 + y, 0, 25, 2);
	gfx.PutPixel(66 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 57 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 58 + y, 0, 118, 11);
	gfx.PutPixel(15 + x, 58 + y, 0, 25, 2);
	gfx.PutPixel(16 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(21 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 58 + y, 0, 25, 2);
	gfx.PutPixel(66 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 58 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 59 + y, 0, 25, 2);
	gfx.PutPixel(15 + x, 59 + y, 0, 70, 6);
	gfx.PutPixel(16 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(22 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(23 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(24 + x, 59 + y, 0, 25, 2);
	gfx.PutPixel(25 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(65 + x, 59 + y, 0, 25, 2);
	gfx.PutPixel(66 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 59 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(57 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(64 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 60 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(1 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(12 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(13 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(14 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(16 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(58 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(63 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(78 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(79 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 61 + y, 0, 146, 14);
	gfx.PutPixel(0 + x, 62 + y, 0, 142, 13);
	gfx.PutPixel(1 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(2 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 62 + y, 0, 70, 6);
	gfx.PutPixel(16 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(47 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 62 + y, 0, 3, 0);
	gfx.PutPixel(54 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(55 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(59 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(62 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(80 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(81 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 62 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 62 + y, 0, 70, 6);
	gfx.PutPixel(1 + x, 63 + y, 0, 142, 13);
	gfx.PutPixel(2 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(3 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(4 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(5 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(6 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(7 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(9 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(10 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(11 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(15 + x, 63 + y, 0, 25, 2);
	gfx.PutPixel(16 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(17 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(19 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(20 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(25 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(26 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(28 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(29 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(30 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(31 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(32 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(33 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(34 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(35 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(36 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(48 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(49 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(50 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(51 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(52 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(53 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(54 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(60 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(61 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(66 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(67 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(68 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(69 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(70 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(71 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(72 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(73 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(74 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(76 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(77 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(82 + x, 63 + y, 0, 146, 14);
	gfx.PutPixel(83 + x, 63 + y, 0, 146, 14);

}

void Game::Drawproiectil(int x, int y,int r,int b,int g)
{
		gfx.PutPixel(7 + x, 0 + y, r, b, g);
		gfx.PutPixel(8 + x, 0 + y, r, b, g);
		gfx.PutPixel(9 + x, 0 + y, r, b, g);
		gfx.PutPixel(10 + x, 0 + y, r, b, g);
		gfx.PutPixel(11 + x, 0 + y, r, b, g);
		gfx.PutPixel(12 + x, 0 + y, r, b, g);
		gfx.PutPixel(5 + x, 1 + y, r, b, g);
		gfx.PutPixel(6 + x, 1 + y, r, b, g);
		gfx.PutPixel(7 + x, 1 + y, r, b, g);
		gfx.PutPixel(8 + x, 1 + y, r, b, g);
		gfx.PutPixel(9 + x, 1 + y, r, b, g);
		gfx.PutPixel(10 + x, 1 + y, r, b, g);
		gfx.PutPixel(11 + x, 1 + y, r, b, g);
		gfx.PutPixel(12 + x, 1 + y, r, b, g);
		gfx.PutPixel(13 + x, 1 + y, r, b, g);
		gfx.PutPixel(14 + x, 1 + y, r, b, g);
		gfx.PutPixel(3 + x, 2 + y, r, b, g);
		gfx.PutPixel(4 + x, 2 + y, r, b, g);
		gfx.PutPixel(5 + x, 2 + y, r, b, g);
		gfx.PutPixel(6 + x, 2 + y, r, b, g);
		gfx.PutPixel(7 + x, 2 + y, r, b, g);
		gfx.PutPixel(8 + x, 2 + y, r, b, g);
		gfx.PutPixel(9 + x, 2 + y, r, b, g);
		gfx.PutPixel(10 + x, 2 + y, r, b, g);
		gfx.PutPixel(11 + x, 2 + y, r, b, g);
		gfx.PutPixel(12 + x, 2 + y, r, b, g);
		gfx.PutPixel(13 + x, 2 + y, r, b, g);
		gfx.PutPixel(14 + x, 2 + y, r, b, g);
		gfx.PutPixel(15 + x, 2 + y, r, b, g);
		gfx.PutPixel(16 + x, 2 + y, r, b, g);
		gfx.PutPixel(2 + x, 3 + y, r, b, g);
		gfx.PutPixel(3 + x, 3 + y, r, b, g);
		gfx.PutPixel(4 + x, 3 + y, r, b, g);
		gfx.PutPixel(5 + x, 3 + y, r, b, g);
		gfx.PutPixel(6 + x, 3 + y, r, b, g);
		gfx.PutPixel(7 + x, 3 + y, r, b, g);
		gfx.PutPixel(8 + x, 3 + y, r, b, g);
		gfx.PutPixel(9 + x, 3 + y, r, b, g);
		gfx.PutPixel(10 + x, 3 + y, r, b, g);
		gfx.PutPixel(11 + x, 3 + y, r, b, g);
		gfx.PutPixel(12 + x, 3 + y, r, b, g);
		gfx.PutPixel(13 + x, 3 + y, r, b, g);
		gfx.PutPixel(14 + x, 3 + y, r, b, g);
		gfx.PutPixel(15 + x, 3 + y, r, b, g);
		gfx.PutPixel(16 + x, 3 + y, r, b, g);
		gfx.PutPixel(17 + x, 3 + y, r, b, g);
		gfx.PutPixel(2 + x, 4 + y, r, b, g);
		gfx.PutPixel(3 + x, 4 + y, r, b, g);
		gfx.PutPixel(4 + x, 4 + y, r, b, g);
		gfx.PutPixel(5 + x, 4 + y, r, b, g);
		gfx.PutPixel(6 + x, 4 + y, r, b, g);
		gfx.PutPixel(7 + x, 4 + y, r, b, g);
		gfx.PutPixel(8 + x, 4 + y, r, b, g);
		gfx.PutPixel(9 + x, 4 + y, r, b, g);
		gfx.PutPixel(10 + x, 4 + y, r, b, g);
		gfx.PutPixel(11 + x, 4 + y, r, b, g);
		gfx.PutPixel(12 + x, 4 + y, r, b, g);
		gfx.PutPixel(13 + x, 4 + y, r, b, g);
		gfx.PutPixel(14 + x, 4 + y, r, b, g);
		gfx.PutPixel(15 + x, 4 + y, r, b, g);
		gfx.PutPixel(16 + x, 4 + y, r, b, g);
		gfx.PutPixel(17 + x, 4 + y, r, b, g);
		gfx.PutPixel(1 + x, 5 + y, r, b, g);
		gfx.PutPixel(2 + x, 5 + y, r, b, g);
		gfx.PutPixel(3 + x, 5 + y, r, b, g);
		gfx.PutPixel(4 + x, 5 + y, r, b, g);
		gfx.PutPixel(5 + x, 5 + y, r, b, g);
		gfx.PutPixel(6 + x, 5 + y, r, b, g);
		gfx.PutPixel(7 + x, 5 + y, r, b, g);
		gfx.PutPixel(8 + x, 5 + y, r, b, g);
		gfx.PutPixel(9 + x, 5 + y, r, b, g);
		gfx.PutPixel(10 + x, 5 + y, r, b, g);
		gfx.PutPixel(11 + x, 5 + y, r, b, g);
		gfx.PutPixel(12 + x, 5 + y, r, b, g);
		gfx.PutPixel(13 + x, 5 + y, r, b, g);
		gfx.PutPixel(14 + x, 5 + y, r, b, g);
		gfx.PutPixel(15 + x, 5 + y, r, b, g);
		gfx.PutPixel(16 + x, 5 + y, r, b, g);
		gfx.PutPixel(17 + x, 5 + y, r, b, g);
		gfx.PutPixel(18 + x, 5 + y, r, b, g);
		gfx.PutPixel(1 + x, 6 + y, r, b, g);
		gfx.PutPixel(2 + x, 6 + y, r, b, g);
		gfx.PutPixel(3 + x, 6 + y, r,b,g);
		gfx.PutPixel(4 + x, 6 + y, r, b, g);
		gfx.PutPixel(5 + x, 6 + y, r, b, g);
		gfx.PutPixel(6 + x, 6 + y, r, b, g);
		gfx.PutPixel(7 + x, 6 + y, r, b, g);
		gfx.PutPixel(8 + x, 6 + y, r, b, g);
		gfx.PutPixel(9 + x, 6 + y, r, b, g);
		gfx.PutPixel(10 + x, 6 + y, r, b, g);
		gfx.PutPixel(11 + x, 6 + y, r,b,g);
		gfx.PutPixel(12 + x, 6 + y, r,b,g);
		gfx.PutPixel(13 + x, 6 + y, r, b, g);
		gfx.PutPixel(14 + x, 6 + y, r, b, g);
		gfx.PutPixel(15 + x, 6 + y, r, b, g);
		gfx.PutPixel(16 + x, 6 + y, r, b, g);
		gfx.PutPixel(17 + x, 6 + y, r, b, g);
		gfx.PutPixel(18 + x, 6 + y, r, b, g);
		gfx.PutPixel(0 + x, 7 + y, r, b, g);
		gfx.PutPixel(1 + x, 7 + y, r, b, g);
		gfx.PutPixel(2 + x, 7 + y, r,b,g);
		gfx.PutPixel(3 + x, 7 + y, r,b,g);
		gfx.PutPixel(4 + x, 7 + y, r, b, g);
		gfx.PutPixel(5 + x, 7 + y, r, b, g);
		gfx.PutPixel(6 + x, 7 + y, r, b, g);
		gfx.PutPixel(7 + x, 7 + y, r, b, g);
		gfx.PutPixel(8 + x, 7 + y, r, b, g);
		gfx.PutPixel(9 + x, 7 + y, r, b, g);
		gfx.PutPixel(10 + x, 7 + y, r, b, g);
		gfx.PutPixel(11 + x, 7 + y,r,b,g);
		gfx.PutPixel(12 + x, 7 + y, r,b,g);
		gfx.PutPixel(13 + x, 7 + y, r, b, g);
		gfx.PutPixel(14 + x, 7 + y, r, b, g);
		gfx.PutPixel(15 + x, 7 + y, r, b, g);
		gfx.PutPixel(16 + x, 7 + y, r, b, g);
		gfx.PutPixel(17 + x, 7 + y, r, b, g);
		gfx.PutPixel(18 + x, 7 + y, r, b, g);
		gfx.PutPixel(19 + x, 7 + y, r, b, g);
		gfx.PutPixel(0 + x, 8 + y, r, b, g);
		gfx.PutPixel(1 + x, 8 + y, r, b, g);
		gfx.PutPixel(2 + x, 8 + y, r,b,g);
		gfx.PutPixel(3 + x, 8 + y, r,b,g);
		gfx.PutPixel(4 + x, 8 + y, r,b,g);
		gfx.PutPixel(5 + x, 8 + y, r, b, g);
		gfx.PutPixel(6 + x, 8 + y, r, b, g);
		gfx.PutPixel(7 + x, 8 + y, r, b, g);
		gfx.PutPixel(8 + x, 8 + y, r, b, g);
		gfx.PutPixel(9 + x, 8 + y, r, b, g);
		gfx.PutPixel(10 + x, 8 + y, r, b, g);
		gfx.PutPixel(11 + x, 8 + y, r,b,g);
		gfx.PutPixel(12 + x, 8 + y, r, b, g);
		gfx.PutPixel(13 + x, 8 + y, r, b, g);
		gfx.PutPixel(14 + x, 8 + y, r, b, g);
		gfx.PutPixel(15 + x, 8 + y, r, b, g);
		gfx.PutPixel(16 + x, 8 + y, r, b, g);
		gfx.PutPixel(17 + x, 8 + y, r, b, g);
		gfx.PutPixel(18 + x, 8 + y, r, b, g);
		gfx.PutPixel(19 + x, 8 + y, r, b, g);
		gfx.PutPixel(0 + x, 9 + y, r, b, g);
		gfx.PutPixel(1 + x, 9 + y, r, b, g);
		gfx.PutPixel(2 + x, 9 + y, r, b, g);
		gfx.PutPixel(3 + x, 9 + y, r, b, g);
		gfx.PutPixel(4 + x, 9 + y, r, b, g);
		gfx.PutPixel(5 + x, 9 + y, r, b, g);
		gfx.PutPixel(6 + x, 9 + y, r, b, g);
		gfx.PutPixel(7 + x, 9 + y, r, b, g);
		gfx.PutPixel(8 + x, 9 + y, r, b, g);
		gfx.PutPixel(9 + x, 9 + y, r, b, g);
		gfx.PutPixel(10 + x, 9 + y, r, b, g);
		gfx.PutPixel(11 + x, 9 + y, r, b, g);
		gfx.PutPixel(12 + x, 9 + y, r, b, g);
		gfx.PutPixel(13 + x, 9 + y, r, b, g);
		gfx.PutPixel(14 + x, 9 + y, r, b, g);
		gfx.PutPixel(15 + x, 9 + y, r, b, g);
		gfx.PutPixel(16 + x, 9 + y, r, b, g);
		gfx.PutPixel(17 + x, 9 + y, r, b, g);
		gfx.PutPixel(18 + x, 9 + y, r, b, g);
		gfx.PutPixel(19 + x, 9 + y, r, b, g);
		gfx.PutPixel(0 + x, 10 + y, r, b, g);
		gfx.PutPixel(1 + x, 10 + y, r, b, g);
		gfx.PutPixel(2 + x, 10 + y, r, b, g);
		gfx.PutPixel(3 + x, 10 + y, r, b, g);
		gfx.PutPixel(4 + x, 10 + y, r, b, g);
		gfx.PutPixel(5 + x, 10 + y, r, b, g);
		gfx.PutPixel(6 + x, 10 + y, r, b, g);
		gfx.PutPixel(7 + x, 10 + y, r, b, g);
		gfx.PutPixel(8 + x, 10 + y, r, b, g);
		gfx.PutPixel(9 + x, 10 + y, r, b, g);
		gfx.PutPixel(10 + x, 10 + y, r, b, g);
		gfx.PutPixel(11 + x, 10 + y, r, b, g);
		gfx.PutPixel(12 + x, 10 + y, r, b, g);
		gfx.PutPixel(13 + x, 10 + y, r, b, g);
		gfx.PutPixel(14 + x, 10 + y, r, b, g);
		gfx.PutPixel(15 + x, 10 + y, r, b, g);
		gfx.PutPixel(16 + x, 10 + y, r, b, g);
		gfx.PutPixel(17 + x, 10 + y, r, b, g);
		gfx.PutPixel(18 + x, 10 + y, r, b, g);
		gfx.PutPixel(19 + x, 10 + y, r, b, g);
		gfx.PutPixel(0 + x, 11 + y, r, b, g);
		gfx.PutPixel(1 + x, 11 + y, r, b, g);
		gfx.PutPixel(2 + x, 11 + y, r, b, g);
		gfx.PutPixel(3 + x, 11 + y, r, b, g);
		gfx.PutPixel(4 + x, 11 + y, r, b, g);
		gfx.PutPixel(5 + x, 11 + y, r, b, g);
		gfx.PutPixel(6 + x, 11 + y, r, b, g);
		gfx.PutPixel(7 + x, 11 + y, r,b,g);
		gfx.PutPixel(8 + x, 11 + y, r,b,g);
		gfx.PutPixel(9 + x, 11 + y,r,b,g);
		gfx.PutPixel(10 + x, 11 + y, r,b,g);
		gfx.PutPixel(11 + x, 11 + y, r,b,g);
		gfx.PutPixel(12 + x, 11 + y, r,b,g);
		gfx.PutPixel(13 + x, 11 + y, r, b, g);
		gfx.PutPixel(14 + x, 11 + y, r, b, g);
		gfx.PutPixel(15 + x, 11 + y, r, b, g);
		gfx.PutPixel(16 + x, 11 + y, r, b, g);
		gfx.PutPixel(17 + x, 11 + y, r, b, g);
		gfx.PutPixel(18 + x, 11 + y, r, b, g);
		gfx.PutPixel(19 + x, 11 + y, r, b, g);
		gfx.PutPixel(0 + x, 12 + y, r, b, g);
		gfx.PutPixel(1 + x, 12 + y, r, b, g);
		gfx.PutPixel(2 + x, 12 + y, r, b, g);
		gfx.PutPixel(3 + x, 12 + y, r, b, g);
		gfx.PutPixel(4 + x, 12 + y, r, b, g);
		gfx.PutPixel(5 + x, 12 + y, r, b, g);
		gfx.PutPixel(6 + x, 12 + y, r, b, g);
		gfx.PutPixel(7 + x, 12 + y, r, b, g);
		gfx.PutPixel(8 + x, 12 + y, r, b, g);
		gfx.PutPixel(9 + x, 12 + y, r, b, g);
		gfx.PutPixel(10 + x, 12 + y, r, b, g);
		gfx.PutPixel(11 + x, 12 + y, r, b, g);
		gfx.PutPixel(12 + x, 12 + y, r, b, g);
		gfx.PutPixel(13 + x, 12 + y, r, b, g);
		gfx.PutPixel(14 + x, 12 + y, r, b, g);
		gfx.PutPixel(15 + x, 12 + y, r, b, g);
		gfx.PutPixel(16 + x, 12 + y, r, b, g);
		gfx.PutPixel(17 + x, 12 + y, r, b, g);
		gfx.PutPixel(18 + x, 12 + y, r, b, g);
		gfx.PutPixel(19 + x, 12 + y, r, b, g);
		gfx.PutPixel(1 + x, 13 + y, r, b, g);
		gfx.PutPixel(2 + x, 13 + y, r, b, g);
		gfx.PutPixel(3 + x, 13 + y, r, b, g);
		gfx.PutPixel(4 + x, 13 + y, r, b, g);
		gfx.PutPixel(5 + x, 13 + y, r, b, g);
		gfx.PutPixel(6 + x, 13 + y, r, b, g);
		gfx.PutPixel(7 + x, 13 + y, r, b, g);
		gfx.PutPixel(8 + x, 13 + y, r, b, g);
		gfx.PutPixel(9 + x, 13 + y, r, b, g);
		gfx.PutPixel(10 + x, 13 + y, r, b, g);
		gfx.PutPixel(11 + x, 13 + y, r, b, g);
		gfx.PutPixel(12 + x, 13 + y, r, b, g);
		gfx.PutPixel(13 + x, 13 + y, r, b, g);
		gfx.PutPixel(14 + x, 13 + y, r, b, g);
		gfx.PutPixel(15 + x, 13 + y, r, b, g);
		gfx.PutPixel(16 + x, 13 + y, r, b, g);
		gfx.PutPixel(17 + x, 13 + y, r, b, g);
		gfx.PutPixel(18 + x, 13 + y, r, b, g);
		gfx.PutPixel(1 + x, 14 + y, r, b, g);
		gfx.PutPixel(2 + x, 14 + y, r, b, g);
		gfx.PutPixel(3 + x, 14 + y, r, b, g);
		gfx.PutPixel(4 + x, 14 + y, r, b, g);
		gfx.PutPixel(5 + x, 14 + y, r, b, g);
		gfx.PutPixel(6 + x, 14 + y, r, b, g);
		gfx.PutPixel(7 + x, 14 + y, r, b, g);
		gfx.PutPixel(8 + x, 14 + y, r, b, g);
		gfx.PutPixel(9 + x, 14 + y, r, b, g);
		gfx.PutPixel(10 + x, 14 + y, r, b, g);
		gfx.PutPixel(11 + x, 14 + y, r, b, g);
		gfx.PutPixel(12 + x, 14 + y, r, b, g);
		gfx.PutPixel(13 + x, 14 + y, r, b, g);
		gfx.PutPixel(14 + x, 14 + y, r, b, g);
		gfx.PutPixel(15 + x, 14 + y, r, b, g);
		gfx.PutPixel(16 + x, 14 + y, r, b, g);
		gfx.PutPixel(17 + x, 14 + y, r, b, g);
		gfx.PutPixel(18 + x, 14 + y, r, b, g);
		gfx.PutPixel(2 + x, 15 + y, r, b, g);
		gfx.PutPixel(3 + x, 15 + y, r, b, g);
		gfx.PutPixel(4 + x, 15 + y, r, b, g);
		gfx.PutPixel(5 + x, 15 + y, r, b, g);
		gfx.PutPixel(6 + x, 15 + y, r, b, g);
		gfx.PutPixel(7 + x, 15 + y, r, b, g);
		gfx.PutPixel(8 + x, 15 + y, r, b, g);
		gfx.PutPixel(9 + x, 15 + y, r, b, g);
		gfx.PutPixel(10 + x, 15 + y, r, b, g);
		gfx.PutPixel(11 + x, 15 + y, r, b, g);
		gfx.PutPixel(12 + x, 15 + y, r, b, g);
		gfx.PutPixel(13 + x, 15 + y, r, b, g);
		gfx.PutPixel(14 + x, 15 + y, r, b, g);
		gfx.PutPixel(15 + x, 15 + y, r, b, g);
		gfx.PutPixel(16 + x, 15 + y, r, b, g);
		gfx.PutPixel(17 + x, 15 + y, r, b, g);
		gfx.PutPixel(2 + x, 16 + y, r, b, g);
		gfx.PutPixel(3 + x, 16 + y, r, b, g);
		gfx.PutPixel(4 + x, 16 + y, r, b, g);
		gfx.PutPixel(5 + x, 16 + y, r, b, g);
		gfx.PutPixel(6 + x, 16 + y, r, b, g);
		gfx.PutPixel(7 + x, 16 + y, r, b, g);
		gfx.PutPixel(8 + x, 16 + y, r, b, g);
		gfx.PutPixel(9 + x, 16 + y, r, b, g);
		gfx.PutPixel(10 + x, 16 + y, r, b, g);
		gfx.PutPixel(11 + x, 16 + y, r, b, g);
		gfx.PutPixel(12 + x, 16 + y, r, b, g);
		gfx.PutPixel(13 + x, 16 + y, r, b, g);
		gfx.PutPixel(14 + x, 16 + y, r, b, g);
		gfx.PutPixel(15 + x, 16 + y, r, b, g);
		gfx.PutPixel(16 + x, 16 + y, r, b, g);
		gfx.PutPixel(17 + x, 16 + y, r, b, g);
		gfx.PutPixel(3 + x, 17 + y, r, b, g);
		gfx.PutPixel(4 + x, 17 + y, r, b, g);
		gfx.PutPixel(5 + x, 17 + y, r, b, g);
		gfx.PutPixel(6 + x, 17 + y, r, b, g);
		gfx.PutPixel(7 + x, 17 + y, r, b, g);
		gfx.PutPixel(8 + x, 17 + y, r, b, g);
		gfx.PutPixel(9 + x, 17 + y, r, b, g);
		gfx.PutPixel(10 + x, 17 + y, r, b, g);
		gfx.PutPixel(11 + x, 17 + y, r, b, g);
		gfx.PutPixel(12 + x, 17 + y, r, b, g);
		gfx.PutPixel(13 + x, 17 + y, r, b, g);
		gfx.PutPixel(14 + x, 17 + y, r, b, g);
		gfx.PutPixel(15 + x, 17 + y, r, b, g);
		gfx.PutPixel(16 + x, 17 + y, r, b, g);
		gfx.PutPixel(5 + x, 18 + y, r, b, g);
		gfx.PutPixel(6 + x, 18 + y, r, b, g);
		gfx.PutPixel(7 + x, 18 + y, r, b, g);
		gfx.PutPixel(8 + x, 18 + y, r, b, g);
		gfx.PutPixel(9 + x, 18 + y, r, b, g);
		gfx.PutPixel(10 + x, 18 + y, r, b, g);
		gfx.PutPixel(11 + x, 18 + y, r, b, g);
		gfx.PutPixel(12 + x, 18 + y, r, b, g);
		gfx.PutPixel(13 + x, 18 + y, r, b, g);
		gfx.PutPixel(14 + x, 18 + y, r, b, g);
		gfx.PutPixel(7 + x, 19 + y, r, b, g);
		gfx.PutPixel(8 + x, 19 + y, r, b, g);
		gfx.PutPixel(9 + x, 19 + y, r, b, g);
		gfx.PutPixel(10 + x, 19 + y, r, b, g);
		gfx.PutPixel(11 + x, 19 + y, r, b, g);
		gfx.PutPixel(12 + x, 19 + y, r, b, g);
}
void Game::Initializari()
{	ok = true;
	for (int i = 0; i < 10; ++i)
		eaten[i] = true, p[i][0] = rand() % 650, p[i][1] = rand() % 550;
	viata = viata2 = 3;
	
	x = 320;
	y = 300;
	dxd = rand() % 630;
	dyd = rand() % 550;
	damage1 = 1;
	damage2 = 1;
	x2 = 100;
	y2 = 140;
	rx = rand() % 630;
	ry = rand() % 550;
	n1 = n2 = dir = dir2 = nr_proiectile = 0;
	speed = speed2 = 2;
	viata = viata2 = viata3 = 3;
	
	/*for(int i = 5; i <= 500; ++i)
		for (int j = 360; j <= 370; ++j)
			zid[i][j] = true;
	for (int i = 100; i <= 630; ++i)
		for (int j = 200; j <= 210; ++j)
			zid[i][j] = true;
	for (int i = 5; i <= 500; ++i)
		for (int j = 270; j <= 280; ++j)
			zid[i][j] = true;
	for (int i = 120; i <= 600; ++i)
		for (int j = 450; j <= 460; ++j)
			zid[i][j] = true;*/
}
void Game::Ok(int x, int y)
{
	int i;
	for (i = 0; i < 10; ++i)
		if (!eaten[i]) {
			if (x >= p[i][0] && x <= p[i][0] + 19 && y >= p[i][1] && y <= p[i][1] + 19)
				eaten[i] = true;
		}
}
void Game::Border()
{
	//bordura
	int dx = 650, dy = 590;
	for (int i = 5; i < dx; ++i)
		gfx.PutPixel(i, 5, 255, 255, 0), gfx.PutPixel(i, dy, 255, 255, 0);

	for (int i = 5; i < dy; ++i)
		gfx.PutPixel(dx, i, 255, 255, 0), gfx.PutPixel(5, i, 255, 255, 0);
}
void Game::Drawimages()
{
	int i;
	DrawMesajviata(655, 250);
	int dx = 700, dy = 500;
	for (i = 1; i <= viata; ++i)
		Realtank(dx, dy, 0, 61, 142, 25), dx += 33;
	dx = 700, dy = 300;

	for (i = 1; i <= viata2; ++i)
		Realtank2(dx, dy,0,255,255,0), dx += 33;
	bool f = true;
	for (int i = 0; i < 10 && f; ++i)
		if (!eaten[i]) f = false;

	//if (f)Gameover(680, 500); 

	DrawRune(rx, ry); // desenam runa de coordonate rx,ry
	DrawRunaDamage(dxd, dyd);// desenam runa de damage cu coordonatele dxd si dyd
	if (!ok) Initializari();//initializari trb sa se execute doar o data 
}
void Game::RunaDamage(int i,int j,int q)
{
	if (q == 1)
	{
		if (i >= dxd && i <= dxd + 23 && j >= dyd && j <= dyd + 23)
			++damage, dxd = rand() % 630, dyd = rand() % 550;
	} 
	else 
		if(q==2)
	{
		if (i >= dxd && i <= dxd + 23 && j >= dyd && j <= dyd + 23)
			++damage2, dxd = rand() % 630, dyd = rand() % 550;
	}
}
void Game::DrawMesajviata(int x, int y)
{
	int i, j, ii, jj;
	for (i = x, j = y; j <= y + 13; ++j, ++i)
		gfx.PutPixel(i, j, 193, 27, 23);

	for (ii = i + 1, jj = j - 1; jj >= y; --jj, ++ii)
		gfx.PutPixel(ii, jj, 193, 27, 23);
}
void Game::DrawViata(int x, int y, int r, int b, int g)
{
	gfx.PutPixel(x, y, r, b, g);
	gfx.PutPixel(x + 1, y, r, b, g);
	gfx.PutPixel(x, y + 1, r, b, g);
	gfx.PutPixel(x + 1, y + 1, r, b, g);
}
void Game::Runa_viata(int i,int j,int q)
{
	if (q == 1)
	{
		if (i >= rx && i <= rx + 23 && j >= ry && j <= ry + 23)
			++viata, rx = rand() % 630, ry = rand() % 550;
	} 
	else
	if(q==2){
		if (i >= rx && i <= rx + 23 && j >= ry && j <= ry + 23)
			++viata2, rx = rand() % 630, ry = rand() % 550;
	}
}

void Game::ComposeFrame()
{
	if (wnd.kbd.KeyIsPressed(VK_CONTROL)) {
		int cnt = 50;
		int dx = x, dy = y;
		if (!dir)dx += 13;
		else if (dir == 1)dx += 13, dy += 25;
		else if (dir == 2)dx += 25, dy += 13;
		else dy += 13;

		if (n1 < 1) { 
			++nr_proiectile;
			++n1;
			int j = nr_proiectile;
			proiectil[j][0] = dx;
			proiectil[j][1] = dy;
			proiectil[j][2] = dir;
			proiectil[j][3] = 1;
		}
	}
	unsigned char cod = 'F';
	if (wnd.kbd.KeyIsPressed(cod)) {
		int cnt = 50;
		int dx = x2, dy = y2; 
		if (!dir2)dx += 13;
		else if (dir2 == 1)dx += 13, dy += 25;
		else if (dir2 == 2)dx += 25, dy += 13;
		else dy += 13;

		if (n2 < 1) {
			++nr_proiectile;
			++n2;
			int j = nr_proiectile;
			proiectil[j][0] = dx;
			proiectil[j][1] = dy;
			proiectil[j][2] = dir2;
			proiectil[j][3] = 2;
		}
	}
	unsigned char c = 'R';
	if (wnd.kbd.KeyIsPressed(c)) Initializari();
}