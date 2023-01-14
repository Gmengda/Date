#pragma once


#define ROW 3
#define COL 3

void init_board(char board[ROW][COL], int row, int col);
void print_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL],int row,int col);
char situation(char board[ROW][COL], int row, int col);
