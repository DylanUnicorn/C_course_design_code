///////////////////////////////////////////
///pro_bar.c
///FUNCTION: �������Ĵ�ӡ 
///////////////////////////////////////////
#include"public.h"
#include"pro_bar.h"
/********************
FUNCTION:pro_bar
DESCRIPTION:��ӡ�������ĺ��� 
PARAMETERS:(x,y)Ϊͼ�η����������Ͻ����� ��bkcolorΪ��ӡ������λ�ñ�����ɫ��timeΪ��������ӡ����ʱ�� 
********************/
void pro_bar(int x, int y,int length,int bkcolor)
{
	int BAR_WIDTH = length;
	int filled_width = 0;
	
	setfillstyle(SOLID_FILL,RED);
	while(1)
	{
		if(filled_width<BAR_WIDTH)
		{
			bar(x,y,x+filled_width,y+5);	
		}
		else
		{
			setfillstyle(SOLID_FILL,bkcolor);
			bar(x,y,x+length,y+5);
			break;
		}
		filled_width +=2;
		delay(100);
	}	
}
