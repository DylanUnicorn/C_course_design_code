///////////////////////////////////////////
///pro_bar.c
///FUNCTION: 进度条的打印 
///////////////////////////////////////////
#include"public.h"
#include"pro_bar.h"
/********************
FUNCTION:pro_bar
DESCRIPTION:打印进度条的函数 
PARAMETERS:(x,y)为图形方形区域左上角坐标 ，bkcolor为打印进度条位置背景颜色，time为进度条打印快慢时间 
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
