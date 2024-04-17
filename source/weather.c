#include"weather.h"

void weather_page(int *page_index)
{
	setbkcolor(WHITE);                                  //ҳ�汳�� 
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(100, 0, 539, 479);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(135, 65, 240, 115);

	settextstyle(DEFAULT_FONT, 0, 10);                   //������������չʾ��
	puthz(136, 66, "�人�к�ɽ��", 16, 18, WHITE);
	circle(240, 120, 5);
	outtextxy(158, 120, "8");
	outtextxy(245, 120, "C");
	puthz(136, 201, "��", 16, 18, WHITE);
	puthz(155, 201, "���", 16, 18, WHITE);
	puthz(210, 201, "���", 16, 18, WHITE);
	sunny(340, 120, 400, 180);

	setfillstyle(SOLID_FILL, DARKGRAY);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);            //�·���������չʾ���� 
	bar(100, 320, 539, 360);
	line(100, 360, 539, 360);
	bar(100, 360, 539, 400);
	line(100, 400, 539, 400);
	bar(100, 400, 539, 440);
	line(100, 440, 539, 440);
	bar(100, 440, 539, 479);

	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	settextstyle(DEFAULT_FONT, 0, 0);                     //�·���������չʾ���� 
	puthz(105, 321, "����", 16, 18, WHITE);
	puthz(145, 321, "��", 16, 18, WHITE);
	sunny(301, 331, 317, 347);
	circle(490, 330, 2);
	outtextxy(480, 330, "7");
	circle(535, 330, 2);
	outtextxy(518, 330, "16");
	puthz(105, 361, "����", 16, 18, WHITE);
	puthz(145, 361, "����", 16, 18, WHITE);
	cloudy(301, 371, 315, 385);
	circle(490, 370, 2);
	outtextxy(480, 370, "6");
	circle(535, 370, 2);
	outtextxy(518, 370, "15");
	puthz(105, 401, "����", 16, 18, WHITE);
	puthz(145, 401, "����", 16, 18, WHITE);
	cloudy(301, 411, 315, 425);
	circle(490, 410, 2);
	outtextxy(480, 410, "8");
	circle(535, 410, 2);
	outtextxy(518, 410, "16");
	setfillstyle(SOLID_FILL, BLUE);
	bar(495, 331, 505, 332);
	bar(495, 371, 505, 372);
	bar(495, 411, 505, 412);
	setfillstyle(SOLID_FILL, RED);
	bar(505, 331, 515, 332);
	bar(505, 371, 515, 372);
	bar(505, 411, 515, 412);
	puthz(300, 441, "�鿴��һ������", 16, 18, WHITE);

	//temcurve();
	
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(564, 445, 615, 460) == 1) 
		{
			*page_index = 0;
			return;
		}
		else if (mouse_press(300, 441, 500, 469) == 1) 
		{
			temcurve(page_index);
			return;
		}
	}
}
