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
	AButton(int x, int y, int width, int height, COLORREF normal_color=RGB(218, 220, 235), string textString=" ", string textStyle="����");

	void drawButton();            //���ư�ť
	bool isInButton(EASYXMSG m);  //�Ƿ��ڰ�ť��
	bool ClickButton(EASYXMSG m); //�Ƿ�����ť
	COLORREF& getcolor();         //���ص����ť��ǰ��ɫ
	string& getText();            //���ص����ť������
	void SetLineColor(COLORREF color);  //����������ɫ
	double scale;                 //����

	void StateColor(int state);   //������ɫ
	

	void SetHoverColor(COLORREF color)  //����Hover��ɫ
	{
		Hover_color = color;
	}

	void SetClickColor(COLORREF color)//���õ����ɫ
	{
		Click_color = color;
	}
};

class Button
{
private:
	vector<AButton*>button;     //��ŵ����ť��ɫ
	string text;                //�ı�
	bool IsClick;               //�Ƿ�����ť
	void Draw();                //
	COLORREF line_color;
	
public:
	Button() :IsClick(false) {};
	~Button() { button.clear(); }
	void AddButton(int x, int y, int width, int height, COLORREF color = RGB(218, 220, 235),
		string textString = " ", string textStyle = "����");

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