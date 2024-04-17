///////////////////////////////////////////
///nowtime.c
///FUNCTION: 系统时间的获取与打印 
///////////////////////////////////////////
#include"nowtime.h"
/********************
FUNCTION:nowtime 
DESCRIPTION:当前时间获取函数 
PARAMETERS:(x,y)为图形方形区域左上角坐标 ，bkcolor为打印时间位置背景颜色 
********************/
void nowtime(int x,int y,int bkcolor) 
{
    char buffer[80];    // 创建一个字符串数组，用于存储格式化后的时间
    time_t rawtime;     // 创建一个time_t类型的变量用于存储时间
	setfillstyle(SOLID_FILL,bkcolor);
	setbkcolor(bkcolor); 
	settextstyle(SMALL_FONT, 0, 10);
 //   while(1)
	//{ 
    	time(&rawtime);     // 将时间格式化   %Y-%m-%d :%S
    	strftime(buffer, 80, "%H:%M",localtime(&rawtime));  // 使用strftime函数格式化时间字符串
  //  	if(bkcolor==WHITE)     // 防止背景为白色时，字体显示不出来 
		//{
		//	setfillstyle(SOLID_FILL,DARKGRAY);
		//	bar(x,y,x+100,y+20);
		//	setfillstyle(SOLID_FILL,bkcolor);
		//}
		outtextxy(x,y,&buffer[0]);  // 输出格式化后的时间字符串
		delay(10);            // 延迟0.1秒，防止刷新过快 
	//}
}
