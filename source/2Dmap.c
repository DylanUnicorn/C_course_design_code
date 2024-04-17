///////////////////////////////////////////
///2Dmap.c
///FUNCTION: 2D地图的打印 
///////////////////////////////////////////
#include "2Dmap.h"
#include "Navigation.h"

void twoDmap(int* page_index)
{
	unsigned P[15][15];
	unsigned D[15][15];
	int now = 0;
	int destination = 0;
	int distance = 0;
	int flag = 0;
	int start = 0;

	int i;
	int river1[16] = { 100,0,0,145,0,180,200,0,180,0,90,45,140,0,100,0 };    //湖泊江河坐标 
	int river2[10] = { 340,0,370,0,639,80,639,110,340,0 };
	int lake1[16] = { 165,315,135,335,160,370,225,325,265,355,280,340,225,305,165,315 };
	int lake2[12] = { 110,150,130,160,115,190,90,185,90,165,110,150 };
	int lake3[30] = { 200,200,215,210,245,195,245,230,260,220,270,225,250,190,295,210,315,185,320,140,295,105,270,105,240,110,215,135,200,200 };

	int green1[10] = { 160,210,140,215,150,245,190,215,160,210 };   //绿地坐标 
	int green2[14] = { 210,180,190,130,235,90,250,95,255,115,230,135,210,180 };
	int green3[10] = { 240,140,250,150,265,145,255,135,240,140 };
	int green4[14] = { 265,155,265,180,255,220,285,215,280,185,280,155,265,155 };
	int green5[12] = { 310,160,305,185,330,190,320,165,305,155,310,160 };
	int green6[10] = { 330,120,320,130,285,115,290,95,330,120 };

	int location[15][2] = {                       //地标坐标 
							{10,105},
							{35,70},
							{35,170},
							{110,165},
							{183,140},
							{190,245},
							{190,365},
							{245,105},
							{225,215},
							{255,145},
							{280,225},
							{280,325},
							{370,280},
							{450,370},
							{485,235},
	};
	char name[15][16] = {
						{"汉江江滩公园"},//0
						{"汉口江滩"},//1
						{"黄鹤楼"},//2
						{"沙湖公园"},//3
						{"牡丹园"},//4
						{"华中师范大学"},//5
						{"华中农业大学"},//6
						{"武汉欢乐谷"},//7
						{"武汉大学"},//8
						{"湖心岛"},//9
						{"华中科技大学"},//10
						{"中南民族大学"},//11
						{"文华学院"},//12
						{"九峰国家森林公园"},//13
						{"旧屋周"},//14
	};
	int load1[28] = { 0,31,0,36,197,130,253,147,261,148,295,229,296,299,295,410,301,410,301,228,265,146,251,143,198,126,0,31 };
	int load2[10] = { 0,76,0,80,179,152,181,147,0,76 };
	int load3[22] = { 0,118,89,181,213,230,307,242,501,214,501,218,306,246,213,234,87,186,0,124,0,118 };
	int load4[30] = { 135,128,185,79,260,70,199,0,205,0,266,70,269,71,334,215,508,410,504,410,330,220,267,75,187,83,139,130,135,128 };
	int load5[22] = { 195,128,163,209,157,212,100,350,134,410,138,410,105,349,161,214,166,211,199,130,195,128 };
	int load6[10] = { 500,0,505,0,505,410,500,410,500,0 };

	setbkcolor(LIGHTGRAY);
	setcolor(LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);

	setfillstyle(SOLID_FILL, LIGHTBLUE);   //湖泊，长江 
	setcolor(LIGHTBLUE);
	fillpoly(8, river1);
	fillpoly(5, river2);
	fillpoly(8, lake1);
	fillpoly(6, lake2);
	fillpoly(15, lake3);

	setfillstyle(SOLID_FILL, GREEN);   //绿地 
	setcolor(GREEN);
	fillpoly(5, green1);
	fillpoly(7, green2);
	fillpoly(5, green3);
	fillpoly(7, green4);
	fillpoly(6, green5);
	fillpoly(5, green6);

	setcolor(LIGHTGREEN);         //道路 
	setfillstyle(SOLID_FILL, WHITE);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	fillpoly(14, load1);
	fillpoly(5, load2);
	fillpoly(11, load3);
	fillpoly(15, load4);
	fillpoly(11, load5);
	fillpoly(5, load6);

	setcolor(RED);             //地标 
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	for (i = 0; i < 15; i++)
	{
		circle(location[i][0], location[i][1], 5);
		if (i != 8)
			puthz(location[i][0], location[i][1] + 6, name[i], 16, 16, RED);   //避免武汉大学字体与华中科技大学字体重合 
		else
			puthz(location[i][0] - 15, location[i][1] + 6, name[i], 16, 16, RED);
	}

	bar(0, 410, 639, 479);        //下方提示板 
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(540, 415, 630, 474);
	puthz(550, 430, "出发", 32, 32, BLUE);
	puthz(200, 430, "请选择始发地", 32, 32, DARKGRAY);

	floyd(P, D);

	/*
					{10,105},{35,70},{35,170},{110,165},{183,140},
					{190,245},{190,365},{245,105},{225,215},{255,145},
					{280,225},{280,325},{370,280},{450,370},{485,235}
	*/

	/*
							{10,105},
							{35,70},
							{35,170},//
							{110,165},
							{183,140},
							{190,245},
							{190,365},
							{245,105},//7
							{225,215},//8
							{255,145},//9
							{280,225},//10
							{280,325},//11
							{370,280},//12
							{450,370},//13
							{485,235},//14
	*/

	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(5, 100, 15, 110) == 1)
		{
			now = 0;
			flag = 1;
			delay(250);
		}
		else if (mouse_press(30, 65, 40, 75) == 1)
		{
			now = 1;					flag = 1;
			delay(250);
		}
		else if (mouse_press(30, 165, 40, 175) == 1)
		{
			now = 2;					flag = 1;
			delay(250);
		}
		else if (mouse_press(105, 160, 115, 170) == 1)
		{
			now = 3;					flag = 1;
			delay(250);
		}
		else if (mouse_press(178, 135, 188, 145) == 1)
		{
			now = 4;					flag = 1;
			delay(250);
		}
		else if (mouse_press(185, 240, 195, 250) == 1)
		{
			now = 5;					flag = 1;
			delay(250);
		}
		else if (mouse_press(185, 360, 195, 370) == 1)
		{
			now = 6;					flag = 1;
			delay(250);
		}
		else if (mouse_press(240, 100, 250, 110) == 1)
		{
			now = 7;					flag = 1;
			delay(250);
		}
		else if (mouse_press(220, 210, 230, 220) == 1)
		{
			now = 8;					flag = 1;
			delay(250);
		}
		else if (mouse_press(250, 140, 260, 150) == 1)
		{
			now = 9;					flag = 1;
			delay(250);
		}
		else if (mouse_press(275, 220, 285, 230) == 1)
		{
			now = 10;					flag = 1;
			delay(250);
		}
		else if (mouse_press(275, 320, 285, 330) == 1)
		{
			now = 11;					flag = 1;
			delay(250);
		}
		else if (mouse_press(365, 275, 375, 285) == 1)
		{
			now = 12;					flag = 1;
			delay(250);
		}
		else if (mouse_press(445, 365, 455, 375) == 1)
		{
			now = 13;					flag = 1;
			delay(250);
		}
		else if (mouse_press(480, 230, 490, 240) == 1)
		{
			now = 14;					flag = 1;
			delay(250);
		}
		if (flag)
		{
			setfillstyle(SOLID_FILL, WHITE);
			bar(200, 430, 400, 465);
			puthz(200, 430, "请选择目的地", 32, 32, DARKGRAY);
			flag = 0;
			while (1)
			{
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(5, 100, 15, 110) == 1)
				{
					destination = 0;				start = 1;
					//flag = 1;
					delay(250);
					break;
				}
				else if (mouse_press(30, 65, 40, 75) == 1)
				{
					destination = 1;					start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(30, 165, 40, 175) == 1)
				{
					destination = 2;					start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(105, 160, 115, 170) == 1)
				{
					destination = 3;					start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(178, 135, 188, 145) == 1)
				{
					destination = 4;					start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(185, 240, 195, 250) == 1)
				{
					destination = 5;					start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(185, 360, 195, 370) == 1)
				{
					destination = 6;					start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(240, 100, 250, 110) == 1)
				{
					destination = 7;				start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(220, 210, 230, 220) == 1)
				{
					destination = 8;					start= 1;
					delay(250);
					break;
				}
				else if (mouse_press(250, 140, 260, 150) == 1)
				{
					destination = 9;			start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(275, 220, 285, 230) == 1)
				{
					destination = 10;				start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(275, 320, 285, 330) == 1)
				{
					destination = 11;			start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(365, 275, 375, 285) == 1)
				{
					destination = 12;			start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(445, 365, 455, 375) == 1)
				{
					destination = 13;		start = 1;
					delay(250);
					break;
				}
				else if (mouse_press(480, 230, 490, 240) == 1)
				{
					destination = 14;			start = 1;
					delay(250);
					break;
				}

			}
		}

		if (start == 1)
		{
			navigaiton(destination, &now, P, &distance);
			start = 0;
			bar(200, 430, 400, 465);
			puthz(200, 430, "准备出发", 32, 32, DARKGRAY);

			while (1) 
			{
				newmouse(&MouseX, &MouseY, &press);
				if (mouse_press(540, 415, 630, 474) == 1)
				{
					*page_index = 2;
					cleardevice();
					clrmous(MouseX, MouseY);
					return;
				}
				else if (mouse_press(540, 415, 630, 474) == 2)
				{
					MouseS = 1;
				}
				else
				{
					MouseS = 0;
				}

			}

		}

	}
}
