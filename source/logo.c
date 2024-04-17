#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<conio.h>
int main()
{
	int v[10] = {320,240,335,255,380,210,365,195,320,240};
	int v1[10] = {0};
	int gd =VGA, gm = VGAHI;
	initgraph(&gd,&dm,"C:\\BORLANDC\\BGI");
	
	setfillstyle(SOLID_FILL,WHITE);
	fillpoly(5,v);
	pieslice(370,190,0,360,20);
	pieslice();  //¿í¶È66£¬¸ß¶È56 
	getch();
	closegraph();
	return 0;	
} 
