#include "carsitu.h"
#include "nowtime.h"

void banshou_icon(int x,int y) 
{
	putbmp(x, y, "C:\\code\\bmp\\banshou.bmp");
}

void gantanhao(int x, int y,int mycolor) 
{
	int polypoint[8] = { 8, 8, 24, 8,12,  26,  20,  26 };
	int i = 3;
	while(i != -1)
	{
		polypoint[2*i]=polypoint[2*i]+x;
		polypoint[2*i+1]=polypoint[2*i+1]+y;
		i--;
	}
	setcolor(mycolor);
	setfillstyle(SOLID_FILL, mycolor);
	circle(x + 16, y + 16, 16);
	fillpoly(4, polypoint);
}

void car_page(int *page_index, AIR* pair,INSTRUMENT* pi,int* ischange)
{
	int str[3] = {0};//显示温度的
	setbkcolor(LIGHTGRAY);
	setcolor(WHITE);//画笔颜色
	setlinestyle(SOLID_LINE,0,THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, LIGHTGRAY);

	bar(0, 0, 639, 479);

	setfillstyle(SOLID_FILL, RED);//画红色
	bar(0, 0, 187, 19);
	setfillstyle(SOLID_FILL, WHITE);
	bar(11,20,85,21);//画白框
	bar(11,79,85,80);
	bar(11,138,85,139); 
	bar(11,197,85,198);

	setfillstyle(SOLID_FILL,DARKGRAY);//画灰框左上角的
	bar(15, 22, 81, 78);
	bar(15, 81, 81, 137);
	bar(15, 140, 81, 196);
	bar(15, 199, 81, 255);

	setfillstyle(SOLID_FILL, BLUE);//画蓝色信息框
	bar(36, 263, 318, 333);
	bar(320, 263, 602, 333);
	bar(36, 356, 318, 426);
	bar(320, 356, 602, 426);

	setfillstyle(SOLID_FILL, WHITE);//画白色线
	bar(319, 262, 319, 427);

	gantanhao(258, 283,WHITE);//画圆和感叹号
	gantanhao(542, 283,WHITE);
	gantanhao(258, 376,WHITE);
	gantanhao(542, 376,WHITE);

	banshou_icon(20, 27);//画扳手
	putbmp(20, 86, "C:\\code\\bmp\\clock.bmp");//画时钟
	putbmp(20, 145, "C:\\code\\bmp\\control.bmp");//画车
	putbmp(20, 204, "C:\\code\\bmp\\brake.bmp");//画车

	moveto(198, 221);//画小车图标
	lineto(180, 225);
	lineto(172,214);
	lineto(179, 209);
	lineto(175,188);
	lineto(180,167);
	lineto(201,145);
	lineto(287,139);
	lineto(355,97);
	lineto(517,104);
	lineto(552,136);
	lineto(557,144);
	lineto(557,179);
	lineto(555,198);
	lineto(545,214);
	lineto(522,215);
	lineto(516,199);
	moveto(441,198);
	lineto(273,198);
	moveto(201,198);
	lineto(198,221);
	moveto(274, 205);
	lineto(441, 203);
	moveto(516, 198);//画背后的斜线
	lineto(557, 179);
	
	circle(201 + 36,198,34);//画轮子
	circle(201 + 36, 198, 30);
	circle(201 + 36, 198, 20);
	circle(441+37, 198, 35);
	circle(441+37, 198, 30);
	circle(441+37, 198, 20);

	moveto(356, 102);//画镜子
	lineto(514, 109);
	lineto(540, 132);
	lineto(300, 138);
	lineto(356, 102);

	moveto(291, 144);//画车门
	lineto(289, 196);
	moveto(382, 142);
	lineto(378, 194);
	moveto(476, 134);
	lineto(465, 168);
	
	//puthz(41, 270, "engine", 24, 24,BLACK);
	settextstyle(SMALL_FONT, HORIZ_DIR, 8);
	outtextxy(43, 265, "Engine");
	outtextxy(327, 265, "Steering");
	outtextxy(43, 358, "Gear shift");	
	outtextxy(327, 358, "Suspensior");


	settextstyle(3, 0, 4);
	outtextxy(43, 290, "Comfort");
	outtextxy(327, 290, "Dynamic");
	outtextxy(43, 383, "Off");
	outtextxy(327, 383, "Comfort");
	
	puthz(200, 430, "点击小车开始导航", 32, 32, WHITE);

	puthz(25,3,"我的动态设置",16,20,BLACK);
	if (pair->air_con == 0) 
	{
		str[0] = 0;
		puthz(200, 20, "空调未开启", 16, 20, RED);
	}
	else 
	{
		puthz(200, 20, "空调已开启，当前温度：", 16, 20, RED);
		itoa(pair->air_degree[0], str, 10);
		setcolor(WHITE);
		outtextxy(350, 45, str);
		puthz(400, 50, "℃", 32, 32, RED);
	}
	MouseS = 0;
	clrmous(MouseX,MouseY);

	while (1)
	{
		
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(15, 21, 81, 78) == 1)
		{
			clrmous(MouseX, MouseY);
			cleardevice();
			setting_page(page_index,pair,pi,ischange);
			return;
		}
		else if (mouse_press(291, 144, 442, 199) == 1) 
		{
			clrmous(MouseX, MouseY);
			cleardevice();
			*page_index = 5;
			return;
		}
		else if (mouse_press(15, 21, 81, 78) == 2)
		{
			setcolor(RED);
			settextstyle(3, HORIZ_DIR, 3);
			outtextxy(89,48, "setting");
			MouseS = 1;
		}
		else if(mouse_press(15,81,81,137) == 1)
		{ 
			clrmous(MouseX, MouseY);
			clock_page(page_index, pair,pi,ischange);
			return;
		}
		else if (mouse_press(15, 81, 81,137) == 2)
		{
			setcolor(RED);
			settextstyle(3, HORIZ_DIR, 3);
			outtextxy(89, 108, "clock");

			MouseS = 1;
		}
		else if(mouse_press(15,140,81,196) == 1)
		{
			clrmous(MouseX, MouseY);
			air_page(page_index, pair,pi,ischange);
			return;
		}
		else if (mouse_press(15, 140, 81, 196) == 2)
		{
			setcolor(RED);
			settextstyle(3, HORIZ_DIR, 3);
			outtextxy(89, 168, "air");

			MouseS = 1;
		}
		else if(mouse_press(15,199,81,255) == 1)
		{
			clrmous(MouseX, MouseY);
			*page_index =  0;//第四个按钮
			return;
		}
		else if (mouse_press(15, 199, 81, 255) == 2)
		{
			setcolor(RED);
			settextstyle(3, HORIZ_DIR, 3);
			outtextxy(89, 230, "return");

			MouseS = 1;
		}
		else if(mouse_press(0, 0, 187, 19) == 1)
		{
			clrmous(MouseX, MouseY);
			*page_index = 2;//左上角是刷新作用的
			return;
		}
		else if (mouse_press(258, 283, 258 + 32, 283 + 32) == 2) 
		{
			//Mouse;
			gantanhao(258, 283, RED);
			setfillstyle(SOLID_FILL, YELLOW);
			bar(171, 278, 250, 322);
			settextstyle(2, HORIZ_DIR, 2);
			outtextxy(180, 280, "Engine is off");
			outtextxy(180, 300, "temperature is well");
			delay(100);
			
		}
		else if (mouse_press(542, 283, 542 + 32, 283 + 32) == 2) 
		{
			gantanhao(542, 283, RED);
			setfillstyle(SOLID_FILL, YELLOW);
			bar(455, 278, 534, 322);
			settextstyle(2, HORIZ_DIR, 2);
			outtextxy(465, 280, "Engine is off");
			outtextxy(465, 300, "temperature is well");
			delay(100);
		}
		else if (mouse_press(258, 376, 258 + 32, 376 + 32) == 2) 
		{
			gantanhao(258, 376, RED);
			setfillstyle(SOLID_FILL, YELLOW);
			bar(171, 371, 250, 415);
			settextstyle(2, HORIZ_DIR, 2);
			outtextxy(180, 373, "Engine is off");
			outtextxy(180, 393, "temperature is well");
			delay(100);
		}
		else if (mouse_press(542, 376, 542 + 32, 376 + 32) == 2) 
		{
			gantanhao(542, 376, RED);
			setfillstyle(SOLID_FILL, YELLOW);
			bar(455, 371, 534, 415);
			settextstyle(2, HORIZ_DIR, 2);
			outtextxy(465, 373, "Engine is off");
			outtextxy(465, 393, "temperature is well");
			delay(100);
		}
		else 
		{
			gantanhao(258, 283, WHITE);//画圆和感叹号
			gantanhao(542, 283, WHITE);
			gantanhao(258, 376, WHITE);
			gantanhao(542, 376, WHITE);
			setfillstyle(SOLID_FILL, BLUE);
			bar(171, 278, 250, 322);//刷掉感叹号信息，左上角

			bar(455, 278, 534, 322);//刷掉感叹号信息，右上角
			bar(171, 371, 250, 415);//刷掉感叹号信息，左下角
			bar(455, 371, 534, 415);//刷掉感叹号信息，右下角



			MouseS = 0;

			setfillstyle(SOLID_FILL, LIGHTGRAY);//消除附加的汉字
			bar(85, 33, 180, 78);
			bar(85, 92, 180, 137);
			bar(85, 151, 170, 196);
			bar(85, 210, 170, 255);
		}
	}
} 

