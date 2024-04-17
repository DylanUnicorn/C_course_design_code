#include "setting.h"
//void SetLight(int mode,INSTRUMENT* pi);
//{
//	if (mode == 0) //调整仪表照明
//	{
//		if (pi->type[0] < 3)
//		{
//			pi->type[0] += 1;
//		}
//	}
//	else if (mode == 1) 
//	{
//		if(pi ->type[0] > 0)
//		pi -> type[0]-= 1;
//	}
//	else if (mode == 2)
//	{
//		if (pi->type[1] < 3)
//		{
//			pi->type[1] += 1;
//		}
//	}
//	else if (mode == 3)
//	{
//		if (pi->type[1] > 0)
//		{
//			pi->type[1] -= 1;
//		}
//	}
//	else if (mode == 4)
//	{
//		if (pi->type[2] < 3)
//		{
//			pi->type[2] += 1;
//		}
//	}
//	else if (mode == 5)
//	{
//		if (pi->type[2] > 0)
//		{
//			pi->type[2] -= 1;
//		}
//	}
//
//}
/***************************************

func:实现灯光设置界面的绘制和功能实现

*****************************************/

void paintbar(INSTRUMENT* pi)
{
	setfillstyle(1, LIGHTGRAY);
	bar(531, 141, 607, 156);//完全覆盖
	bar(531, 141 + 87, 607, 156 + 87);
	bar(531, 141 + 174, 607, 156 + 174);

	setfillstyle(1, WHITE);

	if (pi->setlight.type[0] == 0) 
	{
		bar(531, 141, 531 + 19, 156);
	}
	else if (pi->setlight.type[0] == 1) 
	{
		bar(531+19, 141, 531 + 19 + 19, 156);
	}
	else if (pi->setlight.type[0] == 2) 
	{
		bar(531+19+19, 141, 531 + 19 + 19 + 19, 156);
	}
	else if (pi->setlight.type[0] == 3) 
	{
		bar(531+19+19+19, 141, 531 + 19 + 19 + 19 + 19, 156);
	}

	if(pi->setlight.type[1] == 0)
	{
		bar(531, 141 + 87, 531 + 19, 156 + 87);
	}
	else if (pi->setlight.type[1] == 1)
	{
		bar(531+19, 141 + 87, 531 + 19 + 19, 156 + 87);
	}
	else if (pi->setlight.type[1] == 2)
	{
		bar(531+19 +19, 141 + 87, 531 + 19 + 19 + 19, 156 + 87);
	}
	else if (pi->setlight.type[1] == 3)
	{
		bar(531+19+19+19, 141 + 87, 531 + 19 + 19 + 19 + 19, 156 + 87);
	}

	if (pi->setlight.type[2] == 0)
	{
		bar(531, 141 + 174, 531 + 19, 156 + 174);
	}
	else if (pi->setlight.type[2] == 1)
	{
		bar(531+19, 141 + 174, 531 + 19 + 19, 156 + 174);
	}
	else if (pi->setlight.type[2] == 2)
	{
		bar(531+19+19, 141 + 174, 531 + 19 + 19 + 19, 156 + 174);
	}
	else if (pi->setlight.type[2] == 3)
	{
		bar(531+19+19+19, 141 + 174, 531 + 19 + 19 + 19 + 19, 156 + 174);
	}
}

