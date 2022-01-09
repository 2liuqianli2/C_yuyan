#include"game.h"
void menu()
{
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("<<<<<<<<<<<<<<1.进入  0.退出<<<<<<<<<<<<<<\n");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("<<<<<<<<<<*.代表玩家  #.代表电脑<<<<<<<<<<\n");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("输入坐标后按enter键，坐标格式为数字 数字\n");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
}
void game()
{
	char board[ROW][COL] = { 0 };
	initboard(board, ROW, COL);
	displayboard(board, ROW, COL);
	char i = 'b';
	while (1)
	{
		playermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		i = Iswin(board, ROW, COL);
		if (i != 'u')break;
		computermove(board, ROW, COL);
		displayboard(board, ROW, COL);
		i=Iswin(board, ROW, COL);
		if (i != 'u')break;
	}
	i = Iswin(board, ROW, COL);
	switch (i)
	{
	case'*':
		printf("恭喜你，是你赢了\n"); break;
	case'#':
		printf("**************************\n");
		printf("你不得行啊，连电脑都下不赢\n");
		printf("**************************\n"); break;
	case'p':
		printf("**************************\n");
		printf("唉，你也就只能与电脑下个平局\n"); 
		printf("**************************\n"); break;
	}
}
int main()
{
	system("color 70");
	
	void text();
	{
		int input = 0;
		srand((unsigned int)time(NULL));
		do
		{
			menu();
			printf("请输入1或者0：>");
			scanf_s("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择\n");
			}
		} while (input);
	}
	getchar();
	return 0;
}