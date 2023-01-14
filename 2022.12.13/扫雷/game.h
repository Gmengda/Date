#pragma once
#define ROW 10
#define COL 10
#define BOM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_f_board(char board[ROW][COL], int row, int col);

void print_f_board(char f_board[ROW][COL], int row, int col);

void pull_bom(int board[ROW][COL], int row, int col, int bom);

int clear_bom(int board[ROW][COL], char f_board[ROW][COL], int row, int col);

int fail(int board[ROW][COL], char f_board[ROW][COL], int row, int col);