void setting_page(int *page_index ,AIR* pair,INSTRUMENT* pi,int* ischange)
{
	int trianglepoint[] = { 503,29,525,39,503,52 };

	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 639, 479);
	puthz(52,25,"设置",32,32,WHITE);  //左上标
	settextstyle(3, HORIZ_DIR, 3);
	outtextxy(52, 60, "My car");

	setfillstyle(SOLID_FILL, DARKGRAY);//画灰色框
	bar(53, 109, 570, 157);
	puthz(55,115, "车灯与照明（内外车灯设置）", 24, 24, WHITE);
	bar(53, 165, 570, 210);
	puthz(55, 171, "后视镜与便捷功能（调节后视镜和舒适设置）", 24, 24, WHITE);
	bar(53, 221, 570, 268);
	puthz(55, 227, "车辆锁定设定（车窗车门的锁定和警报设置）", 24, 24, WHITE);
	bar(53, 277, 570, 324);
	puthz(55, 283, "驻车制动与悬架（发动机熄火时使用）", 24, 24, WHITE);
	bar(53, 333, 570, 380);
	puthz(55, 339, "雨刮器（进入刮扫调节菜单）", 24, 24, WHITE);
	bar(38, 389, 135, 429);//画返回按钮
	puthz(50, 395, "返回", 24, 24, WHITE);

	line(284, 23, 334, 23);//画上面的双线
	line(283, 32, 334, 32);
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(3, trianglepoint);//画三角形

	while (1) 
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(38, 389, 135, 429) == 1) 
		{
			clrmous(MouseX, MouseY);
			*page_index = 2;
			return;
		}
		else if (mouse_press(38, 389, 135, 429) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(53, 109, 400, 157) == 1)
		{
			clrmous(MouseX, MouseY);
			cleardevice();
			light_setting_page(page_index,pair,pi,ischange);
			return;
		}
		else if (mouse_press(53, 165, 570, 210) == 1)
		{
			clrmous(MouseX, MouseY);
			cleardevice();
			RearviewMirror_setting_page(page_index,pair,pi,ischange);
			return;
		}
		else if (mouse_press(53, 221, 570, 268) == 1)
		{
			clrmous(MouseX, MouseY);
			cleardevice();
			VehicleLock_setting_page(page_index,pair,pi,ischange);
			return;

		}
		else if (mouse_press(53, 333, 570, 380) == 1)
		{
			clrmous(MouseX, MouseY);
			cleardevice();
			Wiper_setting_page(page_index,pair,pi,ischange);
		}
		else if (mouse_press(53, 109, 400, 157) == 2)
		{

			MouseS = 1;
		}
		else if (mouse_press(53, 165, 570, 210) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(53, 221, 570, 268) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(53, 333, 570, 380) == 2)
		{
			MouseS = 1;
		}
		else if (mouse_press(38, 389, 135, 429) == 2)
		{
			MouseS = 1;
		}
		else 
		{
			MouseS = 0;
		}
	
	}
}