void SetLuseMous(int* page_index,AIR* pair, INSTRUMENT* pi, int* ischange)
{
	paintbar(pi);
	while (1)
	{
		*ischange = 0;
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(578, 34, 616, 98) == 1)
		{
			clrmous(MouseX, MouseY);
			return;
		}
		else if (mouse_press(531, 141, 531 + 19, 156) == 1) 
		{
			pi->setlight.type[0] = 0;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19, 141, 531 + 19 + 19, 156) == 1) 
		{
			pi->setlight.type[0] = 1;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19 + 19, 141, 531 + 19 + 19 + 19, 156) == 1) 
		{
			pi->setlight.type[0] = 2;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19 + 19 + 19, 141, 531 + 19 + 19 + 19 + 19, 156) == 1) 
		{
			pi->setlight.type[0] = 3;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531, 141 + 87, 531 + 19, 156 + 87) == 1) 
		{
			pi->setlight.type[1] = 0;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19, 141 + 87, 531 + 19 + 19, 156 + 87) == 1) 
		{
			pi->setlight.type[1] = 1;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19 + 19, 141 + 87, 531 + 19 + 19 + 19, 156 + 87) == 1) 
		{
			pi->setlight.type[1] = 2;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19 + 19 + 19, 141 + 87, 531 + 19 + 19 + 19 + 19, 156 + 87) == 1) 
		{
			pi->setlight.type[1] = 3;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531, 141 + 174, 531 + 19, 156 + 174) == 1) 
		{
			pi->setlight.type[2] = 0;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19, 141 + 174, 531 + 19 + 19, 156 + 174) == 1) 
		{
			pi->setlight.type[2] = 1;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19 + 19, 141 + 174, 531 + 19 + 19 + 19, 156 + 174) == 1) 
		{
			pi->setlight.type[2] = 2;
			*ischange = 1;
			delay(100);
		}
		else if (mouse_press(531 + 19 + 19 + 19, 141 + 174, 531 + 19 + 19 + 19 + 19, 156 + 174) == 1) 
		{
			pi->setlight.type[2] = 3;
			*ischange = 1;
			delay(100);
		}
		else
		{
			MouseS = 0;
		}
		if (*ischange == 1) 
		{
			clrmous(MouseX, MouseY);
			paintbar(pi);
		}

	}
}


/****************************************


*/

/*
	moveto(327, 191);
	lineto(309, 160);
	lineto(228, 160);
	lineto(216, 206);
	lineto(245, 239);
	lineto(317, 239);
	lineto(327, 210);

*/


//335, 191, 408, 216   alpha最高智能去2
void paintRV(int x, int y,INSTRUMENT* pi, int mode, double alpha)//18.17.32.39.35  13.17.40.44.49
{
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, BLACK);


	if (mode == 0&&pi->RVmirror.positiony[3] < 280) //下移动左后视镜
	{
		bar(215, 121, 327, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[0], pi->RVmirror.positiony[0] +=  17 * alpha);
		lineto(pi->RVmirror.positionx[1], pi->RVmirror.positiony[1] +=  41 * alpha);
		lineto(pi->RVmirror.positionx[2], pi->RVmirror.positiony[2] +=  70 * alpha - 10 * alpha * alpha);
		lineto(pi->RVmirror.positionx[3], pi->RVmirror.positiony[3] +=  40 * alpha);
		lineto(pi->RVmirror.positionx[4], pi->RVmirror.positiony[4] +=  30 * alpha - 11*alpha*alpha);
		lineto(x, y + 19);
	}
	else if (mode == 1 && pi->RVmirror.positiony[1] > 140) //上移动左后视镜
	{
		bar(215, 121, 327, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[0], pi->RVmirror.positiony[0] -=  17 * alpha);
		lineto(pi->RVmirror.positionx[1], pi->RVmirror.positiony[1] -= 41 * alpha);
		lineto(pi->RVmirror.positionx[2], pi->RVmirror.positiony[2] -=  70 * alpha - 10 * alpha * alpha);
		lineto(pi->RVmirror.positionx[3], pi->RVmirror.positiony[3] -=  40 * alpha);
		lineto(pi->RVmirror.positionx[4], pi->RVmirror.positiony[4] -= 30 * alpha - 11* alpha* alpha);
		lineto(x, y + 19);
	}
	else if (mode == 2 && pi->RVmirror.positionx[0]< 322&&pi->RVmirror.positionx[3]< pi->RVmirror.positionx[4]-20)//右移动左后视镜 
	{
		bar(215, 121, 327, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[0] += 10 * alpha, pi->RVmirror.positiony[0] );
		lineto(pi->RVmirror.positionx[1] += 32 * alpha, pi->RVmirror.positiony[1] );
		lineto(pi->RVmirror.positionx[2] += 40 * alpha - 18 * alpha * alpha, pi->RVmirror.positiony[2]);
		lineto(pi->RVmirror.positionx[3] += 109 / 2.0 * alpha - 43 / 2.0 * alpha * alpha, pi->RVmirror.positiony[3]);
		lineto(pi->RVmirror.positionx[4] += 7 * alpha, pi->RVmirror.positiony[4] );
		lineto(x, y + 19);

	}
	else if (mode == 3&&pi->RVmirror.positionx[2]> 216)//左移动左后视镜 
	{
		bar(215, 121, 327, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[0] -= 10 * alpha, pi->RVmirror.positiony[0]);
		lineto(pi->RVmirror.positionx[1] -= 32 * alpha, pi->RVmirror.positiony[1] );
		lineto(pi->RVmirror.positionx[2] -= 40 * alpha - 18 * alpha * alpha, pi->RVmirror.positiony[2]);
		lineto(pi->RVmirror.positionx[3] -= 109 / 2.0 * alpha - 43 / 2.0 * alpha * alpha, pi->RVmirror.positiony[3]);
		lineto(pi->RVmirror.positionx[4] -= 7 * alpha, pi->RVmirror.positiony[4] );
		lineto(x, y + 19);
	}


}

