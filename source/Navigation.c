#include "Navigation.h"
#define inf 999

//int find_point(CAR* mycar) //找最近点
//{
//	int x = 0, i;
//	double point[15][2] = {
//							{10,105},{35,70},{35,170},{110,165},{183,140},
//							{190,245},{190,365},{245,105},{225,215},{255,145},
//							{280,225},{280,325},{370,280},{450,370},{485,235}
//	};
//	double temp = ((mycar->position_x - point[i][0]) * (mycar->position_x - point[i][0]) + (mycar->position_y - point[i][1]) * (mycar->position_y - point[i][1]));
//	for (i = 0; i < 22; i++)
//	{
//		if (((mycar->position_x - point[i][0]) * (mycar->position_x - point[i][0]) + (mycar->position_y - point[i][1]) * (mycar->position_y - point[i][1])) < temp)
//		{
//			temp = ((mycar->position_x - point[i][0]) * (mycar->position_x - point[i][0]) + (mycar->position_y - point[i][1]) * (mycar->position_y - point[i][1]));
//			x = i;
//		}
//	}
//	return x;//返回地图上看上去最近点的编号
//
//}


//(10-35)*(10-35)+ (105-70)*(105-70) = 35*35+35*35 = 2450
//(10-35)*(10-35)+ (105-170)*(105-170) = 35*35+65*65 = 4550
//
/*ROADPOINT****************************************************
	(4,125),(49,155),(87,184),(162,212),(194,224),(222,233),(297,243),(351,238),(477,219)//三横路
	(19，8),(135,132),(187,153)//二横路
	(4,35),(157,109),(198,128),(263,149)//一横路
	(187,80),(265,72)//半横路
	(102,350)//左竖最低个角点
	(297,229),(299,325),(298,379)//中竖一个角点，两个目的点
	（333，218）,(378,269),(461,361)//右竖一个焦点，两个目的点
*/

//double getDistance(int x1, int y1, int x2, int y2)
//{
//
//
//}

void floyd(unsigned (*P)[15], unsigned (*D)[15]) //需要用点计算器计算
{
	int i, j, k;
	unsigned temp_P[15][15];
	unsigned temp_D[15][15] =
	{
		/*0, 1 ,2 ,3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 ,14 ,15*/
		{0,inf,54, inf, inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf } ,//0   //0
		{inf,0, inf,inf,234,inf,inf,288,inf,282,inf,inf,inf,inf,inf},//1		//1
		{54, inf,0 ,47,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf},//2		//2
		{inf,inf, 47, 0,144,114,230,inf, inf,inf,inf,inf,inf,inf,inf} ,//3		//3
		{inf,234,inf,144,0,98,214,184,inf,88,inf,inf,inf, inf, inf} ,//4		//4
		{inf,inf,inf,114,98, 0,184,inf,29,inf,inf,inf,inf,inf,inf},//5		//5
		{inf,inf,inf,230,214,184,0,inf,inf,inf,inf,inf,inf,inf,inf},//6		//6
		{inf,288,inf,inf,184,inf,inf,0,inf,inf,215,inf,229,inf,288},//7
		{inf,inf,inf,inf,inf,29,inf,inf, 0,inf,75,inf,inf,inf,inf},//8
		{inf,282,inf,inf,88,inf,inf,inf, inf,0,86,inf,inf,inf,inf},//9
		{inf,inf,inf,inf,inf,inf,inf,215,75, 86, 0,96,122,inf,181},//10
		{inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,96, 0,inf,inf,inf},//11
		{inf,inf,inf,inf,inf,inf,inf,229,inf,inf,122,inf,0,123,195},//12
		{inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,inf,123,0,inf},//13
		{inf,inf,inf,inf,inf,inf,inf,288,inf,inf,181,inf,195,inf,0} //14			//14
	};
		
	for (i = 0; i < 15;i++) 
	{
		for (j = 0; j < 15; j++) 
		{
			temp_P[i][j] = j;
		}
	}

	for (i = 0; i < 15; i++) 
	{
		for (j = 0; j < 15; j++) 
		{
			D[i][j] = temp_D[i][j];
			P[i][j] = temp_P[i][j];
		}
	}
	for (k = 0; k < 15; k++) 
	{ 
		for (i = 0; i < 15; i++) 
		{
			for (j = 0; j < 15; j++) 
			{
				if (D[i][j] > D[i][k] + D[k][j]) 
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = P[i][k];
				}
			}
		}
	}
}

