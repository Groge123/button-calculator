#pragma once
#include <graphics.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AButton
{
private:
	int x;
	int y;
	int Width;
	int Height;
	int state;
	COLORREF Normal_color;
	COLORREF Hover_color;
	COLORREF Click_color;
	COLORREF Line_color;
	string textString;
	string textStyle;
	enum{NORMAL,HOVER,CLICK};

public:
	AButton(int x, int y, int width, int height, COLORREF normal_color=RGB(218, 220, 235), string textString=" ", string textStyle="楷体");

	void drawButton();            //绘制按钮
	bool isInButton(EASYXMSG m);  //是否在按钮上
	bool ClickButton(EASYXMSG m); //是否点击按钮
	COLORREF& getcolor();         //返回点击按钮当前颜色
	string& getText();            //返回点击按钮的文字
	void SetLineColor(COLORREF color);  //更改线条颜色
	double scale;                 //缩放

	void StateColor(int state);   //更改颜色
	

	void SetHoverColor(COLORREF color)  //设置Hover颜色
	{
		Hover_color = color;
	}

	void SetClickColor(COLORREF color)//设置点击颜色
	{
		Click_color = color;
	}
};

class Button
{
private:
	vector<AButton*>button;     //存放点击按钮颜色
	string text;                //文本
	bool IsClick;               //是否点击按钮
	void Draw();                //
	COLORREF line_color;
	
public:
	Button() :IsClick(false) {};
	~Button() { button.clear(); }
	void AddButton(int x, int y, int width, int height, COLORREF color = RGB(218, 220, 235),
		string textString = " ", string textStyle = "宋体");

	void MouseOperate();

	bool getIsClick();
	string gettext()
	{
		return text.empty() ? "" : text;
	}

	void PrintText()
	{
		if (!text.empty()) cout << text << " ";
	}
	
	void SetButtonLine(COLORREF color);
	
};