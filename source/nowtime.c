///////////////////////////////////////////
///nowtime.c
///FUNCTION: ϵͳʱ��Ļ�ȡ���ӡ 
///////////////////////////////////////////
#include"nowtime.h"
/********************
FUNCTION:nowtime 
DESCRIPTION:��ǰʱ���ȡ���� 
PARAMETERS:(x,y)Ϊͼ�η����������Ͻ����� ��bkcolorΪ��ӡʱ��λ�ñ�����ɫ 
********************/
void nowtime(int x,int y,int bkcolor) 
{
    char buffer[80];    // ����һ���ַ������飬���ڴ洢��ʽ�����ʱ��
    time_t rawtime;     // ����һ��time_t���͵ı������ڴ洢ʱ��
	setfillstyle(SOLID_FILL,bkcolor);
	setbkcolor(bkcolor); 
	settextstyle(SMALL_FONT, 0, 10);
 //   while(1)
	//{ 
    	time(&rawtime);     // ��ʱ���ʽ��   %Y-%m-%d :%S
    	strftime(buffer, 80, "%H:%M",localtime(&rawtime));  // ʹ��strftime������ʽ��ʱ���ַ���
  //  	if(bkcolor==WHITE)     // ��ֹ����Ϊ��ɫʱ��������ʾ������ 
		//{
		//	setfillstyle(SOLID_FILL,DARKGRAY);
		//	bar(x,y,x+100,y+20);
		//	setfillstyle(SOLID_FILL,bkcolor);
		//}
		outtextxy(x,y,&buffer[0]);  // �����ʽ�����ʱ���ַ���
		delay(10);            // �ӳ�0.1�룬��ֹˢ�¹��� 
	//}
}