void navigaiton(int destination,int *pnow, int(*P)[15],double *p_distance) //先暂时不需要判断车子当前的位置
{
	double point[15][2] = {
					{10,105},{35,70},{35,170},{110,165},{183,140},
					{190,245},{190,365},{245,105},{225,215},{255,145},
					{280,225},{280,325},{370,280},{450,370},{485,235}
	};
	int now,temp;

	now = *pnow;

	while (now != destination) 
	{
		temp = P[now][destination];
		paint_line(now, temp);//这个划线函数要好好考究//进去函数看一下
		//*p_distance += getdistance(now, temp);
		now = temp;//说明这个也一样temp=8，now ==5
	}
	//setcolor(RED);
	//setlinestyle(0, 0, THICK_WIDTH);

	//line(49, 155, 87, 184);

}

void paint_line(int now, int temp)
{
	int rP[25][2] =
	{
		{4,125},{49,155},{87,184},{162,212},{194,224},{222,233},{297,243},{351,238},{477,219},//三横路
		{19,8},{135,132},{187,153},//二横路
		{4,35},{157,109},{198,128},{263,149},//一横路
		{187,80},{265,72},//半横路
		{102,350},//左竖最低个角点
		{297,229},{299,325},{298,379},//中竖一个角点，两个目的点
		{333,218},{378,269},{461,361}//右竖一个焦点，两个目的点
	};

	//now = 5; 
	//temp = 8;
	setcolor(RED);
	setlinestyle(0, 0, THICK_WIDTH);


	if ((now == 0 && temp == 2) || (now == 2 && temp == 0)) line(rP[0][0], rP[0][1], rP[1][0], rP[1][1]);
	else if ((now == 1 && temp == 4) || (now == 4 && temp == 1)) { moveto(rP[11][0], rP[11][1]); lineto(rP[14][0], rP[14][1]); lineto(rP[13][0], rP[13][1]); lineto(rP[12][0], rP[12][1]); }
	else if ((now == 1 && temp == 9) || (now == 9 && temp == 1)) { moveto(rP[12][0], rP[12][1]); lineto(rP[13][0], rP[13][1]); lineto(rP[14][0], rP[14][1]); lineto(rP[15][0], rP[15][1]); }
	else if ((now == 2 && temp == 3) || (now == 3 && temp == 2)) line(rP[1][0], rP[1][1], rP[2][0], rP[2][1]);
	else if ((now == 3 && temp == 4) || (now == 4 && temp == 3)) { line(rP[2][0], rP[2][1], rP[3][0], rP[3][1]); line(rP[11][0], rP[11][1], rP[3][0], rP[3][1]); }
	else if ((now == 3 && temp == 5) || (now == 5 && temp == 3)) { line(rP[2][0], rP[2][1], rP[3][0], rP[3][1]); line(rP[3][0], rP[3][1], rP[4][0], rP[4][1]); }
	else if ((now == 3 && temp == 6) || (now == 6 && temp == 3)) { moveto(rP[2][0], rP[2][1]); lineto(rP[3][0], rP[3][1]); lineto(rP[18][0], rP[18][1]); }
	else if ((now == 4 && temp == 5) || (now == 5 && temp == 4)) { line(rP[11][0], rP[11][1], rP[3][0], rP[3][1]); line(rP[3][0], rP[3][1], rP[4][0], rP[4][1]); }
	else if ((now == 4 && temp == 6) || (now == 6 && temp == 4)) { line(rP[11][0], rP[11][1], rP[3][0], rP[3][1]); line(rP[18][0], rP[18][1], rP[3][0], rP[3][1]); }
	else if ((now == 4 && temp == 7) || (now == 7 && temp == 4)) { moveto(rP[11][0], rP[11][1]); lineto(rP[14][0], rP[14][1]); lineto(rP[13][0], rP[13][1]); lineto(rP[16][0], rP[16][1]); lineto(rP[17][0], rP[17][1]); }
	else if ((now == 4 && temp == 9) || (now == 9 && temp == 4)) { moveto(rP[11][0], rP[11][1]); lineto(rP[14][0], rP[14][1]); lineto(rP[15][0], rP[15][1]); }
	else if ((now == 5 && temp == 6) || (now == 6 && temp == 5)) { moveto(rP[4][0], rP[4][1]); lineto(rP[3][0], rP[3][1]); lineto(rP[18][0], rP[18][1]); }
	else if ((now == 5 && temp == 8) || (now == 8 && temp == 5)) { line(rP[4][0], rP[4][1], rP[5][0], rP[5][1]); }//画线的
	else if ((now == 7 && temp == 1) || (now == 1 && temp == 7)) { moveto(rP[17][0], rP[17][1]); lineto(rP[16][0], rP[16][1]); lineto(rP[13][0], rP[13][1]); lineto(rP[12][0], rP[12][1]); }
	else if ((now == 7 && temp == 10) || (now == 10 && temp == 7)) { moveto(rP[17][0], rP[17][1]); lineto(rP[22][0], rP[22][1]); lineto(rP[7][0], rP[7][1]); lineto(rP[6][0], rP[6][1]); }
	else if ((now == 7 && temp == 12) || (now == 12 && temp == 7)) { moveto(rP[17][0], rP[17][1]); lineto(rP[22][0], rP[22][1]); lineto(rP[7][0], rP[7][1]); lineto(rP[23][0], rP[23][1]); }
	else if ((now == 7 && temp == 14) || (now == 14 && temp == 7)) { moveto(rP[17][0], rP[17][1]); lineto(rP[22][0], rP[22][1]); lineto(rP[7][0], rP[7][1]); lineto(rP[8][0], rP[8][1]); }
	else if ((now == 8 && temp == 10) || (now == 10 && temp == 8)) { line(rP[5][0], rP[5][1], rP[6][0], rP[6][1]); }
	else if ((now == 9 && temp == 10) || (now == 10 && temp == 9)) { line(rP[15][0], rP[15][1], rP[19][0], rP[19][1]); line(rP[19][0], rP[19][1], rP[6][0], rP[6][1]); }
	else if ((now == 10 && temp == 11) || (now == 11 && temp == 10)) line(rP[6][0], rP[6][1], rP[20][0], rP[20][1]);
	else if ((now == 10 && temp == 12) || (now == 12 && temp == 10)) { line(rP[6][0], rP[6][1], rP[7][0], rP[7][1]); line(rP[7][0], rP[7][1], rP[23][0], rP[23][1]); }
	else if ((now == 10 && temp == 14) || (now == 14 && temp == 10)) { line(rP[6][0], rP[6][1], rP[7][0], rP[7][1]); line(rP[7][0], rP[7][1], rP[8][0], rP[8][1]); }
	else if ((now == 12 && temp == 13) || (now == 13 && temp == 12))	line(rP[23][0], rP[23][1], rP[24][0], rP[24][1]);
	else if ((now == 12 && temp == 14) || (now == 14 && temp == 12)) { line(rP[7][0], rP[7][1], rP[23][0], rP[23][1]); line(rP[7][0], rP[7][1], rP[8][0], rP[8][1]); }
}