void clock_page(int* page_index, AIR* pair, INSTRUMENT* pi, int* ischange)
{
	clock_t start;
	int x,y;
	void* buffer;
	unsigned a;
	a = imagesize(56, 128, 260, 332);
	buffer = malloc(a);
	start = clock();
						
	clrmous(MouseX, MouseY);
	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, BLACK);
	bar(0, 0, 639, 479);	
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);

	circle(158, 230,102);//速度表
	circle(158, 230, 97);
	circle(158, 230, 50);
	line(85,301,92,294);	//速度表刻度
	outtextxy(95, 275, "0");
	line(72, 287, 78, 282);
	outtextxy(80, 255, "20");
	line(63,269,72,265);
	line(57, 251, 65, 249);
	line(56, 231, 66, 231);
	outtextxy(71, 226, "40");
	line(58, 212, 66, 214);
	line(61, 192, 74, 199);
	outtextxy(80, 195, "60");
	line(74, 177, 80, 181);
	line(86, 163, 93, 170);
	outtextxy(95, 170, "80");
	line(101, 151, 106, 157);
	line(118, 142, 122, 151);
	outtextxy(115, 150, "100");
	line(138, 137, 138, 144);
	line(157, 135, 157, 144);
	outtextxy(150, 140, "120");
	line(176, 138, 175, 146);
	line(195,144, 191, 152);
	outtextxy(185, 155, "140");
	line(211, 153, 206, 160);
	line(226, 165, 220, 171);
	outtextxy(205, 175, "160");
	line(238, 177, 232, 183);
	line(247, 197, 239, 201);
	outtextxy(220, 210, "180");
	line(253, 216, 246, 217);
	line(254, 234, 246, 234);
	outtextxy(220, 240, "200");
	line(253, 247, 247, 247);
	line(251, 260, 244, 258);
	line(246, 272, 238, 268);
	outtextxy(210, 270, "230");
	line(241, 283, 235, 280);
	line(233, 294, 228, 289);
	line(225, 303, 218, 296);
	outtextxy(190, 285, "260");

	getimage(56, 128, 260, 332, buffer);
	putimage(360, 128, buffer, COPY_PUT);
	free(buffer);

	setfillstyle(SOLID_FILL,BLACK );//除去下面那个多余的部分
	bar(91, 298, 216, 336);

	settextstyle(SMALL_FONT, HORIZ_DIR, 8);
	puthz(67,335,"总里程：",16,16,WHITE);//总里程
	outtextxy(200, 325, "km");

	setfillstyle(SOLID_FILL, DARKGRAY);//画白色车子
	bar(0, 416, 151, 478);//左下角的灰色框
	puthz(15, 425, "返回", 48, 48, BLACK);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);

	setfillstyle(SOLID_FILL, DARKGRAY);//画右边的灰色框

	settextstyle(3, HORIZ_DIR, 3);
	outtextxy(206, 50, "13 C");
	setlinestyle(0, 0, 1);
	circle(242, 53, 2);

	x = 200, y = -35;//画灯光的标志
	setfillstyle(SOLID_FILL, DARKGRAY);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	circle(x + 80, 100 + y, 9);
	circle(110 + x, 100 + y, 9);
	bar(70 + x, 91 + y, 80 + x, 110 + y);
	bar(110 + x, 91+ y, 120 + x, 110 + y);
	line(80 + x, 91+ y, 80 + x, 109+ y);
	line(110 + x, 91+ y, 110 + x, 109 +y);
	line(79 + x, 90+ y, 75 + x, 85+ y);
	line(79 + x, 100+ y, 75 + x, 100+ y);
	line(79 + x, 110+ y, 75 + x, 115+ y);
	line(111 + x, 90+ y, 115 + x, 85+ y);
	line(111 + x, 100+ y, 115 + x, 100+ y);
	line(111 + x, 110+ y, 115 + x, 115+ y);

	puthz(370, 335, "剩余油量：", 16, 16, WHITE);
	outtextxy(500, 325, "mL");
	puthz(370,375 ,"预计可用：", 16, 16, WHITE);
	outtextxy(500, 365, "h");
	nowtime(387, 56, BLACK);

	while (1) 
	{
		if (clock() - start == 10)
		{
			start = clock();
			setfillstyle(SOLID_FILL, BLACK);
			bar(387,56,387 + 200, 56 + 50);
			nowtime(387, 56, BLACK);
		}
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(0, 416, 151, 478) == 1) 
		{
			clrmous(MouseX, MouseY);
			*page_index = 2;
			return;
		}
		else if (mouse_press(0, 416, 151, 478) == 2)
		{
			MouseS = 1;
		}
		else 
		{
			MouseS = 0;
		}
	}
}

