#include"game.h"
void menu()
{
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("<<<<<<<<<<<<<<1.����  0.�˳�<<<<<<<<<<<<<<\n");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("<<<<<<<<<<*.�������  #.�������<<<<<<<<<<\n");
	printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
	printf("���������enter���������ʽΪ���� ����\n");
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
		printf("��ϲ�㣬����Ӯ��\n"); break;
	case'#':
		printf("**************************\n");
		printf("�㲻���а��������Զ��²�Ӯ\n");
		printf("**************************\n"); break;
	case'p':
		printf("**************************\n");
		printf("������Ҳ��ֻ��������¸�ƽ��\n"); 
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
			printf("������1����0��>");
			scanf_s("%d", &input);
			switch (input)
			{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��\n");
			}
		} while (input);
	}
	getchar();
	return 0;
}