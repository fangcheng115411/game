#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

using namespace std;

int main()
{
	system("title ·É»ú´óÕ½");
	srand((unsigned int)time(NULL));

	HideCursor();

	Game game;
	int a = drawMenu();
	if (a == 2)
	{
		game.rank = 10;
	}
	system("cls");
	drawPlaying();

	game.Playing();
}