void air_page(int *page_index, AIR* pair,INSTRUMENT* pi,int *ischange)
{
	int humanpoly[] = { 155+30,103,144+30,114,128+30,116,115+30,136,124+30,136,134+30,126,148+30,125,162+30,103,155+30,103 };
	int tranglepoint11[] = { 324,129,358,129,341,160 };
	int tranglepoint12[] = { 340,250,324,280,358,280 };
	int tranglepoint21[] = { 472,130,506,130,489,161 };
	int tranglepoint22[] = { 488,250,472,280,506,280 };
	int tranglepoint31[] = { 411,323,444,323,427,354 };
	int tranglepoint32[] = { 427,444,411,474,444,474 };

	clrmous(MouseX, MouseY);
	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, BLACK);
	settextstyle(SMALL_FONT, 0, 10);
	bar(0, 0, 639, 479);

	line(15, 21, 29, 7);//返回按钮
	line(30, 7, 45, 21);
	moveto(21, 21);
	lineto(21, 35);
	lineto(39, 35);
	lineto(39, 21);
	puthz(52, 50, "空调温度设置", 24, 24,WHITE);
	outtextxy(500, 50, "12:00");

	setfillstyle(SOLID_FILL,WHITE);//画风向小人
	bar(156+30, 89, 165+30, 98);
	fillpoly(8, humanpoly);

	setfillstyle(SOLID_FILL, LIGHTGRAY);//画灰色框
	bar(4, 164, 44, 198);
	settextstyle(3, HORIZ_DIR, 5);
	outtextxy(7, 155, "-");
	bar(51, 183, 75, 198);
	bar(77, 183, 101, 198);
	bar(104, 183, 128, 198);
	bar(131, 183, 155, 198);
	bar(158, 183, 182, 198);
	bar(186, 167, 227, 200);
	outtextxy(189, 158, "+");

	bar(15, 240, 99, 291);//画左边的框
	puthz(20, 255, "自动", 24, 24, WHITE);
	bar(122, 240, 206, 291);
	puthz(127, 255, "关", 24, 24, WHITE);
	bar(15,324,99,375);
	puthz(20, 339, "热风", 24, 24, WHITE);
	bar(122,324,206,375);
	puthz(127,339,"内循环",24,24,WHITE);
	bar(15, 408, 99, 459);
	puthz(20, 423, "风向", 24, 24, WHITE);

	fillpoly(3, tranglepoint11);//画温度调节三角形
	puthz(301, 175, "主驾温度", 24, 24, WHITE);
	fillpoly(3, tranglepoint12);
	fillpoly(3, tranglepoint21);
	puthz(449, 175, "副驾温度", 24, 24, WHITE);
	fillpoly(3, tranglepoint22);
	fillpoly(3, tranglepoint31);
	puthz(386, 360, "后排温度", 24, 24, WHITE);
	fillpoly(3, tranglepoint32);

	moveto(152, 420);//下面的小车表示风向
	lineto(178, 418);
	lineto(190, 424);
	lineto(190, 434);
	lineto(186, 434);
	moveto(172, 434);
	lineto(151, 434);
	moveto(139, 434);
	lineto(133, 434);
	lineto(133, 429);
	lineto(143, 425);
	circle(144, 436, 4);//轮子
	circle(179, 434, 4);
	line(138, 418, 154, 426);//画内外循环风向
	line(154, 426, 164, 426);
		
	airusemous(page_index, pair,ischange);
}
void back_icon() 
{
	setcolor(WHITE);//画返回标志
	moveto(589, 58);
	lineto(599, 49);
	lineto(599, 66);
	lineto(589, 58);
	moveto(599, 58);
	lineto(605, 58);
	lineto(607, 59);
	lineto(609, 61);
	lineto(610, 63);
	lineto(610, 74);
	lineto(609, 76);
	lineto(607, 78);
	lineto(606, 79);
	lineto(586, 79);
	moveto(579, 39);
	lineto(583, 34);
	lineto(612, 34);
	lineto(616, 39);
	lineto(616, 95);
	lineto(613, 98);
	lineto(583, 98);
	lineto(579, 95);
	lineto(579, 35);

}
void light_setting_page(int* page_index, AIR* pair, INSTRUMENT* pi,int * ischange)
{

	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, DARKGRAY);
	settextstyle(SMALL_FONT, 0, 15);

	puthz(28,63,"灯光设置",32,32,WHITE);
	setcolor(YELLOW);//画分割线
	line(10, 106, 633,106);
	back_icon();

	bar(30, 113, 617, 188);//画灯光设置框
	puthz(50, 113 + 20, "仪表照明", 32, 32, WHITE);
	bar(30, 200, 617, 275);
	puthz(50, 200 + 20, "车内照明", 32, 32, WHITE);
	bar(30, 287, 617, 362);
	puthz(50, 287 + 20, "车外照明", 32, 32, WHITE);

	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(531, 141, 607, 156);
	bar(531, 141 + 87, 607, 156 + 87);
	bar(531, 141 + 174, 607, 156 + 174);

	SetLuseMous(page_index, pair,pi,ischange);
}

