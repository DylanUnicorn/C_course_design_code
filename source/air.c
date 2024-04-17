#include<air.h>


void wind(int x, int y, int airType, int speed, int derection) //画在最中间，三个箭头
{
	int color;
	switch (airType) 
	{
		case 0:
			color = 1;//蓝色冷的
			break;
		case 1:
			color = 4;//红色热的
			break;
	}
	setcolor(color);
	setlinestyle(0, 0, 3);
	setfillstyle(1, color);//完全填充
	if (speed == 1 && derection == 1)//向上小风 
	{
		moveto(x, y);//首点
		lineto(x + 17, y - 9);
		lineto(x +17- 7, y -9 - 1);
		lineto(x +17 -7+ 21, y -9-1- 7);
		lineto(x + 17 - 7 + 21 - 8, y - 9 - 1 - 7 + 19);
		lineto(x + 17 - 7 + 21 - 8 - 3, y - 9 - 1 - 7 + 19 - 9);
		lineto(x + 2, y + 2);//尾点
		lineto(x, y);
		floodfill(x+2, y, color);

	}
	else if (speed == 2 && derection == 1)
	{
		moveto(x, y);//首点
		lineto(x + 17+8, y - 9-7);
		lineto(x + 17 - 7+8, y - 9 - 1-7);
		lineto(x + 17 - 7 + 21+8, y - 9 - 1 - 7-7);
		lineto(x + 17 - 7 + 21 - 8+8, y - 9 - 1 - 7 + 19-7);
		lineto(x + 17 - 7 + 21 - 8 - 3+8, y - 9 - 1 - 7 + 19 - 9-7);
		lineto(x + 2, y + 2);//尾点
		lineto(x, y);
		floodfill(x + 2, y, color);

	}
	else if (speed == 3 && derection == 1)
	{
		moveto(x, y);
		lineto(x + 17 + 8+8, y - 9 - 7-7);
		lineto(x + 17 - 7 + 8+8, y - 9 - 1 - 7-7);
		lineto(x + 17 - 7 + 21 + 8+8, y - 9 - 1 - 7 - 7-7);
		lineto(x + 17 - 7 + 21 - 8 + 8+8, y - 9 - 1 - 7 + 19 - 7-7);
		lineto(x + 17 - 7 + 21 - 8 - 3 + 8+8, y - 9 - 1 - 7 + 19 - 9 - 7-7);
		lineto(x + 2, y + 2);
		lineto(x, y);
		floodfill(x + 2, y, color);

	}
	else if (speed == 1 && derection == 2) //向中小风
	{
		moveto(x, y);//head
		lineto(x + 27, y);
		lineto(x + 18, y - 5);
		lineto(x + 38, y);
		lineto(x + 18, y + 6);
		lineto(x + 27, y + 2);
		lineto(x, y + 2);//tail
		lineto(x, y);
		floodfill(x + 2, y, color);
	}
	else if(speed ==2 && derection ==2)//向中中风
	{
		moveto(x, y);//head
		lineto(x + 27+5, y);
		lineto(x + 18+5, y - 5);
		lineto(x + 38+5, y);
		lineto(x + 18+5, y + 6);
		lineto(x + 27+5, y + 2);
		lineto(x, y + 2);//tail
		lineto(x, y);
		floodfill(x + 2, y, color);
	}
	else if (speed == 3 && derection == 2) //向中大风
	{
		moveto(x, y);//head
		lineto(x + 27 + 5+5, y);
		lineto(x + 18 + 5+5, y - 5);
		lineto(x + 38 + 5+5, y);
		lineto(x + 18 + 5+5, y + 6);
		lineto(x + 27 + 5+5, y + 2);
		lineto(x, y + 2);//tail
		lineto(x, y);
		floodfill(x + 2, y, color);
	}
	else if (speed == 1 && derection == 3) //向下小风
	{
		moveto(x, y);//head
		lineto(x + 20, y + 9);
		lineto(x + 18, y + 3);
		lineto(x + 30, y + 20);
		lineto(x + 9, y + 13);
		lineto(x + 17, y + 13);
		lineto(x - 1, y + 3);//tail
		lineto(x, y);
		floodfill(x + 2, y, color);
	}
	else if (speed == 2 && derection == 3) //向下中风
	{
		moveto(x, y);//head
		lineto(x + 20+5, y + 9);
		lineto(x + 18+5, y + 3);
		lineto(x + 30+5, y + 20);
		lineto(x + 9+5, y + 13);
		lineto(x + 17+5, y + 13);
		lineto(x - 1+5, y + 3);//tail
		lineto(x, y);
		floodfill(x + 2, y, color);
	}
	else if (speed == 3 && derection == 3) //向下大风
	{
		moveto(x, y);//head
		lineto(x + 20 + 5+5, y + 9);
		lineto(x + 18 + 5+5, y + 3);
		lineto(x + 30 + 5+5, y + 20);
		lineto(x + 9 + 5+5, y + 13);
		lineto(x + 17 + 5+5, y + 13);
		lineto(x - 1 + 5+5, y + 3);//tail
		lineto(x, y);
		floodfill(x + 2, y, color);
	}
}

