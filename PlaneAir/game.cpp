#include "game.h"
#include<Windows.h>
#include<conio.h>

Game::Game()
{
	initPlane();

	initBullet();

	initEnemy();

	this->score = 0;
	rank = 25;
	rankf = 25;
	flag_rank = 0;
}
void Game::initPlane()
{
	COORD centren;
	centren.X = 39;
	centren.Y = 22;

	position[0].X = position[5].X = position[7].X = position[9].X = centren.X;
	position[1].X = centren.X - 2;
	position[2].X = position[6].X = centren.X - 1;
	position[3].X = position[8].X = centren.X + 1;
	position[4].X = centren.X + 2;
	for (int i = 0; i <= 4; i++)
	{
		position[i].Y = centren.Y;
	}
	for (int i = 6; i <= 8; i++)
	{
		position[i].Y = centren.Y + 1;
	}
	position[5].Y = centren.Y - 1;
	position[9].Y = centren.Y - 2;
}

void Game::drawPlane()
{
	for (int i = 0; i < 9; i++)
	{
		SetPos(position[i].X, position[i].Y);
		if (i != 5)
		{
			cout << "*";
		}
		else if (i == 5)
		{
			cout << "|";
		}
	}
}

void Game::drawPlaneToNull()
{
	for (int i = 0; i < 9; i++)
	{
		SetPos(position[i].X, position[i].Y);
		cout << " ";
	}
}

void Game::initBullet()
{
	for (int i = 0; i < 10; i++)
	{
		bullet[i].Y = 30;
	}
}

void Game::drawBullet()
{
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i].Y != 30)
		{
			SetPos(bullet[i].X, bullet[i].Y);
			cout << "^";
		}
	}
}
void Game::drawBulletToNull()
{
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i].Y != 30)
		{
			SetPos(bullet[i].X, bullet[i].Y + 1);
			cout << " ";
		}
	}
}

COORD random(COORD a, COORD b)
{ 
	int x = rand() % (a.X - b.X) + a.X;
	int y = rand() % (a.Y - b.Y) + a.Y;
	COORD c = { x,y };
	return c;
}

void Game::initEnemy()
{
	COORD a = { 1,1 };
	COORD b = { 45,15 };
	for (int i = 0; i < 8; i++)
	{
		enemy[i].position[0] = random(a, b);

		enemy[i].position[1].X = enemy[i].position[0].X + 3;
		enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
	}
}

void Game::drawEnemy()
{
	for (int i = 0; i < 8; i++)
	{
		drawFrame(enemy[i].position[0], enemy[i].position[1], '-', '|');
	}
}

void Game::drawEnemyToNull()
{
	for (int i = 0; i < 8; i++)
	{
		drawFrame(enemy[i].position[0], enemy[i].position[1], ' ', ' ');
	}
}

void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };//第二个值0表示隐藏光标
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void SetPos(int i, int j)
{
	HANDLE hout;
	COORD coord;
	coord.X = i;
	coord.Y = j;
	hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, coord);
}
void drawFrame(COORD a, COORD b, char row, char col)
{
	drawRow(a.Y, a.X + 1, b.X - 1, row);
	drawRow(b.Y, a.X + 1, b.X - 1, row);
	drawCol(a.X, a.Y + 1, b.Y - 1, col);
	drawCol(b.X, a.Y + 1, b.Y - 1, col);
}

void drawRow(int y, int x1, int x2, char ch)
{
	SetPos(x1, y);
	for (int i = 0; i <= (x2 - x1); i++)
	{
		cout << ch;
	}
}

void drawCol(int x, int y1, int y2, char ch)
{
	int y = y1;
	while (y != y2 + 1)
	{
		SetPos(x, y);
		cout << ch;
		y++;
	}
}

