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
	COORD bullet[10];//�ӵ�����
	Frame enemy[8];//������Ŀ

	int score;
	int rank;//�����Ѷ�
	int rankf;//�ȼ���־
	string title;

	int flag_rank;//�ȼ���־

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

	void Playing();//��Ϸ��ѭ��
	void planeMove(char x);//�ɻ��ƶ�
	void judgePlane();//�жϷɻ��Ƿ���л��ص�
	void GameOver();//��Ϸʧ��
	void Pause();//��Ϸ��ͣ
	void Shoot();//�����ӵ�
	void bulletMove();//�ӵ��ƶ�
	void drawThisBulletToNull(COORD c);//����ʧЧ�ӵ�
	void judgeEnemy();//�ж��ӵ��Ƿ���ел���
	void drawThisEnemyToNull(Frame f);//���ܵĵл����
	void enemyMove();//�л��ƶ�
	void printScore();//�������
};
//���˵�
int drawMenu();
//���ع��
void HideCursor();

void SetPos(int i, int j);//���ù��
COORD random(COORD a, COORD b);//��������л�
void drawFrame(COORD a, COORD b, char row, char col);//�����л�
void drawRow(int y, int x1, int x2, char ch);
void drawCol(int x, int y1, int y2, char ch);
//������Ϸ����
void drawPlaying();
void drawFrame(Frame frame, char row, char col);//׹�ٵл�

bool judgeCoordInFrame(Frame frame, COORD spot);//�ж�ս����л��Ƿ��нӴ�

void drawRow(COORD a, COORD b, char ch);