void paintRV2(int x, int y, INSTRUMENT* pi, int mode, double alpha) 
{
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, BLACK);

	if (mode == 0)//下移右后视镜 
	{
		bar(493, 121, 620, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[5], pi->RVmirror.positiony[5] += 17 * alpha);
		lineto(pi->RVmirror.positionx[6], pi->RVmirror.positiony[6] += 41 * alpha);
		lineto(pi->RVmirror.positionx[7], pi->RVmirror.positiony[7] += 70 * alpha - 10 * alpha * alpha);
		lineto(pi->RVmirror.positionx[8], pi->RVmirror.positiony[8] += 40 * alpha);
		lineto(pi->RVmirror.positionx[9], pi->RVmirror.positiony[9] += 30 * alpha - 11 * alpha * alpha);
		lineto(x, y + 19);

	}
	else if (mode == 1)
	{
		bar(493, 121, 620, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[5], pi->RVmirror.positiony[5] -= 17 * alpha);
		lineto(pi->RVmirror.positionx[6], pi->RVmirror.positiony[6] -= 41 * alpha);
		lineto(pi->RVmirror.positionx[7], pi->RVmirror.positiony[7] -= 70 * alpha - 10 * alpha * alpha);
		lineto(pi->RVmirror.positionx[8], pi->RVmirror.positiony[8] -= 40 * alpha);
		lineto(pi->RVmirror.positionx[9], pi->RVmirror.positiony[9] -= 30 * alpha - 11 * alpha * alpha);
		lineto(x, y + 19);
	}
	else if (mode == 2 )//右移动右后视镜 
	{
		bar(493, 121, 620, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[5] += 10 * alpha, pi->RVmirror.positiony[5]);
		lineto(pi->RVmirror.positionx[6] += 32 * alpha, pi->RVmirror.positiony[6]);
		lineto(pi->RVmirror.positionx[7] += 40 * alpha - 18 * alpha * alpha, pi->RVmirror.positiony[7]);
		lineto(pi->RVmirror.positionx[8] += 109 / 2.0 * alpha - 43 / 2.0 * alpha * alpha, pi->RVmirror.positiony[8]);
		lineto(pi->RVmirror.positionx[9] += 7 * alpha, pi->RVmirror.positiony[9]);
		lineto(x, y + 19);

	}

	else if (mode == 3 )//左移动右后视镜 
	{
		bar(493, 121, 620, 279);
		moveto(x, y);
		lineto(pi->RVmirror.positionx[5] -= 10 * alpha, pi->RVmirror.positiony[5]);
		lineto(pi->RVmirror.positionx[6] -= 32 * alpha, pi->RVmirror.positiony[6]);
		lineto(pi->RVmirror.positionx[7] -= 40 * alpha - 18 * alpha * alpha, pi->RVmirror.positiony[7]);
		lineto(pi->RVmirror.positionx[8] -= 109 / 2.0 * alpha - 43 / 2.0 * alpha * alpha, pi->RVmirror.positiony[8]);
		lineto(pi->RVmirror.positionx[9] -= 7 * alpha, pi->RVmirror.positiony[9]);
		lineto(x, y + 19);
	}


}

