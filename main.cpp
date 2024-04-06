#define _CRT_SECURE_NO_WARNINGS
#include "sbutton.h"
#include "calculator.h"
#include <algorithm>
#include <numeric>

void addbutton(Button* button)
{
	button->AddButton(0, 380, 100, 100, WHITE, "+","Segoe UI Emoji");
	button->AddButton(100, 380, 100, 100, WHITE, "0", "Segoe UI Emoji");
	button->AddButton(200, 380, 100, 100, WHITE, ".", "Segoe UI Emoji");
	button->AddButton(300, 380, 100, 100, WHITE, "=", "Segoe UI Emoji");
	button->AddButton(0, 280, 100, 100, WHITE, "1", "Segoe UI Emoji");
	button->AddButton(100, 280, 100, 100, WHITE, "2", "Segoe UI Emoji");
	button->AddButton(200, 280, 100, 100, WHITE, "3", "Segoe UI Emoji");
	button->AddButton(300, 280, 100, 100, WHITE, "-", "Segoe UI Emoji");
	button->AddButton(0, 180, 100, 100, WHITE, "4", "Segoe UI Emoji");
	button->AddButton(100, 180, 100, 100, WHITE, "5", "Segoe UI Emoji");
	button->AddButton(200, 180, 100, 100, WHITE, "6", "Segoe UI Emoji");
	button->AddButton(300, 180, 100, 100, WHITE, "/", "Segoe UI Emoji");
	button->AddButton(0, 80, 100, 100, WHITE, "7", "Segoe UI Emoji");
	button->AddButton(100, 80, 100, 100, WHITE, "8", "Segoe UI Emoji");
	button->AddButton(200, 80, 100, 100, WHITE, "9", "Segoe UI Emoji");
	button->AddButton(300, 80, 100, 100, WHITE, "*", "Segoe UI Emoji");
	button->AddButton(400, 380, 100, 100, WHITE, "AC", "Segoe UI Emoji");
}

void initsetting()
{
	BeginBatchDraw();
	Button* Init = new Button;
	Init->SetButtonLine(WHITE);
	Init->AddButton(100, 300, 300, 50, WHITE, "开始");
	Init->AddButton(50, 10, 400, 200, WHITE, "计算器0.1","华文琥珀");
	
	while (!Init->getIsClick())
	{
		
		
		Init->MouseOperate();
		FlushBatchDraw();
		
	}
	EndBatchDraw();
	for (int i = 100; i < 236; i++)
	{
		setbkcolor(RGB(i, i, i));
		cleardevice();
		Sleep(1);
	}
	setbkcolor(WHITE);
	cleardevice();
}

int main()
{
	initgraph(500, 480);
	ShowCursor(true);
	

	HWND hwnd = GetHWnd();
	SetWindowText(hwnd, "calcultor");

	setbkcolor(WHITE);
	cleardevice();
	initsetting();
	Button* button = new Button;
	Calculator  calculate;
	addbutton(button);
	string formula;                   //公式
	bool IsSign = false;              //判断是否按下运算符号

	BeginBatchDraw();
	while (1)
	{
		line(textwidth(formula.c_str())+8, 12, textwidth(formula.c_str())+8, 28);
		button->MouseOperate();
		button->PrintText();
		if (!button->gettext().empty())
		{
			if (button->gettext() != "=")
				formula += button->gettext();
			else
			{
				formula = calculate.calculator(formula);

			}
			if (calculate.IsInputSign(button->gettext()) && IsSign)
			{
				formula[formula.length() - 2] = formula.back();
				formula.pop_back();
				
			}
			IsSign=calculate.IsInputSign(button->gettext());
		}
		if (button->gettext() == "AC") formula.clear();
		outtextxy(5, 10, formula.c_str());
		FlushBatchDraw();
	}

	EndBatchDraw();
}