void airfun(int mode, AIR* pair)
{
	char s1[3], s2[3];
	if (pair->air_con == 1)
	{
		if (mode == 1) //控制风速加
		{
			if (pair->mode == 1)
			{
				if (pair->wind_speed < 3)
				{
					pair->wind_speed++;
				}
				if(pair->wind_speed ==4)
				{
					pair->wind_speed = 3;
				}
			}
		}
		if (mode == 2) //控制风速减
		{
			if (pair->mode == 1)
			{
				if (pair->wind_speed > 1)
				{
					pair->wind_speed--;
				}
			}
		}
		if (mode == 3)//控制方向 向上
		{
			if (pair->mode == 1)
			{
				if (pair->wind_direct == 1) 
				{
					pair->wind_direct = 2;
				}
				else if (pair->wind_direct ==2)
				{
					pair->wind_direct = 3;
				}
				else if (pair->wind_direct == 3)
				{
					pair->wind_direct = 1;
				}
			}
		}
		setfillstyle(1, BLACK);
		bar(69, 70, 144, 149);

		wind(73, 105, pair->air_type, pair->wind_speed, pair->wind_direct);
	
	}
	setfillstyle(1, BLACK);
	setcolor(WHITE);
	bar(6, 81, 67, 152);
	itoa(pair->wind_speed, s1, 10);
	itoa(pair->wind_direct, s2, 10);
	settextstyle(1,0,1);
	outtextxy(38, 96, s1);
	outtextxy(38, 116, s2);
}

void airtemshow(AIR* pair)
{
	char s1[3], s2[3], s3[3];
	setfillstyle(1, BLACK);
	bar(285, 197, 400, 245);
	bar(452, 197, 567, 245);
	bar(382,383, 497, 431);
	setcolor(WHITE);
	itoa(pair->air_degree[0], s1, 10);
	itoa(pair->air_degree[1], s2, 10);
	itoa(pair->air_degree[2], s3, 10);
	settextstyle(1, 0, 5);
	outtextxy(301,200, s1);
	puthz(350, 215, "℃", 32, 32, WHITE);
	outtextxy(467, 200, s2);
	puthz(516, 215, "℃", 32, 32, WHITE);
	outtextxy(390, 385, s3);
	puthz(440, 400, "℃", 32, 32, WHITE);
}

void airstage(int mode,AIR* pair)//状态改变
{
	setcolor(WHITE);
	if (mode == 1)//空调开关改变
	{
		if (pair->air_con == 0)
		{
			pair->air_con = 1;
		}
		else 
		{
			pair->air_con = 0;
		}

	}
	else if (mode == 2)//模式改变
	{
		if (pair->mode == 0)
		{
			pair->mode = 1;
		}
		else
		{
			pair->mode = 0;
		}
	}
	else if (mode == 3)//制冷制热改变
	{
		if (pair->air_type == 0)
		{
			pair->air_type = 1;
		}
		else
		{
			pair->air_type = 0;
		}
	}
	else if (mode == 4)//循环模式改变
	{
		if (pair->loop == 0)
		{
			pair->loop = 1;
		}
		else
		{
			pair->loop = 0;
		}
	}
}

