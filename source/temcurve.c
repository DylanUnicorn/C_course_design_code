///////////////////////////////////////////
///temcurve.c
///FUNCTION: 天气近期气温曲线 
///////////////////////////////////////////
#include"public.h"
#include"temcurve.h"

void temcurve(int* page_index)
{
	int daytemmax[16] = {110,370,170,370+1/UNITPIXEL_TEM,230,370,290,370-3/UNITPIXEL_TEM,            //气温曲线折点数值坐标
							350,370-4/UNITPIXEL_TEM,410,370-2/UNITPIXEL_TEM,470,370-1/UNITPIXEL_TEM,530,370};
	int daytemmin[16] = {110,370+9/UNITPIXEL_TEM,170,370+10/UNITPIXEL_TEM,230,370+2/UNITPIXEL_TEM,
							290,370+10/UNITPIXEL_TEM,350,370+5/UNITPIXEL_TEM,410,370+6/UNITPIXEL_TEM,470,
							370+4/UNITPIXEL_TEM,530,370+4/UNITPIXEL_TEM};

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

	setbkcolor(WHITE);                                  //页面背景 
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(100, 0, 539, 479);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(135, 65, 240, 115);

	settextstyle(DEFAULT_FONT, 0, 10);                   //当天气温天气展示方
	puthz(136, 66, "武汉市洪山区", 16, 18, WHITE);
	circle(240, 120, 5);
	outtextxy(158, 120, "8");
	outtextxy(245, 120, "C");
	puthz(136, 201, "晴", 16, 18, WHITE);
	puthz(155, 201, "最高", 16, 18, WHITE);
	puthz(210, 201, "最低", 16, 18, WHITE);
	sunny(340, 120, 400, 180);

	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(100, 320, 539, 479);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	settextstyle(DEFAULT_FONT, 0, 0);

	outtextxy(108, 360, "16");                                          //气温图标与气温数值 
	circle(126, 360, 2);
	sunny(108, 335, 124, 351);
	outtextxy(108, 380 + 9 / UNITPIXEL_TEM, "7");
	circle(120, 380 + 9 / UNITPIXEL_TEM, 2);
	sunny(108, 390 + 9 / UNITPIXEL_TEM, 124, 406 + 9 / UNITPIXEL_TEM);

	outtextxy(168, 357 + 1 / UNITPIXEL_TEM, "15");
	circle(186, 357 + 1 / UNITPIXEL_TEM, 2);
	cloudy(168, 332 + 1 / UNITPIXEL_TEM, 185, 348 + 1 / UNITPIXEL_TEM);
	outtextxy(168, 380 + 10 / UNITPIXEL_TEM, "6");
	circle(180, 380 + 10 / UNITPIXEL_TEM, 2);
	cloudy(168, 400 + 10 / UNITPIXEL_TEM, 184, 416 + 10 / UNITPIXEL_TEM);

	outtextxy(228, 357, "16");
	circle(246, 357, 2);
	cloudy(228, 332, 244, 348);
	outtextxy(228, 380 + 2 / UNITPIXEL_TEM, "7");
	circle(246, 380 + 2 / UNITPIXEL_TEM, 2);
	cloudy(228, 400 + 2 / UNITPIXEL_TEM, 244, 416 + 2 / UNITPIXEL_TEM);

	outtextxy(288, 357 - 3 / UNITPIXEL_TEM, "20");
	circle(306, 357 - 3 / UNITPIXEL_TEM, 2);
	sunny(288, 334 - 3 / UNITPIXEL_TEM, 304, 350 - 3 / UNITPIXEL_TEM);
	outtextxy(288, 380 + 10 / UNITPIXEL_TEM, "8");
	circle(306, 380 + 10 / UNITPIXEL_TEM, 2);
	sunny(288, 390 + 10 / UNITPIXEL_TEM, 304, 406 + 10 / UNITPIXEL_TEM);

	outtextxy(348, 357 - 4 / UNITPIXEL_TEM, "20");
	circle(366, 357 - 4 / UNITPIXEL_TEM, 2);
	sunny(348, 339 - 4 / UNITPIXEL_TEM, 364, 355 - 4 / UNITPIXEL_TEM);
	outtextxy(348, 380 + 5 / UNITPIXEL_TEM, "12");
	circle(366, 380 + 5 / UNITPIXEL_TEM, 2);
	sunny(348, 390 + 5 / UNITPIXEL_TEM, 364, 406 + 5 / UNITPIXEL_TEM);

	outtextxy(408, 357 - 2 / UNITPIXEL_TEM, "19");
	circle(426, 357 - 2 / UNITPIXEL_TEM, 2);
	sunny(408, 332 - 2 / UNITPIXEL_TEM, 424, 348 - 2 / UNITPIXEL_TEM);
	outtextxy(408, 380 + 6 / UNITPIXEL_TEM, "10");
	circle(426, 380 + 6 / UNITPIXEL_TEM, 2);
	sunny(408, 390 + 6 / UNITPIXEL_TEM, 424, 406 + 6 / UNITPIXEL_TEM);

	outtextxy(468, 357 - 1 / UNITPIXEL_TEM, "17");
	circle(486, 357 - 1 / UNITPIXEL_TEM, 2);
	cloudy(468, 332 - 1 / UNITPIXEL_TEM, 484, 348 - 1 / UNITPIXEL_TEM);
	outtextxy(468, 380 + 4 / UNITPIXEL_TEM, "11");
	circle(486, 380 + 4 / UNITPIXEL_TEM, 2);
	cloudy(468, 400 + 4 / UNITPIXEL_TEM, 484, 416 + 4 / UNITPIXEL_TEM);

	outtextxy(518, 357, "16");
	circle(536, 357, 2);
	rainy(516, 330, 532, 346);
	outtextxy(518, 380 + 4 / UNITPIXEL_TEM, "12");
	circle(536, 380 + 4 / UNITPIXEL_TEM, 2);
	rainy(516, 400 + 4 / UNITPIXEL_TEM, 532, 416 + 4 / UNITPIXEL_TEM);

	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);                         //气温曲线绘画 
	drawpoly(8, daytemmax);
	drawpoly(8, daytemmin);

	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(564,445,615,460)==2)
		{
			MouseS = 1; 
		}
		else if(mouse_press(564,445,615,460)==1)
		{
			*page_index = 4;
			return;
		}
	}
}
