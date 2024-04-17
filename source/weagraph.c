///////////////////////////////////////////
///Weagraph.c
///FUNCTION: ����ͼ������������� 
///////////////////////////////////////////
#include"weagraph.h" 
/********************
FUNCTION:sunny
DESCRIPTION:����ͼ��
PARAMETERS:(x1,y1)Ϊͼ�η����������Ͻ����� ����x2,y2)Ϊ���½�����
********************/
void sunny(int x1, int y1, int x2, int y2)
{
	if (x2 - x1 == y2 - y1 || x1 - x2 == y2 - y1)
	{
		setfillstyle(SOLID_FILL, YELLOW);
		if ((x2 - x1) / 2 < 20)
		{
			pieslice((x1 + x2) / 2, (y1 + y2) / 2, 0, 360, (x2 - x1) / 2);
		}
		else
		{
			pieslice((x1 + x2) / 2, (y1 + y2) / 2, 0, 360, 20);
		}
	}
	//else
	//{
	//	printf("error! The area referred to is not a reasonable area!");
	//}
}

/*********************
FUNCTION:rainy
DESCRIPTION:����ͼ��
PARAMETERS:(x1,y1)Ϊͼ�η����������ϽǷ�Χ������ ����x2,y2)Ϊ���½Ƿ�Χ������
**********************/
void rainy(int x1, int y1, int x2, int y2)
{
	if (x2 > x1 && y2 > y1)
	{
		setfillstyle(SOLID_FILL, WHITE);
		if (((x2 - x1) / 2) < 20)
		{
			pieslice(x1, y2 + x1 / 2 - x2 / 2, 0, 360, (x2 - x1) / 2);
			pieslice(x2, y2 + x1 / 2 - x2 / 2, 0, 360, (x2 - x1) / 2);
			pieslice((x2 + x1) / 2, (y2 + y1) / 2 - (y2 - y1) / 2, 0, 360, (x2 - x1) / 2);
			bar(x1, y1, x2, y2);
			setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
			setcolor(BLUE);
			line(x1 + 10, y2 + 3, x1 + 10, y2 + 4);
			line(x1 + 11, y2 + 7, x1 + 10, y2 + 8);
			line(x1 + 11, y2 + 3, x1 + 11, y2 + 4);
			line(x2 - 10, y2 + 3, x2 - 10, y2 + 4);
			line(x2 - 16, y2 + 7, x2 - 16, y2 + 8);
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(WHITE);
		}
		else
		{
			pieslice(x1, y2 + x1 / 2 - x2 / 2, 0, 360, 20);
			pieslice(x2, y2 + x1 / 2 - x2 / 2, 0, 360, 20);
			pieslice((x2 + x1) / 2, (y2 + y1) / 2 - (y2 - y1) / 2, 0, 360, 20);
			bar(x1, y1, x2, y2);
			setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
			setcolor(BLUE);
			line(x1 + 10, y2 + 3, x1 + 10, y2 + 4);
			line(x1 + 11, y2 + 7, x1 + 10, y2 + 8);
			line(x1 + 11, y2 + 3, x1 + 11, y2 + 4);
			line(x2 - 10, y2 + 3, x2 - 10, y2 + 4);
			line(x2 - 16, y2 + 7, x2 - 16, y2 + 8);
			setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
			setcolor(WHITE);
		}
	}
	//else
	//{
	//	printf("error! The area referred to is not a reasonable area!");	
	//}
}

/*********************
FUNCTION:rainy
DESCRIPTION:����ͼ��
PARAMETERS:(x1,y1)Ϊͼ�η����������ϽǷ�Χ������ ����x2,y2)Ϊ���½Ƿ�Χ������
**********************/
void cloudy(int x1, int y1, int x2, int y2)
{
	setfillstyle(SOLID_FILL, WHITE);
	if (x2 > x1 && y2 > y1)
	{
		setfillstyle(SOLID_FILL, WHITE);
		if (((x2 - x1)) / 2 < 20)
		{
			pieslice(x1, y2 + x1 / 2 - x2 / 2, 0, 360, (x2 - x1) / 2);
			pieslice(x2, y2 + x1 / 2 - x2 / 2, 0, 360, (x2 - x1) / 2);
			pieslice((x2 + x1) / 2, (y2 + y1) / 2 - (y2 - y1) / 2, 0, 360, (x2 - x1) / 2);
			bar(x1, y1, x2, y2);
		}
		else
		{
			pieslice(x1, y2 + x1 / 2 - x2 / 2, 0, 360, 20);
			pieslice(x2, y2 + x1 / 2 - x2 / 2, 0, 360, 20);
			pieslice((x2 + x1) / 2, (y2 + y1) / 2 - (y2 - y1) / 2, 0, 360, 20);
			bar(x1, y1, x2, y2);
		}
	}
	//else
	//{
	//	printf("error! The area referred to is not a reasonable area!");	
	//}
}