/// <summary>  @brief 调整
///				
///
/// <param name="func"></param>
/// <param name="pi"></param>

void paintRVAndSeat(INSTRUMENT* pi) 
{
	int i=0;
	
		setfillstyle(1, BLACK);
		setlinestyle(0, 0, 3);
		bar(215, 121, 327, 279);
		setcolor(WHITE);
		moveto(327, 191);
		lineto(pi->RVmirror.positionx[0], pi->RVmirror.positiony[0]);
		lineto(pi->RVmirror.positionx[1], pi->RVmirror.positiony[1]);
		lineto(pi->RVmirror.positionx[2], pi->RVmirror.positiony[2]);
		lineto(pi->RVmirror.positionx[3], pi->RVmirror.positiony[3]);
		lineto(pi->RVmirror.positionx[4], pi->RVmirror.positiony[4]);
		lineto(327, 210);

		bar(493, 121, 620, 279);
		moveto(493, 189);
		lineto(pi->RVmirror.positionx[5], pi->RVmirror.positiony[5]);
		lineto(pi->RVmirror.positionx[6], pi->RVmirror.positiony[6]);
		lineto(pi->RVmirror.positionx[7], pi->RVmirror.positiony[7]);
		lineto(pi->RVmirror.positionx[8], pi->RVmirror.positiony[8]);
		lineto(pi->RVmirror.positionx[9], pi->RVmirror.positiony[9]);
		lineto(493, 189 + 19);

		for ( i = 0; i < 3; i++) 
		{
			drawseat(pi);
		}
}

void seatfunc(int mode,INSTRUMENT* pi) 
{
	if (mode == 0 && pi->seat.height[pi->seat.position] < 10) 
	{
		pi->seat.height[pi->seat.position] += 1;
	}
	else if (mode == 1 && pi->seat.height[pi->seat.position] > 0) 
	{
		pi->seat.height[pi->seat.position] -= 2;
	}
	else if (mode == 2 && pi->seat.horiz[pi->seat.position] < 20) 
	{
		pi->seat.horiz[pi->seat.position] += 2;
	}
	else if (mode == 3 && pi->seat.horiz[pi->seat.position] > 0) 
	{
		pi->seat.horiz[pi->seat.position] -= 2;
	}
	else if (mode == 4 && pi->seat.angle[pi->seat.position] < 60) 
	{
		pi->seat.angle[pi->seat.position] += 2;
	}
	else if (mode == 5 && pi->seat.angle[pi->seat.position] > 0) 
	{
		pi->seat.angle[pi->seat.position] -= 2;
	}
	else if (mode == 6) 
	{
		if (pi->seat.position == 0) //主驾
		{
			pi->seat.position = 1;
		}
		else if (pi->seat.position == 1) //副驾
		{
			pi->seat.position = 2;
		}
		else if (pi->seat.position == 2) //后排
		{
			pi->seat.position = 0;
		}
	}
}


