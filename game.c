#include"game.h"
void initboard(char board[COL][ROW], int col, int row)
{
	int i, k;
	for(i=0;i<col;i++)
		for (k = 0; k < row; k++)
		{
			board[i][k] = ' ';
		}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j <col; j++)
		{
			if (i == 0)printf("  %d ",j+1);
		}
		if (i == 0)printf("\n");
		for (j = 0; j < col; j++)
		{
			if (i == 0&&j==0)printf("  ___ ");
			if (i == 0 && j > 0)printf("___ ");
		}
		if (i == 0)printf("\n");
		for (j = 0; j < col; j++)
		{
			if (j == 0)printf("%d", i+1);
			if (j==0)printf("|");
			printf(" %c ", board[i][j]);
			printf("|");
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if (j==0)printf(" |");
			printf("___");
			printf("|");
		}
		printf("\n");
	}
}
void playermove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("����ߣ�>\n");
	while (1)
	{
		printf("���������꣺>");
		scanf_s("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*'; break;
			}
			else
				printf("�������ѱ�ռ�ã��������������꣺>");
		}
		else
			printf("����������������룺>");
	}

}
void computermove(char board[ROW][COL], int row, int col)
{
	
	printf("�����ߣ�>\n");
	
	while (1)
	{
		
		int i = 0, k, j,c=0;
		
		for( i=0,k=0;i<3;i++)//�жϵ��Ե���
		{ 
			for (j = 0; j < 2; j++)
			{
				if (board[i][j] == board[i][j + 1] && board[i][j] =='#' || board[i][0] == board[i][2] && board[i][0] =='#')
				{
					for (j = 0; j < 3; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = '#'; k++; break;
						}
					}
					if (k == 1)break;
				}
			}
			if (k == 1)break;
		}
		if (k == 1)break;
		for (j = 0, k = 0; j < 3; j++)//�жϵ��Ե���
		{
			for (i = 0; i < 2; i++)
			{
				if (board[i][j] == board[i+1][j ] && board[i][j] =='#' || board[0][j] == board[2][j] && board[0][j] =='#')
				{
					for (i = 0; i < 3; i++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = '#'; k++; break;
						}
					}

				}if (k == 1)break;
			}
			if (k == 1)break;
		}
		if (k == 1)break;
		if (board[0][0] == board[2][2] && board[2][2] != ' ' && board[1][1] == ' ')//�жϵ��Ե���б��
		{
			board[1][1] = '#'; break;
		}
		if (board[1][1] == board[2][2] && board[2][2] != ' ' && board[0][0] == ' ')
		{
			board[0][0] = '#'; break;
		}
		if (board[1][1] == board[0][0] && board[0][0] != ' ' && board[2][2] == ' ')
		{
			board[2][2] = '#'; break;
		}
		if (board[0][2] == board[1][1] && board[1][1] != ' ' && board[2][0] == ' ')//�жϵ��Ե���б��
		{
			board[2][0] = '#'; break;
		}
		if (board[2][0] == board[1][1] && board[1][1] != ' ' && board[0][2] == ' ')
		{
			board[0][2] = '#'; break;
		}
		if (board[0][2] == board[2][0] && board[0][2] != ' ' && board[1][1]==' ')
		{
			board[1][1] = '#'; break;
		}
		for (i = 0, k = 0; i < 3; i++)//�ж�ѡ�ֵ���
		{
			for (j = 0; j < 2; j++)
			{
				if (board[i][j] == board[i][j + 1] && board[i][j] != ' ' || board[i][0] == board[i][2] && board[i][0] != ' ')
				{
					for (j = 0; j < 3; j++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = '#'; k++; break;
						}
					}
					if (k == 1)break;
				}
			}if (k == 1)break;
		}
		if (k == 1)break;
		for (j = 0, k = 0; j < 3; j++)//�ж�ѡ�ֵ���
		{
			for (i = 0; i < 2; i++)
			{
				if (board[i][j] == board[i + 1][j] && board[i][j] != ' ' || board[0][j] == board[2][j] && board[0][j] != ' ')
				{
					for (i = 0; i < 3; i++)
					{
						if (board[i][j] == ' ')
						{
							board[i][j] = '#'; k++; break;
						}
					}
					if (k == 1)break;
				}
			}if (k == 1)break;
		}
		if (k == 1)break;
		if (board[0][0] == board[2][2] && board[2][2] != ' ' && board[1][1] == ' ')//�ж�ѡ�ֵ���б��
		{
			board[1][1] = '#'; break;
		}
		if (board[1][1] == board[2][2] && board[2][2] != ' ' && board[0][0] == ' ')
		{
			board[0][0] = '#'; break;
		}
		if (board[1][1] == board[0][0] && board[0][0] != ' ' && board[2][2] == ' ')
		{
			board[2][2] = '#'; break;
		}
		if (board[0][2] == board[1][1] && board[1][1] != ' ' && board[2][0] == ' ')//�ж�ѡ�ֵ���б��
		{
			board[2][0] = '#'; break;
		}
		if (board[2][0] == board[1][1] && board[1][1] != ' ' && board[0][2] == ' ')
		{
			board[0][2] = '#'; break;
		}
		if (board[0][2] == board[2][0] && board[0][2] != ' ' && board[1][1] == ' ')
		{
			board[1][1] = '#'; break;
		}
		if (1)
		{
			if (board[1][1] == ' ')
			{
				board[1][1] = '#'; c++; break;
			}
			else if (board[0][1] == ' ' && board[2][1] == ' ' && board[1][1] == '#')
			{
				board[2][1] = '#'; c++; break;			}
			else if (board[1][0] == ' ' && board[1][2] == ' ' && board[1][1] == '#')
			{
				board[1][0] = '#'; c++; break;
			}
			else if (board[0][0] == ' ' && board[2][2] == ' ' && board[1][1] == '*')
			{
				board[0][0] = '#'; c++; break;
			}
			else if (board[0][2] == ' ' && board[2][0] == ' ' && board[1][1] == '*')
			{
				board[2][0] = '#'; c++; break;
			}
		}
		
		int n = 0;
		for (i = 0; i < row; i++)//�����������������Ӷ�ѡһ
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')n++;
			}
		}
		k = 0;
		if (n == 2)
		{
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (board[i][j] == ' ') 
					{
						board[i][j] = '#'; k++; break;
					}
				}
				if (k == 1)break;
			}
		}
		if (k == 1)break;
	}
}
 int Isfull(char board[ROW][COL],int row,int col)
 {
	 int n = 0;
	 for (int i = 0; i < row; i++)
	 {
		 for (int j = 0; j < col; j++)
			 if (board[i][j]==' ') n++;
	 }
	 if (n ==1)return 1;
	 else
		 return 0;
}
char Iswin(char  board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
		if (board[i][0] == board[i][1]&&board[i][1] == board[i][2] &&board[i][0]!= ' ')
			return board[i][0];
	for (i = 0; i < row; i++)
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i]&& board[0][i] != ' ')
			return board[0][i];
	if (board[1][1] == board[2][2] && board[1][1] == board[0][0]&& board[2][2] != ' ')
		return board[1][1];
	if (board[1][1] == board[0][2] && board[1][1] == board[2][0]&&board[1][1] != ' ')
		return board[1][1];
	if (Isfull(board, row, col))
		return 'p';
	else return 'u';
}

