#include "public.h"

int music_page()
{
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 639, 479);
	setfillstyle(SOLID_FILL, DARKGRAY); //背景板亮暗 
	bar(0, 0, 100, 479);
	bar(540, 0, 639, 479);
	setcolor(LIGHTGRAY);        //两侧区域划分直线 
	line(5, 96, 95, 96);
	line(5, 192, 95, 192);
	line(5, 288, 95, 288);
	line(5, 384, 95, 384);
	line(545, 420, 634, 420);
	outtextxy(33, 50, "MUSIC");
	outtextxy(38, 146, "GAME");
	outtextxy(33, 242, "MOVIE");
	outtextxy(22, 338, "WEATHER");
	outtextxy(22, 434, "CALENDAR");
	outtextxy(567, 450, "RETURN");

	setcolor(WHITE);
	setbkcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(100, 0, 539, 479);

	setfillstyle(SOLID_FILL, GREEN);
	bar(110, 90, 310, 220);
	puthz(190, 150, "本地音乐", 32, 28, WHITE);
	setfillstyle(SOLID_FILL, YELLOW);
	bar(330, 90, 530, 220);
	puthz(410, 150, "我的喜欢", 32, 28, WHITE);
	setfillstyle(SOLID_FILL, BLUE);
	bar(110, 250, 310, 380);
	puthz(190, 310, "最近播放", 32, 28, WHITE);
	setfillstyle(SOLID_FILL, RED);
	bar(330, 250, 530, 380);
	puthz(410, 310, "我的歌单", 32, 28, WHITE);

	clrmous(MouseX, MouseY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(110, 90, 310, 220) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(330, 90, 530, 220) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(110, 250, 310, 380) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(330, 250, 230, 380) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(110, 90, 310, 220) == 1)
		{
			return localmic();
		}
		else if (mouse_press(564, 445, 615, 460) == 1)
		{
			return 0;
		}
	}
	getch();
	//closegraph();
	return 0;	
}

int localmic(void)
{
	int i;
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(0, 0, 639, 479);
	setfillstyle(SOLID_FILL, DARKGRAY); //背景板亮暗 
	bar(0, 0, 100, 479);
	bar(540, 0, 639, 479);
	setcolor(LIGHTGRAY);        //两侧区域划分直线 
	line(5, 96, 95, 96);
	line(5, 192, 95, 192);
	line(5, 288, 95, 288);
	line(5, 384, 95, 384);
	line(545, 420, 634, 420);
	outtextxy(33, 50, "MUSIC");
	outtextxy(38, 146, "GAME");
	outtextxy(33, 242, "MOVIE");
	outtextxy(22, 338, "WEATHER");
	outtextxy(22, 434, "CALENDAR");
	outtextxy(567, 450, "RETURN");

	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	setbkcolor(DARKGRAY);
	for (i = 130; i <= 390;)
	{
		setfillstyle(SOLID_FILL, i / 100 + 3);
		bar(i, 30, i + 110, 70);
		i += 130;
	}
	puthz(150, 40, "我的喜欢", 16, 18, WHITE);
	puthz(280, 40, "最近播放", 16, 18, WHITE);
	puthz(410, 40, "我的歌单", 16, 18, WHITE);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	for (i = 90; i <= 400;)
	{
		bar(100, i, 539, i + 30);
		line(100, i, 539, i);
		sector(530, i + 10, 0, 360, 1, 1);
		sector(530, i + 15, 0, 360, 1, 1);
		sector(530, i + 20, 0, 360, 1, 1);
		i += 30;
	}
	puthz(120, 100, "心如烟火", 16, 18, WHITE);
	puthz(120, 130, "再次与你同行", 16, 18, WHITE);
	puthz(120, 160, "浮光", 16, 18, WHITE);
	puthz(120, 190, "安河桥", 16, 18, WHITE);
	puthz(120, 220, "雷雨季节", 16, 18, WHITE);
	puthz(120, 250, "离别开出花", 16, 18, WHITE);
	puthz(120, 280, "走马", 16, 18, WHITE);
	puthz(120, 310, "晚风", 16, 18, WHITE);
	puthz(120, 340, "淋雨一直走", 16, 18, WHITE);
	puthz(120, 370, "夜、萤火虫和你", 16, 18, WHITE);
	puthz(120, 400, "画", 16, 18, WHITE);


	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(100, 401, 539, 479);
	setcolor(YELLOW);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	circle(150, 440, 20);
	circle(150, 440, 10);
	line(150, 430, 150, 415);
	circle(150, 440, 5);
	rectangle(120, 410, 180, 470);


	/*	circle(510,440,20);
		moveto(500,428);
		lineto(500,453);
		lineto(520,440);
		lineto(500,428);
		pro_bar(240,440,250,LIGHTGRAY);

		/*pro_bar(240,440,250,LIGHTGRAY);
		circle(510,440,20);
		line(505,435,500,455);
		line(515,435,515,455);*/

	puthz(220, 420, "心如烟火", 16, 18, WHITE);

	clrmous(MouseX, MouseY);
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(520, 98, 539, 112) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(520, 98, 539, 112) == 1)
		{
			//menu();
		}
		else if (mouse_press(564, 445, 615, 460) == 1)
		{
			return 0;
		}
		else 
		{
			MouseS = 0;
		}
	}
}

//void menu(void)
//{
//	setfillstyle(SOLID_FILL, LIGHTGRAY);
//	setcolor(WHITE);
//	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
//
//	bar(500, 90, 539, 120);
//
//}