void drawseat(INSTRUMENT* pi) 
{
	setfillstyle(1, LIGHTGRAY);
	bar(50, 391, 162, 439);
	if (pi->seat.position == 0) 
	{
		puthz(55, 397, "主驾", 32, 32, WHITE);
	}
	else if (pi->seat.position == 1) 
	{
		puthz(55, 397, "副驾", 32, 32, WHITE);
	}
	else if (pi->seat.position == 2) 
	{
		puthz(55, 397, "后排", 32, 32, WHITE);
	}
	setfillstyle(1, BLACK);

	/*
	line(201, 371, 232, 371);//主驾
	line(232, 371, 232, 333);
	line(201, 442, 231, 442);//副驾
	line(231, 442, 231, 404);
	line(425, 411, 473, 411);//后排
	line(473, 411, 473, 357);

		bar(85, 346, 98, 360);
			bar(100, 333, 113, 347);
	bar(115, 346, 128, 360);
	bar(100, 360,113, 374);
	*/
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	if (pi->seat.position == 0) 
	{
		bar(201, 322, 282, 381);
		line(201+ pi->seat.horiz[0], 371 - pi->seat.height[0], 232 + pi->seat.horiz[0], 371 - pi->seat.height[0]);
		line(232 + pi->seat.horiz[0], 371 - pi->seat.height[0], 232 + pi->seat.horiz[0]+38*sin(pi->seat.angle[0]*PI/180.0), 333 - pi->seat.height[0]+38-38*cos(pi->seat.angle[0]*PI/180.0));
	}
	else if (pi->seat.position == 1) 
	{
		bar(201, 392, 282, 463);
		line(201 + pi->seat.horiz[1], 442 - pi->seat.height[1], 231 + pi->seat.horiz[1], 442 - pi->seat.height[1]);
		line(231 + pi->seat.horiz[1], 442 - pi->seat.height[1], 231 + pi->seat.horiz[1] + 38 * sin(pi->seat.angle[1] * PI / 180.0), 404 - pi->seat.height[1] + 38 - 38 * cos(pi->seat.angle[1] * PI / 180.0));
	}
	else if (pi->seat.position == 2) 
	{
		bar(400, 350, 506, 416);
		line(425 + pi->seat.horiz[2], 411 - pi->seat.height[2], 473 + pi->seat.horiz[2], 411 - pi->seat.height[2]);
		line(473 + pi->seat.horiz[2], 411 - pi->seat.height[2], 473 + pi->seat.horiz[2] + 38 * sin(pi->seat.angle[2] * PI / 180.0), 357 - pi->seat.height[2] + 38 - 38 * cos(pi->seat.angle[2] * PI / 180.0));
	}

}

/*
			{{RVxL - 18,RVxL - 99,RVxL - 111,RVxL - 82,RVxL - 10,RVxR + 20,RVxR + 101,RVxR + 114,RVxR + 83,RVxR + 12},
		{ RVyL - 31,RVyL - 31,RVyL + 15, RVyL + 48,RVyL + 48,RVyL - 30,RVyL - 30, RVyL + 14,RVyL + 50,RVyL + 50} ,

*/

