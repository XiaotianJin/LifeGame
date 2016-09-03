#pragma once
#ifndef CMD_GUI_H
#define CMD_GUI_H

#include<Windows.h>
#include<stdio.h>

void setcolor(int num)
{
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	if (num == 0) //黑字
		SetConsoleTextAttribute(hConsoleOutput, 0x0070 | 0x0080);
	if (num == 2) //
		SetConsoleTextAttribute(hConsoleOutput, 42);
	if (num == 4) //
		SetConsoleTextAttribute(hConsoleOutput, 185);
	if (num == 8) //
		SetConsoleTextAttribute(hConsoleOutput, 235);
	if (num == 16) //
		SetConsoleTextAttribute(hConsoleOutput, 155);
	if (num == 32) //
		SetConsoleTextAttribute(hConsoleOutput, 215);
	if (num == 64) //
		SetConsoleTextAttribute(hConsoleOutput, 95);
	if (num == 128) //
		SetConsoleTextAttribute(hConsoleOutput, 225);
	if (num == 256) //
		SetConsoleTextAttribute(hConsoleOutput, 125);
	if (num == 512) //
		SetConsoleTextAttribute(hConsoleOutput, BACKGROUND_INTENSITY | BACKGROUND_RED);
	if (num == 1024) //
		SetConsoleTextAttribute(hConsoleOutput, BACKGROUND_INTENSITY | BACKGROUND_GREEN);
	if (num == 2048) //
		SetConsoleTextAttribute(hConsoleOutput, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN);
	if (num == 4096) //
		SetConsoleTextAttribute(hConsoleOutput, BACKGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN);

}
void printWithColor(int num)//用于输出带颜色的格子 
{
	if (num == 0)
	{
		setcolor(32);
	}
	else
	{
		setcolor(2);
	}

	printf("■");

	setcolor(0);
}

#endif // !CMD_GUI_H