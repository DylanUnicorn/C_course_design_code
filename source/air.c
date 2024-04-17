#include<air.h>


void wind(int x, int y, int airType, int speed, int derection) //�������м䣬������ͷ
{
	int color;
	switch (airType) 
	{
		case 0:
			color = 1;//��ɫ���
			break;
		case 1:
			color = 4;//��ɫ�ȵ�
			break;
	}
	setcolor(color);
	setlinestyle(0, 0, 3);
	setfillstyle(1, color);//��ȫ���
	if (speed == 1 && derection == 1)//����С�� 
	{
		moveto(x, y);//�׵�
		lineto(x + 17, y - 9);
		lineto(x +17- 7, y -9 - 1);
		lineto(x +17 -7+ 21, y -9-1- 7);
		lineto(x + 17 - 7 + 21 - 8, y - 9 - 1 - 7 + 19);
		lineto(x + 17 - 7 + 21 - 8 - 3, y - 9 - 1 - 7 + 19 - 9);
		lineto(x + 2, y + 2);//β��
		lineto(x, y);
		floodfill(x+2, y, color);

	}
	else if (speed == 2 && derection == 1)
	{
		moveto(x, y);//�׵�
		lineto(x + 17+8, y - 9-7);
		lineto(x + 17 - 7+8, y - 9 - 1-7);
		lineto(x + 17 - 7 + 21+8, y - 9 - 1 - 7-7);
		lineto(x + 17 - 7 + 21 - 8+8, y - 9 - 1 - 7 + 19-7);
		lineto(x + 17 - 7 + 21 - 8 - 3+8, y - 9 - 1 - 7 + 19 - 9-7);
		lineto(x + 2, y + 2);//β��
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
	else if (speed == 1 && derection == 2) //����С��
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
	else if(speed ==2 && derection ==2)//�����з�
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
	else if (speed == 3 && derection == 2) //���д��
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
	else if (speed == 1 && derection == 3) //����С��
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
	else if (speed == 2 && derection == 3) //�����з�
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
	else if (speed == 3 && derection == 3) //���´��
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
		if (mode == 1) //���Ʒ��ټ�
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
		if (mode == 2) //���Ʒ��ټ�
		{
			if (pair->mode == 1)
			{
				if (pair->wind_speed > 1)
				{
					pair->wind_speed--;
				}
			}
		}
		if (mode == 3)//���Ʒ��� ����
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
	puthz(350, 215, "��", 32, 32, WHITE);
	outtextxy(467, 200, s2);
	puthz(516, 215, "��", 32, 32, WHITE);
	outtextxy(390, 385, s3);
	puthz(440, 400, "��", 32, 32, WHITE);
}

void airstage(int mode,AIR* pair)//״̬�ı�
{
	setcolor(WHITE);
	if (mode == 1)//�յ����ظı�
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
	else if (mode == 2)//ģʽ�ı�
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
	else if (mode == 3)//�������ȸı�
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
	else if (mode == 4)//ѭ��ģʽ�ı�
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
		bar(122, 240, 206, 291);//���ذ���
		puthz(127, 255, "��", 24, 24, WHITE);

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
			puthz(20, 255, "�Զ�", 24, 24, WHITE);
			
		}
		else if (pair->mode == 1) 
		{
			setfillstyle(1, DARKGRAY);
			bar(15, 240, 99, 291);
			puthz(20, 255, "�ֶ�", 24, 24, WHITE);
		}

		if (pair->air_type == 0) //���
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 324, 100,375);
			puthz(20, 339, "���", 24, 24, WHITE);
		}
		else if (pair->air_type == 1) //�ȷ�
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 324, 100, 375);
			puthz(20, 339, "�ȷ�", 24, 24, WHITE);
		}
		if (pair->loop == 0) 
		{
			setfillstyle(1, DARKGRAY);
			bar(122, 324, 206, 375);
			puthz(126, 339, "��ѭ��", 24, 24, WHITE);
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
			puthz(126, 339, "��ѭ��", 24, 24, WHITE);
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
			puthz(20, 423, "����", 24, 24, WHITE);
		}
		else if (pair->wind_direct == 2) 
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 405, 100, 456);
			puthz(20, 423, "����", 24, 24, WHITE);
		}
		else if (pair->wind_direct == 3) 
		{
			setfillstyle(1, DARKGRAY);
			bar(16, 405, 100, 456);
			puthz(20, 423, "����", 24, 24, WHITE);
		}
	}
	else 
	{
		setfillstyle(1, DARKGRAY);
		setcolor(DARKGRAY);
		bar(122, 240, 206, 291);
		puthz(127, 255, "��", 24, 24, WHITE);

		setfillstyle(1, BLACK);
		bar(69, 70, 144, 149);//������ͼ��Ĩ��

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
		else if (mouse_press(122, 240, 206, 291) == 1) //�ܿ���
		{
			airstage(1, pair);
			*ischange = 1;
			delay(300);
		}
		else if (mouse_press(15, 240, 99, 291) == 1) //ģʽ
		{
			airstage(2, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(16, 324, 100, 375) == 1) //��������
		{
			airstage(3, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(122, 324, 206, 375) == 1) //ѭ��ģʽ
		{
			airstage(4, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(4, 164, 44, 198) == 1) //��С����1
		{
			airfun(2, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(187, 166, 227, 200) == 1) //���ӷ���2
		{
			airfun(1, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(16, 405, 100, 456) == 1) //������
		{
			airfun(3, pair);
			*ischange = 1;
			delay(200);
		}
		else if (mouse_press(323, 129, 361, 161) == 1) //��������λ�õ������¶�
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