int drawMenu()
{
	SetPos(30, 1);
	cout << "飞 机 大 战";
	drawRow(3, 0, 79, '-');
	drawRow(5, 0, 79, '-');
	SetPos(28, 4);
	cout << "w 和 s 选择，k确定";
	int j = 11;
	SetPos(12, j);
	cout << ">>";
	SetPos(15, 11);
	cout << "1. 简单的敌人";
	SetPos(15, 13);
	cout << "2. 冷酷的敌人";
	drawRow(20, 0, 79, '-');
	SetPos(47, 11);
	cout << "简单的敌人：";
	SetPos(47, 13);
	cout << "简单敌人有着较慢的移动速度";
	drawRow(22, 0, 79, '-');

	while (true)
	{
		if (_kbhit())
		{
			char x = _getch();
			switch (x)
			{
			case'w':
			{
				if (j == 13)
				{
					SetPos(12, j);
					cout << " ";
					j = 11;
					SetPos(12, j);
					cout << ">>";
					SetPos(51, 13);
					cout << "                        ";
					SetPos(47, 11);
					cout << "简单的敌人：";
					SetPos(51, 13);
					cout << "简单敌人有着较慢的移动速度，比较容易对付";
				}
				break;
			}
			case's':
			{
				if (j == 11)
				{
					SetPos(12, j);
					cout << " ";
					j = 13;
					SetPos(12, j);
					cout << ">>";
					SetPos(51, 13);
					cout << "                        ";
					SetPos(47, 11);
					cout << "冷酷的敌人：";
					SetPos(51, 13);
					cout << "冷酷敌人有着较快的移动速度，比较难对付";
				}
				break;
			}
			case 'k':
			{
				if (j == 11)
					return 1;
				else
					return 2;
			}
			}
		}
	}
	return 0;
}

void drawFrame(int x1, int y1, int x2, int y2, char row, char col)
{
	COORD a = { x1,y1 };
	COORD b = { x2,y2 };
	drawFrame(a, b, row, col);
}

void drawPlaying()
{
	drawFrame(0, 0, 48, 24, '=', '|');
	drawFrame(49, 0, 79, 4, '-', '|');
	drawFrame(49, 4, 79, 9, '-', '|');
	drawFrame(49, 9, 79, 20, '-', '|');
	drawFrame(49, 20, 79, 24, '-','|');
	SetPos(52, 6);
	cout << "得分：";
	SetPos(52, 7);
	cout << "称号：";
	SetPos(52, 11);
	cout << "操作方式：";
	SetPos(52, 13);
	cout << "a,s,d,w：控制战机移动。";
	SetPos(52, 15);
	cout << "k：发射子弹。";
	SetPos(52,17);
	cout << "p：暂停游戏。";
	SetPos(52, 19);
	cout << "e：退出游戏。";
	SetPos(52, 22);
	cout << "请勿沉迷";
}

void Game::planeMove(char x)
{
	if (x == 'a')
	{
		if (position[1].X != 1)

		{
			for (int i = 0; i <= 9; i++)
			{
				position[i].X -= 2;
			}
		}
	}
	if (x == 's')
	{
		if (position[7].Y != 23)
		{
			for (int i = 0; i <= 9; i++)
			{
				position[i].Y += 1;
			}
		}
	}
	if (x == 'd' && (position[4].X != 47))
	{
		for (int i = 0; i <= 9; i++)
		{
			position[i].X += 2;
		}
	}
	if (x == 'w' && (position[5].Y != 3))
	{
		for (int i = 0; i <= 9; i++)
		{
			position[i].Y -= 1;
		}
	}
}

bool judgeCoordInFrame(Frame frame, COORD spot)
{
	if ((spot.X >= frame.position[0].X) && (spot.X <= frame.position[1].X) && (spot.Y >= frame.position[0].Y) && (spot.Y <= frame.position[1].Y))
	{
		return true;
	}
	return false;
}

void drawFrame(Frame frame, char row, char col)
{
	COORD a = frame.position[0];
	COORD b = frame.position[1];
	drawFrame(a, b, row, col);
}

void Game::GameOver()
{
	system("cls");
	COORD p1 = { 28,9 };
	COORD p2 = { 53,15 };
	drawFrame(p1, p2, '=', '|');
	SetPos(36, 12);
	string str = "Game Over!";
	for (int i = 0; i < str.size(); i++)
	{
		Sleep(80);
		cout << str[i];
	}
	Sleep(1000);
	system("cls");
	drawFrame(p1, p2, '=', '|');
	SetPos(31, 11);
	cout << "击落敌机：" << score / 5 << "架";
	SetPos(31, 12);
	cout << "得    分：" << score;
	SetPos(31, 13);
	cout << "获得称号：" << title;
	SetPos(30, 18);
	Sleep(1000);
	cout << "继续？是(y)|否(n)";
as://goto 语句标签 直接跳转至此
	char x = _getch();
	if (x == 'n')
	{
		exit(0);
	}
	else if (x == 'y')
	{
		system("cls");
		Game game;
		int a = drawMenu();
		if (a == 2)
			game.rank = 10;
		system("cls");
		drawPlaying();
		game.Playing();
	}
	else
		goto as;
}

