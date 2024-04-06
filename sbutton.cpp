#include "sbutton.h"

AButton::AButton(int x, int y, int width, int height, COLORREF normal_color, string textString, string textStyle):
	x(x),y(y),Width(width),Height(height), Normal_color(normal_color),textString(textString),textStyle(textStyle)
{
	Hover_color = RGB(240, 240, 245);
	Click_color = RGB(215, 217, 231);
	state = NORMAL;
	setlinecolor(Line_color);
	scale = 1.0f;
}

void AButton::drawButton()
{
	int ScaleHeight = Height * scale;
	int ScaleWidth = Width * scale;
	int ScaleX = x + (Width - ScaleWidth) / 2;
	int ScaleY = y + (Height - ScaleHeight) / 2;
	int Font_Height = textheight(textString.c_str());
	int Font_Width = textwidth(textString.c_str());
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinecolor(Line_color);
	settextstyle(20,0, textStyle.c_str());
	StateColor(state);
	fillrectangle(ScaleX, ScaleY, ScaleX+ScaleWidth, ScaleY + ScaleHeight);
	outtextxy(ScaleX + (ScaleWidth - Font_Width) / 2, ScaleY + (ScaleHeight - Font_Height) / 2, textString.c_str());
}

bool AButton::isInButton(EASYXMSG m)
{
	int ScaleHeight = Height * scale;
	int ScaleWidth = Width * scale;
	int ScaleX = x + (Width - ScaleWidth) / 2;
	int ScaleY = y + (Height - ScaleHeight) / 2;
	if (m.x >= ScaleX && m.x<=ScaleX + ScaleWidth && m.y>ScaleY && m.y <= ScaleY + ScaleHeight)
	{
		scale = 0.9f;
		state = HOVER;
		return true;
	}
	scale = 1.0f;
	state = NORMAL;
	return false;
	
}


bool AButton::ClickButton(EASYXMSG m)
{
	if (isInButton(m))
	{
		scale = 0.9f;
		state = CLICK;
		return true;
	}

	scale = 1.0f;
	state = NORMAL;
	return false;
}

COLORREF& AButton::getcolor()
{
	return Normal_color;
}

string& AButton::getText()
{
	return textString;
}

void AButton::SetLineColor(COLORREF color)
{
	Line_color = color;
}

void AButton::StateColor(int state)
{
	switch (state)
	{
	case NORMAL:
		setfillcolor(Normal_color);
		break;
	case HOVER:
		setfillcolor(Hover_color);
		break;
	case CLICK:
		setfillcolor(Click_color);
		break;
	}
}

void Button::Draw()
{
	cleardevice();
	for (auto it = button.begin(); it != button.end(); it++)
	{

		(*it)->drawButton();
	}
}

void Button::AddButton(int x, int y, int width, int height, COLORREF color, string textString, string textStyle)
{
	AButton* button = new AButton(x, y, width, height, color, textString, textStyle);
	this->button.push_back(button);
	button->SetLineColor(line_color);
	button->drawButton();
}


void Button::MouseOperate()
{
	this->text = "";
	ExMessage msg;

	while (peekmessage(&msg, EX_MOUSE))
	{
		if (msg.message == WM_LBUTTONDOWN)
		{
			for (auto it = this->button.begin(); it != button.end(); it++)
			{
				if ((*it)->ClickButton(msg))
				{
					this->text = (*it)->getText();
					IsClick = true;
					/*cout << "click" << endl;*/
				}
				
			}
		}
		else if (msg.message = WM_MOUSEMOVE)
		{
			for (auto it = this->button.begin(); it != button.end(); it++)
			{
				if ((*it)->isInButton(msg))
				{

					/*cout << "move" << endl;*/
				}
			}
		}
		Draw();
	}
}

bool Button::getIsClick()
{
	return this->IsClick;
}

void Button::SetButtonLine(COLORREF color)
{
	line_color = color;
	for (auto it = button.begin(); it != button.end(); it++)
	{
		(*it)->SetLineColor(color);
	}
}