void RearviewMirror_setting_page(int *page_index, AIR* pair,INSTRUMENT* pi,int *ischange)
{
	int trangle1[] = { 89,155,80,172,99,172 };
	int trangle2[] = { 80,259,89,277,99,259 };
	int trangle3[] = { 133,205,133,224,151,215 };
	int trangle4[] = { 46,205,46,224,28,214 };

	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, DARKGRAY);
	settextstyle(SMALL_FONT, 0, 15);

	puthz(28, 63, "后视镜和舒适设置", 32, 32, WHITE);
	setcolor(YELLOW);//画分割线
	line(10, 106, 633, 106);
	back_icon();//画返回标志

	puthz(38, 113, "后视镜", 32, 32, WHITE);
	circle(89, 214,64);//画控制的圆
	circle(89, 214, 29);
	line(117, 192, 136, 173);
	line(115, 240, 134, 262);
	line(70, 245, 51, 267);
	line(67, 188, 45, 170);

	fillpoly(3, trangle1);//画控制方向盘
	fillpoly(3, trangle2);
	fillpoly(3, trangle3);
	fillpoly(3, trangle4);
	puthz(70, 198, "左", 32, 32, WHITE);

	puthz(38, 280, "座椅调整", 32, 32, WHITE);

	setfillstyle(1, WHITE);
	setcolor(RED);
	bar(67, 321, 96, 331);
	bar(117, 321, 146, 331);
	//line(96, 323, 67, 343);
	//line(117, 326, 151, 340);
	bar(85, 346, 98, 360);
	line(106, 345, 105, 340);//画座椅调整的线--1
	line(104, 337, 102, 342);
	line(106, 338, 109, 343);
	bar(100, 333, 113, 347);
	line(94, 353, 89, 353);//2
	line(91, 350, 87, 353);
	line(86, 355, 91, 357);
	bar(115, 346, 128, 360);
	line(105, 362, 105, 367);//3
	line(102, 366, 105, 370);
	line(107, 371, 110, 365);
	line(118, 353, 123, 353);
	bar(100, 360,113, 374);
	line(125, 350, 129, 353);//4
	line(130, 355, 125, 357);
	line(114, 362, 114, 367);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(50, 391, 162, 439);//画改变不同座椅的按钮
	line(201, 371, 232, 371);//主驾
	line(232, 371, 232, 333);
	line(201, 442, 231, 442);//副驾
	line(231, 442, 231, 404);
	line(425, 411, 473, 411);//后排
	line(473, 411, 473, 357);

	line(335, 191, 408, 216);//画左后视镜
	line(332, 203, 404, 229);
	//moveto(327, 191);
	//lineto(309, 160);
	//lineto(228, 160);
	//lineto(216, 206);
	//lineto(245, 239);
	//lineto(317, 239);
	//lineto(327, 210);

	line(414, 215, 486, 190);
	line(487, 203, 415, 229);
	//moveto(493, 189);
	//lineto(513,159);
	//lineto(594, 160);
	//lineto(607, 203);
	//lineto(576, 239);
	//lineto(505, 239);
	//lineto(493, 215);

	setfillstyle(SOLID_FILL, LIGHTGRAY);
	fillellipse(409, 140, 30,30);//画回归原后视镜的按键
	puthz(390, 125, "回归", 24, 24, WHITE);

	fillellipse(413, 302, 30, 30);//画回归原来座椅的按键
	puthz(394, 291, "回归", 24, 24, WHITE);


	RVuseMous(page_index, pair,pi,ischange);
}