void Game::judgePlane()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (judgeCoordInFrame(enemy[i], position[j]))
			{
				SetPos(62, 1);
				cout << "坠毁";
				drawFrame(enemy[i], '+', '+');
				Sleep(1000);
				GameOver();
				break;
			}
		}
	   	
	}
}

void Game::Pause()
{
	SetPos(61, 2);
	cout << "        ";
	SetPos(61, 2);
	cout << "暂停……";

	char c = _getch();
	while (c != 'p')
	{
		c = _getch();
	}
	SetPos(61, 2);
	cout << "        ";
}

void Game::Shoot()
{
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i].Y == 30)
		{
			bullet[i].X = position[5].X;
			bullet[i].Y = position[5].Y - 1;
			break;
		}
	}
}

void Game::drawThisBulletToNull(COORD c)
{
	SetPos(c.X, c.Y);
	cout << " ";
}

void Game::bulletMove()
{
	for (int i = 0; i < 10; i++)
	{
		if (bullet[i].Y != 30)
		{
			bullet[i].Y -= 1;
			if (bullet[i].Y == 1)
			{
				COORD pos = { bullet[i].X,bullet[i].Y + 1 };
				drawThisBulletToNull(pos);
				bullet[i].Y = 30;
			}

		}
	}
}

void Game::drawThisEnemyToNull(Frame f)
{
	drawFrame(f, ' ', ' ');
}

void Game::judgeEnemy()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (judgeCoordInFrame(enemy[i], bullet[j]))
			{
				score += 5;
				drawThisEnemyToNull(enemy[i]);
				COORD a = { 1,1 };
				COORD b = { 45,3 };
				enemy[i].position[0] = random(a, b);
				enemy[i].position[1].X = enemy[i].position[0].X + 3;
				enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
				drawThisBulletToNull(bullet[j]);
				bullet[j].Y = 30;
			}
		}
	}
}

void Game::enemyMove()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			enemy[i].position[j].Y++;
		}
		if (enemy[i].position[1].Y == 24)
		{
			COORD a = { 1,1 };
			COORD b = { 45,3 };
			enemy[i].position[0] = random(a, b);
			enemy[i].position[1].X = enemy[i].position[0].X + 3;
			enemy[i].position[1].Y = enemy[i].position[0].Y + 2;
		}
	}
}

void Game::printScore()
{
	flag_rank = score / 120+1;
	SetPos(60, 6);
	cout << score;
	SetPos(60, 7);
	switch (flag_rank)
	{
	case 1:
	{
		title = "初级飞行员";
		break;
	}
	case 2:
	{
		title = "中级飞行员";
		break;
	}
	case 3:
	{
		title = "高级飞行员";
		break;
	}
	default:
	{
		title = "王牌飞行员";
		break;
	}
	}
	cout << title;
}

void Game::Playing()
{
	drawEnemy();
	drawPlane();

	int flag_bullet = 0;
	int flag_enemy = 0;

	while (true)
	{
		Sleep(20);

		if (_kbhit())
		{
			char x = _getch();
			if ('a' == x || 's' == x || 'd' == x || 'w' == x)
			{
				drawPlaneToNull();
				planeMove(x);
				drawPlane();

				judgePlane();
			}
			else if ('p' == x)
			{
				Pause();
			}
			else if ('k' == x)
			{
				Shoot();
			}
			else if ('e' == x)
			{
				GameOver();
				break;
			}
		}
		if (flag_bullet == 0)
		{
			bulletMove();
			drawBulletToNull();
			drawBullet();
			judgeEnemy();
		}
		flag_bullet++;
		if (flag_bullet == 1)
		{
			flag_bullet = 0;
		}

		if (flag_enemy == 0)
		{
			drawEnemyToNull();
			enemyMove();
			drawEnemy();
			judgePlane();
		}
		flag_enemy++;
		if (flag_enemy >= rank)
		{
			flag_enemy = 0;
		}
		printScore();
	}
}