void paintAir(AIR* pair) 
{
	setfillstyle(1, WHITE);
	
	if (pair->air_con == 1) 
	{
		//bar(69, 70, 144, 149);
		wind(73, 105, pair->air_type, pair->wind_speed, pair->wind_direct);
		setfillstyle(1,DARKGRAY);
		bar(122, 240, 206, 291);//开关按键
		puthz(127, 255, "开", 24, 24, WHITE);

		if (pair->wind_speed == 1) 
		{

			setfillstyle(1,DARKGRAY);
			bar(51, 183, 178, 199);
			setfillstyle(1, WHITE);
			bar(51, 183, 96, 199);
		}
		else if (pair->wind_speed == 2) 
		{
			setfillstyle(1, DARKGRAY);
			bar(51, 183, 178, 199);
			setfillstyle(1, WHITE);
			bar(51, 183, 137, 199);
		}
		else if (pair->wind_speed == 3) 
		{
			setfillstyle(1, DARKGRAY);
			bar(51, 183, 178, 199);
			setfillstyle(1, WHITE);
			bar(51, 183, 178, 199);
		}
		if (pair->mode == 0) 
		{
			setfillstyle(1, DARKGRAY);
			bar(15, 240, 99, 291);
			puthz(20, 255, "自动", 24, 24, WHITE);
			
		}
		else if (pair->mode == 1) 
		{
			setfillstyle(1, DARKGRAY);
			bar(15, 240, 99, 291);
			puthz(20, 255, "手动", 24, 24, WHITE);
		}

		if (pair->air_type == 0) //冷风
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 324, 100,375);
			puthz(20, 339, "冷风", 24, 24, WHITE);
		}
		else if (pair->air_type == 1) //热风
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 324, 100, 375);
			puthz(20, 339, "热风", 24, 24, WHITE);
		}
		if (pair->loop == 0) 
		{
			setfillstyle(1, DARKGRAY);
			bar(122, 324, 206, 375);
			puthz(126, 339, "内循环", 24, 24, WHITE);
			setcolor(WHITE);
			setfillstyle(1, BLACK);
			bar(132, 414, 140, 421);
			moveto(164, 422);
			lineto(172, 426);
			lineto(164, 430);
			lineto(164, 422);
		}
		else if (pair->loop == 1) 
		{
			setfillstyle(1, DARKGRAY);
			bar(122, 324, 206, 375);
			puthz(126, 339, "外循环", 24, 24, WHITE);
			setcolor(WHITE);
			setfillstyle(1, BLACK);
			bar(164, 422, 172, 430);
			moveto(136, 421);
			lineto(132, 414);
			lineto(140, 416);
			lineto(136, 421);
		}
		if (pair->wind_direct == 1) 
		{
			setfillstyle(1,DARKGRAY);
			bar(16, 405, 100, 456);
			puthz(20, 423, "向上", 24, 24, WHITE);
		}
		else if (pair->wind_direct == 2) 
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 405, 100, 456);
			puthz(20, 423, "向中", 24, 24, WHITE);
		}
		else if (pair->wind_direct == 3) 
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 405, 100, 456);
			puthz(20, 423, "向下", 24, 24, WHITE);
		}
	}
	else 
	{
		setfillstyle(1, DARKGRAY);
		setcolor(DARKGRAY);
		bar(122, 240, 206, 291);
		puthz(127, 255, "关", 24, 24, WHITE);

		setfillstyle(1, BLACK);
		bar(69, 70, 144, 149);//将风向图标抹掉

	}
}

void airusemous(int *page_index,AIR *pair,int *ischange) 
{
	airtemshow(pair);
	paintAir(pair);

	while (1)
	{
		*ischange = 0;
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(0, 0, 50, 50) == 1)
		{
			clrmous(MouseX, MouseY);
			*page_index = 2;
			return;
		}
		else if (mouse_press(0, 0, 50, 50) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(122, 240, 206, 291) == 1) //总开关
		{
			airstage(1, pair);
			*ischange = 1;
			delay(300);
		}
		else if (mouse_press(15, 240, 99, 291) == 1) //模式
		{
			airstage(2, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(16, 324, 100, 375) == 1) //制冷制热
		{
			airstage(3, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(122, 324, 206, 375) == 1) //循环模式
		{
			airstage(4, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(4, 164, 44, 198) == 1) //减小风速1
		{
			airfun(2, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(187, 166, 227, 200) == 1) //增加风速2
		{
			airfun(1, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(16, 405, 100, 456) == 1) //风向上
		{
			airfun(3, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(323, 129, 361, 161) == 1) //控制主驾位置的增加温度
		{
			if (pair->air_con == 1)
			{
				pair->air_degree[0] += 1;
				*ischange = 1;
				delay(200);
			}
		}
		else if (mouse_press(323, 251, 359, 281) == 1)
		{
			if (pair->air_con == 1) 
			{
				pair->air_degree[0] -= 1;
				*ischange = 1;
				delay(200);
			}
		
		}
		else if (mouse_press(470, 129, 510, 161) == 1)
		{
			pair->air_degree[1] += 1;
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(470, 251, 510, 281) == 1)
		{
			pair->air_degree[1] -= 1;
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(410, 323, 445, 354) == 1)
		{
			pair->air_degree[2] += 1;
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(409, 419, 446, 451) == 1) 
		{
			pair->air_degree[2] -= 1;
			*ischange = 1;
			delay(200);
		}
		else
		{
			MouseS = 0;
		}
		if (*ischange == 1) 
		{
			airtemshow(pair);
			paintAir(pair);
		}
	}




}