void VehicleLock_setting_page(int* page_index, AIR* pair,INSTRUMENT* pi,int *ischange)
{
	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, DARKGRAY);
	settextstyle(SMALL_FONT, 0, 15);

	puthz(28, 63, "车辆锁定设定", 32, 32, WHITE);
	setcolor(YELLOW);//画分割线
	line(10, 106, 633, 106);
	back_icon();//画返回标志

	puthz(58, 130, "门锁控制", 32, 32, WHITE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(43, 189, 97, 257);
	puthz(50, 195, "上", 24, 24, WHITE);
	puthz(50, 230, "下", 24, 24, WHITE);
	bar(151, 189, 205, 257);
	puthz(158, 195, "上", 24, 24, WHITE);
	puthz(158, 230, "下", 24, 24, WHITE);
	bar(43, 289, 97, 357);
	puthz(50, 295, "上", 24, 24, WHITE);
	puthz(50, 330, "下", 24, 24, WHITE);
	bar(151, 289, 205, 357);
	puthz(158, 295, "上", 24, 24, WHITE);
	puthz(158, 330, "下", 24, 24, WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//画门锁控制
	line(43, 224, 97, 224);
	line(151,224, 205, 224);
	line(43, 324, 97, 324);
	line(151, 324, 205, 324);

	//画左前门
	moveto(254, 227);//画外轮廓
	lineto(332, 152);
	lineto(345, 152);
	lineto(345, 227);
	lineto(351, 233);
	lineto(351, 293);
	lineto(262, 293);
	lineto(262, 234);
	lineto(254, 227);
	moveto(317, 179);//画车窗，从左上角开始画，顺时针
	lineto(340, 179);
	lineto(340, 223);
	lineto(273, 223);
	lineto(318, 179);
	moveto(321, 237);//画开关
	lineto(341, 237);
	lineto(341, 245);
	lineto(321, 245);
	lineto(321, 237);

	moveto(491, 153);//画右前门
	lineto(491, 228);
	lineto(485, 235);
	lineto(485, 294);
	lineto(574, 294);
	lineto(574, 237);
	lineto(583, 228);
	lineto(504, 153);
	lineto(491, 153);//
	moveto(497, 180);//画车窗，从左上角开始画，顺时针
	lineto(518, 180);
	lineto(564, 225);
	lineto(497, 225);
	lineto(497, 180);//
	moveto(496, 238);//画开关
	lineto(516, 238);
	lineto(516, 246);
	lineto(496, 246);
	lineto(496, 238);

	moveto(254, 227+170);//画外轮廓
	lineto(332, 152+170);
	lineto(345, 152+170);
	lineto(345, 227 + 170);
	lineto(351, 233 + 170);
	lineto(351, 293 + 170);
	lineto(262, 293 + 170);
	lineto(262, 234 + 170);
	lineto(254, 227 + 170);//
	moveto(317, 179 + 170);
	lineto(340, 179 + 170);
	lineto(340, 223 + 170);
	lineto(273, 223 + 170);
	lineto(318, 179 + 170);
	moveto(321, 237 + 170);
	lineto(341, 237 + 170);
	lineto(341, 245 + 170);
	lineto(321, 245 + 170);
	lineto(321, 237 + 170);

	moveto(491, 153 + 170);//画右前门
	lineto(491, 228 + 170);
	lineto(485, 235 + 170);
	lineto(485, 294 + 170);
	lineto(574, 294 + 170);
	lineto(574, 237 + 170);
	lineto(583, 228 + 170);
	lineto(504, 153 + 170);
	lineto(491, 153 + 170);//
	moveto(497, 180 + 170);
	lineto(518, 180 + 170);
	lineto(564, 225 + 170);
	lineto(497, 225 + 170);
	lineto(497, 180 + 170);//
	moveto(496, 238 + 170);
	lineto(516, 238 + 170);
	lineto(516, 246 + 170);
	lineto(496, 246 + 170);
	lineto(496, 238 + 170);


	DWusemous(page_index,pi,ischange);
}

void Wiper_setting_page(int* page_index, AIR* pair,INSTRUMENT* pi,int *ischange)
{
	setbkcolor(BLACK);
	setcolor(WHITE);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);//背景，画笔颜色和选型
	setfillstyle(SOLID_FILL, DARKGRAY);
	settextstyle(SMALL_FONT, 0, 15);

	puthz(28, 63, "雨刮器", 32, 32, WHITE);
	setcolor(YELLOW);//画分割线
	line(10, 106, 633, 106);
	back_icon();//画返回标志

	puthz(58, 130, "前挡风玻璃", 32, 32, WHITE);
	setfillstyle(SOLID_FILL, DARKGRAY);
	bar(43, 189,600 , 257);
	bar(43, 289, 600, 357);
	puthz(100, 195, "倒车档时后窗玻璃刮水",32,32,WHITE);
	puthz(100, 295, "雨天时自动刮水", 32, 32, WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(50,202,90,242);
	bar(50, 302, 90, 342);

	while (1) 
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(578, 34, 616, 98) == 1) 
		{
			clrmous(MouseX, MouseY);
			setting_page(page_index,pair,pi,ischange);
			return;
		}
		else 
		{
			MouseS = 0;
		}
	}
}