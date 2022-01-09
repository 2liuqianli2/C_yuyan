#define COL 3
#define ROW 3
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col);
void computermove(char board[ROW][COL], int row, int col);
int Isfull(char board[ROW][COL], int row, int col);
char Iswin(char  board[ROW][COL], int row, int col);
/*x = rand() % row;
y = rand() % col;
if (board[x][y] == ' ')
{
	board[x][y] = '#'; break;
}*/