void restore(int item, INSTRUMENT* pi) 
{
	int i = 0;
	int init[] = { 18,99,111,82,10,20,101,114,83,12 };
	int init2[] = { 31,31,-15,-48,-48,-30,-30,14,50,50 };
	if (item == 0)//回复原来的后视镜 
	{
		for (i = 0; i < 5; i++) 
		{
			pi->RVmirror.positionx[i] = RVxL - init[i];
			pi->RVmirror.positiony[i] = RVyL - init2[i];
			pi->RVmirror.positionx[i + 5] = RVxR + init[i+5];
			pi->RVmirror.positiony[i + 5] = RVyR + init2[i+5];
		}
		setfillstyle(1, BLACK);
		setlinestyle(0, 0, 3);
		bar(215, 121, 327, 279);//还原左后视镜
		setcolor(WHITE);
		moveto(327, 191);
		lineto(pi->RVmirror.positionx[0], pi->RVmirror.positiony[0]);
		lineto(pi->RVmirror.positionx[1], pi->RVmirror.positiony[1]);
		lineto(pi->RVmirror.positionx[2], pi->RVmirror.positiony[2]);
		lineto(pi->RVmirror.positionx[3], pi->RVmirror.positiony[3]);
		lineto(pi->RVmirror.positionx[4], pi->RVmirror.positiony[4]);
		lineto(327, 210);

		bar(493, 121, 620, 279);//还原右后视镜
		moveto(493, 189);
		lineto(pi->RVmirror.positionx[5], pi->RVmirror.positiony[5]);
		lineto(pi->RVmirror.positionx[6], pi->RVmirror.positiony[6]);
		lineto(pi->RVmirror.positionx[7], pi->RVmirror.positiony[7]);
		lineto(pi->RVmirror.positionx[8], pi->RVmirror.positiony[8]);
		lineto(pi->RVmirror.positionx[9], pi->RVmirror.positiony[9]);
		lineto(493, 189+19);

	}
	else if (item == 1) //还原座椅
	{
		for (i = 0; i < 3; i++) 
		{
			pi->seat.height[i] = 0;
			pi->seat.horiz[i] = 0;
			pi->seat.angle[i] = 0;
		}
		for (i = 2; i >= 0; i--) 
		{
			pi->seat.position = i;
			drawseat(pi);
		}

	}
}

