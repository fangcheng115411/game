#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

typedef struct Frame
{
	COORD position[2];

	int flag;


}Frame;

class Game
{
public:
	COORD position[10];
	COORD bullet[10];//子弹坐标
	Frame enemy[8];//敌人数目

	int score;
	int rank;//级别，难度
	int rankf;//等级标志
	string title;

	int flag_rank;//等级标志

	Game();

	void initPlane();
	void initBullet();
	void initEnemy();

	void drawPlane();
	void drawPlaneToNull();
	void drawBullet();
	void drawBulletToNull();
	void drawEnemy();
	void drawEnemyToNull();

	void Playing();//游戏主循环
	void planeMove(char x);//飞机移动
	void judgePlane();//判断飞机是否与敌机重叠
	void GameOver();//游戏失败
	void Pause();//游戏暂停
	void Shoot();//发射子弹
	void bulletMove();//子弹移动
	void drawThisBulletToNull(COORD c);//画出失效子弹
	void judgeEnemy();//判断子弹是否击中敌机；
	void drawThisEnemyToNull(Frame f);//击败的敌机清空
	void enemyMove();//敌机移动
	void printScore();//输出分数
};
//主菜单
int drawMenu();
//隐藏光标
void HideCursor();

void SetPos(int i, int j);//设置光标
COORD random(COORD a, COORD b);//产生随机敌机
void drawFrame(COORD a, COORD b, char row, char col);//画出敌机
void drawRow(int y, int x1, int x2, char ch);
void drawCol(int x, int y1, int y2, char ch);
//绘制游戏界面
void drawPlaying();
void drawFrame(Frame frame, char row, char col);//坠毁敌机

bool judgeCoordInFrame(Frame frame, COORD spot);//判断战机与敌机是否有接触

void drawRow(COORD a, COORD b, char ch);