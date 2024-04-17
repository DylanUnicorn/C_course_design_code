#include "entern.h"

void life_page(int *page_index)
{

    setcolor(LIGHTGRAY);
    setbkcolor(WHITE);
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(0, 0, 639, 479);
    
    setfillstyle(SOLID_FILL, DARKGRAY); //背景板亮暗 
    bar(0, 0, 100, 479);
    bar(540, 0, 639, 479);
    setfillstyle(SOLID_FILL, LIGHTGRAY);
    bar(100, 0, 540, 479);
    
    setfillstyle(SOLID_FILL, DARKGRAY); //中间主页面三个选项矩形 
    bar(104, 170, 244, 310);
    bar(248, 170, 388, 310);
    bar(392, 170, 532, 310);
    line(100, 0, 100, 479);
    line(540, 0, 540, 479);
    setcolor(RED);                  
    line(104, 310, 244, 310);
    setcolor(GREEN);
    line(248, 310, 388, 310);
    setcolor(BLUE);
    line(392, 310, 532, 310);
    
    setcolor(LIGHTGRAY);        //两侧区域划分直线 
    line(5, 96, 95, 96);
    line(5, 192, 95, 192);
    line(5, 288, 95, 288);
    line(5, 384, 95, 384);
    line(545,420,634,420);     
    
    setcolor(WHITE);            //中间下方白色选项演示浮点 
    circle(298, 330, 2);
    floodfill(298, 333, WHITE);
    circle(308, 330, 2);
    floodfill(308, 333, WHITE);
    circle(318, 330, 4);
    floodfill(318, 333, WHITE); 
    circle(328, 330, 2);
    floodfill(328, 333, WHITE);
    circle(338, 330, 2);
    floodfill(338, 333, WHITE);
    
    setfillstyle(SOLID_FILL,DARKGRAY);  //鼠标作用矩形范围 
	bar(30,45,73,60);
	bar(35,141,70,156);
	bar(30,237,73,253);
	bar(19,333,79,348);
	bar(19,429,86,444);
	bar(564,445,615,460);
    
	puthz(154,220,"音乐",16,20,WHITE);   //区域文字名称打印
	puthz(298,220,"视频",16,20,WHITE);
	puthz(442,220,"天气",16,20,WHITE);
    settextstyle(SMALL_FONT, HORIZ_DIR, 5);
	outtextxy(33,50,"MUSIC");
	outtextxy(38,146,"GAME");
	outtextxy(33,242,"MOVIE");
	outtextxy(22,338,"WEATHER");
	outtextxy(22,434,"CALENDAR"); 
	outtextxy(567,450,"RETURN");

    
    clrmous(MouseX, MouseY);

    while (1)
    {
        newmouse(&MouseX, &MouseY, &press);
        if (mouse_press(104, 170, 244, 310) == 2) 
        {  
            MouseS = 1;//手势鼠标
        }
        else if (mouse_press(248, 170, 388, 310) == 2) 
		{
			MouseS = 1;
		}
		else if (mouse_press(392, 170, 532, 310) == 2) 
		{
			MouseS = 1;
		}
		else if (mouse_press(104, 170, 244, 310) == 1) 
		{
            clrmous(MouseX, MouseY);
            *page_index = 2;
            return;
		}
		else if (mouse_press(248, 170, 388, 310) == 1) 
		{
            clrmous(MouseX, MouseY);
            *page_index = 4;
            return;
		}
		else if (mouse_press(392, 170, 532, 310) == 1) 
		{
            clrmous(MouseX, MouseY);
            *page_index = 1;
            return;
		}
        else if(mouse_press(30, 45, 73, 60) == 1)
        {
            closegraph();
            *page_index = 3;
            return;
        }
        else
        {
            MouseS = 0;//默认情况
        }
    }
   //drawmous(200, 200);
   // mouse(200, 200);

    //getch();
    //closegraph();
    //return 0;
    


}