void RVuseMous(int* page_index, AIR* pair, INSTRUMENT* pi, int* ischange) 
{
	paintRVAndSeat(pi);
	while (1) 
	{
		*ischange = 0;
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(578, 34, 616, 98) == 1)
		{
			clrmous(MouseX, MouseY);
			return;
		}
		else if (mouse_press(63, 194, 114, 239) == 1) //左右选择
		{
			if (pi->RVmirror.choose == 0)
			{
				pi->RVmirror.choose = 1;
			}
			else
			{
				pi->RVmirror.choose = 0;
			}
			delay(250);
			*ischange = 1;
		}
		else if (pi->RVmirror.choose == 0 && mouse_press(63, 156, 111, 181) == 1)//左边的后视镜上增
		{
			paintRV(327, 191, pi, 1, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 0 && mouse_press(75, 253, 104, 281) == 1)//上减
		{
			paintRV(327, 191, pi, 0, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 0 && mouse_press(130, 202, 154, 226) == 1)//右增
		{
			paintRV(327, 191, pi, 2, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 0 && mouse_press(26, 198, 50, 228) == 1)//右减
		{
			paintRV(327, 191, pi, 3, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 1 && mouse_press(63, 156, 111, 181) == 1)//右边的后视镜上增
		{
			paintRV2(493, 189, pi, 1, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 1 && mouse_press(75, 253, 104, 281) == 1)//上减
		{
			paintRV2(493, 189, pi, 0, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 1 && mouse_press(130, 202, 154, 226) == 1)//右增
		{
			paintRV2(493, 189, pi, 2, 0.1);
			delay(250);
		}
		else if (pi->RVmirror.choose == 1 && mouse_press(26, 198, 50, 228) == 1)//右减
		{
			paintRV2(493, 189, pi, 3, 0.1);
			delay(250);
		}
		else if (mouse_press(85, 346, 98, 360) == 1)//控制座椅的
		{
			seatfunc(3, pi);
			delay(250);
			*ischange = 1;

		}
		else if(mouse_press(100, 333, 113, 347) == 1)
		{
			seatfunc(0, pi);
			delay(250);
			*ischange = 1;
		}
		else if (mouse_press(115, 346, 128, 360) == 1) 
		{
			seatfunc(2, pi);
			delay(250);
			*ischange = 1;
		}
		else if (mouse_press(100, 360, 113, 374) == 1)
		{
			seatfunc(1, pi);
			delay(250);
			*ischange = 1;
		}
		else if (mouse_press(50, 391, 162, 439) == 1) 
		{
			seatfunc(6, pi);
			delay(250);
			*ischange = 1;
		}
		/*
		* 	bar(67, 321, 96, 331);
		bar(117, 321, 146, 331);
		*/
		else if (mouse_press(67, 321, 96, 331) == 1) 
		{
			seatfunc(5, pi);
			delay(250);
			*ischange = 1;
		}
		else if (mouse_press(117, 321, 146, 331) == 1) 
		{
			seatfunc(4, pi);
			delay(250);
			*ischange = 1;
		}
		else if (mouse_press(395, 125, 425, 155) == 1) //设置回归按键
		{
			restore(0, pi);
			delay(250);
		}
		else if (mouse_press(399, 291, 429, 321) == 1)
		{
			restore(1, pi);
			delay(250);
		}
		else
		{
			MouseS = 0;
		}
		if (*ischange == 1)
		{
			clrmous(MouseX, MouseY);
			//paintRV(327, 191,pi, 0, pi->RVmirror.adjust[0]/10.0);
			drawseat(pi);

			setfillstyle(1, BLACK);
			bar(70, 198, 108, 235);
			if (pi->RVmirror.choose == 0) 
			{
				puthz(70, 198, "左", 32, 32, WHITE);
			}
			else 
			{
				puthz(70, 198, "右", 32, 32, WHITE);
			}
		}
	}
}


/*
	moveto(317, 179);//画车窗，从左上角开始画，顺时针
	lineto(340, 179);
	lineto(340, 223);
	lineto(273, 223);
	lineto(317, 179);

	223-179=44
	317-273=44

	moveto(497, 180);//画车窗，从左上角开始画，顺时针
	lineto(518, 180);
	lineto(564, 225);
	lineto(497, 224);
	lineto(497, 180);//

225-180=45
564-518=46

	moveto(317, 179 + 170);
	lineto(340, 179 + 170);
	lineto(340, 223 + 170);
	lineto(273, 223 + 170);
	lineto(318, 179 + 170);

	moveto(497, 180 + 170);
	lineto(518, 180 + 170);
	lineto(564, 225 + 170);
	lineto(497, 225 + 170);
	lineto(497, 180 + 170);//


*/

void DoorWinfunc(int mode,INSTRUMENT* pi) 
{
	if (mode == 0) 
	{
		if (pi->doorwin.position[0] < 44) 
		{
			pi->doorwin.position[0] += 2;
		}
	}
	else if (mode == 1) 
	{
		if (pi->doorwin.position[0] > 0) 
		{
			pi->doorwin.position[0] -= 2;
		}
	}
	else if (mode == 2) 
	{
		if (pi->doorwin.position[1] < 44) 
		{
			pi->doorwin.position[1] += 2;
		}
	}
	else if (mode == 3) 
	{
		if (pi->doorwin.position[1] > 0) 
		{
			pi->doorwin.position[1] -= 2;
		}
	}
	else if (mode == 4) 
	{
		if (pi->doorwin.position[2] < 44) 
		{
			pi->doorwin.position[2] += 2;
		}
	}
	else if (mode == 5) 
	{
		if (pi->doorwin.position[2] > 0) 
		{
			pi->doorwin.position[2] -= 2;
		}
	}
	else if (mode == 6) 
	{
		if (pi->doorwin.position[3] < 44) 
		{
			pi->doorwin.position[3] += 2;
		}
	}
	else if (mode == 7) 
	{
		if (pi->doorwin.position[3] > 0) 
		{
			pi->doorwin.position[3] -= 2;
		}
	}
}

void paintDoorWin(INSTRUMENT* pi) 
{
	int polypoint1[]= { 273,223, 340, 223, 340, 223, 273, 223 };
	int polypoint2[] = { 497, 225, 564, 225, 564, 225, 497, 225 };
	int polypoint3[] = { 273,223 + 170, 340, 223 + 170, 340, 223 + 170, 273, 223 + 170 };
	int polypoint4[] = { 497, 225 + 170, 564, 225 + 170, 564, 225 + 170, 497, 225 + 170 };

	setfillstyle(1, BLACK);
	setcolor(WHITE);

		floodfill(318, 180, WHITE);

		polypoint1[0] = 273 + pi->doorwin.position[0];
		polypoint1[1] = 223 - pi->doorwin.position[0];
		polypoint1[2] = 340;
		polypoint1[3] = 223 - pi->doorwin.position[0];
		setfillstyle(1, LIGHTGRAY);
		fillpoly(4, polypoint1);

		setfillstyle(1, BLACK);
		floodfill(498, 226, WHITE);
		polypoint2[0] = 497;
		polypoint2[1] = 225 - pi->doorwin.position[1];
		polypoint2[2] = 564 - pi->doorwin.position[1];
		polypoint2[3] = 225 - pi->doorwin.position[1];
		setfillstyle(1, LIGHTGRAY);
		fillpoly(4, polypoint2);

		setfillstyle(1, BLACK);
		floodfill(318, 180+170, WHITE);
		polypoint3[0] = 273 + pi->doorwin.position[2];
		polypoint3[1] = 223+170 - pi->doorwin.position[2];
		polypoint3[2] = 340;
		polypoint3[3] = 223 +170 - pi->doorwin.position[2];
		setfillstyle(1, LIGHTGRAY);
		fillpoly(4, polypoint3);

		setfillstyle(1, BLACK);
		floodfill(498, 226+170, WHITE);
		polypoint4[0] = 497;
		polypoint4[1] = 225 + 170 - pi->doorwin.position[3];
		polypoint4[2] = 564 - pi->doorwin.position[3];
		polypoint4[3] = 225 + 170 - pi->doorwin.position[3];
		setfillstyle(1, LIGHTGRAY);
		fillpoly(4, polypoint4);
}
/*
* 	bar(43, 189, 97, 257);
	bar(151, 189, 205, 257);
	bar(43, 289, 97, 357);
	bar(151, 289, 205, 357);

	line(43, 224, 97, 224);
	line(151,224, 205, 224);
	line(43, 324, 97, 324);
	line(151, 324, 205, 324);	
*/

void DWusemous(int* page_index, INSTRUMENT* pi, int* ischange) 
{
	while (1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(578, 34, 616, 98) == 1)
		{
			clrmous(MouseX, MouseY);
			//setting_page(page_index, pair, pi, ischange);
			return;
		}
		else if (mouse_press(43, 189, 97, 224) == 1) 
		{
			DoorWinfunc(0, pi);
			*ischange = 1;
			delay(250);
		}
		else if (mouse_press(43, 224, 97, 257) == 1) 
		{
			DoorWinfunc(1, pi);
			*ischange = 1;
			delay(250);

		}
		else if (mouse_press(151, 189, 205, 224) == 1) 
		{
			DoorWinfunc(2, pi);
			*ischange = 1;
			delay(250);

		}
		else if (mouse_press(151, 224, 205, 257) == 1) 
		{
			DoorWinfunc(3, pi);
			*ischange = 1;
			delay(250);

		}
		else if (mouse_press(43, 289, 97, 324) == 1) 
		{
			DoorWinfunc(4, pi);
			*ischange = 1;
			delay(250);

		}
		else if (mouse_press(43, 324, 97, 357) == 1) 
		{
			DoorWinfunc(5, pi);
			*ischange = 1;
			delay(250);

		}
		else if (mouse_press(151, 289, 205, 324) == 1) 
		{
			DoorWinfunc(6, pi);
			*ischange = 1;
			delay(250);

		}
		else if (mouse_press(151, 324, 205, 357) == 1) 
		{
			DoorWinfunc(7, pi);
			*ischange = 1;
			delay(250);

		}
		else
		{
			MouseS = 0;
		}
		if (*ischange == 1)
		{
				paintDoorWin(pi);
		
		}
	}
}


